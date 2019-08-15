#include <gtest/gtest.h>
#include "data.hpp"

TEST(DataTest, ConstructionFromGridCopy) {
    Grid1D grid = Grid1D::newLinear(0,1,2,2);
    Data data(grid);

    ASSERT_EQ(data.grid.size(), 6);
}

TEST(DataTest, ConstructionFromGridRvalue) {
    Data data(Grid1D::newLinear(0,1,2,2));

    ASSERT_EQ(data.grid.size(), 6);
}

TEST(DataTest, LinearConstructor) {

}