#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int check_num_validity(int num) { 
    if (num < 0) {
        printf("Error: Negative number in input: %d\n", num);
        return 0;
    }
    else if (num > 1000) {
        return 0;
    }
    else {
        return 1;
    }
}

int calculate_sum(char *token, char *delimiters) {   
    int num = 0, sum = 0;
    while (token != NULL) {
        num = atoi(token);
        if(check_num_validity(num)) {
            sum += num;
        }       
        token = strtok(NULL, delimiters);
    }
    return sum;
}

void check_for_custom_delimiters(char *mod_input, char *delimiters, int *offset) {
    if(strncmp(mod_input, "//", 2) == 0) {
        delimiters[0] = mod_input[2];
        *offset = 4;
    }    
}

int add(const char *input_string) {   
    if((input_string == NULL || input_string[0] == '\0')) {
        return 0;
    }
    
    char delimiters[] = ",\n";
    char *mod_input = strdup(input_string);
    int offset = 0;
    
    check_for_custom_delimiters(mod_input, delimiters, &offset);
    
    char *token = strtok(mod_input+offset, delimiters);
    int sum = calculate_sum(token, delimiters);

    free(mod_input);

    return sum; 
}
