#include<stdio.h>
#include <string.h>

int main() {
   char string1[50] = "my_name_is_edcast_future_skills";
   char string2[50] = "this is a trial test";
   char * substring1 = strtok(string1, "_");
   while(substring1 != NULL)
   {
    printf( " %s\n", substring1 );
    substring1 = strtok(NULL,"_");
   }
   printf("\n");
    char * substring2 = strtok(string2, " ");
   while(substring2 != NULL)
   {
    printf( " %s\n", substring2 );
    substring2 = strtok(NULL," ");
   }
   return 0;
}
