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
    auto datosA = generador.generator(dim, dim, rango);
    auto datosB = generador.generator(dim, dim, rango);
    Matriz A(datosA, dim, dim);
    Matriz B(datosB, dim, dim);

    // Creamos el problema
    MatrixInstances problema(A, B);
    
    // Inicializamos el Benchmark
    BenchmarkResult resultado;
    resultado.dimension = dim;

    // Calentamos motores filas
    RowAlgorithmSolve warmup;
    warmup.solve(problema);

    // Medir tiempo del algoritmo por FILAS
    RowAlgorithmSolve estrategiaFilas;
    auto inicio = std::chrono::steady_clock::now();
    std::unique_ptr<Solution> sol1 = estrategiaFilas.solve(problema);
    auto fin = std::chrono::steady_clock::now();
    resultado.tiempo_filas = std::chrono::duration<double, std::milli>(fin - inicio).count();

    // Calentamos motores columnas
    ColumnsAlgorithmSolve warmup2;
    warmup2.solve(problema);
    
    // Medir tiempo del algoritmo por COLUMNAS
    ColumnsAlgorithmSolve estrategiaColumnas;
    inicio =  std::chrono::steady_clock::now();
    std::unique_ptr<Solution> sol2 = estrategiaColumnas.solve(problema);
    fin =  std::chrono::steady_clock::now();
    resultado.tiempo_columnas = std::chrono::duration<double, std::milli>(fin - inicio).count();
    
    // Almacenamos los datos en crudo
    resultados.push_back(resultado);
    std::cout << "✓\n";
  }
  
  return resultados;
}