#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include<windows.h>
//including created files to contain different functions
#include "library/functions.h"
int main(){
	system("color F1");
	int option;
	printf("\n\t\t\tBUYING ELECTRICITY PROGRAM\n");
	printf("\t\t\t===============================\n\n\n");
	printf("\t\t\t=================================\n");
	printf("\t\t\t|         OPTIONS MENU                     |\n");
	printf("\t\t\t===========================================\n");
	printf("\t\t\t| 1 = User Cashpower Register              |\n");
	printf("\t\t\t| 2 = Buying Electricity                   |\n");
	printf("\t\t\t| 3 = Exit program                         |\n");
	printf("\t\t\t===========================================\n");
	printf("\t\t\t Enter your option:");
	scanf("%d",&option);
	do{
		switch(option){
		case 1:
			//registerCashpower() is defined in functions.h
			registerCashpower();
			option=4;
		break;
		case 2:
			//BuyElectricity() is defined in functions.h
			BuyElectricity();
			printf("\n\n\t\t\tWant to continue? Enter onother option:");
			scanf("%d",&option);
		break;
		case 3:
			//exitProgram() is defined in functions.h
			exitProgram();
			option=4;
		break;
		default:
			printf("\n\n\t\t\tSorry! Option not found!");
			printf("\n\n\t\tWant to continue? Enter onother option:");
			scanf("%d",&option);
				
	}
	}while(option < 4);
	printf("\n");
	return 0;
}
