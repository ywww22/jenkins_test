#include "gtest/gtest.h"
#include "../inc/sum.h"

TEST(SumTest, Test1){
    int a = sum(3,9);
    a = sum(9,3);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}