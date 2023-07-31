#include "gtest/gtest.h"
#include "../inc/sum.h"

TEST(SumTest, Test1){
    EXPECT_EQ(sum(5,6),11);
}

TEST(SumTest, Test2){
    EXPECT_EQ(sum(9,1),10);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}