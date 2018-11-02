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

int ILC_Init(struct ILCSave *ILCData)
{
	
	memset(pushm + 1,0,ITERPERIOD * 80);
	int i;
	for (i = 0;i < ITERPERIOD; i++)
	{	
		*((double*)pushm + 101 + i) = 0;
		ILCData->U[i] = *((double*)pushm + 101 + i);
	}
	*((double*)pushm + 5) = 1;
	ILCData->IterCount = *((double*)pushm + 5); 
	ILCInit = 1;	
	ILCCurPos = 1;
	return 1;
}

//int ILC_Assignment(struct ILCSave *ILCData)
//{
//	int i;
//	for (i = 0;i < ILCData->IterPeriod; i++)
//	{	
//		ILCData->U[i] = (double*)pushm + 101 + i;
//	}
//	ILCData->PreError = 0;
//	ILCData->IterCount = 1; 
//	return 1;
//}

int ILC_Save_Iter_Data(struct ILCSave *ILCData , double CurError)
{
	int count = *((double*)pushm + 5);
	*((double*)pushm + 200 + ITERPERIOD + count % ITERPERIOD) = CurError;
	*((double*)pushm + 5) = *((double*)pushm + 5) + 1;
	return 1;
}

double Derivative(double e1, double e2)
{
	return (e2 - e1);
}

double Integrate(double e1, double e2)
{
	return (e1 + e2);
}

double ILC_Iteration(struct ILCSave *ILCData)//PID
{
	int i,j;
	double Uk1;
	double inte;
	for (i = 0; i < ITERPERIOD; i++)
	{	
		ILCData->U[i] = *((double*)pushm + 101 + i);
		ILCData->PreError[i] = *((double*)pushm + 201 + ITERPERIOD + i);
	}

	*((double*)pushm + 101) = KP * ILCData->PreError[0];
	for (i = 1; i < ITERPERIOD-1; i++)
	{ 
		inte = 0;
		for (j = 0;j <= i;j++)
		{
			inte = inte + ILCData->PreError[j];
		}
		Uk1 = ILCData->U[i] + KP * ILCData->PreError[i] + KD *(ILCData->PreError[i] - ILCData->PreError[i-1]) ;
		//; + ILCData->PreError[i]+ + KI * inte
		*((double*)pushm + 101 + i) = Uk1;
	}
//	*((double*)pushm + 100 + ITERPERIOD) = KP * ILCData->PreError[ITERPERIOD-1];
	*((double*)pushm + 5) = 1;	
	ILCCurPos = 0;
	return (0);
}

//double PIDController(struct ILCSave *ILCData , int CurCount)
//{
//	double Uc;
//	double e;
//	double e_1;
//	double Integrate = 0;
//	int i;
//	for (i = 1;i <= CurCount; i++)
//	{
//		Integrate = Integrate + *((double*)pushm + 200 + ITERPERIOD + i) ;
//	}
//	e = *((double*)pushm + 200 + ITERPERIOD + CurCount);
//	if (CurCount == 1)
//		e_1 = 0;
//	else
//		e_1 = *((double*)pushm + 200 + ITERPERIOD + CurCount - 1);
//	Uc = KP1 * e + KD1 * (e - e_1) + KI1 * Integrate;
////	*((double*)pushm + 300 + 2 * ITERPERIOD + CurCount) = Uc;
//	return Uc;
//}

double PIDControl(struct MotorData *Mptr)
{
	double ctrl_out;
	double Error;
	if (ILCCurPos == 1)
	{
		return 0;
	}
	Error = Mptr->DesPos - Mptr->ActPos;
	ctrl_out = KP1 * Error - KD1 * Mptr->ActVel;
	Mptr->Servo.Integrator += Error * KI1;
	//*((double*)pushm + 300 + 2 * ITERPERIOD + CurCount) = ctrl_out;
	return ctrl_out;
}

double ILC_Main(struct MotorData *Mptr)
{
	double Output;
    double Uk1;
	double Uc;
	int CurCount;
	double Error;
	Error = Mptr->DesPos - Mptr->ActPos;

	if (Mptr->ClosedLoop)
	{
		if(!ILCInit)//first iterative period
		{
			if(!ILC_Init(&ILCData))
			{
				//print error
				return 0;
			}
		}
		 
		if (ILCCurPos == 1)
		{
			*((double*)pushm + 9) = 1;
			Mptr->DesPos = DESPOSITION;
			ILCData.IterCount = *((double*)pushm + 5);
			
			if(ILCData.IterCount != ITERPERIOD) //迭代周期内，记录u、e 
			{
				*((double*)pushm + 10) = 1;
				ILC_Save_Iter_Data(&ILCData , Error);
//				Uc = PIDController(&ILCData , ILCData.IterCount);
				Uc = PIDControl(Mptr);
			}
			else
			{
				*((double*)pushm + 10) = 0;
				ILC_Save_Iter_Data(&ILCData , Error);
//				Uc = PIDController(&ILCData , ILCData.IterCount);
				Uc = PIDControl(Mptr);
				ILC_Iteration(&ILCData);

			} 
			CurCount = *((double*)pushm + 5);
			Uk1 = *((double*)pushm + 100 + CurCount);
		}
		else
		{
			*((double*)pushm + 9) = 0;
			Mptr->DesPos = 0;
			ILCData.IterCount = *((double*)pushm + 5);
			ILC_Save_Iter_Data(&ILCData , Error);
//			Uc = PIDController(&ILCData , ILCData.IterCount);
			Uc = PIDControl(Mptr);
			if(ILCData.IterCount == ITERPERIOD)
			{
				ILCCurPos = 1;
				*((double*)pushm + 5) = 1;
			}
			Uk1 = 0;
		}
		
		Output = Uk1 + Uc;
		if (Output > 800)
			Output = 800;
		else if (Output < -800)
			Output = -800;
		return Output;
	}
	
	
	else{
		return 0.0;
	}
}


