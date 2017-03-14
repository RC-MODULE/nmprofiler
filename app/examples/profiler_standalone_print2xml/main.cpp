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
	for(int i=0; i<10; i++){
		mysin();
		mysin();
		mysin();
	
		mycos();
		mycos();
		mycos();
						
		test();
	}
	nmprofiler_print2xml();
	return nmprofiler_count();
	
}