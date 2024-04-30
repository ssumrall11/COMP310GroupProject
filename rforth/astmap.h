#ifndef ASTMAP_H
#define ASTMAP_H

#include <stdio.h>
#include "types.h"

extern void map_init(map_t *map,int capacity);
extern void map_print(map_t *map);
//extern void map_delete(map* head_ptr);
extern int map_put(map_t *map,char *word,AST_node_t *def);
extern int map_containsKey(map_t *map,char *key);
extern AST_node_t* map_get(map_t *map,char *key);
extern int hash(int capacity,char *word);

#endif