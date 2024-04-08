#include <stdlib.h>
#include "LinkedList.h"
#include "token.h"
#include "ast.h"


// create a new entry for the linked list
LL_node_t* LL_node_init(token_t* token,AST_node_t* node){
  if((token!=NULL)==(node!=NULL)){ // one and only one of these can be filled
    abort();
  }
  LL_node_t* newNode=(LL_node_t*)malloc(sizeof(LL_node_t));
  newNode->value.token=token;
  newNode->value.node=node;
  newNode->last=NULL;
  newNode->next=NULL;
  return newNode;
}

// create a linked list
LL_t* LL_init(){
  LL_t* list=(LL_t*)malloc(sizeof(LL_t));
  list->head=NULL;
  list->tail=NULL;
  return list;
}

// delete the entire list (might have errors)
void LL_free(LL_node_t *head){
  if(head->next!=null){
    LL_delete(head->next);
  }
  free(head->value); // this may not work because I created both possible variable types myself
  free(head->next); // almost certainly is redundant
  free(head);
}

// adds a node to the tail end of the list
void LL_add(LL_t* list,LL_node_t* node){
  if(list->head==NULL){
    list->head=node;
  }else{
    list->tail->next=node;
  }
  list->tail=node;
}