#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
//this file contains main different functions

#include "residential.h"
#include "non-residential.h"
#include "telecomtowers.h"
#include "Hotel.h"
#include "healthFacilities.h"
#include "watertreatment.h"
#include "Broadcasters.h"
#include "CommercialCenters.h"

int cashPowerNo;
char* customerName;

// structure to collect information of a Customer
struct Customer{
	int id;
	char name[40];
	int categoryId;
	int cashpowerNumber;
	float tunits;
};

struct boughtElectricity {
	float tunits;
	float boughtUnits;
};

int findTUnits(int cashPowerNo) {
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
		return 0;
	}
	
	fclose(ptr);
}

char* searchUser() {
	struct Customer customer1;
	FILE *ptr;
	ptr=fopen("storage/customers.csv","r");
	int found=0;
//	assuming that the number of characters for a name is 80
	char *name = (char*)calloc(80, sizeof(char));
	while(fread(&customer1, sizeof(customer1), 1, ptr)) {
		if (customer1.cashpowerNumber == cashPowerNo) {
			found = 1;
			customerName = customer1.name;
			printf("\t\t\tCustomer name: %s\n", customerName);
			return customerName;
		}
	}
	
	fclose(ptr);
}

int searchCashPowerCategory(int cashPowerNo) {
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
	if (!found) {
		printf("Not found!");
	}
	fclose(ptr);
}

float UpdateTUnits(int cashPowerNo, float tunits) {
	struct Customer customer1;
	FILE *ptr, *ptr1;
	int found = 0;
	ptr=fopen("storage/customers.csv","r");
	ptr1 = fopen("storage/temp.txt", "w");
	while(fread(&customer1, sizeof(customer1), 1, ptr)) {
		if (customer1.cashpowerNumber == cashPowerNo) {
			found = 1;
			customer1.tunits += tunits;
		}
		fwrite(&customer1, sizeof(customer1), 1, ptr1);
	}
	fclose(ptr);
	fclose(ptr1);
	if (found) {
		ptr1 = fopen("storage/temp.txt", "r");
		ptr=fopen("storage/customers.csv","w");
		
		while(fread(&customer1, sizeof(customer1), 1, ptr1)) {
			fwrite(&customer1, sizeof(customer1), 1, ptr);
		}
		
		fclose(ptr);
		fclose(ptr1);
	}
}

int printElecticityDetails(float units, int cashpower, float money) {
	printf("\t\t\tProcessing.....\n");
	printf("\n");
	printf("\t\t\tE-STEP Electicity\n");
	printf("\t\t\telectricity paid: %.2fKWH\n",units);
	printf("\t\t\tcashpower number: %d\n",cashpower);
	printf("\t\t\ttotal amount cost: %.2fFrw\n",money);
	printf("\t\t\ttransaction done on %s\n",__DATE__);
	printf("\t\t\t-----------------------------------------");
	printf("\n\n");
	exit(-1);
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
				printf("\n\n\t\t\tWant to continue? Enter onother option:");
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
	printf("\t\t\tEnter the your cashpower number: ");
	scanf("%d", &cashPowerNo);
	searchCashPowerCategory(cashPowerNo);
	int customerCategoryId =  searchCashPowerCategory(cashPowerNo);
	if (customerCategoryId == 0) {
		printf("\n\n\t\t\tYou're not registered! First register to continue");
		registerCashpower();
	}
	float money;
	printf("\n\n\t\t\tEnter the amount of money you want to buy units for: ");
	scanf("%f", &money);
//	searchUser();
	searchUser();
	
	struct boughtElectricity buyingInfo;
	switch (customerCategoryId) {
		case 1:{
			buyingInfo.tunits = Residential(money, findTUnits(cashPowerNo)).tunits;
			buyingInfo.boughtUnits = Residential(money, findTUnits(cashPowerNo)).boughtUnits;
			UpdateTUnits(cashPowerNo, buyingInfo.boughtUnits);
			printElecticityDetails(buyingInfo.boughtUnits, cashPowerNo, money);
			break;
		}
		case 2:{
			buyingInfo.tunits = nonResidential(money, findTUnits(cashPowerNo)).tunits;
			buyingInfo.boughtUnits = nonResidential(money, findTUnits(cashPowerNo)).boughtUnits;
			UpdateTUnits(cashPowerNo, buyingInfo.boughtUnits);
			printElecticityDetails(buyingInfo.boughtUnits, cashPowerNo, money);
			break;
		}
		case 3:{
			float boughtUnits = telecom(money);
			UpdateTUnits(cashPowerNo, boughtUnits);
			printElecticityDetails(boughtUnits, cashPowerNo, money);
			break;
		}
		case 4:{
			float boughtUnits = watertreatment(money);
			UpdateTUnits(cashPowerNo, boughtUnits);
			printElecticityDetails(boughtUnits, cashPowerNo, money);
			break;
		}
		case 5:{
			float boughtUnits = Hotels(money);
			UpdateTUnits(cashPowerNo, boughtUnits);
			printElecticityDetails(boughtUnits, cashPowerNo, money);
			break;
		}
		case 6:{
			float boughtUnits = HealthFacilities(money);
			UpdateTUnits(cashPowerNo, boughtUnits);
			printElecticityDetails(boughtUnits, cashPowerNo, money);
			break;
		}
		case 7:{
			float boughtUnits = getBroadcaster(money);
			UpdateTUnits(cashPowerNo, boughtUnits);
			printElecticityDetails(boughtUnits, cashPowerNo, money);
			break;
		}
		default:{
			float boughtUnits = getCommercialCenters(money);
			UpdateTUnits(cashPowerNo, boughtUnits);
			printElecticityDetails(boughtUnits, cashPowerNo, money);
		}
	}
}
