#include "Formatter.h"
#include <sstream>
#include <iomanip>

std::string ResultFormatter::formatearParaConsola(const std::vector<BenchmarkResult>& resultados) {
  std::ostringstream oss;
  
  oss << "\n";
  oss << "════════════════════════════════════════════════════════\n";
  oss << "              RESULTADOS DEL BENCHMARK\n";
  oss << "════════════════════════════════════════════════════════\n\n";
  
  oss << std::setw(12) << "Dimensión" 
      << std::setw(20) << "Filas (ms)" 
      << std::setw(20) << "Columnas (ms)" << "\n";
  oss << "────────────────────────────────────────────────────────\n";
  
  for (const auto& r : resultados) {
    oss << std::setw(10) << r.dimension << "x" << r.dimension
        << std::setw(20) << std::fixed << std::setprecision(3) << r.tiempo_filas
        << std::setw(20) << r.tiempo_columnas << "\n";
  }
  
  oss << "════════════════════════════════════════════════════════\n\n";
  
  return oss.str();
}

std::string ResultFormatter::formatearParaArchivo(const std::vector<BenchmarkResult>& resultados) {
  std::ostringstream oss;
  
  oss << "════════════════════════════════════════════════════════\n";
  oss << "              RESULTADOS DEL BENCHMARK\n";
  oss << "  Multiplicación de Matrices (Filas vs Columnas)\n";
  oss << "════════════════════════════════════════════════════════\n\n";
  
  oss << std::setw(12) << "Dimensión" 
      << std::setw(20) << "Filas (ms)" 
      << std::setw(20) << "Columnas (ms)" << "\n";
  oss << "────────────────────────────────────────────────────────\n";
  
  for (const auto& r : resultados) {
    oss << std::setw(10) << r.dimension << "x" << r.dimension
        << std::setw(20) << std::fixed << std::setprecision(3) << r.tiempo_filas
        << std::setw(20) << r.tiempo_columnas << "\n";
  }
  
  oss << "════════════════════════════════════════════════════════\n";
  
  return oss.str();
}