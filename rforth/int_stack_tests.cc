#include <gtest/gtest.h>
#include "int_stack.hh"

TEST(IntStackTests, Initialization)
{
    int_stack_t stack1;
    int_stack_init(&stack1, 10);
    ASSERT_EQ(stack1.size, 0);
    ASSERT_EQ(stack1.capacity, 10);
}

TEST(IntStackTests, PushToCapacityAndOverflow)
{
    // create stack that can hold 10 items
    int_stack_t stack1;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);

    // fill it
    for (int i=0; i < capacity; i++) {
        int result = int_stack_push(&stack1, i);
        ASSERT_TRUE(result);
    }

    // ensure it's full
    ASSERT_EQ(stack1.size, capacity);

    // try to add one more
    int result = int_stack_push(&stack1, capacity+1);

    // and make sure it is an overflow (error)
    ASSERT_FALSE(result);
}

TEST(IntStackTests, PushToCapcacityPopUntilUnderflow)
{
    // create stack that can hold 10 items [similar to previous test]
    int_stack_t stack1;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);

    // fill it
    for (int i=0; i < capacity; i++) {
        int result = int_stack_push(&stack1, i);
        ASSERT_TRUE(result);
    }

    // now drain it one item at a time, ensuring each item is the value expected
    for (int i=capacity-1; i >= 0; i--) {
        int top_value;
        int result = int_stack_pop(&stack1, &top_value);
        ASSERT_EQ(i, top_value);
    }

    // try to remove from empty stack and ensure it fails
    int top_value;
    int result = int_stack_pop(&stack1, &top_value);
    ASSERT_FALSE(result);
}
/*
TEST(IntStackTests, TestIfThen){
   int_stack_t stack1;
   int top_value, next_to_top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 11);
   int_stack_if_then(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 101);
   int_stack_push(&stack1, 11);
   int_stack_if_then(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestIfElseThen){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 11);
   int_stack_if_else_then(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 12);
   int_stack_if_else_then(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(0, top_value);
}*/
/*TEST(IntStackTests, TestDoLoop){
   int_stack_t stack1;
   int top_value, next_to_top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 7);
   int_stack_push(&stack1, 0);
   int_stack_do_loop(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_EQ(0, top_value);
   ASSERT_EQ(7, next_to_top_value);
   int_stack_push(&stack1, 7);
   int_stack_push(&stack1, 10);
   int_stack_do_loop(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_EQ(0, top_value);
}*/

