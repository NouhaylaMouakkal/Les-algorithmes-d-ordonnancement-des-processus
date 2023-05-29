#include "structures.h"
#include "Fonctions.h"
#include "FCFS.h"
#include "SRT.h"
#include "SPF.h"
#include "PPP.h"
void menu(){
	printf("\t****************************************** MENU ****************************************\n\n");
	printf("\t\t\t\t__________________ 1-FCFS__________________\n");
	printf("\t\t\t\t__________________ 2-SPF __________________ \n");
	printf("\t\t\t\t__________________ 3-PPP __________________ \n");
	printf("\t\t\t\t__________________ 4-SRT __________________ \n");
}
int main() 
{
int choix;
char reponse;
	processList l;

do{	
		do{
		menu();
		printf("\n==>Choisir un algorithme : ");
		scanf("%d",&choix);
		system("cls");
		}while(choix <1 || choix >4);
init_process_list(&l);
	switch(choix){
		case 1:
		start_FCFS_processor(&l);
		break;
		case 2:
		start_SPF_processor(&l);
		break;
		case 3:
		start_PPP_processor(&l);	
		break;
		case 4:
		start_SRT_processor(&l);
			break;
	}	
	afficher(&l);
	
	printf("\nVous voulez faire une autre operation ? ");
	scanf(" %c",&reponse);
	system("cls");
	
}while(reponse != 'n' );

	return 0;
}
