#ifndef AST_H
#define AST_H

#include <stdio.h>
#include "token.h"
#include "astmap.h"
#include "LinkedList.h"

typedef struct AST_node {
  char* str;
  LL_t* children;
} AST_node_t;

extern AST_node_t* generate_AST(map_t* worddefs,char* str,char* triggerword){
extern void AST_process(AST_node_t* root);
extern void AST_free(AST_node_t* root);

#endif
