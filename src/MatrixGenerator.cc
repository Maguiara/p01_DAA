#include "MatrixGenerator.h"

std::vector<std::vector<int>> MatrixGenerator::generator(const int rows, const int columns, const int range) {
  //inicializamos la semilla
  srand(time(nullptr));

  std::vector<std::vector<int>> matriz_generada (rows, std::vector<int>(columns));

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matriz_generada[i][j] = rand() % (range + 1);  // Valores entre 0 y rango
    }
  }

  return matriz_generada;
}