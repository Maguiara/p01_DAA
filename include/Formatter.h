#pragma once

#include "Benchmark.h"
#include <string>
#include <vector>

// Responsabilidad: SOLO formatear resultados
class ResultFormatter {
public:
  static std::string formatearParaConsola(const std::vector<BenchmarkResult>& resultados);
  static std::string formatearParaArchivo(const std::vector<BenchmarkResult>& resultados);
};