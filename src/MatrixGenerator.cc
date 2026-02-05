#include "MatrixGenerator.h"

std::vector<long long> MatrixGenerator::generator(const int rows, const int columns, const int range) {
  //inicializamos la semilla
  srand(time(nullptr));

  std::vector<long long> matriz_generada (rows * columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matriz_generada[i * columns + j] = rand() % (range + 1);  // Valores entre 0 y rango
    }
  }

  return matriz_generada;
}