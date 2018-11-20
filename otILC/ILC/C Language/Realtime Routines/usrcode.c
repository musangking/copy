//---------------------------------------------------------------------------
//  Project PowerPMAC Firmware
//  Delta Tau Data Systems, Inc.
//  Copyright  2007. All Rights Reserved.
//
//  SUBSYSTEM:			User Servo Driver
//  FILE:         		usrcode.c
//  TEMPLATE AUTHOR:		Henry Bausley
//
//  OVERVIEW
//  ~~~~~~~~
//  This file is where exportable user code can be placed.
//  To make a function callable as a user servo do three steps
//
//  1.)  Prototye the function user_func(void ,void );
//  2.)  Export the function  EXPORT_SYMBOL(user_func);
//  3.)  Make sure useralgo.ko has been loaded with projpp.ini
//
//--------------------------------------------------------------------------------
#include "usrcode.h"
//----------------------------------------------------------------------------------
// pp_proj.h is the C header for accessing PMAC Global, CSGlobal, Ptr vars
// _PPScriptMode_ for Pmac Script like access global & csglobal
// global Mypvar - access with "Mypvar"
// global Myparray(32) - access with "Myparray(i)"
// csglobal Myqvar - access with "Myqvar(i)" where "i" is Coord #
// csglobal Myqarray(16) - access with "Myqvar(i,j)" where "j" is index
// _EnumMode_ for Pmac enum data type checking on Set & Get global functions
// Example
// global Mypvar
// csglobal Myqvar
// "SetGlobalVar(Myqvar, data)" will give a compile error because its a csglobal var.
// "SetCSGlobalVar(Mypvar, data)" will give a compile error because its a global var.
//------------------------------------------------------------------------------------
#define _PPScriptMode_	// uncomment for Pmac Script type access
// #define _EnumMode_			// uncomment for Pmac enum data type checking on Set & Get global functions		

#include "../Include/pp_proj.h"
#ifdef __KERNEL__
// Kernal mode can't have paths with spaces and long names
//#include "../../PMACSC~1/GLOBAL~1/asharedwithcapp.pmh"
#else
//#include "../../PMAC Script Language/Global Includes/asharedwithcapp.pmh"
#endif

extern struct SHM        *pshm;  // Pointer to shared memory
extern volatile unsigned *piom;  // Pointer to I/O memory
extern void              *pushm; // Pointer to user memory

void user_phase( struct MotorData *Mptr)
{
}

double user_pid_ctrl( struct MotorData *Mptr)
{
  double *p;
  p = pushm;
  return 0;
}

void CaptCompISR(void)
{
  unsigned *pUnsigned = pushm;
  *pUnsigned = *pUnsigned + 1;
}

double GetLocal(struct LocalData *Ldata,int m)
{
  return *(Ldata->L + Ldata->Lindex + m);
}

void SetLocal(struct LocalData *Ldata,int m,double value)
{
  *(Ldata->L + Ldata->Lindex + m) = value;
}

double *GetLocalPtr(struct LocalData *Ldata,int m)
{
  return (Ldata->L + Ldata->Lindex + m);
}

double CfromScript(double cfrom_type, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, struct LocalData *Ldata)
{
  int icfrom_type = (int) cfrom_type;
  double *C, *D, *L, *R, rtn; // C, D, R - only needed if doing Kinmatics
  
  C = GetCVarPtr(Ldata);  // Only needed if doing Kinmatics
  D = GetDVarPtr(Ldata);  // Only needed if doing Kinmatics
  L = GetLVarPtr(Ldata);  // Only needed if using Ldata or Kinmatics
  R = GetRVarPtr(Ldata);  // Only needed if doing Kinmatics
  rtn = -1.0;
  return rtn;
}

