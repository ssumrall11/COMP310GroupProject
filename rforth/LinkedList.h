#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include "ast.h"
#include "token.h"

// node for a singly linked list
typedef struct LL_node {
  union { // value is a pointer to either a token_t type or AST_node type variable
    token_t* token;
    struct AST_node* node;
  } value;
  struct LL_node *next;
} LL_node_t;

typedef struct LL {
  LL_node_t *head,*tail;
} LL_t;

extern LL_node_t* LL_node_init(token_t* token,struct AST_node* node);
extern LL_t* LL_init();
extern void LL_free(LL_t *head);
extern void LL_node_free(LL_node_t *head);
extern void LL_add(LL_t* list,LL_node_t* node);
extern void LL_print(LL_t* list, int indent);

#endif
