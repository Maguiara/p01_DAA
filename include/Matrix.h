#pragma once

#include <vector>


class Matriz {
  public:

  Matriz() = default;
  Matriz(const int rows, const int columns) { }
  const std::vector<std::vector<int>> getMatriz() const { return matriz_; }

  const int getRows() const { return matriz_.size();}
  const int getColumns() const { return matriz_[0].size(); }


  private:
  std::vector<std::vector<int>> matriz_;
};