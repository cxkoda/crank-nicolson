#include "grid.hpp"
#include <boost/array.hpp>

Grid1D::Grid1D(const array_type& _cellEdges, int _nRim)
    : cellEdges(_cellEdges) {
  nRim = _nRim;
  nCells = cellEdges.size() - 2 * nRim;

  cellCenters.resize(boost::extents[cellEdges.size() - 1]);
  for (int ix = cellEdges.index_bases()[0]; ix < cellEdges.size(); ++ix) {
    cellCenters[ix] = 0.5 * (cellEdges[ix] + cellEdges[ix + 1]);
  }

  boost::array<array_type::index, 1> bases = {{-nRim}};
  cellEdges.reindex(bases);
  cellCenters.reindex(bases);
}

Grid1D Grid1D::new_linear(double xa, double xb, int nCells, int nRim) {
  typedef array_type::extent_range range;
  array_type cellEdges(boost::extents[range(-nRim, nCells + nRim + 1)]);

  double dx = (xb - xa) / nCells;
  for (int ix = cellEdges.index_bases()[0]; ix < cellEdges.size(); ++ix) {
    cellEdges[ix] = ix * dx;
  }

  return Grid1D(cellEdges, nRim);
}
