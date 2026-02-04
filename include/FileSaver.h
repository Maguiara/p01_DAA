#pragma once

#include <string>

// Responsabilidad: SOLO escribir archivos
class FileWriter {
public:
  static void guardar(const std::string& contenido, const std::string& ruta);
};