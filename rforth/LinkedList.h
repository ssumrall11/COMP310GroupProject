#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include "types.h"

extern LL_node_t* LL_node_init(token_t* token,struct AST_node* node);
extern LL_t* LL_init();
extern void LL_free(LL_t *head);
extern void LL_node_free(LL_node_t *head);
extern void LL_add(LL_t* list,LL_node_t* node);
//extern void LL_print(LL_t* list, int indent);

#endif
