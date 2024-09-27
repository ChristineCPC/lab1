#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"
/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 * 
 * fileName is c-string representing the file to read.
 * 
 */
char* readString(char* fileName){
    //TODO: Replace this line with your code
    FILE* fptr;
    int maxLen = 99;
    char* memory;
    memory = (char*)malloc(maxLen*sizeof(char)); //allocates 99 characters + NULL
    
    //opens up file and reads it
    fptr = fopen(fileName, "r");

    if (fptr == NULL)
    {
        perror("Cant open file");
        return NULL;
    }

    fgets(memory, maxLen, fptr);
    
    char *ch = strchr(memory, '\n');

    if(ch)
    {
        *ch ='\0'; //last element will be NULL
    }

    return memory;

}

/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 * 
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 * 
 */
char* mysteryExplode(const char* str){
    //TODO: Replace this line with your code

    
    int maxLen = 99;
    char* explodedText = (char*)malloc(maxLen*sizeof(char));

    for(int i = 0; i < strlen(str)+1; i++)
    {   
        char* currentText = (char*)malloc(maxLen*sizeof(char));
        strncpy(currentText, str, i); //copies parts of str to currentText
        strcat(explodedText, currentText);
    }

    return explodedText;
}