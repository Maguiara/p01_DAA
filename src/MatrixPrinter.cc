#include "MatrixPrinter.h"
#include <iomanip>


void MatrixPrinter::MatriPrinter(const Matriz& matriz) {
  const int ancho = 4;
  for (int i = 0; i < matriz.getRows(); i++) { 
    for (int j = 0; j < matriz.getColumns(); j++) {
      std::cout << std::setw(ancho) << matriz[i][j];
    }
    std::cout<< std::endl;
  }
  std::cout << std::endl;
}