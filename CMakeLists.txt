cmake_minimum_required(VERSION 3.10)

# Información del proyecto
project(DAA_Practica1 
    VERSION 1.0 
    DESCRIPTION "Framework de Análisis Algorítmico (Strategy Pattern)"
    LANGUAGES CXX
)

# ==============================================================================
# 1. Configuración del Compilador (C++17 y Warnings)
# ==============================================================================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)

# Flags de limpieza de código (Professional Mode)
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ==============================================================================
# 2. Configuración de Directorios de Salida (La clave de tu petición)
# ==============================================================================
# Los archivos objeto (.o) se quedarán automáticamente en la carpeta 'build' 
# desde donde ejecutes el comando `cmake`.

# Definimos dónde "escupir" los binarios finales para que no se queden en build:
# .a (Librerías estáticas) -> van a la carpeta /lib del proyecto
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# Ejecutables -> van a la carpeta /bin del proyecto
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Indicamos dónde están los .hpp
include_directories(include)

# ==============================================================================
# 3. Creación de la LIBRERÍA (Core)
# ==============================================================================
# El PDF pide explícitamente "crear esta librería"[cite: 87].
# Recopilamos los fuentes de las estrategias (sin el main)
file(GLOB_RECURSE LIB_SOURCES "src/strategies/*.cpp")

# Creamos la librería estática llamada "daa_strategy"
add_library(daa_strategy STATIC ${LIB_SOURCES})

# ==============================================================================
# 4. Creación del EJECUTABLE (Cliente/Benchmarker)
# ==============================================================================
# Este es el programa que usa la librería para medir tiempos
add_executable(daa_main src/main.cpp)

# Enlazamos el ejecutable con nuestra librería
target_link_libraries(daa_main PRIVATE daa_strategy)

# Mensaje final
message(STATUS "Build configurado:")
message(STATUS " -> Objetos intermedios: En carpeta 'build'")
message(STATUS " -> Librería (.a):       ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message(STATUS " -> Ejecutable:          ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")