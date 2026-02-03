#pragma once

#include <vector>


class Matriz {
  public:

  Matriz() = default;
  Matriz(const int rows, const int columns) : matriz_(rows, std::vector<int>(columns, 0)) { }

  const std::vector<std::vector<int>> getMatriz() const { return matriz_; }
  const int getRows() const { return matriz_.size();}
  const int getColumns() const { return matriz_[0].size(); }

  int& operator()(int row, int col) { return matriz_[row][col];}
  const int& operator()(int row, int col) const { return matriz_[row][col]; }
  
  const int Size() const { return getRows() * getColumns();}


  private:
  std::vector<std::vector<int>> matriz_;
};