#include "RowAlgorithmSolve.h"
#include "ColumnAlgorithmSolve.h"
#include "MatrixInstance.h"
#include "MatrixSolution.h"
#include "MatrixPrinter.h"
#include "Matrix.h"
#include "MatrixPrinter.h"
#include "MatrixGenerator.h"


int main () {

Matriz matrizA = MatrixGenerator().generator(3, 4, 100);
Matriz matrizB = MatrixGenerator().generator(4, 3, 100);
  
}





// const int row = 3;
// Matriz matrizA(row, row);
// MatrixPrinter().MatriPrinter(matrizA);

// std::vector<std::vector<int>> relleno_matriz = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
// Matriz matrizB = relleno_matriz;
// MatrixPrinter().MatriPrinter(matrizB);

// Matriz matrizC = matrizB;
// MatrixPrinter().MatriPrinter(matrizC);