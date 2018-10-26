#include <stdio.h>
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




int  main(){
//for(int i=0; i<10000;i ++)
	
	printf("***************Profiler-output****************:\n");
	
	
	for(int i=0; i<11; i++){
		mysin();
		mysin();
		mysin();
	
		mycos();
		mycos();
		mycos();
						
		test();
	}
	

	nmprofiler_print2tbl();
/*
	int count=nmprofiler_count();
	S_ProfilerData* clone= new S_ProfilerData[count];
	nmprofiler_copy(clone);
	S_ProfilerData* head=clone;
	while (head){
		nmprofiler_printf(head,NMPROFILER_TBL);
		head=nmprofiler_next(head);
	}
	return count;*/
	return 1;
	
}