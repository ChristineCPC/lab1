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
    int maxLen = 100;
    char* memory;
    //char str[i];
    //char* buffer[i]; //99 characters + NULL
    memory = (char*)malloc(maxLen*sizeof(char)); //allocates 99 characters + NULL

    //opens up file and reads it
    fptr = fopen(fileName, "r");

    if (fptr == NULL)
    {
        perror("Cant open file");
        return NULL;
    }

    //copies file contents to memory
    fread(memory, sizeof(char), maxLen, fptr);
    
    memory[maxLen] = '\0'; //last element will be NULL
    //fclose(fptr);
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

    
    int maxLen = 100;
    char* explodedText = (char*)malloc(maxLen*sizeof(char));
    //char* currentText = (char*)malloc(maxLen*sizeof(char));
    int count;
    //int currentSize = 2;

    for(int i = 0; i < strlen(str); i++)
    {   
        char* currentText = (char*)malloc(maxLen*sizeof(char));
        strncpy(currentText, str, i);
        strcat(explodedText, currentText);
    }

/*
    for(int i = 0; i < strlen(str); i++)
    {
        char* currentText = (char*)malloc(currentSize*sizeof(char));
        if(str[i] != (NULL || '\0'))
        {
            for(int j = 0; j <= i; j++)
            {
                //char currentChar = str[j];
                strcat(currentText, str);
            }
        }

        strcat(explodedText, currentText);
        free(currentText);
        currentSize++;
    }
    */

    //explodedText[maxLen] = '\0';
    return explodedText;
}