#pragma once

#include <vector>


#pragma once

#include <vector>

class Matriz {
  public:
  
  Matriz() = default;
  
  Matriz(const int rows, const int columns) 
    : rows_(rows), columns_(columns), matriz_(rows * columns, 0) {}
  
  Matriz(const std::vector<long long>& other_matriz, int rows, int columns) {
    if (other_matriz.empty()) {
      rows_ = 0;
      columns_ = 0;
      matriz_ = {};
      return;
    }
    rows_ = rows;
    columns_ = columns;
    matriz_ = other_matriz;
  }

  const std::vector<long long>& getMatriz() const { return matriz_; }
  
  const int getRows() const { return rows_; }
  const int getColumns() const { return columns_; }

  long long& operator()(int row, int col) {  return matriz_[row * columns_ + col];}
  const long long& operator()(int row, int col) const { return matriz_[row * columns_ + col]; }

  long long& operator[](int index) { return matriz_[index]; }
  const long long& operator[](int index) const { return matriz_[index]; }
  
  const int Size() const { return rows_ * columns_; }

  private:
  int rows_ = 0;
  int columns_ = 0;
  std::vector<long long> matriz_;
};