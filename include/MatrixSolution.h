#pragma once

#include "Solution.h"
#include "Matrix.h"


class MatrixSolution : public Solution {
 public:
  MatrixSolution(const Matriz& resultado) : solucion_(resultado) {}
  const Matriz& getResultado() const { return solucion_; }
  
 private:
  Matriz solucion_;
};