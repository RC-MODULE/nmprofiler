#include <stdio.h>
#include "nmprofiler.h"

extern "C"{
	extern S_ProfilerData clonedProfile[ ]; //buffer to profile cloning in shared memory
	
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

	int count=nmprofiler_count();
	nmprofiler_copy(clonedProfile); // copy profile from internal to shared memory. 
									// Memory dump is possible only from shared memory
	return count;
}