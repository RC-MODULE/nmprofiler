#include "pc_connector_mc5103.h"
#include "nm_io_host.h"
class C_PC_Connector_mc5103_io: public C_PC_Connector_mc5103 {
public:
	PL_Access* access_io;
	NM_IO_Service *nmservice;

	C_PC_Connector_mc5103_io(char* absfile=0){
		Init(absfile);
	}

	int Init(char* absfile){
		struct PL_Board *board;
		int boardCount;
		PL_Word Length = 0;
		PL_Word *Buffer = 0;
		PL_Word AddrLoad = 0;

		//TRACE ("Connection to mc5103...");
		if (PL_GetBoardCount(&boardCount))	{
			TRACE( "ERROR: Can't open driver.\n");
			return  (1);
		}

		if (boardCount < 1)	{
			TRACE( "ERROR: Can't find board.\n");
			return  (1);
		}

		if (PL_GetBoardDesc(0, &board))	{
			TRACE( "ERROR: Can't open board 0 \n");
			return  (1);
		}

		if (absfile) 
			if (PL_ResetBoard(board)) {
				TRACE( "ERROR: Can't reset board  0 .\n");
				return  (1);
			}

		if (PL_GetAccess(board, 0, &access)){
			TRACE( "ERROR: Can't access processor  0 on board  0  \n");
			return  (1);
		}
		
		
		if (absfile) 
			if (PL_LoadProgramFile(access, absfile)){
				TRACE( ": : ERROR: Can't load program into board.\n");
				return  (1);
			}

		
		if (PL_GetAccess(board, 0, &access_io)){
			TRACE( "ERROR: Can't access processor  0 on board  0  \n");
			return  (1);
		}

		nmservice=new NM_IO_Service(absfile,access_io);		
		if (nmservice==0)
			return 1;
		
		TRACE ("OK!\n");

		
		return 0;
	}

};
