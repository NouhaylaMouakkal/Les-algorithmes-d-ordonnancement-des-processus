#include "structures.h"
#include "fonctions.h"


void init_process_list(processList* l ) 
{
	l->process_nbr = 5;
	l->context_change_nbr = 0;
	
	l->allProcess = (process*) malloc (l->process_nbr * sizeof (process));
	
	for(int i=0; i<l->process_nbr; i++) {
		
		l->allProcess[i].real_exec_time = 0;
		l->allProcess[i].process_status = -1;
	}
	
	l->allProcess[0].process_name = 'A'; l->allProcess[0].exec_time = 3;  l->allProcess[0].arrivale_date = 0;	l->allProcess[0].priority=1;
	l->allProcess[1].process_name = 'B'; l->allProcess[1].exec_time = 6;  l->allProcess[1].arrivale_date = 1;	l->allProcess[1].priority=2;
	l->allProcess[2].process_name = 'C'; l->allProcess[2].exec_time = 4;  l->allProcess[2].arrivale_date = 4;	l->allProcess[2].priority=5;
	l->allProcess[3].process_name = 'D'; l->allProcess[3].exec_time = 2;  l->allProcess[3].arrivale_date = 6;	l->allProcess[3].priority=4;
	l->allProcess[4].process_name = 'E'; l->allProcess[4].exec_time = 1;  l->allProcess[4].arrivale_date = 7; 	l->allProcess[4].priority=3;		
	
}

int is_all_process_end (processList* l)
{
	for(int i=0; i<l->process_nbr; i++) {
		if(l->allProcess[i].process_status != ZOMBIE)
			return 0;
	}
	
	return 1;
}

void update_all_process_ready (processList* l, int clock)
{
	for(int i=0; i<l->process_nbr; i++) {
	
		if(l->allProcess[i].arrivale_date <= clock  &&
		   l->allProcess[i].real_exec_time <  l->allProcess[i].exec_time)
		   {
		   	 l->allProcess[i].process_status = READY;
		   }
	}	
}

float TRM (processList* l) 
{
	int s = 0;
	
	for(int i=0; i<l->process_nbr; i++) {
		
		s += l->allProcess[i].end_date - l->allProcess[i].arrivale_date;
	}
	
	return s/(float)l->process_nbr;
}

float TAM (processList* l) 
{
	int s = 0;
	
	for(int i=0; i<l->process_nbr; i++) {
		
		s += l->allProcess[i].end_date - l->allProcess[i].arrivale_date - l->allProcess[i].exec_time;
	}
	
	return s/(float)l->process_nbr;
}

void afficher (processList* l) 
{
	printf("La chaine d'execution est :  %s , nbr de chagement de contexte = %d, TRM = %.2f, TAM = %.2f \n\n",
	l->exec_string, l->context_change_nbr, TRM(l), TAM(l));
//	free(l->exec_string);
	l->exec_string[0]='\0';
	for(int i=0; i<l->process_nbr; i++) {
	
		printf("%c, D.arrivee = %d, D.fin = %d, D.exec = %d, D.exec.real = %d, status = %d  Priority= %d\n",
		l->allProcess[i].process_name, l->allProcess[i].arrivale_date, l->allProcess[i].end_date,
		 l->allProcess[i].exec_time, l->allProcess[i].real_exec_time, l->allProcess[i].process_status,l->allProcess[i].priority);
	}
}
