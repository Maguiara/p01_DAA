#pragma once

#include "Strategy.h"
#include "MatrixInstance.h"
#include <vector>

struct BenchmarkResult {
  int dimension;
  double tiempo_filas;
  double tiempo_columnas;
};

// Responsabilidad: SOLO ejecutar benchmarks
class Benchmark {
public:
  std::vector<BenchmarkResult> ejecutar(const std::vector<int>& dimensiones, int rango);
};