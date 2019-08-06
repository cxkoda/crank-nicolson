#include <boost/multi_array.hpp>

class Grid1D {
 public:
  typedef boost::multi_array<double, 1> array_type;

  /** contruct a linear grid */
  static Grid1D newLinear(double xa, double xb, int nCells, int nRim);

  /** construct a grid form given cell edges */
  Grid1D(const array_type& cellEdges, int nRim);

  /** get the cell center of a given cell */
  double xC(int ix) const;

  /** get the left cell edge of a given cell */
  double xL(int ix) const;

  /** get the cell width */
  double cellWidth(int ix) const;

  /** get the difference between two cell centers ix, ix+1 */
  double cellDistance(int ix) const;

  /** get the total size of the grid (incl. ghost cells) */
  int size() const;

 private:
  int nCells, nRim;
  array_type cellEdges;
  array_type cellCenters;

  array_type dxEdges;
  array_type dxCenters;
};