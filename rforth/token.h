// token.h
#ifndef TOKEN_H
#define TOKEN_H

#include "types.h"

// find the type of the class from the string
extern token_type_t id_type(char* str);

// Function to create a new token
extern token_t* create_token(token_type_t type, char* str);

// print the token
extern void print_token(token_t* token,int indent);

// Function to free memory allocated for a token
extern void free_token(token_t* token);

//isolate and load tokens
extern token_t* get_next_token(char** line);

#endif

