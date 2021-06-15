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
	char category[40];
	char cashpowerNumber[40];
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
	scanf("%s",newCustomer.category);
	int customNo = atoi(newCustomer.category);
	
	if (customNo != 1 && customNo != 2 && customNo != 3 && customNo != 4 && customNo != 5 && customNo != 6 && customNo != 7 && customNo != 8) {
		printf("Please choose a correct option!\n");
		goto categoryChoosing;
	}
	
	int n;
    srand(time(NULL));
    for(n=0; n<3; n++)  *newCustomer.cashpowerNumber = printf("%04d", rand()%10000);
	
	if(fprintf(ptr,"%d,%s,%s,%s\n",userID,newCustomer.name,newCustomer.category,newCustomer.cashpowerNumber)) {
		printf("\n\n\t\t\t WELCOME! you are now registered!");
	}
	fclose(ptr);
}


//function to buy electricity
int BuyElectricity(){
	
}
