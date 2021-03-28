/* [mmn 14 : ]:
in this file: 

author: Uri K.H,   Lihi Haim       Date: 21.3.2021 
ID: 215105321,     313544165       Tutor: Danny Calfon */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "label.h"
#include "util.h"

#define LABEL_SIZE 31

/* readWord(): the function get as parameters a line and a pointer to a word in the line,
and returns the word as a string */

char *readWord(char *line, int *lInd){
     char curr;
     int size = 1;
     char *label = malloc(size);
     if(!isAlloc(label))
          return NULL;
     while((curr = line[*lInd]) != '\0' && !isspace(curr) && curr != ','){
          label = realloc(label, ++size);
          if(!isAlloc(label))
               return NULL;
          label[size-2] = curr;
          (*lInd)++;
     }
     if(size == 1)
          return "\0";
     label[size-1] = '\0';
     return label;
}

/* isLabel(): the function gets as parameters a label as a string,
and returns whether it ends with a ':' like a label or not and return true or false accordingly */

boolean isLabel(char *string){
     int i;
     for(i = 0; i < strlen(string); i++){
          if(string[i] == ':')
               return TRUE;
     }
     return FALSE;
}

/* isValidLabel(): the function gets as parameters a label as a string, it's length and a boolean indicator,
to check if the label is valid and return true or false accordingly */

boolean isValidLabel(char *label, int lineCnt, boolean optLabel){
     boolean valid = TRUE, isDec = TRUE;
     int i = 0;
     /*int runUntil = (optLabel) ? strlen(label)-1 : strlen(label);*/
     for(i = 0; i < strlen(label)-1 && !optLabel; i++){
          if(!isdigit(label[i])){
               isDec = FALSE;
               break;
          }
     }
     if(isDec && !optLabel){
          printf("error [line %d]: Did you ment to represent a decimal number as an operand?\n", lineCnt);
          printf("\t\tFor decimal numbers use the immidiate addressing method - # in the start of the decimal\n");
          valid = FALSE;
     }
     i = 0;
     if(optLabel && label[strlen(label)-1] != ':'){
          printf("error [line %d]: After the end of an optional label must come a semicolon\n", lineCnt);
          valid = FALSE; /* labbel is not valid */
     }
     if(!isalpha(label[i])){
          printf("error [line %d]: Label \"%s\" must start with an alphabetic character\n", lineCnt, label);
          valid = FALSE;
     }
     if(strlen(label) > LABEL_SIZE){
          printf("error [line %d]: The maximum label length is %d characters\n", lineCnt, LABEL_SIZE);
          valid = FALSE;
     }
     for(i = 1; i < strlen(label)-1; i++){
          if(label[i] == ':' && i != strlen(label)-1){
               printf("error [line %d]: After end of label \"%s\" must be at least one space\n", lineCnt, label);
               valid = FALSE;
               break;
          }
          if(!isalnum(label[i])){
               printf("error [line %d]: The label \"%s\" must include only alphabetical and numerical characters\n", lineCnt, label);
               valid = FALSE;
          }
     }
     if(label[strlen(label)-1] == ':')
          label[strlen(label)-1] = '\0';
     return valid;
}