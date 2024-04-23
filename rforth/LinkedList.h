#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// node for a singly linked list
typedef struct LL_node {
  union { // value is a pointer to either a token_t type or AST_node type variable
    token_t* token;
    AST_node_t* node;
  } value;
  LL_node_t *next;
} LL_node_t;

typedef struct LL {
  LL_node_t *head,*tail;
} LL_t;

extern LL_node_t* LL_node_init(token_t* token,AST_node_t* node);
extern LL_t* LL_init(LL_node_t* head);
extern void LL_free(LL_node_t *head);
extern void LL_add(LL_t* list,LL_node_t* node);
extern void LL_print(LL_t* list, int indent);
##endif
