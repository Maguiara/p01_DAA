#include "Benchmark.h"
#include "RowAlgorithmSolve.h"
#include "ColumnAlgorithmSolve.h"
#include "MatrixGenerator.h"
#include "MatrixSolution.h"
#include <chrono>
#include <iostream>

std::vector<BenchmarkResult> Benchmark::ejecutar(const std::vector<int>& dimensiones, int rango) {
  std::vector<BenchmarkResult> resultados;
  MatrixGenerator generador;
  
  for (int dim : dimensiones) {
    std::cout << "Probando dimensión " << dim << "x" << dim << "... " << std::flush;
    
    // Generar matrices
    Matriz A = generador.generator(dim, dim, rango);
    Matriz B = generador.generator(dim, dim, rango);
    MatrixInstances problema(A, B);
    
    BenchmarkResult resultado;
    resultado.dimension = dim;
    
    // Medir tiempo del algoritmo por FILAS
    RowAlgorithmSolve estrategiaFilas;
    auto inicio = std::chrono::high_resolution_clock::now();
    std::unique_ptr<Solution> sol1 = estrategiaFilas.solve(problema);
    auto fin = std::chrono::high_resolution_clock::now();
    resultado.tiempo_filas = std::chrono::duration<double, std::milli>(fin - inicio).count();
    
    // Medir tiempo del algoritmo por COLUMNAS
    ColumnsAlgorithmSolve estrategiaColumnas;
    inicio = std::chrono::high_resolution_clock::now();
    std::unique_ptr<Solution> sol2 = estrategiaColumnas.solve(problema);
    fin = std::chrono::high_resolution_clock::now();
    resultado.tiempo_columnas = std::chrono::duration<double, std::milli>(fin - inicio).count();
    
    resultados.push_back(resultado);
    std::cout << "✓\n";
  }
  
  return resultados;
}