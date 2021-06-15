#include <stdio.h>
#include <stdlib.h>

float nonResidential(float money,float tunits){
    if(tunits < 100){
        float rem = (100 - tunits) * 227;
        if(rem < money){
            float newMoney = money - rem;
            float units = (newMoney/255) + 100;
            tunits += units;
            return tunits;
        }
        else{
            tunits += (money/227);
            return tunits;
        }
    }
    else{
        float units = money/255;
        tunits += units;
        return units;
    }
    return tunits;
}