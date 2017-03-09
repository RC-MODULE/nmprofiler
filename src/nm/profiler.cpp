//#include "nmprofiler.h"


//! Определяет макс размер строки имени функции в поле S_ProfilerData.funcname
//#include "nmprofiler_def.h"
#include "string.h"
#include "time.h"
#include <stdio.h>
#include "nmprofiler.h"
//#include "nmprofiler_nmcout.h"
//#define MAX_FUNCNAME_LENGTH 64
//#define MAX_FUNCNAME_LENGTH 16

extern "C"{

 
	// Функция выводит результат профилирования одной функции в stdout в форматированном виде
	// \param prof указатель структуру профилирования 
	// \param format формат вывода аналогичный printf 
	void nmprofiler_printf(S_ProfilerData* prof, char* format){
		printf(format, prof->summary, prof->calls,  prof->summary/(prof->calls+(prof->calls==0)) , prof->funcaddr, prof->funcname);
	}	

	// Функция форматрирует в результат профилирования одной функции в dststr
	// \param prof указатель структуру профилирования 
	// \param format формат вывода аналогичный sprintf 
	void nmprofiler_sprintf(char* dststr, S_ProfilerData* prof, char* format, char* full_func_name){
		if (full_func_name==0)
			full_func_name=(char*)prof->funcname;
		sprintf(dststr, format, prof->summary, prof->calls,  prof->summary/(prof->calls+(prof->calls==0)) , prof->funcaddr, full_func_name);
	}	


	// Функция возвращает указатель на первую структуру профилирования в связном списке 
	S_ProfilerData* nmprofiler_head();
	/*
	{
		int dummy=reinterpret_cast<int> (nmprofiler_list);
		int *p=reinterpret_cast<int*> (dummy);
		return (S_ProfilerData*)(p+4);
	}
	*/
	
	// Функция возвращает указатель на последнюю структуру профилирования в связном списке 
	// \param head указатель на первую структуру в списке.
	S_ProfilerData* nmprofiler_tail(S_ProfilerData* head)
	{
		while (head->next){
			head=head->next;
		}
		return head;
	}

	// Функция выводит результаты профилирования в stdout в табличном-формате по списку начиная с head. Для форматированного отображения xml-файла прилагается xsl-преобразование: profile.xsl.
	// \param head указатель на первую структуру в списке.
	void  nmprofiler_print2tbl(S_ProfilerData* head)
	{
		if (head==0)
			head=nmprofiler_head();
		char PROFILER_TBL[]="%-12u| %-12u| %-12u| %08X| %-20s\n";
		
		printf("SUMMARY     | CALLS       | AVERAGE     | ADDRESS | FUNCTION \n");
		printf("------------+-------------+-------------+---------+----------\n");
		
		while (head){
			nmprofiler_printf(head,PROFILER_TBL);
			head=head->next;
		};
		printf("------------+-------------+-------------+---------+----------\n");
	}

	//! Функция выводит результаты профилирования в stdout в xml-формате по списку начиная с head. Для форматированного отображения xml-файла прилагается xsl-преобразование: profile.xsl.
	//! \param head указатель на первую структуру в списке.
	void  nmprofiler_print2xml(S_ProfilerData* head)
	{
		if (head==0)
			head=nmprofiler_head();
		char PROFILER_XML[]="  <prof summary=\"%-12u\"	calls=\"%-12u\"	average=\"%-12u\"	addr=\"%08X\"	name=\"%s\"/>\n";
		printf("<?xml version='1.0' ?>\n");
		printf("<?xml-stylesheet type='text/xsl' href='profile.xsl'?>\n");
		printf("<profiling version=\"1.0\">\n");
		while (head){
			nmprofiler_printf(head,PROFILER_XML);
			head=head->next;
		};
		printf("</profiling>\n");
	}
};
