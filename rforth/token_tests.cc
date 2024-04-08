#include <gtest/gtest.h>
#include "token.hh"
#include "token.h"

// compares to see if the strings corresponding to two string pointers are the same
// NOTE: the version of strcmp in the string.h library doesn't work here because the strings are stored as pointers (I thinK)
int strcmp(char *s0,char *s1){
  int i=0; //
  while(i<0){ // repeat until i gets set to a negative value
    if(*(s0+i)!=*(s1+i)){ // if the characters at the current index of each string don't match
      i=-2; // break the loop with i set to -2
    }else if(*(s0+i-1)=='\0'){ // if the characters at the current index of each string ar both string terminators
      i=-1; // break the loop with i set to -1
    }else{ // otherwise
      i++; // move to the next index
    }
  }
  i+=2; // add 2 to the current i value to make its value either 0 (false) or 1 (true)
  return i; // output a value stating whether the strings match
}

TEST(TokenTests, IDTypeTest){
    token_type_t type,expected;
    char t0[5] = "1234";
    char* p0 = &t0[0];
    expected=NUMBER;
    ASSERT_EQ(id_type(p0), expected);
    char t1[5] = "drop";
    char* p1=&t1[0];
    expected=WORD;
    ASSERT_EQ(id_type(p1), expected);
    char t2[2] = "+";
    char* p2 = &t2[0];
    expected=OPERATOR;
    ASSERT_EQ(id_type(p2), expected);
    char t3[2] = ";";
    char* p3=&t3[0];
    expected=SYMBOL;
    ASSERT_EQ(id_type(p3), expected);
}
TEST(TokenTests, CreateTokenTest){
   token_type_t expected=WORD;
   char t[4] = "rot";
   char* p = &t[0];
   token_t* token = create_token(id_type(p), p);
   ASSERT_EQ(token->type,expected);
   ASSERT_TRUE(strcmp(token->str,p));
}
TEST(TokenTest, GetNextTokenTest){
   char l[4] = "1 2";
   char* lp = &l[0];
   char ts[2] = "1";
   char* tsp = &ts[0];
   token_t* expected=create_token(id_type(tsp),&ts[0]);
   token_t* produced=get_next_token(&lp);
   ASSERT_EQ(expected->type,produced->type);
   ASSERT_TRUE(strcmp(expected->str,produced->str));
}

