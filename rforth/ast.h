#ifndef AST_H
#define AST_H

#include <stdio.h>
#include "types.h"
#include "token.h"
#include "int_stack.h"
#include "LinkedList.h"
#include "astmap.h"

extern AST_node_t* generate_AST(map_t* worddefs,char** toStr,char* triggerword);
extern void AST_process(AST_node_t* root,int_stack_t* stack,map_t* words);
extern void AST_free(AST_node_t* root);
//extern void AST_print(AST_node_t* root,int indent);

#endif
