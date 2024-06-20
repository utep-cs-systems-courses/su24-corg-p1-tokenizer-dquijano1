#include "stdio.h"
#include <stdlib.h>
#include "tokenizer.c"

int main(){
  printf("Welcome to the tokenizer press q to exit\n");
  while(1){
   char str[256];
   printf("$ ");
   fgets(str,sizeof(str), stdin);
   for(int i=0; i<sizeof(str); i++){
     if(str[i]=='\n'){
       str[i]='\0';
       break;
     }  
   }
   char* token=token_start(str);
   count_tokens(token);
    switch(str[0]){
    case 'q':
     printf("Bye thanks for using the tokenizer!!\n");
     return 0;
    default:
     break;
   }
  }
  return 0; 
}
