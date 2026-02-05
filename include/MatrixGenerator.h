#pragma once

#include "Matrix.h"
#include <cstdlib>  // Para rand()
#include <ctime>    // Para time()

class MatrixGenerator {

 public:

  std::vector<long long> generator(const int rows, const int columns, const int range);

};