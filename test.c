#include <stdio.h>

int main()
{
   
   struct test
   {
       int index;
   }keyword_info[10] = {
       [0] = {123}
   };
   
   printf("%d", keyword_info[0].index);



   return 0;
}