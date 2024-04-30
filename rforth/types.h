#ifndef TYPES_H
#define TYPES_H

#include <sys/queue.h>

typedef enum {
  NUMBER=1,
  OPERATOR=2,
  SYMBOL=3,
  WORD=4
} token_type_t;

// Struct to represent a token
typedef struct {
    token_type_t type;
    char* str;
} token_t;

typedef struct int_entry {
  int value;
  SLIST_ENTRY(int_entry) entries;
} int_entry_t;

typedef struct int_stack {
  SLIST_HEAD(stackhead,int_entry) head;
  int size;
  int capacity;
} int_stack_t;

typedef struct AST_node {
  char* str;
  struct LL* children;
} AST_node_t;

typedef struct map_node {
  char* word;
  AST_node_t* def;
} map_node_t; // hash node

typedef struct map {
  map_node_t *head;
  int capacity,size;
} map_t; // hash map

typedef struct LL_node {
  union { // value is a pointer to either a token_t type or AST_node type variable
    token_t* token;
    AST_node_t* node;
  } value;
  struct LL_node* next;
} LL_node_t;

typedef struct LL {
  struct LL_node *head,*tail;
} LL_t;

#endif