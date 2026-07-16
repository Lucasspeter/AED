#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid (char * s ) {
    char pilha[strlen(s)];
    int top = -1;
    
    for ( int i = 0; s[i] != '\0'; i++ ) {
        if  ( s[i] == '(' || s[i] == '{' || s[i] == '[' ) {
            pilha[++top] = s[i]; 
        } else {
            if ( top == -1 || 
               ( s[i] == ')' && pilha[top] != '(' ) || 
               ( s[i] == '}' && pilha[top] != '{' ) || 
               ( s[i] == ']' && pilha[top] != '[' ) ) {
                
                return false; 
            }
            top--; 
        }
    }
    return top == -1; 
}