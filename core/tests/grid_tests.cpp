#include <gtest/gtest.h>
#include "grid.hpp"

TEST(GridTest, GridConstructorBasic) {
  Grid1D::array_type cellEdges(boost::extents[2]);
  cellEdges[0] = 0;
  cellEdges[1] = 1;
  Grid1D grid(cellEdges, 0);

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