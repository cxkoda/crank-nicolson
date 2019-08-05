#include <boost/multi_array.hpp>

class Grid1D {
 public:
  typedef boost::multi_array<double, 1> array_type;

  static Grid1D new_linear(double xa, double xb, int nCells, int nRim);
  Grid1D(const array_type& cellEdges, int nRim);

  double xC(int ix) const;
  double xL(int ix) const;
  int size() const;

 private:
  int nCells, nRim;
  array_type cellEdges;
  array_type cellCenters;
};