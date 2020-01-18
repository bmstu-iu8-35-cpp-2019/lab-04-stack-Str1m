// Copyright 2019 Sabitov Egoк <q.st.stream@gmail.com>

#include <gtest/gtest.h>

#include <header.hpp>

TEST(Stack_, Test_1){
    Stack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    int val = a.pop(1);
    EXPECT_EQ(4, val);
}

TEST(Stack_, Test_2){
    Stack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    int val = a.head();
    EXPECT_EQ(4, val);
}

TEST(Stack_, Test_3){
    Stack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    int val = a.head();
    EXPECT_EQ(4, val);
    a.push(5);
    val = a.head();
    EXPECT_EQ(5, val);
}
