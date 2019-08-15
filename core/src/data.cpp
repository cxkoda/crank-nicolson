#include "data.hpp"

Data::Data(const Grid1D& _grid) : grid(_grid) {
    initData();
}

Data::Data(Grid1D&& _grid) : grid(_grid) {
    initData();
}

void Data::initData() {}

Data Data::newLinear(double xa, double xb, int nCells, int nRim) {}
