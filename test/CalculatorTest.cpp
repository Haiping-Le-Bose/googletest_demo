#include "Calculator.hpp"
#include <gtest/gtest.h>

TEST(CalculatorTest, Add) {
    Calculator cal;
    EXPECT_EQ(cal.add(1, 2), 3);
    EXPECT_EQ(cal.add(-1, -1), -2);
    EXPECT_EQ(cal.add(100, 200), 300);
}

TEST(CalculatorTest, Subtract) {
    Calculator cal;
    EXPECT_EQ(cal.subtract(2, 1), 1);
    EXPECT_EQ(cal.subtract(-1, -1), 0);
    EXPECT_EQ(cal.subtract(100, 50), 50);
}

TEST(CalculatorTest, Multiply) {
    Calculator cal;
    EXPECT_EQ(cal.multiply(2, 3), 6);
    EXPECT_EQ(cal.multiply(-1, 1), -1);
    EXPECT_EQ(cal.multiply(0, 100), 0);
}

TEST(CalculatorTest, Divide) {
    Calculator cal;
    EXPECT_EQ(cal.divide(6, 3), 2);
    EXPECT_EQ(cal.divide(100, 10), 10);
    EXPECT_THROW(cal.divide(1, 0), std::invalid_argument);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}