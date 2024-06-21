#include "stdio.h"
#include <stdlib.h>
#include "tokenizer.h"

int main(){
 
  while(1){
   printf("Welcome to the tokenizer press q to exit\n");
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
   printf("%s\n", token);
   printf("%d\n", count_tokens(token));
   printf("%s\n", copy_str(token, 256));
    switch(str[0]){
    case 'q':
      switch(str[1]){
	case '\0':
	  printf("Bye thanks for using the tokenizer!!\n");
	  return 0;
	  break;
      }
      break;
    default:
     break;
   }
  }
  return 0; 
}
