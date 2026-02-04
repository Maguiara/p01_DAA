#pragma once

#include "ProblemInstance.h"
#include <vector>
#include "Matrix.h"

class MatrixInstances : public ProblemInstance {
 public:

  MatrixInstances(const Matriz& A, const Matriz& B) : matrixA_(A), matrixB_(B) {
    if(A.getColumns() != B.getRows()) {
      throw std::invalid_argument("The matrices introduced are not multipliable");
    }
  }

  const Matriz& getMatrizA() const { return matrixA_; }
  const Matriz& getMatrizB() const { return matrixB_; }

 
 private:
  Matriz matrixA_;
  Matriz matrixB_;
};