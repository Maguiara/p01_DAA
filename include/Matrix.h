#pragma once

#include <vector>


class Matriz {
  public:
  
  Matriz() = default;
  Matriz(const int rows, const int columns) : matriz_(rows, std::vector<int>(columns, 0)) {}
  // Matriz(const std::vector<std::vector<int>>& other_matriz) : matriz_(other_matriz) { }
  Matriz(std::vector<std::vector<int>> other_matriz) {
    if (other_matriz.empty()) {
      rows_ = 0;
      columns_ = 0;
      matriz_ = {};
    }
    rows_ = other_matriz.size();
    columns_ = other_matriz[0].size();
    matriz_ = other_matriz;
  }

  const std::vector<std::vector<int>> getMatriz() const { return matriz_; }
  const int getRows() const { return matriz_.size();}
  const int getColumns() const { return matriz_[0].size(); }

  int& operator()(int row, int col) { return matriz_[row][col];}
  const int& operator()(int row, int col) const { return matriz_[row][col]; }

  std::vector<int>& operator[](int row) { return matriz_[row]; }
  const std::vector<int>& operator[](int row) const { return matriz_[row]; }
  
  const int Size() const { return getRows() * getColumns();}


  private:
  int rows_ = 0;
  int columns_ = 0;
  std::vector<std::vector<int>> matriz_;
};