#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "token.h"
#include "astmap.h"

// generate an abstract syntax tree given a line of forth code
AST_node_t* generate_AST(map_t* worddefs,char* str,char* triggerword){
  // create the AST node and assign the basic fields
  AST_node_t* node=(AST_node_t*)malloc(sizeof(AST_node_t));
  node->str=triggerword;
  node->children=LL_init();
  // what word to is needed to end the function
  char* breakword;
  if(strcmp(triggerword,"if")){
    breakword="then"; // how do i handle else
  }else if(strcmp(triggerword,"do")){
    breakword="loop";
  }else if(strcmp(triggerword,"begin")){
    breakword="until";
  }
  // fill the children linked list
  token_t* token=get_next_token(str);
  while(strcmp(token->str,breakword)){
    if(token->type!=4){ // or default word
      LL_node_t* child=LL_node_init(token,NULL);
      LL_add(node->children,child);
    }else{
      if(wordmap_containsKey(worddefs,token->str){ // user defined word (already defined)
        AST_node_t* sub=wordmap_get(worddefs,token->str);
        LL_node_t* sib=LL_node_init(NULL,sub);
        LL_add(node->children,sib);
      }else if(strcmp(token->str,"if") || strcmp(token->str,"do") || strcmp(token->str,"begin")){ // 'if' 'do' and 'until'
        node->children=LL_init(); // initialize the linked list to hold the children
        char* keyword=strdup(token->str); // specifies the word that starts the new recursion (triggerword for the recursive call)
        AST_node_t* sub=AST_init(worddefs,char* str,keyword); // recursive call
        LL_node_t* child=LL_node_init(NULL,sub);
        LL_add(node->children,child);
      }//else{ (a word that is currently being defined or an error)
    }
    token=get_next_token(str);
  }
  return node;
}

void process_AST(AST_node_t* root){}

void free_AST(AST_node_t* root){
  //(added children_len field to AST_node to replace this) use root.token to determine the size of root.children?
  free_token(root.token);
  for(int i=0; i<root->children_len; i++){
    free_AST((root.children+i));
  }
}