TEST(IntStackTests, TestEquals){
   int_stack_t stack1;
   int top_value, next_to_top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 64);
   int_stack_push(&stack1, 64);
   int_stack_equal(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 73);
   int_stack_push(&stack1, 33);
   int_stack_equal(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestLessThan){
   int_stack_t stack1;
   int top_value, next_to_top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 5);
   int_stack_push(&stack1, 2);
   int_stack_less(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 5);
   int_stack_push(&stack1, 12);
   int_stack_less(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(-1, top_value);
}
TEST(IntStackTests, TestGreaterThan){
   int_stack_t stack1;
   int top_value, next_to_top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 5);
   int_stack_push(&stack1, 22);
   int_stack_greater(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 50);
   int_stack_push(&stack1, 12);
   int_stack_greater(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(-1, top_value);
}
TEST(IntStackTests, TestInvert){
   int_stack_t stack1;
   int top_value, next_to_top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 5);
   int_stack_invert(&stack1);
   int_stack_push(&stack1, 0);
   int_stack_invert(&stack1);
   int_stack_push(&stack1, -1);
   int_stack_invert(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(0, top_value);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(-1, top_value);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(-6, top_value);
}
TEST(IntStackTests,TestOr){
   int_stack_t stack1;
   int top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 0);
   int_stack_push(&stack1, 0);
   ASSERT_TRUE(int_stack_or(&stack1));
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(0, top_value);
   ASSERT_FALSE(int_stack_pop(&stack1, &top_value));
   int_stack_push(&stack1, 0);
   int_stack_push(&stack1, -1);
   ASSERT_TRUE(int_stack_or(&stack1));
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(-1, top_value);
   ASSERT_FALSE(int_stack_pop(&stack1, &top_value));
   int_stack_push(&stack1, -1);
   int_stack_push(&stack1, 0);
   ASSERT_TRUE(int_stack_or(&stack1));
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(-1, top_value);
   ASSERT_FALSE(int_stack_pop(&stack1, &top_value));
   int_stack_push(&stack1, -1);
   int_stack_push(&stack1, -1);
   ASSERT_TRUE(int_stack_or(&stack1));
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(-1, top_value);
   ASSERT_FALSE(int_stack_pop(&stack1, &top_value));
}
TEST(IntStackTests, TestAnd){
   int_stack_t stack1;
   int top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 0);
   int_stack_push(&stack1, 0);
   ASSERT_TRUE(int_stack_and(&stack1));
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(0, top_value);
   ASSERT_FALSE(int_stack_pop(&stack1, &top_value));
   int_stack_push(&stack1, 0);
   int_stack_push(&stack1, -1);
   ASSERT_TRUE(int_stack_and(&stack1));
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(0, top_value);
   ASSERT_FALSE(int_stack_pop(&stack1, &top_value));
   int_stack_push(&stack1, -1);
   int_stack_push(&stack1, 0);
   ASSERT_TRUE(int_stack_and(&stack1));
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(0, top_value);
   ASSERT_FALSE(int_stack_pop(&stack1, &top_value));
   int_stack_push(&stack1, -1);
   int_stack_push(&stack1, -1);
   ASSERT_TRUE(int_stack_and(&stack1));
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(-1, top_value);
   ASSERT_FALSE(int_stack_pop(&stack1, &top_value));
}
TEST(IntStackTests, TestDup){
    int_stack_t stack1;
    int top_value;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);
    int_stack_push(&stack1, 56);
    int_stack_dup(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
    ASSERT_EQ(56, top_value);
}
TEST(IntStackTests, TestSwap){
    int_stack_t stack1;
    int top_value;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);
    int_stack_push(&stack1, 11);
    int_stack_push(&stack1, 3);
    int_stack_swap(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
    ASSERT_EQ(11, top_value);
}
TEST(IntStackTests, TestOver){
    int_stack_t stack1;
    int top_value;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);
    int_stack_push(&stack1, 83);
    int_stack_push(&stack1, 4);
    int_stack_over(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
    ASSERT_EQ(83, top_value);
}
TEST(IntStackTests, TestROT){
    int_stack_t stack1;
    int top_value, next_to_top_value;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);
    int_stack_push(&stack1, 4);
    int_stack_push(&stack1, 6);
    int_stack_push(&stack1, 8);
    int_stack_rot(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
    ASSERT_EQ(4, top_value);
    ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
    ASSERT_EQ(8, next_to_top_value);
    ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
    ASSERT_EQ(6, next_to_top_value);
}
TEST(IntStackTests, TestDrop){
    int_stack_t stack1;
    int top_value, next_to_top_value;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);
    int_stack_push(&stack1, 66);
    int_stack_push(&stack1, 77);
    int_stack_push(&stack1, 88);
    int_stack_push(&stack1, 99);
    int_stack_drop(&stack1);
    int_stack_drop(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
    ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
    ASSERT_EQ(77, top_value);
    ASSERT_EQ(66, next_to_top_value);
}
TEST(IntStackTests, TestDupTwo){
    int_stack_t stack1;
    int top_value, next_to_top_value;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);
    int_stack_push(&stack1, 7);
    int_stack_push(&stack1, 6);
    int_stack_2dup(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
    ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
    ASSERT_EQ(6, top_value);
    ASSERT_EQ(7, next_to_top_value);
    int_stack_push(&stack1, 10);
    int_stack_push(&stack1, 9);
    int_stack_2dup(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
    ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
    ASSERT_EQ(9, top_value);
    ASSERT_EQ(10, next_to_top_value);
}
TEST(IntStackTests, TestSwapTwo){// fix this one later
    int_stack_t stack1;
    int top_value, next_to_top_value;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);
    int_stack_push(&stack1, 3);
    int_stack_push(&stack1, 6);
    int_stack_push(&stack1, 9);
    int_stack_push(&stack1, 12);
    int_stack_2swap(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
    ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
    ASSERT_EQ(6, top_value);
    ASSERT_EQ(3, next_to_top_value);
}
TEST(IntStackTests, TestOverTwo){
    int_stack_t stack1;
    int top_value, next_to_top_value;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);
    int_stack_push(&stack1, 15);
    int_stack_push(&stack1, 16);
    int_stack_push(&stack1, 17);
    int_stack_push(&stack1, 18);
    int_stack_2over(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
    ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
    ASSERT_EQ(16, top_value);
    ASSERT_EQ(15, next_to_top_value);
}
TEST(IntStackTests, TestDropTwo){
    int_stack_t stack1;
    int top_value;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);
    int_stack_push(&stack1, 88);
    int_stack_push(&stack1, 77);
    int_stack_push(&stack1, 11);
    int_stack_2drop(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
    ASSERT_EQ(88, top_value);
}
TEST(IntStackTests, TestAddition){
    int_stack_t stack1;
    int top_value;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);
    int_stack_push(&stack1, 7);
    int_stack_push(&stack1, 3);
    int_stack_add(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
    ASSERT_EQ(10, top_value);
    ASSERT_FALSE(int_stack_pop(&stack1, &top_value));
}
TEST(IntStackTests, TestSubtraction){
    int_stack_t stack1;
    int top_value;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);
    int_stack_push(&stack1, 17);
    int_stack_push(&stack1, 8);
    int_stack_subtract(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
    ASSERT_EQ(9, top_value);
    ASSERT_FALSE(int_stack_pop(&stack1, &top_value));
}
TEST(IntStackTests, TestMultiplication){
   int_stack_t stack1;
   int top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 10);
   int_stack_push(&stack1, 25);
   int_stack_multiply(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(250, top_value);
   ASSERT_FALSE(int_stack_pop(&stack1, &top_value));
}
TEST(IntStackTests, TestDivision){
   int_stack_t stack1;
   int top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 15);
   int_stack_push(&stack1, 5);
   int_stack_divide(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(3, top_value);
   ASSERT_FALSE(int_stack_pop(&stack1, &top_value));
}
TEST(IntStackTests, TestModulos){//note: this test tests both modulo versions!
   int_stack_t stack1;
   int top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 122);
   int_stack_push(&stack1, 13);
   int_stack_mod(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(5, top_value);
   ASSERT_FALSE(int_stack_pop(&stack1, &top_value));
}
TEST(IntStackTests, TestDivisionModulos){//note: this test tests both modulo versions!
   int_stack_t stack1;
   int top_value, next_to_top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 122);
   int_stack_push(&stack1, 13);
   int_stack_dividemod(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(9, top_value);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(5, top_value);
   ASSERT_FALSE(int_stack_pop(&stack1, &top_value));
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
