#include <stdio.h>

typedef int MY_INT; //create new name for int

typedef struct Man
{
    int id;
    char name[50];
}M, * PM; 



int main(void)
{
   
   MY_INT a = 20;
   M man;
   PM pm = &man;
   return 0;
}