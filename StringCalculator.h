#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(const char *input_string)
{
   if (input_string == NULL || input_string[0] == '\0') {
        return 0; // The string is empty
   }
    
   char *input_string_copy = (char *)malloc(strlen(input_string) + 1);
   if(input_string_copy != NULL)
   {
       strcpy(input_string_copy, input_string);
   }

   char delimiters[] = ",\n";
   char *token;
   int sum = 0;
   
   token = strtok(input_string_copy, delimiters);
    
    // Walk through other tokens
    while (token != NULL) {
        int num = atoi(token);
        sum += num;
        token = strtok(NULL, delimiters);
    }
   
   return sum; 
}
