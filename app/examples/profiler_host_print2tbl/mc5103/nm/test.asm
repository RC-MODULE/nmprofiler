//#include "profiler_def.h"		

begin ".text"

global _test:label;
<_test>
	gr7=t1;
	push ar0,gr0;
	
	nul;
	nul;
	nul;
	nul;
	
	nul;
	nul;
	nul;
	nul;
	
	nul;
	nul;
	nul;
	nul;
	
	nul;
	nul;
	nul;
	nul;
	
	
	gr0=t1;
	
	pop ar0,gr0 with gr7=gr0-gr7;
	return;

end ".text";

