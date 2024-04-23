// token.h
#ifndef TOKEN_H
#define TOKEN_H

// Enum to represent different token types
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

