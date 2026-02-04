#include "FileSaver.h"
#include <fstream>
#include <iostream>

void FileWriter::guardar(const std::string& contenido, const std::string& ruta) {
  std::ofstream file(ruta);
  
  if (!file.is_open()) {
    throw std::runtime_error("Error al abrir el archivo: " + ruta);
  }
  
  file << contenido;
  file.close();
  
  std::cout << "✓ Resultados guardados en: " << ruta << "\n";
}