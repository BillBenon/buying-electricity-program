#include <stdio.h>
#include <stdlib.h>

struct boughtElectricityInfo{
    float tunits;
    float boughtUnits;
};

struct boughtElectricityInfo nonResidential(float money,float tunits){
    if(tunits < 100){
        float rem = (100 - tunits) * 227;
        if(rem < money){
            float newMoney = money - rem;
            float units = (newMoney/255) + 100;
            tunits += units;
            struct boughtElectricityInfo buyingInfo;
            buyingInfo.tunits = tunits;
            buyingInfo.boughtUnits = units;
            return buyingInfo;
        }
        else{
            float units = (money/227);
            tunits += units;
            struct boughtElectricityInfo buyingInfo;
            buyingInfo.tunits = tunits;
            buyingInfo.boughtUnits = units;
            return buyingInfo;
        }
    }
    else{
        float units = money/255;
        tunits += units;
        struct boughtElectricityInfo buyingInfo;
        buyingInfo.tunits = tunits;
        buyingInfo.boughtUnits = units;
        return buyingInfo;
    }
}

// void main(){
//     struct boughtElectricityInfo buyingInfo = nonResidential(55040,102);
//     printf("Bought units:  %.2f\n",buyingInfo.boughtUnits);
//     printf("Total units:  %.2f\n",buyingInfo.tunits);
// }
