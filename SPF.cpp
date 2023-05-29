#include "structures.h"
#include "fonctions.h"
#include "SPF.h"

process* choose_SPF_process (processList* l)
{
	process* selectedprocess = NULL;
	
	for(int i=0; i < l->process_nbr; i++ )
	{
		if(l->allProcess[i].process_status == READY)
		{
			selectedprocess = l->allProcess + i;
			break;
		}
	}
	
	if(selectedprocess == NULL)
		return NULL;
	
	for(int i=0; i < l->process_nbr; i++ )
	{
		if(l->allProcess[i].exec_time < selectedprocess->exec_time &&
			l->allProcess[i].process_status == READY )
		{
			selectedprocess = l->allProcess + i;
		}
	}
	
	return selectedprocess;
}

void start_SPF_processor(processList* l)
{
	int clock = 0;
	
	process* runningprocess = NULL;
	
	while(is_all_process_end(l) == 0)
	{
		update_all_process_ready(l, clock);
		
		if(runningprocess != choose_SPF_process(l))
		{
			if(runningprocess != NULL)
			{
				if(runningprocess->real_exec_time == runningprocess->exec_time)
				{
					runningprocess = choose_SPF_process(l);
					if(runningprocess != NULL)
					l->context_change_nbr ++;
				}
			}
			else
			{
				runningprocess = choose_SPF_process(l);
				if(runningprocess != NULL)
					l->context_change_nbr ++;
			}
		}
		
		if(runningprocess)
		{
			clock++;
			runningprocess->real_exec_time ++;
			runningprocess->process_status = RUNNING;
			
			l->exec_string[strlen(l->exec_string)+1] = '\0';
			l->exec_string[strlen(l->exec_string)] = runningprocess->process_name;
			
			if(runningprocess->real_exec_time == runningprocess->exec_time)
			{
				runningprocess->process_status = ZOMBIE;
				runningprocess->end_date = clock;
			}
		}
		else
		{
			clock++;
		}

	}
	
}
