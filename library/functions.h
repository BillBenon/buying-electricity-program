#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
//this file contains main different functions
// structure to collect information of a Customer
struct Customer{
	int id;
	char name[40];
	int categoryId;
	int cashpowerNumber;
};

// function to exit the application
int exitProgram(){
	system("color 07");
	printf("\n\n\t\t\tGood Customer, thank you for using this program.\n\n");
}

//function to register cashpower
int registerCashpower(){
	srand(time(0)); 
	int randId;
	randId= rand();
	int userID=randId;
	struct Customer newCustomer;
	newCustomer.id = userID;
	FILE *ptr;
	ptr=fopen("storage/customers.csv","a");
	system("color 07");
	printf("\n\t\t\t REGISTER NEW CASHPOWER");
	printf("\n\t\t\t--------------------------\n\n");
	printf("\t\t\tEnter your Name:");
	scanf("%s",newCustomer.name);
	
	int option;
	categoryChoosing:
	printf("\t\t\t|         CATEGORIES AVAILABLE                                 |\n");
	printf("\t\t\t===============================================================\n");
	printf("\t\t\t| 1 = residential                                              |\n");
	printf("\t\t\t| 2 = non residential                                          |\n");
	printf("\t\t\t| 3 = telecom towers                                           |\n");
	printf("\t\t\t| 4 = water treatment plants and pumping stations              |\n");
	printf("\t\t\t| 5 = hotels                                                   |\n");
	printf("\t\t\t| 6 = health facilities                                        |\n");
	printf("\t\t\t| 7 = Broadcasters                                             |\n");
	printf("\t\t\t| 8 = commercial data centers                                  |\n");
	printf("\t\t\t===============================================================\n");
	printf("\t\t\tChoose your category:");
	scanf("%d",&option);
	do{
		switch(option){
			case 1:
				newCustomer.categoryId = 1;
				printf("%d", newCustomer.categoryId);
				option=9;
				break;
			case 2:
				newCustomer.categoryId = 2;
				option=9;
				break;
			case 3:
				newCustomer.categoryId = 3;
				option=9;
				break;
			case 4:
				newCustomer.categoryId = 4;
				option=9;
				break;
			case 5:
				newCustomer.categoryId = 5;
				option=9;
				break;
			case 6:
				newCustomer.categoryId = 6;
				option=9;
				break;
			case 7:
				newCustomer.categoryId = 7;
				option=9;
				break;
			case 8:
				newCustomer.categoryId = 8;
				option=9;
				break;
			default:
				printf("\n\n\t\t\tSorry! Option not found!");
				printf("\n\n\t\tWant to continue? Enter onother option:");
				scanf("%d",&option);
		}
	}while(option < 9);
	printf("\n");
//	randomly generate cash power number
	int n;
    srand(time(0));
	newCustomer.cashpowerNumber = (rand() % (99999999999 - 10000000000 + 1)) + 10000000000;
	if(fprintf(ptr,"%d,%s,%d,%d, 0\n",userID,newCustomer.name,newCustomer.categoryId,newCustomer.cashpowerNumber)) {
		printf("\n\n\t\t\t WELCOME! you are now registered!");
		exit(-1);
	}
	fclose(ptr);
}


//function to buy electricity
int BuyElectricity(){
	
}
