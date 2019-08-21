#include <gtest/gtest.h>
#include "deepPtr.hpp"

TEST(DeepPtr, BasicContructor) {
  int number = 100;
  DeepPtr<int> ptr(number);

  ASSERT_EQ(number, *ptr);
}

TEST(DeepPtr, CopyConstructor) {
  int number = 100;
  DeepPtr<int> ptr1(number);
  DeepPtr<int> ptr2(ptr1);

  ASSERT_EQ(*ptr1, *ptr2);
  ASSERT_NE(ptr1.get(), ptr2.get());
}

TEST(DeepPtr, MoveConstructor) {
  int number = 100;
  DeepPtr<int> ptr1(number);
  DeepPtr<int> ptr2(std::move(ptr1));

  ASSERT_EQ(ptr1.get(), nullptr);
  ASSERT_EQ(number, *ptr2);
}

TEST(DeepPtr, CopyAssignment) {
  int number = 100;
  DeepPtr<int> ptr1(number);
  DeepPtr<int> ptr2;
  ptr2 = ptr1;

  ASSERT_EQ(*ptr1, *ptr2);
  ASSERT_NE(ptr1.get(), ptr2.get());
}

TEST(DeepPtr, MoveAssignment) {
  int number = 100;
  DeepPtr<int> ptr1(number);
  DeepPtr<int> ptr2;
  ptr2 = std::move(ptr1);

  ASSERT_EQ(ptr1.get(), nullptr);
  ASSERT_EQ(number, *ptr2);
}

#include <vector>

TEST(DeepPtr, ArrowOperator) {
  std::vector<int> vec(2);
  DeepPtr<std::vector<int> > ptr(vec);

  ASSERT_EQ(ptr->size(), 2);
}

TEST(DeepPtr, Swap) {
  DeepPtr<int> ptr1(2);
  DeepPtr<int> ptr2(3);

  swap(ptr1, ptr2);

  ASSERT_EQ(*ptr1, 3);
  ASSERT_EQ(*ptr2, 2);
}

TEST(DeepPtr, BoolOperator) {
  DeepPtr<int> ptr1;
  DeepPtr<int> ptr2(3);

  ASSERT_EQ(bool(ptr1), false);
  ASSERT_EQ(bool(ptr2), true);
}

TEST(DeepPtr, UniquePtrContructor) {
  int* ptr = new int[1];
  std::unique_ptr<int> ptr1(ptr);
  DeepPtr<int> ptr2(std::move(ptr1));

  ASSERT_EQ(ptr1.get(), nullptr);
  ASSERT_EQ(ptr2.get(), ptr);
}

TEST(DeepPtr, UniquePtrAssignment) {
  int* ptr = new int[1];
  std::unique_ptr<int> ptr1(ptr);
  DeepPtr<int> ptr2;
  ptr2 = std::move(ptr1);

  ASSERT_EQ(ptr1.get(), nullptr);
  ASSERT_EQ(ptr2.get(), ptr);
}
