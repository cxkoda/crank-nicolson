#include <gtest/gtest.h>
#include "grid.hpp"

TEST(GridTest, GridConstructorBasic) {
  Grid1D::array_type cellEdges_ptr(boost::extents[2]);
  cellEdges_ptr[0] = 0;
  cellEdges_ptr[1] = 1;
  Grid1D grid(cellEdges_ptr, 0);

  EXPECT_EQ(1, grid.size());
  EXPECT_EQ(0, grid.xL(0));
  EXPECT_EQ(1, grid.xL(1));
  EXPECT_EQ(0.5, grid.xC(0));
}

TEST(GridTest, LinearGridEdges) {
  Grid1D grid = Grid1D::newLinear(0, 1, 2, 2);
  EXPECT_EQ(0, grid.xL(0));
  EXPECT_EQ(0.5, grid.xL(1));
  EXPECT_EQ(1, grid.xL(2));
}

TEST(GridTest, LinearGridCenters) {
  Grid1D grid = Grid1D::newLinear(0, 1, 2, 2);
  EXPECT_EQ(0.25, grid.xC(0));
  EXPECT_EQ(0.75, grid.xC(1));
}

TEST(GridTest, LinearGridRimEdges) {
  Grid1D grid = Grid1D::newLinear(0, 1, 2, 2);
  EXPECT_EQ(-1, grid.xL(-2));
  EXPECT_EQ(-0.5, grid.xL(-1));
  EXPECT_EQ(1.5, grid.xL(3));
  EXPECT_EQ(2, grid.xL(4));
}

TEST(GridTest, LinearGridRimCenters) {
  Grid1D grid = Grid1D::newLinear(0, 1, 2, 2);
  EXPECT_EQ(-0.75, grid.xC(-2));
  EXPECT_EQ(-0.25, grid.xC(-1));
  EXPECT_EQ(1.25, grid.xC(2));
  EXPECT_EQ(1.75, grid.xC(3));
}

TEST(GridTest, CellWidth) {
  Grid1D grid = Grid1D::newLinear(0, 0.2, 1, 1);
  EXPECT_DOUBLE_EQ(0.2, grid.cellWidth(-1));
  EXPECT_DOUBLE_EQ(0.2, grid.cellWidth(0));
  EXPECT_DOUBLE_EQ(0.2, grid.cellWidth(1));
}

TEST(GridTest, CellDistance) {
  Grid1D grid = Grid1D::newLinear(0, 0.3, 1, 1);
  EXPECT_DOUBLE_EQ(0.3, grid.cellDistance(-1));
  EXPECT_DOUBLE_EQ(0.3, grid.cellDistance(0));
}

TEST(GridTest, MoveSemantics) {
  Grid1D grid1 = Grid1D::newLinear(0, 0.3, 1, 1);
  const Grid1D::array_type* cellEdges_ptr1 = &grid1.xL();

  Grid1D grid2(std::move(grid1));
  const Grid1D::array_type* cellEdges_ptr2 = &grid2.xL();

  ASSERT_EQ(&grid1.xL(), nullptr);
  ASSERT_EQ(cellEdges_ptr1, cellEdges_ptr2);
  ASSERT_EQ(grid2.size(), 3);
}

TEST(GridTest, RvalueAssignment) {
  Grid1D grid1 = Grid1D::newLinear(0, 0.3, 1, 1);
  Grid1D grid2 = Grid1D::newLinear(0, 0.3, 1, 1);
  const Grid1D::array_type* cellEdges_ptr1 = &grid1.xL();

  grid2 = std::move(grid1);
  const Grid1D::array_type* cellEdges_ptr2 = &grid2.xL();

  ASSERT_EQ(&grid1.xL(), nullptr);
  ASSERT_EQ(cellEdges_ptr1, cellEdges_ptr2);
}