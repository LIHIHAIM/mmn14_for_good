/* [mmn 14 : ]:
in this file: 

author: Uri K.H,   Lihi Haim       Date: 21.3.2021 
ID: 215105321,     313544165       Tutor: Danny Calfon */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "line.h"
#include "util.h"
#include "label.h"

#define MAX_DIR_COM_LEN 8 /* maximum length of a directive command */ 
#define DIR_COMS 4 /* the directive commands */

/* getDirCom(): the function get as parameters a line and a pointer to a word in the line and it's length,
 and returns which directive commands it is by it's identification number */
int getDirCom(char *command, int lineCnt, boolean printErr){
     char dirCommands[DIR_COMS][MAX_DIR_COM_LEN] =  {".data", ".string", ".entry", ".extern"}; /* the directive commands */
     int i;
     for(i = 0; i < DIR_COMS; i++){
          if(strcmp(command, dirCommands[i]) == 0)
               return i;
     }
     if(printErr){
          printf("error [line %d]: directive command \"%s\" is not valid.\n", lineCnt, command);
          printf("\t\t Command must be: %s / %s / %s / %s\n",dirCommands[data],dirCommands[string],dirCommands[entry],dirCommands[external]);
     }
     return -1;
}