#include <stdio.h>

long nejmensi_56bit( long *tp_array, int t_N );

int nsc(int *intArray, int size){
    int nsc = -1;

    for (int i = 0; i < size; i++)
    {
        if(intArray[i] % 2 == 0){
            if (nsc == -1 || intArray[i] < nsc)
            {
                nsc = intArray[i];
            }
            
        }
    }
    return nsc;
}

int nlc(int *longArray, int size){
    int nlc = -1;

    for (int i = 0; i < size; i++)
    {
        if(longArray[i] % 2 != 0){
            if (nlc == -1 || longArray[i] > nlc)
            {
                nlc = longArray[i];
            }
            
        }
    }
    return nlc;
}



main(){
    int intArray [] = {1,2,4,6,8,10};
    long longArray [] = {3,5,7,9,11,13};
}