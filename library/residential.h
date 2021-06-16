#include <stdio.h>
#include <string.h>
typedef struct buyingElectricity {
	float tunits;
	float boughtUnits;
}electricityInfo;

electricityInfo Residential(float money,float tunits){

	float rem,units,money_2,units_2,money_3,secondRem,units_3;
	electricityInfo buyingInfo;
	if(tunits <=15){
	 	rem =(15-tunits)*89;
			 	if(rem > money){
			 		units =money/89;
			 	
			 		buyingInfo.tunits +=units;
			 		buyingInfo.boughtUnits =units;
			 		return buyingInfo;
				 }else{
						 	units +=15-tunits;
						 	money_2 =money -rem;
						 	if(money_2 <= 35*212){
						 			units_2 =money_2 /212;
									units +=units_2;
									buyingInfo.tunits +=units;
									buyingInfo.boughtUnits =units;
									return buyingInfo;
							 }else{
								 	secondRem = rem + (35*212);
								 	units +=35;
								 	money_3 = money -secondRem;
								 	units_3 =money_3 /249;
								 	units +=units_3;
								 	buyingInfo.tunits +=units;
									buyingInfo.boughtUnits =units;
									return buyingInfo;
					 }
				 }
	 	
	}else if(tunits > 15 && tunits >= 50){
	 	rem = (50-tunits)*212;
	 	if(rem > money){
	 		units =money/212;
	 		buyingInfo.tunits +=units;
			buyingInfo.boughtUnits =units;
			return buyingInfo;
		 }else{
		 	units =50-tunits;
		 	money_2 =money -rem;
		 	units_2 =money_2 /249;
		 	units +=units_2;
		 	buyingInfo.tunits +=units;
			buyingInfo.boughtUnits =units;
			return buyingInfo;
		 }	 	
	}else{
	units =money /249;
		buyingInfo.tunits +=units;
		buyingInfo.boughtUnits =units;
		return buyingInfo;
}
	
}

// int main(){
// 	electricityInfo units =Residential(1500 ,17);
// 	printf("Units are %f\n",units.boughtUnits);
// }
	
	
	
	
	
