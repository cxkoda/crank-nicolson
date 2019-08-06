#include "grid.hpp"
#include <boost/array.hpp>
#include <iostream>

Grid1D::Grid1D(const array_type& _cellEdges, int _nRim)
    : cellEdges(_cellEdges) {
  nRim = _nRim;
  nCells = cellEdges.size() - 1 - 2 * nRim;

  cellCenters.resize(boost::extents[cellEdges.size() - 1]);
  const int lo = cellEdges.index_bases()[0];
  const int hi = lo + cellEdges.size();
  int ixc = 0;
  for (int ix = lo; ix < hi - 1; ++ix) {
    cellCenters[ixc] = 0.5 * (cellEdges[ix] + cellEdges[ix + 1]);
    ++ixc;
  }

  boost::array<array_type::index, 1> bases = {{-nRim}};
  cellEdges.reindex(bases);
  cellCenters.reindex(bases);
}

Grid1D Grid1D::newLinear(double xa, double xb, int nCells, int nRim) {
  typedef array_type::extent_range range;
  array_type cellEdges(boost::extents[range(-nRim, nCells + nRim + 1)]);

  double dx = (xb - xa) / nCells;
  const int lo = cellEdges.index_bases()[0];
  const int hi = lo + cellEdges.size();
  
  for (int ix = lo; ix < hi; ++ix) {
    cellEdges[ix] = ix * dx;
  }

  return Grid1D(cellEdges, nRim);
}

double Grid1D::xC(int ix) const { return cellCenters[ix]; }
double Grid1D::xL(int ix) const { return cellEdges[ix]; }
int Grid1D::size() const { return cellCenters.size(); }
