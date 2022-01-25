#include "gtest/gtest.h"
#include "myuniqueptr.hpp"

class MyUniquePointerFixture : public ::testing::Test {
public:
    MyUniquePtr<int> cut{new int(5)};

};

TEST_F(MyUniquePointerFixture, dereferenceOperatorShouldReturnCorrectData) {
    EXPECT_EQ(*cut, 5);
}

TEST(MyUniquePointerSuite, shouldGetRawPointer) {
    int* rawPtr = new int {99};
    MyUniquePtr<int> cut(rawPtr);
    EXPECT_EQ(cut.get(), rawPtr);
}