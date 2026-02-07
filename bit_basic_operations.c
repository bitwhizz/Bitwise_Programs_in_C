#include<stdio.h>
#include<stdbool.h>

//Checking if bit is set
bool isBitSet(int num,int bitposition){
    return (num & (1<<bitposition)) != 0;
}

//Setting a bit
int setBit(int num,int bitPosition){
    return num | (1<<bitPosition);
}

//Clearing a bit
int clearingBit(int num,int bitPosition){
    return num & ~(1<<bitPosition);
}

//toggling a bit
int toggleBit(int num,int bitPosition){
    return num ^ (1 << bitPosition);
}

int main(void)
{
    int num = 0x55;

    if(isBitSet(num,2))
    {
        printf("BitSet : TRUE\n");
    }
    else{
        printf("BitSet : FALSE\n");
    }

    num = setBit(num,1);

    printf("Set bit value = %x\n",num);

    num = clearingBit(num,1);

    printf("clear bit value = %x\n",num);

    num = toggleBit(num,1);

    printf("toggeld value = %x\n",num);    

    num = toggleBit(num,1);

    printf("toggled value = %x\n",num);  

    return 0;
}