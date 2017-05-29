#include <stdio.h>

//#define DISABLE_STOPWATCH
//#include "profiler_nmcout.h"
//#include "stopwatch.h"
#include "nmprofiler.h"
extern "C"{
	volatile int mysin(){
		int g=1;
		for (int i=0; i<1000; i++){
			g*=2;
			
		}

		return g;
	}
	volatile int mycos(){
		int g=1;
		for (int i=0; i<1000; i++){
			g+=1;
		}
		return g;
	}
	int test();
};

//STOPWATCH_INIT();

int  main(){

	printf("***************Profiler output****************:\n");
	
	
	//STOPWATCH_START(tmr_all,"tmr_all");			// ��������� ������ tmr_all.	
	
	
	for(int i=0; i<10; i++){
		//STOPWATCH_START(tmr_sin,"tmr_sin");			// ��������� ������ tmr_sin.	
		mysin();
		mysin();
		mysin();
		//STOPWATCH_STOP(tmr_sin);					// ������������� ������ tmr_sin.
	
		//STOPWATCH_START(tmr_cos,"tmr_cos");			// ��������� ������ tmr_cos.
		mycos();
		mycos();
		mycos();
		//STOPWATCH_STOP(tmr_cos);					// ������������� ������ tmr_cos.
						
		test();
	}
	//STOPWATCH_STOP(tmr_all);						// ������������� ������ tmr_all.
	

	nmprofiler_print2tbl();				// ������� ��������� �������������� � std ������� 

	//STOPWATCH_PRINT2TBL();			// ������� ��������� ������� �� ������� 
	printf("\n");
	

	return 0;
	
}