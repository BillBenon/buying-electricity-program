#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
//this file contains main different functions

#include "residential.c"
#include "non-residential.c"
#include "telecomtowers.c"
#include "Hotel.c"
#include "healthFacilities.c"
#include "watertreatment.c"
#include "Broadcasters.c"
#include "CommercialCenters.c"

// structure to collect information of a Customer
struct Customer{
	int id;
	char name[40];
	int categoryId;
	int cashpowerNumber;
	float tunits;
};

int search(int cashPowerNo) {
	struct Customer customer1;
	FILE *ptr;
	ptr=fopen("storage/customers.csv","r");
	int found=0;
	while(fread(&customer1, sizeof(customer1), 1, ptr)) {
		if (customer1.cashpowerNumber == cashPowerNo) {
			found = 1;
			return customer1.tunits;
		}
	}
	if (!found) {
//		char notFound[40] = "Cashpower number not found!";
		return 0;
	}
	
	fclose(ptr);
}

float findTUnits(int cashPowerNo) {
	struct Customer customer1;
	FILE *ptr;
	ptr=fopen("storage/customers.csv","r");
	int found=0;
	while(fread(&customer1, sizeof(customer1), 1, ptr)) {
		if (customer1.cashpowerNumber == cashPowerNo) {
			found = 1;
			return customer1.categoryId;
		}
	}
	fclose(ptr);
}

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
	newCustomer.tunits = 0;
	printf("\n\t\t\tYour cashpower number is: %d", newCustomer.cashpowerNumber);
	if (fwrite(&newCustomer, sizeof(struct Customer), 1, ptr)) {
		printf("\n\n\t\t\tWELCOME! you are now registered!");
		exit(-1);
	}
//	if(fprintf(ptr,"%d,%s,%d,%d, 0\n",userID,newCustomer.name,newCustomer.categoryId,newCustomer.cashpowerNumber)) {
//		
//	}
	fclose(ptr);
}


//function to buy electricity
int BuyElectricity(){
	int cashPowerNo;
	printf("\t\t\tEnter the your cashpower number: ");
	scanf("%d", &cashPowerNo);
	int customerCategoryId = search(cashPowerNo);
	if (customerCategoryId == 0) {
		printf("\n\n\t\t\tYou're not registered! First register to continue");
		registerCashpower();
	}
	printf("\n\n\t\t\tEnter the amount of money you want to buy units for: ");
	float money;
	scanf("%f", &money);
	switch (customerCategoryId) {
		case 1:
			Residential(money, findTUnits(cashPowerNo));
			break;
		case 2:
			nonResidential(money, findTUnits(cashPowerNo));
			break;
		case 3:
			telecom(money);
			break;
		case 4:
			watertreatment(money);
			break;
		case 5:
			Hotels(money);
			break;
		case 6:
			HealthFacilities(money);
			break;
		case 7:
			getBroadcaster(money);
			break;
		default:
			getCommercialCenters(money);
	}
}
