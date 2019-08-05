#include <boost/multi_array.hpp>

class Grid1D {
 private:
  typedef boost::multi_array<double, 1> array_type;

  int nCells, nRim;
  array_type cellEdges;
  array_type cellCenters;

 public:
  static Grid1D new_linear(double xa, double xb, int nCells, int nRim);
  Grid1D(const array_type& cellEdges, int nRim);
};