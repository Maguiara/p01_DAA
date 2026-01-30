# Diseño y Análisis de Algoritmos - Framework de Análisis

Este repositorio contiene la implementación de un framework genérico para la ejecución y análisis de algoritmos, desarrollado como parte de la asignatura **Diseño y Análisis de Algoritmos**.

El proyecto ha sido diseñado siguiendo estrictamente los principios **SOLID** y utilizando el patrón de diseño **Estrategia (Strategy Pattern)** para permitir la intercambiabilidad dinámica de algoritmos y facilitar la extensibilidad en futuras prácticas.

## 🚀 Objetivos del Proyecto

El objetivo principal es desacoplar la lógica de los algoritmos de la gestión de datos y la medición de rendimiento. Para la **Práctica 1**, se implementan estrategias para el **Producto de Matrices**, permitiendo comparar el rendimiento según el acceso a memoria:

* **Implementación de Arquitectura Flexible:** Uso de interfaces genéricas (`IStrategy`, `IInstance`, `ISolution`).
* **Análisis de Complejidad:** Comparación empírica de tiempos de ejecución.
* **Cumplimiento de SOLID:** Énfasis en el *Single Responsibility Principle* y *Open/Closed Principle*.

## 🛠️ Arquitectura y Patrones de Diseño

El núcleo del proyecto se basa en la abstracción del problema computacional:

> "Un algoritmo es una caja negra que recibe una Instancia y devuelve una Solución."

### Estructura de Clases
[cite_start]El diseño sigue el patrón **Strategy**[cite: 71, 74]:

1.  **Contexto:** El cliente o benchmarker que ejecuta el algoritmo.
2.  [cite_start]**Interfaz (Strategy):** Define el contrato `solve(Instance) -> Solution`[cite: 78].
3.  **Estrategias Concretas:**
    * [cite_start]`RowMajorMultiplication`: Recorrido optimizado por filas[cite: 89].
    * [cite_start]`ColMajorMultiplication`: Recorrido por columnas[cite: 90].

Esta arquitectura permite añadir nuevos problemas (ej. ordenación, grafos) sin modificar el código base del benchmarker.

## 📂 Estructura del Repositorio

El proyecto separa claramente la definición (interfaces) de la implementación:

```text
.
├── CMakeLists.txt          # Configuración de compilación (CMake)
├── docs/                   # Documentación e informes de rendimiento
├── include/                # Archivos de cabecera (.hpp)
│   ├── interfaces/         # Definiciones abstractas (IStrategy, etc.)
│   └── strategies/         # Cabeceras de algoritmos concretos
├── src/                    # Código fuente (.cpp)
│   ├── strategies/         # Implementación de la lógica de algoritmos
│   └── main.cpp            # Punto de entrada y análisis de tiempos
└── README.md               # Este archivo