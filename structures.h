#ifndef STRUCTURES.H
#define STRUCTURES.H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READY 0
#define RUNNING 1
#define BLOCKED 2
#define ZOMBIE 3

typedef struct {
	
	char process_name;
	int arrivale_date;
	int exec_time;
	int priority;
	
	int real_exec_time;
	int process_status;
	int end_date;
} process;

typedef struct {
	
	process* allProcess;
	int process_nbr;
	
	int context_change_nbr;
	char exec_string[100];
}processList;

#endif
