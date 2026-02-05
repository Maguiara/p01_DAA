
#include "RowAlgorithmSolve.h"
#include "MatrixInstance.h"
#include "MatrixSolution.h"
#include <stdexcept>

std::unique_ptr<Solution> RowAlgorithmSolve::solve(const ProblemInstance& problem)  {
  
  //Desglose del problema
  const MatrixInstances& matrixProblem = dynamic_cast<const MatrixInstances&>(problem);
  const Matriz& A = matrixProblem.getMatrizA();
  const Matriz& B = matrixProblem.getMatrizB();

  //Creamos la solucion
  Matriz resultado(A.getRows(), B.getColumns());

  //Algoritmo por filas
  for (int i = 0; i < A.getRows(); i++) {
    for (int j = 0; j < B.getColumns(); j++) {
      long long suma = 0;
      for (int k = 0; k < A.getColumns(); k++) {
        suma += A(i, k) * B(k, j);
      }
      resultado(i, j) = suma;
    }
  }
  //Resultado
  return std::make_unique<MatrixSolution>(resultado);
}