/*************************迭代学习控制*************************/
/*************************
  初始化
*************************/
int ILC_Init(struct Para *ILC)
{	
	int AddrInterval = 0;
	
	ILC->TrajRunNums = 0;
	//ILC->CurTrajLength = 0;
	CurTrajLength = 0;
	ILC->CurTrajCounter = 0;

	ILC->CurrentFF = 0;

	ILC->kp = 3;   //学习律参数
	ILC->ki = 0.1;
	ILC->kd = 10;
	
	ILC->SingleIntBufferWidth = sizeof(int);
	ILC->SingleDataBufferWidth = sizeof(double);
	ILC->SingleBufferDepth = 1500;//1000*T/pshm->ServoPeriod;
	ILC->Error =  (volatile double *) pushm + 8;
	AddrInterval = ILC->SingleDataBufferWidth * ILC->SingleBufferDepth;
	//AddrInterval = ILC->SingleBufferDepth;
	ILC->LastFF = (volatile int *) pushm + 8 + AddrInterval;
	AddrInterval += ILC->SingleIntBufferWidth * ILC->SingleBufferDepth;
	ILC->Tmp1 = (volatile int *) pushm + 8 + AddrInterval;
	AddrInterval += ILC->SingleIntBufferWidth * ILC->SingleBufferDepth;
	ILC->Tmp2 = (volatile int *) pushm + 8 + AddrInterval;
	AddrInterval += ILC->SingleIntBufferWidth * ILC->SingleBufferDepth;
	ILC->Tmp3 = (volatile int *) pushm + 8 + AddrInterval;
	AddrInterval += ILC->SingleIntBufferWidth * ILC->SingleBufferDepth;
	ILC->Tmp4 = (volatile int *) pushm + 8 + AddrInterval;
	F_isClearing = 1;
	ILC_Clear(ILC);
	return 0;
}
/*************************
  清空缓存器
*************************/
int ILC_Clear(struct Para *ILC)
{
	if(F_isClearing == 1)
	{
		memset(ILC->Error, 0, ILC->SingleBufferDepth * ILC->SingleDataBufferWidth);
		memset(ILC->LastFF, 0, ILC->SingleBufferDepth * ILC->SingleDataBufferWidth);
		ILC->CurrentFF = 0;
		ILC->TrajRunNums = 0;
		//ILC->CurTrajLength = 0;
		CurTrajLength = 0;
		ILC->CurTrajCounter = 0;
		F_isClearing = 2;
	}
	return 0;
}
/*************************
  计算当前控制量
*************************/
int ILC_CurFF(struct Para *ILC)
{
	if(!F_isRunning)
	{
		ILC->CurrentFF = 0.0;
	}	
	ILC->CurrentFF =  ILC->LastFF[ILC->CurTrajCounter];	// +346 delaycycles	
	return 0;
}
/*************************
  存误差
*************************/
int ILC_SaveError(struct Para *ILC,double e)
{
	if(F_isRunning)
	{
		ILC->Error[ILC->CurTrajCounter] =  e; // 0.00001 *
		ILC->CurTrajCounter ++;
		//ILC->CurTrajLength = ILC->CurTrajCounter;
		CurTrajLength = ILC->CurTrajCounter;
		F_isSavingError = 1;		
	}
	else
	{
		ILC->CurTrajCounter = 0;
		F_isSavingError = 0;
	}
	return 0;
}
/*************************
  计算下次迭代控制量
*************************/
int ILC_NextFF(struct Para *ILC)
{
	static int i = 0;

	//if(ILC->TrajRunNums > 1) 
	//{
		for(i=1; i < CurTrajLength; i++)  
		{
			ILC->LastFF[i] +=  ILC->kp * ILC->Error[i] + ILC->kd * ( ILC->Error[i] - ILC->Error[i-1] );
		}
		ILC->LastFF[0] += ILC->kp * ILC->Error[0] + ILC->kd * ILC->Error[0];  //
		//ILC_FiltFilt(ILC, ILC->LastFF, CurTrajLength);
	//}
	ILC->TrajRunNums ++;
	F_CalcuNext = !F_CalcuNext;
	return 0;
}
/*************************
  滤波
*************************/
int ILC_FiltFilt(struct Para *ILC, volatile int *pp, int DataLength)
{
	int i = 0;
	for(i = 0; i < DataLength + 10; i++)
	{
		ILC->Tmp1[i] = 0;
		ILC->Tmp2[i] = 0;
		ILC->Tmp3[i] = 0;
		ILC->Tmp4[i] = 0;
	}
	//
	for(i = 0; i < DataLength; i++)
	{
		ILC->Tmp1[i] = *(pp + DataLength - 1 - i);
	}
	for(i = 0; i < DataLength; i++)
	{
		if(i >= 2)
		{
			ILC->Tmp2[i] = - LP_a[1] * ILC->Tmp2[i-1] - LP_a[2] * ILC->Tmp2[i-2]
						   + LP_b[0] * ILC->Tmp1[i] + LP_b[1] * ILC->Tmp1[i-1] 
						   + LP_b[2] * ILC->Tmp1[i-2];
		}
		ILC->Tmp2[0] =  LP_b[0] * ILC->Tmp1[0]; 
		ILC->Tmp2[1] =  - LP_a[1] * ILC->Tmp2[0] + LP_b[0] * ILC->Tmp1[1] + LP_b[1] * ILC->Tmp1[0];
	}
	//
	for(i = 0; i < DataLength; i++)
	{
		ILC->Tmp3[i] = ILC->Tmp2[DataLength - 1 - i];
	}
	for(i = 0; i < DataLength; i++)
	{
		if(i >= 2)
		{
			ILC->Tmp4[i] = - LP_a[1] * ILC->Tmp4[i-1] - LP_a[2] * ILC->Tmp4[i-2]
						   + LP_b[0] * ILC->Tmp3[i] + LP_b[1] * ILC->Tmp3[i-1] 
						   + LP_b[2] * ILC->Tmp3[i-2];
		}
		ILC->Tmp4[0] =  LP_b[0] * ILC->Tmp3[0]; 
		ILC->Tmp4[1] =  - LP_a[1] * ILC->Tmp4[0] + LP_b[0] * ILC->Tmp3[1] + LP_b[1] * ILC->Tmp3[0];
	}
	//
	for(i = 0; i < DataLength; i++)
	{
		*(pp+i) = ILC->Tmp4[i];
	}
	return 0;
}
/*************************
  迭代学习控制器
*************************/
double mainILC(struct MotorData *Mptr)
{
    double u, Integrator;
	static double e_1 = 0;
    static int maini = 0, flag = 1;
    static double initpos = 0.0, termpos = 0.0;
	double t;
	struct Para *ILC;

	if(Mptr->ClosedLoop) 
	{	
		if(F_Init) 
		{
			ILC_Init( ILC );
			F_Init = 0;
		}	
		
		if(flag) 
		{
			initpos=Mptr->ActPos;
			flag=0;
		}		
		maini++;
		t = maini * myServoPeriod;
		if(t<T) 
		{
			F_isRunning = 1;
			Mptr->DesPos = initpos + a3*t*t*t + a4*t*t*t*t + a5*t*t*t*t*t;
			termpos = Mptr->DesPos;
		}
		else if(t<3*T/2) //2000*T/pshm->ServoPeriod
		{
			F_isRunning = 1;
			Mptr->DesPos = termpos;
		}
		else
		{			
			F_isRunning = 0;
			Mptr->DesPos = initpos; 
			if(maini == 5200)
			{
				maini = 0;
			}
		}
		mye = Mptr->DesPos - Mptr->ActPos;
					
		ILC_CurFF( ILC );	
		ILC_SaveError(ILC, mye);	
		if(F_isRunning)		
		{
			ILC->CurrentFF += kp * mye - kd * Mptr->ActVel;
			Integrator += ki * mye;
			ILC->CurrentFF += Integrator;
			u = ILC->CurrentFF;
		}
		else
		{
			u = kp * mye - kd * Mptr->ActVel;
			Integrator += ki * mye;
			u += Integrator;
		}

		

		if(maini == 700) 
		{
			ILC_NextFF( ILC );
		}
		if(u>1000) 
		{
			u = 1000;
		}
		if(u<-1000) 
		{
			u = -1000;
		}				
		return(u);
						
	}
	else
	{
		return(0);
	}
}


