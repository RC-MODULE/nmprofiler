
//****************************************************************************************
// This is automaticly generated asm-file by generate_proflist.bat (generate_proflist.tcl )
// Use this script to parse map-file to extract functions from abs-file 
// and to generate initial asm-template for profiling.
// It is recommended to remove  all unnecessary functions to make profiling more precise.
//****************************************************************************************
import from nmprofiler.mlb;

PROFILE_BEGIN(16);



	// place here macros with function name for each function you wish to profile like:
	// PROFILE_FUNC(_myfunc,"myfunc");

	PROFILE_FUNC(_test,"_test");
	PROFILE_NONSTD_FUNC(Mul32,"Mul32");
	PROFILE_FUNC(_mysin,"_mysin");
	PROFILE_FUNC(_mycos,"_mycos");
	PROFILE_FUNC(_sprintf,"_sprintf");
	PROFILE_NONSTD_FUNC(UDiv32,"UDiv32");
	PROFILE_NONSTD_FUNC(UMod32,"UMod32");
	PROFILE_FUNC(UMod64,"UMod64");
	PROFILE_FUNC(UDiv64,"UDiv64");
	PROFILE_FUNC(RShift64,"RShift64");
	PROFILE_FUNC(LShift64,"LShift64");
	PROFILE_NONSTD_FUNC(IDiv32,"IDiv32");
	PROFILE_NONSTD_FUNC(IMod32,"IMod32");
	PROFILE_FUNC(_malloc,"_malloc");
	PROFILE_FUNC(_free,"_free");
	PROFILE_FUNC(_memcpy,"_memcpy");
	PROFILE_FUNC(_memset,"_memset");
	PROFILE_NONSTD_FUNC(RShift32,"RShift32");
	PROFILE_NONSTD_FUNC(ARShift32,"ARShift32");
	PROFILE_NONSTD_FUNC(LShift32,"LShift32");
	PROFILE_FUNC(_memmove,"_memmove");

PROFILE_END();

