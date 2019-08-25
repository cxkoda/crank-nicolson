#include "grid.hpp"
#include <boost/array.hpp>
#include <iostream>

Grid1D::Grid1D() {
  cellEdges = std::make_unique<array_type>();
  cellCenters = std::make_unique<array_type>();
  dxEdges = std::make_unique<array_type>();
  dxCenters = std::make_unique<array_type>();
}

Grid1D::Grid1D(const array_type& _cellEdges, int _nRim) : Grid1D() {
  cellEdges = std::make_unique<array_type>(_cellEdges);

  nRim = _nRim;
  nCells = cellEdges->size() - 1 - 2 * nRim;
  const long nCellsAll = cellEdges->size() - 1;

  const long lo = cellEdges->index_bases()[0];
  const long hi = lo + cellEdges->size();

  cellCenters->resize(boost::extents[nCellsAll]);
  dxEdges->resize(boost::extents[nCellsAll]);
  dxCenters->resize(boost::extents[nCellsAll - 1]);

  int ixc = 0;
  for (int ix = lo; ix < hi - 1; ++ix) {
    (*cellCenters)[ixc] = 0.5 * ((*cellEdges)[ix] + (*cellEdges)[ix + 1]);
    (*dxEdges)[ixc] = (*cellEdges)[ix + 1] - (*cellEdges)[ix];
    ++ixc;
  }

  for (int ix = 0; ix < nCellsAll - 1; ++ix) {
    (*dxCenters)[ix] = (*cellCenters)[ix + 1] - (*cellCenters)[ix];
  }

  boost::array<array_type::index, 1> bases = {{-nRim}};
  cellEdges->reindex(bases);
  cellCenters->reindex(bases);
  dxEdges->reindex(bases);
  dxCenters->reindex(bases);
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

double Grid1D::xC(int ix) const { return (*cellCenters)[ix]; }
double Grid1D::xL(int ix) const { return (*cellEdges)[ix]; }
int Grid1D::size() const { return cellCenters->size(); }

double Grid1D::cellWidth(int ix) const { return (*dxEdges)[ix]; }
double Grid1D::cellDistance(int ix) const { return (*dxCenters)[ix]; }

const Grid1D::array_type& Grid1D::xC() const { return *cellCenters; }
const Grid1D::array_type& Grid1D::xL() const { return *cellEdges; }
const Grid1D::array_type& Grid1D::cellWidth() const { return *dxEdges; }
const Grid1D::array_type& Grid1D::cellDistance() const { return *dxCenters; }