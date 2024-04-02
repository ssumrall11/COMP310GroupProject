//
// Created by George Thiruvathukal on 2/17/24.
// Additions made by Sarah Sumrall

#include <gtest/gtest.h>

#include "intstack.hh"

TEST(IntStackTests, Initialization)
{
    int_stack_t stack1;
    int_stack_init(&stack1, 10);
    ASSERT_EQ(int_stack_size(&stack1), 0);
    ASSERT_EQ(int_stack_capacity(&stack1), 10);
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
    ASSERT_EQ(int_stack_size(&stack1), capacity);

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
}/*
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
TEST(IntStackTests, TestVariable){
   int_stack_t stack1;
   int top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 44);
   int_stack_variable(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(44, top_value);
}
TEST(IntStackTests, TestConstant){
   int_stack_t stack1;
   int top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 16);
   int_stack_constant(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_EQ(16, top_value);

}
TEST(IntStackTests, TestEquals){
   int_stack_t stack1;
   int top_value, next_to_top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 64);
   int_stack_push(&stack1, 64);
   int_stack_equals(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
  //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 73);
   int_stack_push(&stack1, 33);
   int_stack_equals(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestLessThan){
   int_stack_t stack1;
   int top_value, next_to_top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 5);
   int_stack_push(&stack1, 2);
   int_stack_less_than(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 5);
   int_stack_push(&stack1, 12);
   int_stack_less_than(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestGreaterThan){
   int_stack_t stack1;
   int top_value, next_to_top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 5);
   int_stack_push(&stack1, 22);
   int_stack_greater_than(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 50);
   int_stack_push(&stack1, 12);
   int_stack_greater_than(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestInvertEquals){
   int_stack_t stack1;
   int top_value, next_to_top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 68);
   int_stack_push(&stack1, 121);
   int_stack_invert_one(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 21);
   int_stack_push(&stack1, 21);
   int_stack_invert_one(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestInvertLessThan){
   int_stack_t stack1;
   int top_value, next_to_top_value;
   const int capacity = 10;  
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 77);
   int_stack_push(&stack1, 70);
   int_stack_invert_two(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 170);
   int_stack_push(&stack1, 900);
   int_stack_invert_two(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_EQ(-0, top_value);
}
TEST(IntStackTests, TestInvertGreaterThan){
   int_stack_t stack1;
   int top_value, next_to_top_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 10);
   int_stack_push(&stack1, 20);
   int_stack_invert_three(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 100);
   int_stack_push(&stack1, 20);
   int_stack_invert_three(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_EQ(0, top_value);
}
/*TEST(IntStackTests, TestOr){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 10);
   int_stack_push(&stack1, 20);
   int_stack_push(&stack1, 18);
   int_stack_push(&stack1, 28);
   int_stack_or(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
}*/
TEST(IntStackTests,TestOrBothLessThan){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 10);
   int_stack_push(&stack1, 20);
   int_stack_push(&stack1, 18);
   int_stack_push(&stack1, 28);
   int_stack_or_one(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 100);
   int_stack_push(&stack1, 20);
   int_stack_push(&stack1, 18);
   int_stack_push(&stack1, 28);
   int_stack_or_one(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 10);
   int_stack_push(&stack1, 20);
   int_stack_push(&stack1, 38);
   int_stack_push(&stack1, 28);
   int_stack_or_one(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 100);
   int_stack_push(&stack1, 20);
   int_stack_push(&stack1, 198);
   int_stack_push(&stack1, 28);
   int_stack_or_one(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestOrBothGreaterThan){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 15);
   int_stack_push(&stack1, 3);
   int_stack_push(&stack1, 28);
   int_stack_push(&stack1, 2);
   int_stack_or_two(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 10);
   int_stack_push(&stack1, 20);
   int_stack_push(&stack1, 30);
   int_stack_push(&stack1, 28);
   int_stack_or_two(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 100);
   int_stack_push(&stack1, 20);
   int_stack_push(&stack1, 8);
   int_stack_push(&stack1, 28);
   int_stack_or_two(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   // ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   // ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   // ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 5);
   int_stack_push(&stack1, 20);
   int_stack_push(&stack1, 14);
   int_stack_push(&stack1, 28);
   int_stack_or_two(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestOrBothEquals){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 15);
   int_stack_push(&stack1, 15);
   int_stack_push(&stack1, 28);
   int_stack_push(&stack1, 28);
   int_stack_or_three(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 15);
   int_stack_push(&stack1, 15);
   int_stack_push(&stack1, 8);
   int_stack_push(&stack1, 28);
   int_stack_or_three(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 5);
   int_stack_push(&stack1, 15);
   int_stack_push(&stack1, 28);
   int_stack_push(&stack1, 28);
   int_stack_or_three(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
/*   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 2);
   int_stack_push(&stack1, 3);
   int_stack_push(&stack1, -9);
   int_stack_or_three(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);*/
}
TEST(IntStackTests, TestLessOrGreaterThan){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 3);
   int_stack_push(&stack1, 5);
   int_stack_push(&stack1, 20);
   int_stack_push(&stack1, 10);
   int_stack_or_four(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 15);
   int_stack_push(&stack1, 3);
   int_stack_push(&stack1, 30);
   int_stack_push(&stack1, 22);
   int_stack_or_four(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 5);
   int_stack_push(&stack1, 15);
   int_stack_push(&stack1, 28);
   int_stack_push(&stack1, 32);
   int_stack_or_four(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 2);
   int_stack_push(&stack1, 3);
   int_stack_push(&stack1, 19);
   int_stack_or_four(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestGreaterOrLessThan){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 5);
   int_stack_push(&stack1, 2);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 20);
   int_stack_or_five(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 3);
   int_stack_push(&stack1, 3);
   int_stack_push(&stack1, 22);
   int_stack_or_five(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 15);
   int_stack_push(&stack1, 5);
   int_stack_push(&stack1, 38);
   int_stack_push(&stack1, 32);
   int_stack_or_five(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 2);
   int_stack_push(&stack1, 39);
   int_stack_push(&stack1, 19);
   int_stack_or_five(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   ///ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestEqualsOrLessThan){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 2);
   int_stack_push(&stack1, 9);
   int_stack_or_six(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 3);
   int_stack_push(&stack1, 2);
   int_stack_push(&stack1, 9);
   int_stack_or_six(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 9);
   int_stack_push(&stack1, 2);
   int_stack_or_six(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   /*int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 2);
   int_stack_push(&stack1, 9);
   int_stack_push(&stack1, 2);
   int_stack_or_six(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);*/
}
TEST(IntStackTests, TestEqualsOrGreaterThan){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 9);
   int_stack_or_seven(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 3);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 9);
   int_stack_or_seven(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 2);
   int_stack_or_seven(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   /*int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 101);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 2);
   int_stack_or_seven(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);*/
}
TEST(IntStackTests, TestLessThanOrEquals){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 12);
   int_stack_or_eight(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 9);
   int_stack_or_eight(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 2);
   int_stack_push(&stack1, 2);
   int_stack_or_eight(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   /*int_stack_push(&stack1, 111);
   int_stack_push(&stack1, 101);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 2);
   int_stack_or_eight(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);*/
}
TEST(IntStackTests, TestGreaterThanOrEquals){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 111);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 12);
   int_stack_or_nine(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 3);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 9);
   int_stack_or_nine(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 111);
   int_stack_push(&stack1, 2);
   int_stack_push(&stack1, 2);
   int_stack_or_nine(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   /*int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 101);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 2);
   int_stack_or_nine(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);*/
}
TEST(IntStackTests, TestAndBothLessThan){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 3);
   int_stack_push(&stack1, 20);
   int_stack_push(&stack1, 4);
   int_stack_push(&stack1, 30);
   int_stack_and_one(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 3);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 91);
   int_stack_and_one(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 13);
   int_stack_push(&stack1, 2);
   int_stack_and_one(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, -2);
   int_stack_and_one(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestAndBothGreaterThan){
  int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 2);
   int_stack_push(&stack1, 14);
   int_stack_push(&stack1, 9);
   int_stack_and_two(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 3);
   int_stack_push(&stack1, 8);
   int_stack_push(&stack1, 9);
   int_stack_and_two(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 111);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 2);
   int_stack_and_two(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 101);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 2);
   int_stack_and_two(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestAndBothEquals){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 12);
   int_stack_and_three(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   /*int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 3);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 12);
   int_stack_and_three(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 2);
   int_stack_and_three(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 101);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 2);
   int_stack_and_three(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);*/
}
TEST(IntStackTests, TestLessAndGreaterThan){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 9);
   int_stack_and_four(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 9);
   int_stack_and_four(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 9);
   int_stack_push(&stack1, 12);
   int_stack_and_four(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 9);
   int_stack_push(&stack1, 12);
   int_stack_and_four(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestGreaterAndLessThan){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 9);
   int_stack_push(&stack1, 12);
   int_stack_and_five(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 9);
   int_stack_and_five(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 9);
   int_stack_push(&stack1, 12);
   int_stack_and_five(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 9);
   int_stack_and_five(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestEqualsAndLessThan){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 2);
   int_stack_push(&stack1, 9);
   int_stack_and_six(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   /*int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 2);
   int_stack_push(&stack1, 9);
   int_stack_and_six(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 9);
   int_stack_push(&stack1, 2);
   int_stack_and_six(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);*/
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 9);
   int_stack_push(&stack1, 2);
   int_stack_and_six(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
  // ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
}
TEST(IntStackTests, TestEqualsAndGreaterThan){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 9);
   int_stack_and_seven(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
  /* int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 9);
   int_stack_and_seven(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 9);
   int_stack_push(&stack1, 12);
   int_stack_and_seven(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 9);
   int_stack_push(&stack1, 12);
   int_stack_and_seven(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);*/
}
TEST(IntStackTests, TestLessThanAndEquals){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 12);
   int_stack_and_eight(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   /*int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 9);
   int_stack_and_eight(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 12);
   int_stack_and_eight(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 9);
   int_stack_push(&stack1, 12);
   int_stack_and_eight(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);*/
}
TEST(IntStackTests, TestGreaterThanAndEquals){
   int_stack_t stack1;
   int top_value, next_to_top_value, after_value, next_after_value;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 12);
   int_stack_and_nine(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(-1, top_value);
   /*int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 9);
   int_stack_and_nine(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 12);
   int_stack_push(&stack1, 12);
   int_stack_and_nine(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);
   int_stack_push(&stack1, 1);
   int_stack_push(&stack1, 11);
   int_stack_push(&stack1, 9);
   int_stack_push(&stack1, 12);
   int_stack_and_nine(&stack1);
   ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
   //ASSERT_TRUE(int_stack_pop(&stack1, &next_after_value));
   ASSERT_EQ(0, top_value);*/
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
    ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
    ASSERT_EQ(4, top_value);
    ASSERT_EQ(8, next_to_top_value);
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
    int_stack_dup_two(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
    ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
    ASSERT_EQ(6, top_value);
    ASSERT_EQ(7, next_to_top_value);
    int_stack_push(&stack1, 10);
    int_stack_push(&stack1, 9);
    int_stack_dup_two(&stack1);
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
    int_stack_swap_two(&stack1);
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
    int_stack_over_two(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &top_value));
    ASSERT_TRUE(int_stack_pop(&stack1, &next_to_top_value));
    ASSERT_EQ(16, top_value);
    ASSERT_EQ(15, next_to_top_value);
}
TEST(IntStackTests, TestDropTwo){
    int_stack_t stack1;
    int top_value, next_to_top_value, after_value;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);
    int_stack_push(&stack1, 88);
    int_stack_push(&stack1, 77);
    int_stack_push(&stack1, 11);
    int_stack_drop_two(&stack1);
    ASSERT_TRUE(int_stack_pop(&stack1, &after_value));
    ASSERT_EQ(88, after_value);
}
TEST(IntStackTests, TestAddition){
    int_stack_t stack1;
    int top_value, next_to_top_value;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);
    int_stack_push(&stack1, 7);
    int_stack_push(&stack1, 3);
    int_stack_add(&stack1);
    ASSERT_EQ(10, 3 + 7);
}
TEST(IntStackTests, TestSubtraction){
    int_stack_t stack1;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);
    int_stack_push(&stack1, 17);
    int_stack_push(&stack1, 8);
    int_stack_sub(&stack1);
    ASSERT_EQ(9, 17 - 8);
}
TEST(IntStackTests, TestMultiplication){
   int_stack_t stack1;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 10);
   int_stack_push(&stack1, 25);
   int_stack_mul(&stack1);
   ASSERT_EQ(250, 25 * 10);
}
TEST(IntStackTests, TestDivision){
   int_stack_t stack1;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 15);
   int_stack_push(&stack1, 5);
   int_stack_div(&stack1);
   ASSERT_EQ(3, 15 / 5);
}
TEST(IntStackTests, TestModulos){//note: this test tests both modulo versions!
   int_stack_t stack1;
   const int capacity = 10;
   int_stack_init(&stack1, capacity);
   int_stack_push(&stack1, 122);
   int_stack_push(&stack1, 13);
   int_stack_mod(&stack1);
   int_stack_mod_two(&stack1);
   ASSERT_EQ(5, 122 % 13);
   ASSERT_EQ(9, 122 / 13);
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
