#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#ifdef DLL_EXPORT
    #define DLLTYPE __declspec(dllexport)
#else
    #define DLLTYPE __declspec(dllimport)
#endif //DLL_EXPORT

#if _MSC_VER > 1000
#pragma once

#endif // _MSC_VER > 1000
//#include "lib/include/pcomm.h"

#define MAX_QUEUE	4096
#define TIMEOUT	1000

/* error code */
#define FPMC_OK	0
#define FPMC_TIMEOUT	-1
#define FPMC_INVALID_PORT	1
#define FPMC_INVALID_BAUDRATE	2
#define FPMC_INVALID_NODE	3
#define FPMC_INVALID_AXIS	4
#define FPMC_INVALID_DATA	5

/* baudrate setting */
#define FPMC_BAUD_9600	9600
#define FPMC_BAUD_19200	19200
#define FPMC_BAUD_38400	38400
#define FPMC_BAUD_57600	57600
#define FPMC_BAUD_115200	115200

/* Node ID setting*/
#define Node01 0x01
#define Node02 0x02
#define Node03 0x03
#define Node04 0x04
#define Node05 0x05
#define Node06 0x06
#define Node07 0x07
#define Node08 0x08
#define Node09 0x09
#define Node10 0x0A
#define Node11 0x0B
#define Node12 0x0C
#define Node13 0x0D
#define Node14 0x0E
#define Node15 0x0F
#define Node16 0x10
#define Broadcast 0x80

/* Axis setting */
#define FPMC_X_AXIS	0
#define FPMC_Y_AXIS	1
#define FPMC_X_Y_AXIS 2

/* Parameters */
#define FPMC_INSTANT	0
#define FPMC_SLOW	1

#define FPMC_INSTANTSTOP	0
#define FPMC_SLOWSTOP	1

#define FPMC_HSTOP0	0
#define FPMC_HSTOP1	1
#define FPMC_HSTOP2	2

#define FPMC_INPORT0	0
#define FPMC_INPORT1	1

#define FPMC_OUTPORT0	0
#define FPMC_OUTPORT1	1

#define FPMC_LOW	0
#define FPMC_HIGH	1

#define FPMC_DISABLE	0
#define FPMC_ENABLE		1

#define FPMC_SOFLMT_MINUS	0
#define FPMC_SOFLMT_PLUS	1

#define FPMC_OFF 0
#define	FPMC_ON	1

#define FPMC_SETPULSE1 1
#define FPMC_SETPULSE2 2

extern "C" DLLTYPE int autpmc_Open(int PortNum, int BaudRate);
extern "C" DLLTYPE int autpmc_SetBaudrate(int PortNum, char nNodeId, int BaudRate);
extern "C" DLLTYPE int autpmc_Close(int PortNum);

