#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
  printf("Checking the parentheses in argv arguments\n");
  int i,N,j;
  char out;
  int check = 0;
  Stack s;
  s.size = 0;
  s.top = NULL;

 
  for(i=1;i<argc;i++){
   
     for(j=0;j<strlen(argv[i]);j++){//loop นี้จบตรงไหน
       /* Use stack to help with the parentheses*/
      if(argv[i][j] == '{' || argv[i][j] == '['){
         push(&s,argv[i][j]);
         s.size +=1;
         }
      if(argv[i][j] == '}'){
        out = pop(&s);
        s.size -= 1;
        if(out != '{'){check = 1;break;
        }
      }
      if(argv[i][j] == ']'){
        out = pop(&s);
        s.size -= 1;
        if(out != '['){check = 1; break;
        }
      }
     }
     if(s.size>0 ||  check == 1){
       pop_all(&s);
       printf("The parentheses does not match successfully in %s\n", argv[i]);
     }
     else{printf("The parentheses match successfull in %s\n",argv[i]);}
     check = 0;
}return 0;
}