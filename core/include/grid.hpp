#ifndef grid_hpp
#define grid_hpp

#include <boost/multi_array.hpp>
#include <memory>
#include "deepPtr.hpp"

class Grid1D {
 public:
  typedef boost::multi_array<double, 1> array_type;

  /** contruct a linear grid */
  static Grid1D newLinear(double xa, double xb, int nCells, int nRim);

  /** construct a grid form given cell edges */
  Grid1D(const array_type& cellEdges, int nRim);

  /** copy constructor
   * use the default implementation (which was implicitly deleted)
   */
  Grid1D(const Grid1D&) = default;

  /** Move constructor */
  Grid1D(Grid1D&&) = default;

  /** Rvalue assignment */
  Grid1D& operator=(Grid1D&&) = default;

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

  const array_type& xC() const;
  const array_type& xL() const;
  const array_type& cellWidth() const;
  const array_type& cellDistance() const;

 private:
  /** Default constructor (initializes field pointers) */
  Grid1D();

  int nCells, nRim;
  DeepPtr<array_type> cellEdges;
  DeepPtr<array_type> cellCenters;

  DeepPtr<array_type> dxEdges;
  DeepPtr<array_type> dxCenters;
};

#endif