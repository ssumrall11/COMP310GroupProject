#include <gtest/gtest.h>
#include <string.h>
#include "token.hh"


TEST(TokenTests, IDTypeTest){
    token_type_t type; 
    char* t = "1234";
    ASSERT_EQ(id_type(t), "NUMBER"); 
    char* tt = "+";
    ASSERT_EQ(id_type(tt), "OPERATOR");
    char* ttt = ";";
    ASSERT_EQ(id_type(ttt), "SYMBOL");
    char* tttt = "drop"; 
    ASSERT_EQ(id_type(tttt), "WORD");
}
TEST(TokenTests, CreateTokenTest){
   token_type_t type = 4;
   char* p = "rot";
   token_t* token = create_token(type, p);
   ASSERT_EQ(token->type,type);
   ASSERT_EQ(strcmp(token->str,*p)); 
}
TEST(TokenTest, GetNextTokenTest){
   token_type_t type=1;
   char* l = "1 2";
   char* ts="1";
   token_t* token=create_token(type,ts);
   ASSERT_EQ(*get_next_token(&l),*token); 
}

