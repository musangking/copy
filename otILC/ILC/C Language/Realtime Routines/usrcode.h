#ifdef __KERNEL__
#include <linux/module.h>
#else
#define EXPORT_SYMBOL(x) // x
#define KERN_ALERT
#define printk printf
#include <gplib.h>
#endif
#include <RtGpShm.h>	// Global Rt/Gp Externals and structures
#include <rtpmacapi.h>

int rtsprintf(char * buf, const char *fmt, ...);

double user_pid_ctrl( struct MotorData *Mptr);
EXPORT_SYMBOL(user_pid_ctrl);

void user_phase( struct MotorData *Mptr);
EXPORT_SYMBOL(user_phase);

void CaptCompISR(void);
EXPORT_SYMBOL(CaptCompISR);

double CfromScript(double arg1,double arg2,double arg3,double arg4,double arg5,double arg6,double arg7,struct LocalData *Ldata);
EXPORT_SYMBOL(CfromScript);

//----------------------------------------
// Required Kinematic define Names
//----------------------------------------
#define KinPosMotor  L
#define KinVelMotor  R
#define KinEnaAxisA 0x1
#define KinPosAxisA C[0]
#define KinVelAxisA C[32]
#define KinEnaAxisB 0x2
#define KinPosAxisB C[1]
#define KinVelAxisB C[33]
#define KinEnaAxisC 0x4
#define KinPosAxisC C[2]
#define KinVelAxisC C[34]
#define KinEnaAxisU 0x8
#define KinPosAxisU C[3]
#define KinVelAxisU C[35]
#define KinEnaAxisV 0x10
#define KinPosAxisV C[4]
#define KinVelAxisV C[36]
#define KinEnaAxisW 0x20
#define KinPosAxisW C[5]
#define KinVelAxisW C[37]
#define KinEnaAxisX 0x40
#define KinPosAxisX C[6]
#define KinVelAxisX C[38]
#define KinEnaAxisY 0x80
#define KinPosAxisY C[7]
#define KinVelAxisY C[39]
#define KinEnaAxisZ 0x100
#define KinPosAxisZ C[8]
#define KinVelAxisZ C[40]
#define KinEnaAxisAA 0x200
#define KinPosAxisAA C[9]
#define KinVelAxisAA C[41]
#define KinEnaAxisBB 0x400
#define KinPosAxisBB C[10]
#define KinVelAxisBB C[42]
#define KinEnaAxisCC 0x800
#define KinPosAxisCC C[11]
#define KinVelAxisCC C[43]
#define KinEnaAxisDD 0x1000
#define KinPosAxisDD C[12]
#define KinVelAxisDD C[44]
#define KinEnaAxisEE 0x2000
#define KinPosAxisEE C[13]
#define KinVelAxisEE C[45]
#define KinEnaAxisFF 0x4000
#define KinPosAxisFF C[14]
#define KinVelAxisFF C[46]
#define KinEnaAxisGG 0x8000
#define KinPosAxisGG C[15]
#define KinVelAxisGG C[47]
#define KinEnaAxisHH 0x10000
#define KinPosAxisHH C[16]
#define KinVelAxisHH C[48]
#define KinEnaAxisLL 0x20000
#define KinPosAxisLL C[17]
#define KinVelAxisLL C[49]
#define KinEnaAxisMM 0x40000
#define KinPosAxisMM C[18]
#define KinVelAxisMM C[50]
#define KinEnaAxisNN 0x80000
#define KinPosAxisNN C[19]
#define KinVelAxisNN C[51]
#define KinEnaAxisOO 0x100000
#define KinPosAxisOO C[20]
#define KinVelAxisOO C[52]
#define KinEnaAxisPP 0x200000
#define KinPosAxisPP C[21]
#define KinVelAxisPP C[53]
#define KinEnaAxisQQ 0x400000
#define KinPosAxisQQ C[22]
#define KinVelAxisQQ C[54]
#define KinEnaAxisRR 0x800000
#define KinPosAxisRR C[23]
#define KinVelAxisRR C[55]
#define KinEnaAxisSS 0x1000000
#define KinPosAxisSS C[24]
#define KinVelAxisSS C[56]
#define KinEnaAxisTT 0x2000000
#define KinPosAxisTT C[25]
#define KinVelAxisTT C[57]
#define KinEnaAxisUU 0x4000000
#define KinPosAxisUU C[26]
#define KinVelAxisUU C[58]
#define KinEnaAxisVV 0x8000000
#define KinPosAxisVV C[27]
#define KinVelAxisVV C[59]
#define KinEnaAxisWW 0x10000000
#define KinPosAxisWW C[28]
#define KinVelAxisWW C[60]
#define KinEnaAxisXX 0x20000000
#define KinPosAxisXX C[29]
#define KinVelAxisXX C[61]
#define KinEnaAxisYY 0x40000000
#define KinPosAxisYY C[30]
#define KinVelAxisYY C[62]
#define KinEnaAxisZZ 0x80000000
#define KinPosAxisZZ C[31]
#define KinVelAxisZZ C[63]
#define KinAxisUsed  D[0]
#define KinVelEna    D[0]
//----------------------------------------
float Step = 112500, T = 0.200;  //步长cts//和步进时间s
#define     a3       10*Step/(T*T*T)
#define     a4       -15*Step/(T*T*T*T)
#define     a5       6*Step/(T*T*T*T*T)    //五次曲线轨迹规划用
double dp[82] = {1.44577E-08, 1.15662E-07, 3.90359E-07, 9.25295E-07, 1.80722E-06, 3.12287E-06, 4.959E-06,
			    7.40236E-06, 1.05397E-05, 1.44577E-05, 1.92432E-05, 2.68567E-05, 3.38598E-05, 4.18427E-05,	
			    5.08054E-05, 6.07479E-05, 7.16703E-05, 8.35724E-05, 9.64543E-05, 0.000110316, 0.000125158,	
			    0.000140979, 0.000162909, 0.000180878, 0.000199653, 0.000219148, 0.000239275, 0.000259948,
			    0.000281081, 0.000302587, 0.000324378, 0.000346368, 0.000368471, 0.000397134, 0.000419267,	
			    0.000441401, 0.000463535, 0.000485668, 0.000507802, 0.000529936, 0.000552069, 0.000574203,	
			    0.000596337, 0.000618471, 0.000640604, 0.000662738, 0.000684872, 0.000707005, 0.000729139,	
			    0.000772119, 0.000794152, 0.000816011, 0.000837609, 0.000858861, 0.000879679, 0.000899977,	
			    0.000919667, 0.000938664, 0.000956879, 0.000974227, 0.000995277, 0.001010408, 0.001024558,	
			    0.001037729, 0.00104992, 0.001061132, 0.001071363, 0.001080615, 0.001088887, 0.001096179,	
			    0.001102492, 0.001109225, 0.00111339, 0.001116748, 0.001119387, 0.001121393, 0.001122854,	
			    0.001123855, 0.001124483, 0.001124825, 0.001124969, 0.001125}; //m 要转换成cts

