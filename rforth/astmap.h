#ifndef ASTMAP_H
#define ASTMAP_H

#include <stdio.h>
#include "ast.h"

typedef struct map_node {
  char* word;
  AST_node_t* def;
} map_node_t; // hash node

typedef struct map {
  map_node_t *head;
  int capacity,size;
} map_t ; // hash map

extern void map_init(map_t *map,int capacity);
extern void map_print(map_t *map);
//extern void map_delete(map* head_ptr);
extern int map_put(map_t *map,char *word,char *def);
extern int map_containsKey(map_t *map,char *key);
extern AST_node_t* map_get(map_t *map,char *key);
extern int hash(int capacity,char *word);

#endif