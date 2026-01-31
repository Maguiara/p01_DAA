
#include "RowAlgorithmSolve.h"
#include "MatrixInstance.h"


using Matrix = std::vector<std::vector<int>>;

std::unique_ptr<Solution> RowAlgorithmSolve::solve(const ProblemInstance& problem)  {
  
  const MatrixInstances& matrixProblem = dynamic_cast<const MatrixInstances&>(problem);
  const Matrix& A = matrixProblem.getMatrixA();
  const Matrix& B = matrixProblem.getMatrixB();

  
// Cambiar esto a columnas, este que esta ahora es el de filas
  for (size_t i = 0; i < A.size(); ++i) {
    for (size_t j = 0; j < B[0].size(); ++j) {
      for (size_t k = 0; k < A[0].size(); ++k) {
       
      }
    }
  }

  
}