extern "C" DLLTYPE int autpmc_ClrINCPos(int PortNum, char nNodeId, char axis);
extern "C" DLLTYPE int autpmc_ClrINCPos_X(int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_ClrINCPos_Y(int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_ClrINCPos_X_Y(int PortNum, char nNodeId);

extern "C" DLLTYPE int autpmc_ClrABSPos(int PortNum, char nNodeId, char axis);
extern "C" DLLTYPE int autpmc_ClrABSPos_X(int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_ClrABSPos_Y(int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_ClrABSPos_X_Y(int PortNum, char nNodeId);

extern "C" DLLTYPE int autpmc_SetDrvSpd(int PortNum, char nNodeId, char axis, int nDrvIndex);
extern "C" DLLTYPE int autpmc_SetDrvSpd_X(int PortNum, char nNodeId, int nDrvIndex);
extern "C" DLLTYPE int autpmc_SetDrvSpd_Y(int PortNum, char nNodeId, int nDrvIndex);

extern "C" DLLTYPE int autpmc_SetCurDrvSpd(int PortNum, char nNodeId, char axis, int iDrvSpd_X, int iDrvSpd_Y);
extern "C" DLLTYPE int autpmc_SetCurDrvSpd_X(int PortNum, char nNodeId, int iDrvSpd_X);
extern "C" DLLTYPE int autpmc_SetCurDrvSpd_Y(int PortNum, char nNodeId, int iDrvSpd_Y);
extern "C" DLLTYPE int autpmc_SetCurDrvSpd_X_Y(int PortNum, char nNodeId, int iDrvSpd_X, int iDrvSpd_Y);

extern "C" DLLTYPE int autpmc_SetStrSpd(int PortNum, char nNodeId, char axis, int iStrSpd);
extern "C" DLLTYPE int autpmc_SetStrSpd_X(int PortNum, char nNodeId, int iStrSpd);
extern "C" DLLTYPE int autpmc_SetStrSpd_Y(int PortNum, char nNodeId, int iStrSpd);

extern "C" DLLTYPE int autpmc_GetStrSpd(int PortNum, char nNodeId, char axis, int *iStrSpd);
extern "C" DLLTYPE int autpmc_GetStrSpd_X(int PortNum, char nNodeId, int *iStrSpd);
extern "C" DLLTYPE int autpmc_GetStrSpd_Y(int PortNum, char nNodeId, int *iStrSpd);

extern "C" DLLTYPE int autpmc_HomRun (int PortNum, char nNodeId, char axis);
extern "C" DLLTYPE int autpmc_HomRun_X (int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_HomRun_Y (int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_HomRun_X_Y(int PortNum, char nNodeId);

extern "C" DLLTYPE int autpmc_HomStop (int PortNum, char nNodeId, char axis);
extern "C" DLLTYPE int autpmc_HomStop_X (int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_HomStop_Y (int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_HomStop_X_Y (int PortNum, char nNodeId);

extern "C" DLLTYPE int autpmc_ABSMove(int PortNum, char nNodeId, char axis, long lPos_X, long lPos_Y);
extern "C" DLLTYPE int autpmc_ABSMove_X(int PortNum, char nNodeId, long lPos_X);
extern "C" DLLTYPE int autpmc_ABSMove_Y(int PortNum, char nNodeId, long lPos_Y);
extern "C" DLLTYPE int autpmc_ABSMove_X_Y(int PortNum, char nNodeId, long lPos_X, long lPos_Y);

extern "C" DLLTYPE int autpmc_INCMove(int PortNum, char nNodeId, char axis, long lPos_X, long lPos_Y);
extern "C" DLLTYPE int autpmc_INCMove_X (int PortNum, char nNodeId, long lPos_X);
extern "C" DLLTYPE int autpmc_INCMove_Y (int PortNum, char nNodeId, long lPos_Y);
extern "C" DLLTYPE int autpmc_INCMove_X_Y(int PortNum, char nNodeId, long lPos_X, long lPos_Y);

extern "C" DLLTYPE int autpmc_LIDMove (int PortNum, char nNodeId, BOOL bFLS, long lXEndPos, long lYEndPos);
extern "C" DLLTYPE int autpmc_LIDMove_ON (int PortNum, char nNodeId, long lXEndPos, long lYEndPos);
extern "C" DLLTYPE int autpmc_LIDMove_OFF (int PortNum, char nNodeId, long lXEndPos, long lYEndPos);

extern "C" DLLTYPE int autpmc_CIDMove (int PortNum, char nNodeId, BOOL bFLS, long lRadius, long lMDP);
extern "C" DLLTYPE int autpmc_CIDMove_ON (int PortNum, char nNodeId, long lRadius, long lMDP);
extern "C" DLLTYPE int autpmc_CIDMove_OFF (int PortNum, char nNodeId, long lRadius, long lMDP);

extern "C" DLLTYPE int autpmc_FIDMove (int PortNum, char nNodeId, BOOL bFLS, long lXCenPos, long lYCenPos, long lXEndPos, long lYEndPos, long lMDP);
extern "C" DLLTYPE int autpmc_FIDMove_ON (int PortNum, char nNodeId, long lXCenPos, long lYCenPos, long lXEndPos, long lYEndPos, long lMDP);
extern "C" DLLTYPE int autpmc_FIDMove_OFF (int PortNum, char nNodeId, long lXCenPos, long lYCenPos, long lXEndPos, long lYEndPos, long lMDP);

extern "C" DLLTYPE int autpmc_RIDMove (int PortNum, char nNodeId, BOOL bFLS, long lXCenPos, long lYCenPos, long lXEndPos, long lYEndPos, long lMDP);
extern "C" DLLTYPE int autpmc_RIDMove_ON (int PortNum, char nNodeId, long lXCenPos, long lYCenPos, long lXEndPos, long lYEndPos, long lMDP);
extern "C" DLLTYPE int autpmc_RIDMove_OFF (int PortNum, char nNodeId, long lXCenPos, long lYCenPos, long lXEndPos, long lYEndPos, long lMDP);

extern "C" DLLTYPE int autpmc_SlowStop(int PortNum, char nNodeId, char axis);
extern "C" DLLTYPE int autpmc_SlowStop_X(int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_SlowStop_Y(int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_SlowStop_X_Y(int PortNum, char nNodeId);

extern "C" DLLTYPE int autpmc_EmgStop(int PortNum, char nNodeId);

extern "C" DLLTYPE int autpmc_SetSpdMul (int PortNum, char nNodeId, char axis, int iSpdMul);
extern "C" DLLTYPE int autpmc_SetSpdMul_X(int PortNum, char nNodeId, int iSpdMul);
extern "C" DLLTYPE int autpmc_SetSpdMul_Y(int PortNum, char nNodeId, int iSpdMul);

extern "C" DLLTYPE int autpmc_GetSpdMul (int PortNum, char nNodeId, char axis, int *iSpdMul);
extern "C" DLLTYPE int autpmc_GetSpdMul_X(int PortNum, char nNodeId, int *iSpdMul);
extern "C" DLLTYPE int autpmc_GetSpdMul_Y(int PortNum, char nNodeId, int *iSpdMul);

extern "C" DLLTYPE int autpmc_SetJrkSpd (int PortNum, char nNodeId, char axis, int iJrkSpd);
extern "C" DLLTYPE int autpmc_SetJrkSpd_X (int PortNum, char nNodeId, int iJrkSpd);
extern "C" DLLTYPE int autpmc_SetJrkSpd_Y (int PortNum, char nNodeId, int iJrkSpd);

extern "C" DLLTYPE int autpmc_GetJrkSpd (int PortNum, char nNodeId, char axis, int *iJrkSpd);
extern "C" DLLTYPE int autpmc_GetJrkSpd_X (int PortNum, char nNodeId, int *iJrkSpd);
extern "C" DLLTYPE int autpmc_GetJrkSpd_Y (int PortNum, char nNodeId, int *iJrkSpd);

extern "C" DLLTYPE int autpmc_SetAccSpdRate (int PortNum, char nNodeId, char axis, int iAccSpdRate);
extern "C" DLLTYPE int autpmc_SetAccSpdRate_X (int PortNum, char nNodeId, int iAccSpdRate);
extern "C" DLLTYPE int autpmc_SetAccSpdRate_Y (int PortNum, char nNodeId, int iAccSpdRate);

extern "C" DLLTYPE int autpmc_GetAccSpdRate (int PortNum, char nNodeId, char axis, int *iAccSpdRate);
extern "C" DLLTYPE int autpmc_GetAccSpdRate_X (int PortNum, char nNodeId, int *iAccSpdRate);
extern "C" DLLTYPE int autpmc_GetAccSpdRate_Y (int PortNum, char nNodeId, int *iAccSpdRate);

extern "C" DLLTYPE int autpmc_SetDecSpdRate (int PortNum, char nNodeId, char axis, int iDecSpdRate);
extern "C" DLLTYPE int autpmc_SetDecSpdRate_X (int PortNum, char nNodeId, int iDecSpdRate);
extern "C" DLLTYPE int autpmc_SetDecSpdRate_Y (int PortNum, char nNodeId, int iDecSpdRate);

extern "C" DLLTYPE int autpmc_GetDecSpdRate (int PortNum, char nNodeId, char axis, int *iDecSpdRate);
extern "C" DLLTYPE int autpmc_GetDecSpdRate_X (int PortNum, char nNodeId, int *iDecSpdRate);
extern "C" DLLTYPE int autpmc_GetDecSpdRate_Y (int PortNum, char nNodeId, int *iDecSpdRate);

extern "C" DLLTYPE int autpmc_GetCurDrvSpd(int PortNum, char nNodeId, char axis, int *iDrvSpd_X, int *iDrvSpd_Y); 
extern "C" DLLTYPE int autpmc_GetCurDrvSpd_X(int PortNum, char nNodeId, int *iDrvSpd_X);
extern "C" DLLTYPE int autpmc_GetCurDrvSpd_Y(int PortNum, char nNodeId, int *iDrvSpd_Y);
extern "C" DLLTYPE int autpmc_GetCurDrvSpd_X_Y(int PortNum, char nNodeId, int *iDrvSpd_X, int *iDrvSpd_Y);

extern "C" DLLTYPE int autpmc_SetDrvSpdPgm (int PortNum, char nNodeId, char axis, int nDrvIndex, int iDrvSpd);
extern "C" DLLTYPE int autpmc_SetDrvSpdPgm_X (int PortNum, char nNodeId, int nDrvIndex, int iDrvSpd);
extern "C" DLLTYPE int autpmc_SetDrvSpdPgm_Y (int PortNum, char nNodeId, int nDrvIndex, int iDrvSpd);

extern "C" DLLTYPE int autpmc_GetDrvSpdPgm (int PortNum, char nNodeId, char axis, int nDrvIndex, int *iDrvSpd); 
extern "C" DLLTYPE int autpmc_GetDrvSpdPgm_X(int PortNum, char nNodeId, int nDrvIndex, int *iDrvSpd);
extern "C" DLLTYPE int autpmc_GetDrvSpdPgm_Y(int PortNum, char nNodeId, int nDrvIndex, int *iDrvSpd);

extern "C" DLLTYPE int autpmc_SetSofLmt (int PortNum, char nNodeId, char axis, int iDirection, long lSoftLmt);
extern "C" DLLTYPE int autpmc_SetSofLmt_X (int PortNum, char nNodeId, int iDirection, long lSoftLmt);
extern "C" DLLTYPE int autpmc_SetSofLmt_Y (int PortNum, char nNodeId, int iDirection, long lSoftLmt);

extern "C" DLLTYPE int autpmc_GetSofLmt (int PortNum, char nNodeId, char axis, int iDirection, long *lSoftLmt);
extern "C" DLLTYPE int autpmc_GetSofLmt_X (int PortNum, char nNodeId, int iDirection, long *lSoftLmt);
extern "C" DLLTYPE int autpmc_GetSofLmt_Y (int PortNum, char nNodeId, int iDirection, long *lSoftLmt);

extern "C" DLLTYPE int autpmc_SetEndPWidth (int PortNum, char nNodeId, char axis, int iEndPWidth);
extern "C" DLLTYPE int autpmc_SetEndPWidth_X (int PortNum, char nNodeId, int iEndPWidth);
extern "C" DLLTYPE int autpmc_SetEndPWidth_Y (int PortNum, char nNodeId, int iEndPWidth);

extern "C" DLLTYPE int autpmc_GetEndPWidth (int PortNum, char nNodeId, char axis, int *iEndPWidth);
extern "C" DLLTYPE int autpmc_GetEndPWidth_X (int PortNum, char nNodeId, int *iEndPWidth);
extern "C" DLLTYPE int autpmc_GetEndPWidth_Y (int PortNum, char nNodeId, int *iEndPWidth);

extern "C" DLLTYPE int autpmc_SetPulSclNum (int PortNum, char nNodeId, char axis, int iPulScl);
extern "C" DLLTYPE int autpmc_SetPulSclNum_X (int PortNum, char nNodeId, int iPulScl);
extern "C" DLLTYPE int autpmc_SetPulSclNum_Y (int PortNum, char nNodeId, int iPulScl);

extern "C" DLLTYPE int autpmc_GetPulSclNum (int PortNum, char nNodeId, char axis, int *iPulScl);
extern "C" DLLTYPE int autpmc_GetPulSclNum_X (int PortNum, char nNodeId, int *iPulScl);
extern "C" DLLTYPE int autpmc_GetPulSclNum_Y (int PortNum, char nNodeId, int *iPulScl);

extern "C" DLLTYPE int autpmc_SetPulSclDen (int PortNum, char nNodeId, char axis, int iPulScl);
extern "C" DLLTYPE int autpmc_SetPulSclDen_X (int PortNum, char nNodeId, int iPulScl);
extern "C" DLLTYPE int autpmc_SetPulSclDen_Y (int PortNum, char nNodeId, int iPulScl);

extern "C" DLLTYPE int autpmc_GetPulSclDen (int PortNum, char nNodeId, char axis, int *iPulScl);
extern "C" DLLTYPE int autpmc_GetPulSclDen_X (int PortNum, char nNodeId, int *iPulScl);
extern "C" DLLTYPE int autpmc_GetPulSclDen_Y (int PortNum, char nNodeId, int *iPulScl);

extern "C" DLLTYPE int autpmc_SetHomSpd (int PortNum, char nNodeId, char axis, BOOL bSpd, int iSpd);
extern "C" DLLTYPE int autpmc_SetHomSpd_X (int PortNum, char nNodeId, BOOL bSpd, int iSpd);
extern "C" DLLTYPE int autpmc_SetHomSpd_Y (int PortNum, char nNodeId, BOOL bSpd, int iSpd);

extern "C" DLLTYPE int autpmc_GetHomSpd (int PortNum, char nNodeId, char axis, BOOL bSpd, int *iSpd);
extern "C" DLLTYPE int autpmc_GetHomSpd_X (int PortNum, char nNodeId, BOOL bSpd, int *iSpd);
extern "C" DLLTYPE int autpmc_GetHomSpd_Y (int PortNum, char nNodeId, BOOL bSpd, int *iSpd);

extern "C" DLLTYPE int autpmc_SetHomOffset(int PortNum, char nNodeId, char axis, long lOffset);
extern "C" DLLTYPE int autpmc_SetHomOffset_X(int PortNum, char nNodeId, long lOffset);
extern "C" DLLTYPE int autpmc_SetHomOffset_Y(int PortNum, char nNodeId, long lOffset);

extern "C" DLLTYPE int autpmc_GetHomOffset(int PortNum, char nNodeId, char axis, long *lOffset);
extern "C" DLLTYPE int autpmc_GetHomOffset_X(int PortNum, char nNodeId, long *lOffset);
extern "C" DLLTYPE int autpmc_GetHomOffset_Y(int PortNum, char nNodeId, long *lOffset);

extern "C" DLLTYPE int autpmc_SetTimPgm (int PortNum, char nNodeId, char axis, int nIndex, int iPostTim);
extern "C" DLLTYPE int autpmc_SetTimPgm_X (int PortNum, char nNodeId, int nIndex, int iPostTim);
extern "C" DLLTYPE int autpmc_SetTimPgm_Y (int PortNum, char nNodeId, int nIndex, int iPostTim);

extern "C" DLLTYPE int autpmc_GetTimPgm (int PortNum, char nNodeId, char axis, int nIndex, int *iPostTim);
extern "C" DLLTYPE int autpmc_GetTimPgm_X (int PortNum, char nNodeId, int nIndex, int *iPostTim);
extern "C" DLLTYPE int autpmc_GetTimPgm_Y (int PortNum, char nNodeId, int nIndex, int *iPostTim);

extern "C" DLLTYPE int autpmc_SetLmtStopMod(int PortNum, char nNodeId, char axis, BOOL bInstant);
extern "C" DLLTYPE int autpmc_SetLmtStopMod_X(int PortNum, char nNodeId, BOOL bInstant);
extern "C" DLLTYPE int autpmc_SetLmtStopMod_Y(int PortNum, char nNodeId, BOOL bInstant);

extern "C" DLLTYPE int autpmc_GetLmtStopMod(int PortNum, char nNodeId, char axis, BOOL *bStopType);
extern "C" DLLTYPE int autpmc_GetLmtStopMod_X(int PortNum, char nNodeId, BOOL *bStopType);
extern "C" DLLTYPE int autpmc_GetLmtStopMod_Y(int PortNum, char nNodeId, BOOL *bStopType);

extern "C" DLLTYPE int autpmc_SetLmtActLev (int PortNum, char nNodeId, char axis, BOOL bLmtActLev);
extern "C" DLLTYPE int autpmc_SetLmtActLev_X (int PortNum, char nNodeId, BOOL bLmtActLev);
extern "C" DLLTYPE int autpmc_SetLmtActLev_Y (int PortNum, char nNodeId, BOOL bLmtActLev);

extern "C" DLLTYPE int autpmc_GetLmtActLev(int PortNum, char nNodeId, char axis, BOOL *bLevel);
extern "C" DLLTYPE int autpmc_GetLmtActLev_X(int PortNum, char nNodeId, BOOL *bLevel);
extern "C" DLLTYPE int autpmc_GetLmtActLev_Y(int PortNum, char nNodeId, BOOL *bLevel);

extern "C" DLLTYPE int autpmc_SetSCurve (int PortNum, char nNodeId, char axis, BOOL bEnable);
extern "C" DLLTYPE int autpmc_SetSCurve_X (int PortNum, char nNodeId, BOOL bEnable);
extern "C" DLLTYPE int autpmc_SetSCurve_Y (int PortNum, char nNodeId, BOOL bEnable);

extern "C" DLLTYPE int autpmc_GetSCurve (int PortNum, char nNodeId, char axis, BOOL *bEnable);
extern "C" DLLTYPE int autpmc_GetSCurve_X (int PortNum, char nNodeId, BOOL *bEnable);
extern "C" DLLTYPE int autpmc_GetSCurve_Y (int PortNum, char nNodeId, BOOL *bEnable);

extern "C" DLLTYPE int autpmc_SetEndPEnable (int PortNum, char nNodeId, char axis, BOOL bEnable);
extern "C" DLLTYPE int autpmc_SetEndPEnable_X (int PortNum, char nNodeId, BOOL bEnable);
extern "C" DLLTYPE int autpmc_SetEndPEnable_Y (int PortNum, char nNodeId, BOOL bEnable);

extern "C" DLLTYPE int autpmc_GetEndPEnable (int PortNum, char nNodeId, char axis, BOOL *bEnable);
extern "C" DLLTYPE int autpmc_GetEndPEnable_X (int PortNum, char nNodeId, BOOL *bEnable);
extern "C" DLLTYPE int autpmc_GetEndPEnable_Y (int PortNum, char nNodeId, BOOL *bEnable);

extern "C" DLLTYPE int autpmc_SetDecValue (int PortNum, char nNodeId, char axis, BOOL bDec);
extern "C" DLLTYPE int autpmc_SetDecValue_X (int PortNum, char nNodeId, BOOL bDec);
extern "C" DLLTYPE int autpmc_SetDecValue_Y (int PortNum, char nNodeId, BOOL bDec);

extern "C" DLLTYPE int autpmc_GetDecValue (int PortNum, char nNodeId, char axis, BOOL *bDec);
extern "C" DLLTYPE int autpmc_GetDecValue_X (int PortNum, char nNodeId, BOOL *bDec);
extern "C" DLLTYPE int autpmc_GetDecValue_Y (int PortNum, char nNodeId, BOOL *bDec);

extern "C" DLLTYPE int autpmc_SetSofLmtEnable (int PortNum, char nNodeId, char axis, BOOL bEnable);
extern "C" DLLTYPE int autpmc_SetSofLmtEnable_X (int PortNum, char nNodeId, BOOL bEnable);
extern "C" DLLTYPE int autpmc_SetSofLmtEnable_Y (int PortNum, char nNodeId, BOOL bEnable);

extern "C" DLLTYPE int autpmc_GetSofLmtEnable (int PortNum, char nNodeId, char axis, BOOL *bEnable);
extern "C" DLLTYPE int autpmc_GetSofLmtEnable_X (int PortNum, char nNodeId, BOOL *bEnable);
extern "C" DLLTYPE int autpmc_GetSofLmtEnable_Y (int PortNum, char nNodeId, BOOL *bEnable);

extern "C" DLLTYPE int autpmc_SetPowHomStart (int PortNum, char nNodeId, char axis, BOOL bEnable);
extern "C" DLLTYPE int autpmc_SetPowHomStart_X (int PortNum, char nNodeId, BOOL bEnable);
extern "C" DLLTYPE int autpmc_SetPowHomStart_Y (int PortNum, char nNodeId, BOOL bEnable);

extern "C" DLLTYPE int autpmc_GetPowHomStart (int PortNum, char nNodeId, char axis, BOOL *bEnable);
extern "C" DLLTYPE int autpmc_GetPowHomStart_X (int PortNum, char nNodeId, BOOL *bEnable);
extern "C" DLLTYPE int autpmc_GetPowHomStart_Y (int PortNum, char nNodeId, BOOL *bEnable);

extern "C" DLLTYPE int autpmc_SetPowPgmStart (int PortNum, char nNodeId, char axis, BOOL bEnable);
extern "C" DLLTYPE int autpmc_SetPowPgmStart_X (int PortNum, char nNodeId, BOOL bEnable);
extern "C" DLLTYPE int autpmc_SetPowPgmStart_Y (int PortNum, char nNodeId, BOOL bEnable);

extern "C" DLLTYPE int autpmc_GetPowPgmStart (int PortNum, char nNodeId, char axis, BOOL *bEnable);
extern "C" DLLTYPE int autpmc_GetPowPgmStart_X (int PortNum, char nNodeId, BOOL *bEnable);
extern "C" DLLTYPE int autpmc_GetPowPgmStart_Y (int PortNum, char nNodeId, BOOL *bEnable);

extern "C" DLLTYPE int autpmc_SetInputLev (int PortNum, char nNodeId, char axis, BOOL bInPort, BOOL bActLev);
extern "C" DLLTYPE int autpmc_SetInputLev_X (int PortNum, char nNodeId, BOOL bInPort, BOOL bActLev);
extern "C" DLLTYPE int autpmc_SetInputLev_Y (int PortNum, char nNodeId, BOOL bInPort, BOOL bActLev);

extern "C" DLLTYPE int autpmc_GetInputLev (int PortNum, char nNodeId, char axis, BOOL bInPort, BOOL *bActLev);
extern "C" DLLTYPE int autpmc_GetInputLev_X (int PortNum, char nNodeId, BOOL bInPort, BOOL *bActLev);
extern "C" DLLTYPE int autpmc_GetInputLev_Y (int PortNum, char nNodeId, BOOL bInPort, BOOL *bActLev);

extern "C" DLLTYPE int autpmc_SetPulseType (int PortNum, char nNodeId, int iPulseType);
extern "C" DLLTYPE int autpmc_GetPulseType (int PortNum, char nNodeId, int *iPulseType);

extern "C" DLLTYPE int autpmc_Step1Enable (int PortNum, char nNodeId, char axis, BOOL bEnable);
extern "C" DLLTYPE int autpmc_Step1Enable_X (int PortNum, char nNodeId, BOOL bEnable);
extern "C" DLLTYPE int autpmc_Step1Enable_Y (int PortNum, char nNodeId, BOOL bEnable);

extern "C" DLLTYPE int autpmc_Step1Direction (int PortNum, char nNodeId, char axis, BOOL bDirection);
extern "C" DLLTYPE int autpmc_Step1Direction_X (int PortNum, char nNodeId, BOOL bDirection);
extern "C" DLLTYPE int autpmc_Step1Direction_Y (int PortNum, char nNodeId, BOOL bDirection);

extern "C" DLLTYPE int autpmc_Step2Enable (int PortNum, char nNodeId, char axis, BOOL bEnable);
extern "C" DLLTYPE int autpmc_Step2Enable_X (int PortNum, char nNodeId, BOOL bEnable);
extern "C" DLLTYPE int autpmc_Step2Enable_Y (int PortNum, char nNodeId, BOOL bEnable);

extern "C" DLLTYPE int autpmc_Step2Direction (int PortNum, char nNodeId, char axis, BOOL bDirection);
extern "C" DLLTYPE int autpmc_Step2Direction_X (int PortNum, char nNodeId, BOOL bDirection);
extern "C" DLLTYPE int autpmc_Step2Direction_Y (int PortNum, char nNodeId, BOOL bDirection);

extern "C" DLLTYPE int autpmc_Step3Enable (int PortNum, char nNodeId, char axis, BOOL bEnable);
extern "C" DLLTYPE int autpmc_Step3Enable_X (int PortNum, char nNodeId, BOOL bEnable);
extern "C" DLLTYPE int autpmc_Step3Enable_Y (int PortNum, char nNodeId, BOOL bEnable);

extern "C" DLLTYPE int autpmc_Step3Direction (int PortNum, char nNodeId, char axis, BOOL bDirection);
extern "C" DLLTYPE int autpmc_Step3Direction_X (int PortNum, char nNodeId, BOOL bDirection);
extern "C" DLLTYPE int autpmc_Step3Direction_Y (int PortNum, char nNodeId, BOOL bDirection);

extern "C" DLLTYPE int autpmc_Step4Enable (int PortNum, char nNodeId, char axis, BOOL bEnable);
extern "C" DLLTYPE int autpmc_Step4Enable_X (int PortNum, char nNodeId, BOOL bEnable);
extern "C" DLLTYPE int autpmc_Step4Enable_Y (int PortNum, char nNodeId, BOOL bEnable);

extern "C" DLLTYPE int autpmc_Step4Direction (int PortNum, char nNodeId, char axis, BOOL bDirection);
extern "C" DLLTYPE int autpmc_Step4Direction_X (int PortNum, char nNodeId, BOOL bDirection);
extern "C" DLLTYPE int autpmc_Step4Direction_Y (int PortNum, char nNodeId, BOOL bDirection);

extern "C" DLLTYPE int autpmc_SetHomEndPosClr (int PortNum, char nNodeId, char axis, BOOL bEnable);
extern "C" DLLTYPE int autpmc_SetHomEndPosClr_X (int PortNum, char nNodeId, BOOL bEnable);
extern "C" DLLTYPE int autpmc_SetHomEndPosClr_Y (int PortNum, char nNodeId, BOOL bEnable);

extern "C" DLLTYPE int autpmc_GetHomEndPosClr (int PortNum, char nNodeId, char axis, BOOL *bClear);
extern "C" DLLTYPE int autpmc_GetHomEndPosClr_X (int PortNum, char nNodeId, BOOL *bClear);
extern "C" DLLTYPE int autpmc_GetHomEndPosClr_Y (int PortNum, char nNodeId, BOOL *bClear);

extern "C" DLLTYPE int autpmc_SetHomSigLev (int PortNum, char nNodeId, char axis, int nHomSigNo, BOOL bLevel);
extern "C" DLLTYPE int autpmc_SetNearHomeSignal_X (int PortNum, char nNodeId, BOOL bActLev);
extern "C" DLLTYPE int autpmc_SetNearHomeSignal_Y (int PortNum, char nNodeId, BOOL bActLev);
extern "C" DLLTYPE int autpmc_SetHomeSignalLevel_X (int PortNum, char nNodeId, BOOL bActLev);
extern "C" DLLTYPE int autpmc_SetHomeSignalLevel_Y (int PortNum, char nNodeId, BOOL bActLev);
extern "C" DLLTYPE int autpmc_SetZSignalLevel_X (int PortNum, char nNodeId, BOOL bActLev);
extern "C" DLLTYPE int autpmc_SetZSignalLevel_Y (int PortNum, char nNodeId, BOOL bActLev);

extern "C" DLLTYPE int autpmc_GetHomSigLev (int PortNum, char nNodeId, char axis, int nHomSigNo, BOOL *bLevel);
extern "C" DLLTYPE int autpmc_GetNearHomeSignal_X (int PortNum, char nNodeId, BOOL *bLevel);
extern "C" DLLTYPE int autpmc_GetNearHomeSignal_Y (int PortNum, char nNodeId, BOOL *bLevel);
extern "C" DLLTYPE int autpmc_GetHomeSignalLevel_X (int PortNum, char nNodeId, BOOL *bLevel);
extern "C" DLLTYPE int autpmc_GetHomeSignalLevel_Y (int PortNum, char nNodeId, BOOL *bLevel);
extern "C" DLLTYPE int autpmc_GetZSignalLevel_X (int PortNum, char nNodeId, BOOL *bLevel);
extern "C" DLLTYPE int autpmc_GetZSignalLevel_Y (int PortNum, char nNodeId, BOOL *bLevel);

extern "C" DLLTYPE int autpmc_SetHomMod(int PortNum, char nNodeId, char axis, int nStepNo, BOOL bEnable, BOOL bDirection);
extern "C" DLLTYPE int autpmc_SetHomMod_X(int PortNum, char nNodeId, char axis, int nStepNo, BOOL bEnable, BOOL bDirection);
extern "C" DLLTYPE int autpmc_SetHomMod_Y(int PortNum, char nNodeId, char axis, int nStepNo, BOOL bEnable, BOOL bDirection);

extern "C" DLLTYPE struct HOMMOD *autpmc_GetHomMod(int PortNum, char nNodeId, char axis, int nStepNo, HOMMOD *pMode);
extern "C" DLLTYPE struct HOMMOD *autpmc_GetHomMod_X(int PortNum, char nNodeId, int nStepNo, HOMMOD *pMode);
extern "C" DLLTYPE struct HOMMOD *autpmc_GetHomMod_Y(int PortNum, char nNodeId, int nStepNo, HOMMOD *pMode);

extern "C" DLLTYPE int autpmc_PgmABS (int PortNum, char nNodeId, char axis, int nStepNo, long lPos, int nSpeed, int nTimer, BOOL bEndP, BOOL bBoth);
extern "C" DLLTYPE int autpmc_PgmABS_X (int PortNum, char nNodeId, char axis, int nStepNo, long lPos, int nSpeed, int nTimer, BOOL bEndP, BOOL bBoth);
extern "C" DLLTYPE int autpmc_PgmABS_Y (int PortNum, char nNodeId, char axis, int nStepNo, long lPos, int nSpeed, int nTimer, BOOL bEndP);

extern "C" DLLTYPE int autpmc_PgmINC (int PortNum, char nNodeId, char axis, int nStepNo, long lPos, int nSpeed, int nTimer, BOOL bEndP, BOOL bBoth);
extern "C" DLLTYPE int autpmc_PgmINC_X (int PortNum, char nNodeId, char axis, int nStepNo, long lPos, int nSpeed, int nTimer, BOOL bEndP, BOOL bBoth);
extern "C" DLLTYPE int autpmc_PgmINC_Y (int PortNum, char nNodeId, char axis, int nStepNo, long lPos, int nSpeed, int nTimer, BOOL bEndP);

extern "C" DLLTYPE int autpmc_PgmHOM (int PortNum, char nNodeId, char axis, int nStepNo, BOOL bEndP, BOOL bBoth);
extern "C" DLLTYPE int autpmc_PgmHOM_X (int PortNum, char nNodeId, char axis, int nStepNo, BOOL bEndP, BOOL bBoth);
extern "C" DLLTYPE int autpmc_PgmHOM_Y (int PortNum, char nNodeId, char axis, int nStepNo, BOOL bEndP);

extern "C" DLLTYPE int autpmc_PgmLID (int PortNum, char nNodeId, int nStepNo, long lXEndPos, long lYEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);
extern "C" DLLTYPE int autpmc_PgmLID_X (int PortNum, char nNodeId, int nStepNo, long lXEndPos, long lYEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);
extern "C" DLLTYPE int autpmc_PgmLID_Y (int PortNum, char nNodeId, int nStepNo, long lXEndPos, long lYEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP); 

extern "C" DLLTYPE int autpmc_PgmCID (int PortNum, char nNodeId, int nStepNo, long lRadius, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);
extern "C" DLLTYPE int autpmc_PgmCID_1 (int PortNum, char nNodeId, int nStepNo, long lRadius, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);	
extern "C" DLLTYPE int autpmc_PgmCID_2 (int PortNum, char nNodeId, int nStepNo, long lRadius, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP, long ManualDecelPoint);	
extern "C" DLLTYPE int autpmc_PgmCID_3 (int PortNum, char nNodeId, int nStepNo, long lRadius, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);
extern "C" DLLTYPE int autpmc_PgmCID_4 (int PortNum, char nNodeId, int nStepNo, long lRadius, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP, long ManualDecelPoint);

extern "C" DLLTYPE int autpmc_PgmFID (int PortNum, char nNodeId, int nStepNo, long XCenPos, long XEndPos, long YCenPos, long YEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);
extern "C" DLLTYPE int autpmc_PgmFID1 (int PortNum, char nNodeId, int nStepNo, long XCenPos, long XEndPos, long YCenPos, long YEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);
extern "C" DLLTYPE int autpmc_PgmFID2 (int PortNum, char nNodeId, int nStepNo, long XCenPos, long XEndPos, long YCenPos, long YEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);
extern "C" DLLTYPE int autpmc_PgmFID3 (int PortNum, char nNodeId, int nStepNo, long XCenPos, long XEndPos, long YCenPos, long YEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP, long ManualDecelPoint);
extern "C" DLLTYPE int autpmc_PgmFID4 (int PortNum, char nNodeId, int nStepNo, long XCenPos, long XEndPos, long YCenPos, long YEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);
extern "C" DLLTYPE int autpmc_PgmFID5 (int PortNum, char nNodeId, int nStepNo, long XCenPos, long XEndPos, long YCenPos, long YEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);
extern "C" DLLTYPE int autpmc_PgmFID6 (int PortNum, char nNodeId, int nStepNo, long XCenPos, long XEndPos, long YCenPos, long YEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP, long ManualDecelPoint);

extern "C" DLLTYPE int autpmc_PgmRID (int PortNum, char nNodeId, int nStepNo, long XCenPos, long XEndPos, long YCenPos, long YEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);
extern "C" DLLTYPE int autpmc_PgmRID1 (int PortNum, char nNodeId, int nStepNo, long XCenPos, long XEndPos, long YCenPos, long YEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);
extern "C" DLLTYPE int autpmc_PgmRID2 (int PortNum, char nNodeId, int nStepNo, long XCenPos, long XEndPos, long YCenPos, long YEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);
extern "C" DLLTYPE int autpmc_PgmRID3 (int PortNum, char nNodeId, int nStepNo, long XCenPos, long XEndPos, long YCenPos, long YEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP, long ManualDecelPoint);
extern "C" DLLTYPE int autpmc_PgmRID4 (int PortNum, char nNodeId, int nStepNo, long XCenPos, long XEndPos, long YCenPos, long YEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);
extern "C" DLLTYPE int autpmc_PgmRID5 (int PortNum, char nNodeId, int nStepNo, long XCenPos, long XEndPos, long YCenPos, long YEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP);
extern "C" DLLTYPE int autpmc_PgmRID6 (int PortNum, char nNodeId, int nStepNo, long XCenPos, long XEndPos, long YCenPos, long YEndPos, BOOL bFLS, int nSpeed, int nTimer, BOOL bEndP, long ManualDecelPoint);

extern "C" DLLTYPE int autpmc_PgmICJ (int PortNum, char nNodeId, char axis, int nStepNo, int nJumpStep, int nInputPtNo);
extern "C" DLLTYPE int autpmc_PgmICJ_X (int PortNum, char nNodeId, char axis, int nStepNo, int nJumpStep, int nInputPtNo);
extern "C" DLLTYPE int autpmc_PgmICJ_Y (int PortNum, char nNodeId, char axis, int nStepNo, int nJumpStep, int nInputPtNo);

extern "C" DLLTYPE int autpmc_PgmIRD (int PortNum, char nNodeId, char axis, int nStepNo, int nInputPtNo);
extern "C" DLLTYPE int autpmc_PgmIRD_X (int PortNum, char nNodeId, char axis, int nStepNo, int nInputPtNo);
extern "C" DLLTYPE int autpmc_PgmIRD_Y (int PortNum, char nNodeId, char axis, int nStepNo, int nInputPtNo);

extern "C" DLLTYPE int autpmc_PgmOPC (int PortNum, char nNodeId, char axis, int nStepNo, int nInputPtNo, BOOL bON);
extern "C" DLLTYPE int autpmc_PgmOPC_X (int PortNum, char nNodeId, char axis, int nStepNo, int nInputPtNo, BOOL bON);
extern "C" DLLTYPE int autpmc_PgmOPC_Y (int PortNum, char nNodeId, char axis, int nStepNo, int nInputPtNo, BOOL bON);

extern "C" DLLTYPE int autpmc_PgmOPT (int PortNum, char nNodeId, char axis, int nStepNo, int nOutPtNo, int iOnTim, BOOL bNextStep);
extern "C" DLLTYPE int autpmc_PgmOPT_X (int PortNum, char nNodeId, char axis, int nStepNo, int nOutPtNo, int iOnTim, BOOL bNextStep);
extern "C" DLLTYPE int autpmc_PgmOPT_Y (int PortNum, char nNodeId, char axis, int nStepNo, int nOutPtNo, int iOnTim, BOOL bNextStep);

extern "C" DLLTYPE int autpmc_PgmJMP (int PortNum, char nNodeId, char axis, int nStepNo, int nJumpStep);
extern "C" DLLTYPE int autpmc_PgmJMP_X (int PortNum, char nNodeId, char axis, int nStepNo, int nJumpStep);
extern "C" DLLTYPE int autpmc_PgmJMP_Y (int PortNum, char nNodeId, char axis, int nStepNo, int nJumpStep);

extern "C" DLLTYPE int autpmc_PgmREP (int PortNum, char nNodeId, char axis, int nStepNo, int nRepCnt);
extern "C" DLLTYPE int autpmc_PgmREP_X (int PortNum, char nNodeId, char axis, int nStepNo, int nRepCnt);
extern "C" DLLTYPE int autpmc_PgmREP_Y (int PortNum, char nNodeId, char axis, int nStepNo, int nRepCnt);

extern "C" DLLTYPE int autpmc_PgmRPE (int PortNum, char nNodeId, char axis, int nStepNo);
extern "C" DLLTYPE int autpmc_PgmRPE_X (int PortNum, char nNodeId, char axis, int nStepNo);
extern "C" DLLTYPE int autpmc_PgmRPE_Y (int PortNum, char nNodeId, char axis, int nStepNo);

extern "C" DLLTYPE int autpmc_PgmEND (int PortNum, char nNodeId, char axis, int nStepNo);
extern "C" DLLTYPE int autpmc_PgmEND_X (int PortNum, char nNodeId, char axis, int nStepNo);
extern "C" DLLTYPE int autpmc_PgmEND_Y (int PortNum, char nNodeId, char axis, int nStepNo);

extern "C" DLLTYPE int autpmc_PgmTIM (int PortNum, char nNodeId, char axis, int nStepNo, int nOnTim);
extern "C" DLLTYPE int autpmc_PgmTIM_X (int PortNum, char nNodeId, char axis, int nStepNo, int nOnTim);
extern "C" DLLTYPE int autpmc_PgmTIM_Y (int PortNum, char nNodeId, char axis, int nStepNo, int nOnTim);

extern "C" DLLTYPE int autpmc_PgmNOP (int PortNum, char nNodeId, char axis, int nStepNo);
extern "C" DLLTYPE int autpmc_PgmNOP_X (int PortNum, char nNodeId, char axis, int nStepNo);
extern "C" DLLTYPE int autpmc_PgmNOP_Y (int PortNum, char nNodeId, char axis, int nStepNo);

extern "C" DLLTYPE int autpmc_PgmRun (int PortNum, char nNodeId, char axis, int iStepNo);
extern "C" DLLTYPE int autpmc_PgmRun_X (int PortNum, char nNodeId, int iStepNo);
extern "C" DLLTYPE int autpmc_PgmRun_Y (int PortNum, char nNodeId, int iStepNo);
extern "C" DLLTYPE int autpmc_PgmRun_X_Y(int PortNum, char nNodeId, int iStepNo);

extern "C" DLLTYPE int autpmc_PgmStepRun (int PortNum, char nNodeId, char axis, int iStepNo);
extern "C" DLLTYPE int autpmc_PgmStepRun_X (int PortNum, char nNodeId, int iStepNo);
extern "C" DLLTYPE int autpmc_PgmStepRun_Y (int PortNum, char nNodeId, int iStepNo);
extern "C" DLLTYPE int autpmc_PgmStepRun_X_Y(int PortNum, char nNodeId, int iStepNo);

extern "C" DLLTYPE int autpmc_PgmPause (int PortNum, char nNodeId, char axis);
extern "C" DLLTYPE int autpmc_PgmPause_X (int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_PgmPause_Y (int PortNum, char nNodeId);

extern "C" DLLTYPE int autpmc_PgmReRun (int PortNum, char nNodeId, char axis);
extern "C" DLLTYPE int autpmc_PgmReRun_X (int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_PgmReRun_Y (int PortNum, char nNodeId);

extern "C" DLLTYPE int autpmc_PgmStop (int PortNum, char nNodeId, char axis);
extern "C" DLLTYPE int autpmc_PgmStop_X (int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_PgmStop_Y (int PortNum, char nNodeId);

extern "C" DLLTYPE int autpmc_DelPgmDataAll (int PortNum, char nNodeId, char axis);
extern "C" DLLTYPE int autpmc_DelPgmDataAll_X (int PortNum, char nNodeId, char axis);
extern "C" DLLTYPE int autpmc_DelPgmDataAll_Y (int PortNum, char nNodeId, char axis);

extern "C" DLLTYPE int autpmc_DelPgmData (int PortNum, char nNodeId, char axis, int nStepNo);
extern "C" DLLTYPE int autpmc_DelPgmData_X (int PortNum, char nNodeId, char axis, int nStepNo);
extern "C" DLLTYPE int autpmc_DelPgmData_Y (int PortNum, char nNodeId, char axis, int nStepNo);

extern "C" DLLTYPE int autpmc_Reset (int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_Init (int PortNum, char nNodeId);
extern "C" DLLTYPE int autpmc_IsCon (int PortNum, char nNodeId, BOOL *bOn);

extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaAll (int PortNum, char nNodeId, char axis, PMC_PARADATA *pData);
extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaAll_X (int PortNum, char nNodeId, PMC_PARADATA *pData);
extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaAll_Y (int PortNum, char nNodeId, PMC_PARADATA *pData);
extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaAll_X_Y (int PortNum, char nNodeId, PMC_PARADATA *pData);

extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaOPMAll (int PortNum, char nNodeId, char axis, PMC_PARADATA *pData);
extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaOPMAll_X (int PortNum, char nNodeId, PMC_PARADATA *pData);
extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaOPMAll_Y (int PortNum, char nNodeId, PMC_PARADATA *pData);
extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaOPMAll_X_Y (int PortNum, char nNodeId, PMC_PARADATA *pData);

extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaPMAll (int PortNum, char nNodeId, char axis, PMC_PARADATA *pData);
extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaPMAll_X (int PortNum, char nNodeId, PMC_PARADATA *pData);
extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaPMAll_Y (int PortNum, char nNodeId, PMC_PARADATA *pData);
extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaPMAll_X_Y (int PortNum, char nNodeId, PMC_PARADATA *pData);

extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaHSMAll (int PortNum, char nNodeId, char axis, PMC_PARADATA *pData);
extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaHSMAll_X (int PortNum, char nNodeId, PMC_PARADATA *pData);
extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaHSMAll_Y (int PortNum, char nNodeId, PMC_PARADATA *pData);
extern "C" DLLTYPE struct PMC_PARADATA *autpmc_GetParaHSMAll_X_Y (int PortNum, char nNodeId, PMC_PARADATA *pData);

extern "C" DLLTYPE int autpmc_GetCurPos (int PortNum, char nNodeId, char axis, long *lCurPos_X, long *lCurPos_Y);
extern "C" DLLTYPE int autpmc_GetCurPos_X (int PortNum, char nNodeId, long *lCurPos_X);
extern "C" DLLTYPE int autpmc_GetCurPos_Y (int PortNum, char nNodeId, long *lCurPos_Y);
extern "C" DLLTYPE int autpmc_GetCurPos_X_Y (int PortNum, char nNodeId, long *lCurPos_X, long *lCurPos_Y);

extern "C" DLLTYPE int autpmc_GetCurPgmNo (int PortNum, char nNodeId, char axis, int *iCurPgmNo_X, int *iCurPgmNo_Y);
extern "C" DLLTYPE int autpmc_GetCurPgmNo_X (int PortNum, char nNodeId, int *iCurPgmNo_X);
extern "C" DLLTYPE int autpmc_GetCurPgmNo_Y (int PortNum, char nNodeId, int *iCurPgmNo_Y);
extern "C" DLLTYPE int autpmc_GetCurPgmNo_X_Y (int PortNum, char nNodeId, int *iCurPgmNo_X, int *iCurPgmNo_Y);

extern "C" DLLTYPE struct PMC_ERRORSTATE *autpmc_GetErrorSt (int PortNum, char nNodeId, char axis, PMC_ERRORSTATE *pError);
extern "C" DLLTYPE struct PMC_ERRORSTATE *autpmc_GetErrorSt_X (int PortNum, char nNodeId, PMC_ERRORSTATE *pError);
extern "C" DLLTYPE struct PMC_ERRORSTATE *autpmc_GetErrorSt_Y (int PortNum, char nNodeId, PMC_ERRORSTATE *pError);
extern "C" DLLTYPE struct PMC_ERRORSTATE *autpmc_GetErrorSt_X_Y (int PortNum, char nNodeId, PMC_ERRORSTATE *pError);

extern "C" DLLTYPE struct PMC_RUNSTATE *autpmc_IsRun (int PortNum, char nNodeId, char axis, PMC_RUNSTATE *pRun);
extern "C" DLLTYPE struct PMC_RUNSTATE *autpmc_IsRun_X (int PortNum, char nNodeId, PMC_RUNSTATE *pRun);
extern "C" DLLTYPE struct PMC_RUNSTATE *autpmc_IsRun_Y (int PortNum, char nNodeId, PMC_RUNSTATE *pRun);
extern "C" DLLTYPE struct PMC_RUNSTATE *autpmc_IsRun_X_Y (int PortNum, char nNodeId, PMC_RUNSTATE *pRun);

extern "C" DLLTYPE struct PMC_SOFTVERSION *autpmc_GetModName (int PortNum, char nNodeId, PMC_SOFTVERSION *pVersion);
extern "C" DLLTYPE struct PMC_SOFTVERSION *autpmc_GetSofVer (int PortNum, char nNodeId, PMC_SOFTVERSION *pVersion);

extern "C" DLLTYPE int autpmc_ContMove (int PortNum, char nNodeId, char axis, BOOL bDirection);
extern "C" DLLTYPE int autpmc_ContMove_X (int PortNum, char nNodeId, BOOL bDirection);
extern "C" DLLTYPE int autpmc_ContMove_Y (int PortNum, char nNodeId, BOOL bDirection);

extern "C" DLLTYPE struct PARALLELSTATE *autpmc_GetParallelIO (int PortNum, char nNodeId, PARALLELSTATE *pState);

extern "C" DLLTYPE struct AXISSTATE *autpmc_GetAxisIO (int PortNum, char nNodeId, char axis, AXISSTATE *pState);
extern "C" DLLTYPE struct AXISSTATE *autpmc_GetAxisIO_X (int PortNum, char nNodeId, AXISSTATE *pState);
extern "C" DLLTYPE struct AXISSTATE *autpmc_GetAxisIO_Y (int PortNum, char nNodeId, AXISSTATE *pState);
extern "C" DLLTYPE struct AXISSTATE *autpmc_GetAxisIO_X_Y (int PortNum, char nNodeId, AXISSTATE *pState);

extern "C" DLLTYPE int autpmc_SetUserOut (int PortNum, char nNodeId, char axis, BOOL bPort, BOOL bOn);
extern "C" DLLTYPE int autpmc_SetUserOut_X (int PortNum, char nNodeId, BOOL bPort, BOOL bOn);
extern "C" DLLTYPE int autpmc_SetUserOut_Y (int PortNum, char nNodeId, BOOL bPort, BOOL bOn);

extern "C" DLLTYPE int autpmc_Send(int PortNum, char* nData, int data_length);
extern "C" DLLTYPE int autpmc_Read(int PortNum);
extern "C" DLLTYPE int  getReadBuf(char *buf, int len, int PortNum);
extern "C" DLLTYPE bool getCheckModBusRTU(byte data);
extern "C" DLLTYPE int CRC16 (char *nData, int wLength);
extern "C" DLLTYPE long __fastcall CalculateManualDecelPoint(const int Range,
	long Acceleration, long Deceleration, long StVelocity, long DrVelocity,
	const int CtXaxis, const int CtYaxis, const int EndXaxis, const int EndYaxis,
	const BOOL CW, const BOOL FLS);
extern "C" DLLTYPE void __fastcall CalTotShortPulse(const bool CW, const double BeginArcXaxis,
	const double BeginArcYaxis, const double EndArcXaxis, const double EndArcYaxis,
	const double Radius2, const int BeginPhase, const int EndPhase, long &TotalShortPulse,
	double &BeginPhasePulse, double &EndPhasePulse, int &NumberOfPassPhase);

#ifndef  MYHEADER
#define MYHEADER

typedef struct PMC_PARADATA
{
	int iErrorState;
	BOOL bLmtStopMod[2];
	BOOL bLmtActLev[2];
	BOOL bSCurve[2];
	BOOL bEndPEnable[2];
	BOOL bDecValue[2];
	BOOL bSofLmtEnable[2];
	BOOL bPowHomStart[2];
	BOOL bPowPgmStart[2];
	BOOL bInput0Lev[2];
	BOOL bInput1Lev[2];
	int iPulseType;
	int iSpdMul[2];
	int iJrkSpd[2];
	int iAccSpdRate[2];
	int iDecSpdRate[2];
	int iStrSpd[2];
	int iDrvSpd[2]; 
	int iDrvSpd1Pgm[2];
	int iDrvSpd2Pgm[2];
	int iDrvSpd3Pgm[2];
	int iDrvSpd4Pgm[2];
	int iTim1Pgm[2];
	int iTim2Pgm[2];
	int iTim3Pgm[2];
	long lSofLmtP[2];
	long lSofLmtM[2];
	int iEndPWidth[2];
	int iPulSclNum[2];
	int iPulSclDen[2];
	BOOL bHomMod1[2];
	BOOL bHomMod1Dir[2];
	BOOL bHomMod2[2];
	BOOL bHomMod2Dir[2];
	BOOL bHomMod3[2];
	BOOL bHomMod3Dir[2];
	BOOL bHomMod4[2];
	BOOL bHomMod4Dir[2];
	BOOL bHomEndPosClr[2];
	BOOL bHomSig0Lev[2];
	BOOL bHomSig1Lev[2];
	BOOL bHomSig2Lev[2];
	int iHomLowSpd[2];
	int iHomHighSpd[2];
	long lHomOffset[2];

} PMC_PARADATA;

typedef struct PMC_SOFTVERSION
{
	int iErrorState;
	char cModName[11];
	char cSofVer[7];

} PMC_SOFTVERSION;

typedef struct PMC_ERRORSTATE
{
	int iErrorState;
	BOOL bSofLmtErrP[2];
	BOOL bSofLmtErrM[2];
	BOOL bHardLmtErrP[2];
	BOOL bHardLmtErrM[2];
	BOOL bEmgErr[2];
	BOOL bPgmErr[2];
	BOOL bHomErr[2];
	BOOL bInxErr[2];
} PMC_ERRORSTATE;

typedef struct PMC_RUNSTATE
{
	int iErrorState;
	BOOL bHomIsRun[2];
	BOOL bJogIsRun[2];
	BOOL bPgmIsRun[2];

} PMC_RUNSTATE;

typedef struct HOMMOD
{
	int iErrorState;
	BOOL bEnable[2];
	BOOL bDirection[2];
} HOMMOD;

typedef struct PARALLELSTATE
{
	int iErrorState;
	BOOL HOME;
	BOOL STROBE;
	BOOL X;
	BOOL Y;
	BOOL MODE0;
	BOOL MODE1;
	BOOL STEPSL0;
	BOOL STEPSL1;
	BOOL STEPSL2;
	BOOL STEPSL3;
	BOOL STEPSL4;
	BOOL STEPSL5;
} PARALLELSTATE;

typedef struct AXISSTATE
{
	int iErrorState;
	BOOL bHomSig0[2];
	BOOL bHomSig1[2];
	BOOL bHomSig2[2];
	BOOL LmtP[2];
	BOOL LmtM[2];
	BOOL EMG[2];
	BOOL bInput0Lev[2];
	BOOL bInput1Lev[2];
} AXISSTATE;

#endif
#endif