struct Para
{	
	int TrajRunNums;
	//int CurTrajLength;
	int CurTrajCounter; //当前轨迹位置

	int CurrentFF; //当前前馈控制量，在每个伺服周期直接输出给servoout
	float kp;
	float ki;
	float kd;

	unsigned int SingleDataBufferWidth;
	unsigned int SingleIntBufferWidth;
	unsigned int SingleBufferDepth; //一次迭代需要存储的数据长度

	volatile double *Error; //存储一次迭代中每个伺服周期的跟踪误差
	volatile double *LastFF;   //存储一次迭代中每个伺服周期的前馈控制
	volatile int *Tmp1;
	volatile int *Tmp2;
	volatile int *Tmp3;
	volatile int *Tmp4;
	
}ILC;

float LP_a[3] = {1, -1.9041, 0.9085};
float LP_b[3] = {0.0011, 0.0022, 0.0011};  //滤波器
//float LP_a[3] = {1, 0.1357, 0.1748};
//float LP_b[3] = {0.3276, 0.6553, 0.3276};  //滤波器

float kp=3, ki=0.1, kd=10;                 //闭环PID参数

extern int ILC_Init(struct Para *ILC);
extern int ILC_CurFF(struct Para *ILC);
extern int ILC_SaveError(struct Para *ILC,double e);
extern int ILC_NextFF(struct Para *ILC);
extern int ILC_Clear(struct Para *ILC);
extern int ILC_FiltFilt(struct Para *ILC, volatile *pp, int DataLength);

double mainILC(struct MotorData *Mptr);
EXPORT_SYMBOL(mainILC);


