#include "structures.h"
#include "fonctions.h"
#include "FCFS.h"

process* choose_FCFS_process (processList* l)
{
	process* selected_process = NULL;
	
	for(int i=0; i<l->process_nbr; i++) {
		
		if(l->allProcess[i].process_status == READY)
			selected_process = l->allProcess + i; // <=> selected_process = &l->allProcess[i];
	}
	
	if(selected_process == NULL)
		return NULL;
	
	for(int i=0; i<l->process_nbr; i++) {
		
		if(l->allProcess[i].process_status == READY && 
		   l->allProcess[i].arrivale_date < selected_process->arrivale_date)
		   
		   selected_process = l->allProcess + i;
	}
	
	return selected_process;
}


void start_FCFS_processor (processList* l) 
{
	int clock = 0;
	process* running_process = NULL;
	
	while(!is_all_process_end(l)) 
	{
		update_all_process_ready(l, clock);
		
		if( running_process != choose_FCFS_process(l) )
		{
			running_process = choose_FCFS_process(l);
			
			if(running_process != NULL) {
				l->context_change_nbr ++;
			}
		}
		
		if(running_process != NULL)
		{
			clock++;
			running_process->process_status = RUNNING;
			running_process->real_exec_time ++;
			
			l->exec_string[strlen(l->exec_string)+1] = '\0';
			l->exec_string[strlen(l->exec_string)] = running_process->process_name;
			
			if(running_process->exec_time == running_process->real_exec_time)
			{
				running_process->process_status = ZOMBIE;
				running_process->end_date = clock; 
			}
		}
		else
		{
			clock++;
		}
		
	}
	
}
