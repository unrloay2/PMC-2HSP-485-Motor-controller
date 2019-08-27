//
//Need to modify path for Library.h, PMCLibrary.dll, PMCLibrary.lib
//Environment : Windows10, Visual Studio 2017
//Need to link PMCLibrary.dll implicitly 
//

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "Library.h"
#pragma comment(lib, "PMCLibrary.lib")
#define PortNum 15
int main()
{
	char modselect;
	Sleep(1000);
	printf("****** Microstage Control Code ver1.0 ******\n");
	Sleep(1000);
	printf("******* by CheolJun Park@IMPACT LAB ********\n\n");
	Sleep(2000);
	printf("Please the select the mode to operate \n\n # 1: Comport status check \n # 2: Microstage Initialize\n # 3: Microstage move\n : ");
	Sleep(1000);
	scanf_s("%c", &modselect);
	
	if (modselect == '1')
	{

		int stat = 0;

		for (int i = 0; i < PortNum; i++)
		{

			switch (i)
			{
			case 0: stat = autpmc_Open(0, FPMC_BAUD_115200);
				break;
			case 1: stat = autpmc_Open(1, FPMC_BAUD_115200);
				break;
			case 2: stat = autpmc_Open(2, FPMC_BAUD_115200);
				break;
			case 3: stat = autpmc_Open(3, FPMC_BAUD_115200);
				break;
			case 4: stat = autpmc_Open(4, FPMC_BAUD_115200);
				break;
			case 5: stat = autpmc_Open(5, FPMC_BAUD_115200);
				break;
			case 6: stat = autpmc_Open(6, FPMC_BAUD_115200);
				break;
			case 7: stat = autpmc_Open(7, FPMC_BAUD_115200);
				break;
			case 8: stat = autpmc_Open(8, FPMC_BAUD_115200);
				break;
			case 9: stat = autpmc_Open(9, FPMC_BAUD_115200);
				break;
			case 10: stat = autpmc_Open(10, FPMC_BAUD_115200);
				break;
			case 11: stat = autpmc_Open(11, FPMC_BAUD_115200);
				break;
			case 12: stat = autpmc_Open(12, FPMC_BAUD_115200);
				break;
			case 13: stat = autpmc_Open(13, FPMC_BAUD_115200);
				break;
			case 14: stat = autpmc_Open(14, FPMC_BAUD_115200);
				break;
			case 15: stat = autpmc_Open(15, FPMC_BAUD_115200);
				break;
			}

			if (stat == FPMC_OK)
			{
				printf("MESSAGE : Found and open 'PMC-2HSP(N) (ID = %d)' ComPort\n", i);
			}
		}
	}

	//***************************************************************
	
	/*
	autpmc_Open(10, FPMC_BAUD_9600);

	PMC_PARADATA Data;
	PMC_PARADATA *pData = &Data;

	autpmc_GetParaAll(10, Node02, FPMC_X_Y_AXIS, pData);

	printf("X axis Limit Stop Mode : %d\nY axis Limit Stop Mode: %d\n", pData->bLmtStopMod[0], pData->bLmtStopMod[1]);

	if (pData->iErrorState != FPMC_OK)
	{
		printf("error!\n");
		//return;
	}

	autpmc_Close(10);	
	*/
	//***************************************************************/
	/*
	int Flag = 0;
	int stat = 0;
	int iscon = 0;


	stat = autpmc_Open(10, FPMC_BAUD_9600);

	if (stat == FPMC_OK)
	{
		printf("Connection to port 10 OK!\n");

	}	
	
	Flag = autpmc_ContMove(10, Node02,1, FPMC_Y_AXIS);

	if (Flag != FPMC_OK)
	{
		printf("error!\n");
		printf("Flag is %d", Flag);
		
	}



	
	autpmc_Close(10);	
	*/
//**************************************************************8

	if (modselect == '2')
	{
		autpmc_Open(10, FPMC_BAUD_9600);


		//Initialize axes : Return to origin
		int Flag1 = 0;
		int Flag2 = 0;
		int Flag3 = 0;


		Flag2 = autpmc_HomRun(10, Node02, FPMC_X_Y_AXIS);
		Sleep(10);
		Flag1 = autpmc_HomRun(10, Node01, FPMC_X_AXIS);
		Sleep(10);
		Flag1 = autpmc_HomRun(10, Node01, FPMC_X_AXIS);
		Sleep(10);
		Flag3 = autpmc_HomRun(10, Node03, FPMC_X_AXIS);
		Sleep(10);
		Flag3 = autpmc_HomRun(10, Node03, FPMC_X_AXIS);
		Sleep(10);

		if (Flag1 != FPMC_OK)
		{
			printf("Error: Node01 HomRun error\n");
		}
		if (Flag2 != FPMC_OK)
		{
			printf("Error: Node02 HomRun error\n");
		}
		if (Flag3 != FPMC_OK)
		{
			printf("Error: Node03 HomRun error\n");
		}
		//End of Initialize axes
	}

	
	//Moving relative distance
	//Need a delay between operations

	if (modselect == '3') {

		autpmc_Open(10, FPMC_BAUD_9600);

		int Flag4 = 0;
		autpmc_SetDrvSpd(10, Node02, FPMC_X_Y_AXIS, 2);

		Flag4 = autpmc_INCMove(10, Node02, FPMC_X_Y_AXIS, -10000, 10000);

		Sleep(2000);

		autpmc_INCMove(10, Node02, FPMC_X_Y_AXIS, 20000, -20000);

		Sleep(2000);

		autpmc_INCMove(10, Node02, FPMC_X_Y_AXIS, -10000, 10000);



		if (Flag4 != FPMC_OK)
		{
			printf("Error: Node02 X axis 10000pulse error!\n");
		}


		//autpmc_SetStrSpd(10, Node02, FPMC_X_Y_AXIS, 2000);
		//autpmc_SetStrSpd(10, Node03, FPMC_X_AXIS, 2000);

	}

	autpmc_Close(10);


	printf("end\n");
	system("pause");

    return 0;
}

