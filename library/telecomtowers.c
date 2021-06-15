#include <stdio.h>
#include <stdlib.h>

struct boughtElectricityInfo{
    float tunits;
};

struct boughtElectricityInfo telecom(float money){
        float tunits = money/201;
        struct boughtElectricityInfo finalBuyingInfo;
        finalBuyingInfo.tunits = tunits;
        return finalBuyingInfo;
}
