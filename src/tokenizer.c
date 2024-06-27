#ifndef _TOKENIZER_
#define _TOKENIZER_
#include "stdio.h"
#include <stdlib.h>
#include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c==' ' || c=='\t'){
    return 1;
  }
  else if(c=='\0'){
    return 0;
  }
  else{
    return 0;
  }
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  return(c!=' ' && c!='\t' && c!='\0');
}
/* 
Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
  if (str==NULL){
    return NULL;
  }
  while(space_char(*str)){
      str++;
  }
  return str;
} 

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
  if(token==NULL){
    return NULL;
  }
  while(non_space_char(*token)){
    token++;
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
 int count=0;
 while(*str!='\0'){
   if(non_space_char(*str)){
     count++;
     str=token_terminator(str);
     str=token_start(str);
   }
   else{
     str++;
   }
 }
 return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *newStr=malloc(len* sizeof(char));
  for(char i=0; i<len; i++){
    newStr[i]=inStr[i];
    if(inStr[i]=='\0'){
      return newStr;
    }
  }
  return newStr;
}

int leng(char* str){
  int len=0;
  while(non_space_char(*str)){
    len++;
    str++;
  }
  return len;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  int count=count_tokens(str);
  char **tokens=(char **)malloc((count+1)*sizeof(char*));
  for(int i=0; i<count; i++){
    int len=leng(str);
    tokens[i]=copy_str(str,len);
    str=token_terminator(str);
    str=token_start(str);
  }
  tokens[count]='\0';
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  int i=0;
  while(tokens[i]){
    printf("%d.%s\n", i+1, tokens[i]);
    i++;
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  int i=0;
  while(tokens[i]){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}

#endif
