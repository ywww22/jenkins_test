#include "gtest/gtest.h"
#include "../inc/sum.h"

TEST(SumTest, Test1){
    sum("hi.txt");
}

TEST(SumTest, Test2){
    std::string name;
    sum(name);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}