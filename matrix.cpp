#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

class Matrix {
  public:
    Matrix ()
    {
      cols = 0;
      rows = 0;
      matrix.clear();
    }

    Matrix(int num_rows, int num_cols)
    {
      Reset(num_rows, num_cols);
    }

    void Reset(int num_rows, int num_cols)
    {
      if (num_rows < 0 || num_cols < 0)
      {
        throw std::out_of_range("");
      }
      rows = num_rows;
      cols = num_cols;
      matrix.assign(rows, std::vector<int>(cols));
    }

    int At(int index_row, int index_col) const
    {
      if (index_row < 0 || index_row >= rows || index_col < 0 || index_col >= cols)
      {
        throw std::out_of_range("");
      }
      return matrix.at(index_row).at(index_col);
    }

    int& At(int index_row, int index_col) 
    {
      return matrix.at(index_row).at(index_col);
    }

    int GetNumRows() const
    {
      return rows;
    }

    int GetNumColumns() const
    {
      return cols;
    }

    friend std::istream& operator>> (std::istream& out, Matrix& m);
    friend std::ostream& operator<< (std::ostream& out, const Matrix& m);
    friend bool operator== (const Matrix& m1, const Matrix& m2);
    friend Matrix operator+ (const Matrix& m1, const Matrix& m2);

  private:
    std::vector<std::vector<int>> matrix;
    int cols;
    int rows;
};

std::istream& operator>> (std::istream& in, Matrix& m)
{
  in >> m.rows >> m.cols;
  m.Reset(m.rows, m.cols);
  for (int i = 0; i < m.rows; ++i)
  {
    for (int j = 0; j < m.cols; ++j)
    {
      in >> m.matrix.at(i).at(j);
    }
  }
  return in; 
}

std::ostream& operator<< (std::ostream& out, const Matrix& m)
{
  out << m.rows << " " << m.cols << "\n";
  for (int i = 0; i < m.rows; ++i)
  {
    for (int j = 0; j < m.cols; ++j)
    {
      out << m.matrix.at(i).at(j) << " ";
    }
    out << "\n";
  }
  return out;
}

bool operator== (const Matrix& m1, const Matrix& m2)
{ 
  if ((m1.cols == 0 || m1.rows == 0) && (m2.cols == 0 || m2.rows == 0))
  {
    return true;
  }

  if (m1.cols != m2.cols || m1.rows != m2.rows)
  {
    return false;
  }
  
  for (int i = 0; i < m1.rows; ++i)
  {
    for (int j = 0; j < m1.cols; ++j)
    {
      if (m1.matrix.at(i).at(j) != m2.matrix.at(i).at(j))
      {
        return false;
      }
    }
  }
  return true;
}

Matrix operator+ (const Matrix& m1, const Matrix& m2)
{
  if ((m1.cols == 0 || m1.rows == 0) && (m2.cols == 0 || m2.rows == 0))
  {
    Matrix result;
    return result;
  }

  if (m1.cols != m2.cols || m1.rows != m2.rows)
  {
    throw std::invalid_argument("");
  }

  Matrix result(m1.rows, m1.cols);

  for (int i = 0; i < m1.rows; ++i)
  {
    for (int j = 0; j < m1.cols; ++j)
    {
      result.matrix.at(i).at(j) = m1.matrix.at(i).at(j) + m2.matrix.at(i).at(j);
    }
  }
  return result;
}

/*int main() {
  Matrix one;
  Matrix two;

  std::cin >> one >> two;
  std::cout << one + two << std::endl;
  return 0;
}*/