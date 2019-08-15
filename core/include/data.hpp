#include <memory>
#include "grid.hpp"

class Data {
 public:
  typedef Grid1D::array_type array_type;

  /** contruct a linear grid */
  static Data newLinear(double xa, double xb, int nCells, int nRim);

  /** copy constructor */
  Data(const Data&) = default;

  /** Move constructor */
  Data(Data&&) = default;

  /** Rvalue assignment */
  Data& operator=(Data&&) = default;

  Data(Grid1D &&);
  Data(const Grid1D &);

  Grid1D grid;

 private:
  std::unique_ptr<array_type> data;

  void initData();
};