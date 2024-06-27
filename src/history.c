#ifndef _HISTORY_
#define _HISTORY_
#include "history.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;
 
/* Initialize the linked list to keep the history. */
List* init_history(){
  List* list=(List*)malloc(sizeof(List*));
  list-> root=NULL;
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *addedItem=list->root;
  int idnum=1;
  while(addedItem!=NULL){
    addedItem=addedItem->next;
    idnum++;
  }
   addedItem=(Item*)malloc(sizeof(Item));
   addedItem->id=idnum;
   addedItem->str=str;
   addedItem->next=NULL;
}
  

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  if(list->root==NULL){
    return '\0';
  }
  else{
    Item *lookingid=list->root;
    while(lookingid!=NULL){
      if(lookingid->id==id){
	return lookingid->str;
      }
      lookingid=lookingid->next;
    }
    return '\0';
  }
}

/*Print the entire contents of the list. */
void print_history(List *list){
  if(list->root==NULL){
     printf("Your history is empty");
  }
  else{
    Item *printed=list->root;
    while(printed){
      printf("%d: %s\n", printed->id, printed->str);
      printed=printed->next;
    }
  }
   
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *currentfree=list->root;
  while(currentfree!=NULL){
    free(currentfree);
    currentfree->next;
  }
  free(list);
}

#endif
