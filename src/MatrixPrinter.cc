#include "MatrixPrinter.h"
#include <algorithm>
#include <cmath>


int calcWidth(const Matriz& matriz) {
  long long max_valor = 0;
  for (int i = 0; i < matriz.getRows(); i++) {
    for (int j = 0; j < matriz.getColumns(); j++) {
      max_valor = std::max(max_valor, std::abs(matriz[i][j]));
    }
  }
  // Calcular cuántos dígitos tiene el número más grande
  int ancho = (max_valor == 0) ? 1 : std::log10(max_valor) + 1;
  ancho += 2;  // Añadir espacio extra para separación
  return ancho;
}


void MatrixPrinter::MatriPrinter(const Matriz& matriz) {
  int width = calcWidth(matriz);
  for (int i = 0; i < matriz.getRows(); i++) { 
    for (int j = 0; j < matriz.getColumns(); j++) {
      std::cout << std::setw(width) << matriz[i][j];
    }
    std::cout<< std::endl;
  }
  std::cout << std::endl;
}