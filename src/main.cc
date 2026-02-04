#include "Benchmark.h"
#include "Formatter.h"
#include "FileSaver.h"
#include <iostream>
#include <vector>

int main() {
  
  std::cout << "════════════════════════════════════════════════════════\n";
  std::cout << "  BENCHMARK: Multiplicación de Matrices\n";
  std::cout << "  Comparación de Algoritmos (Filas vs Columnas)\n";
  std::cout << "════════════════════════════════════════════════════════\n\n";
  
  // Definir las dimensiones a probar
  std::vector<int> dimensiones = {3, 4, 5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
                                   200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000};
  
  const int rango = 100000;
  
  std::cout << "Configuración:\n";
  std::cout << "  - Rango de valores: 0 - " << rango << "\n";
  std::cout << "  - Dimensiones: 3x3 hasta 1000x1000\n";
  std::cout << "  - Total de pruebas: " << dimensiones.size() << "\n\n";
  
  try {
    // Ejecutar benchmark (SRP: solo ejecuta)
    Benchmark benchmark;
    auto resultados = benchmark.ejecutar(dimensiones, rango);
    
    // Formatear para consola (SRP: solo formatea)
    std::string salidaConsola = ResultFormatter::formatearParaConsola(resultados);
    std::cout << salidaConsola;
    
    // Formatear para archivo (SRP: solo formatea)
    std::string salidaArchivo = ResultFormatter::formatearParaArchivo(resultados);
    
    // Guardar en archivo (SRP: solo guarda)
    std::cout << "Introduzca el nombre del archivo para los resultados (sin la extension .txt)" << std::endl;
    std::string nombre_archivo;
    std::cin >> nombre_archivo;
    std::string ruta_archivo = "docs/" + nombre_archivo + ".txt";
    FileWriter::guardar(salidaArchivo, ruta_archivo);
    
  } catch (const std::exception& e) {
    std::cerr << "Error durante el benchmark: " << e.what() << std::endl;
    return 1;
  }
  
  return 0;
}