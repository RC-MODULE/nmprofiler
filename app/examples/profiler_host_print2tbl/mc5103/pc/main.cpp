#include <stdio.h>
#include "pc_connector_mc5103_io.h"
#include "crtdbg.h"
#include "windows.h" // for Sleep()

int main (int argc, char ** argv)
{

//#ifdef _DEBUG
	C_PC_Connector_mc5103_io nmconnector("../../nm/mc5103_stdout_nmd.abs");
//#else
//	C_PC_Connector_mc5103_io nmconnector("..\\nm\\mc5103_stdout_nm.abs");
//#endif



	::Sleep(5000);
	delete nmconnector.nmservice;
	return 0;
}


