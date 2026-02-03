#pragma once

#include "Matrix.h"
#include <cstdlib>  // Para rand()
#include <ctime>    // Para time()

class MatrixGenerator {

 public:

  std::vector<std::vector<int>> generator(const int rows, const int columns, const int range);

};