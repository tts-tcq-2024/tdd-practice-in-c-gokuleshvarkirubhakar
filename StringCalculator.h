#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validate_inputs(const char* input) {
    return ((input_string == NULL || input_string[0] == '\0'));
}

char* duplicate_input(const char *input) {
    char *copy = (char *)malloc(strlen(input) + 1);
    if(copy != NULL) {
        strcpy(copy, input);
    }
    return copy;
}

int calculate_sum(char *token, char *delimiters)
{   
    int num = 0, sum = 0;
    while (token != NULL) {
        num = atoi(token);
        if(num <= 1000) sum += num;
        token = strtok(NULL, delimiters);
    }
    
    return sum;
}

int add(const char *input_string) {
    
    if(validate_inputs(input_string)) {
        return 0;
    }

    char delimiters[] = ",\n";
    char *input_string_copy = duplicate_input(input_string);
    if (input_string_copy == NULL) {
        return 0;
    }
    
    char *token = strtok(input_string_copy, delimiters);
    int sum = calculate_sum(token, delimiters);

    free(input_string_copy);
    return sum; 
}
