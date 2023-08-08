#include "gtest/gtest.h"
#include "../inc/sum.h"

TEST(SumTest, Test1){
    EXPECT_EQ(sum(7,6),13);
    EXPECT_EQ(sum(3,6),6);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}