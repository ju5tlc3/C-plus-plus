#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include<algorithm>

using namespace std;


class Matrix
{
public:
    Matrix()
    {
        rows = 0;
        columns = 0;
    }
    Matrix(int num_rows, int num_cols)
    {
        if (num_rows < 0 || num_cols < 0)
        {
            throw out_of_range("Negative value!");
        }
        Reset(num_rows, num_cols);
    }
   void Reset(int new_rows, int new_cols)
    {
       if (new_rows < 0 || new_cols < 0)
       {
           throw out_of_range("Negative value!");
       }
       if (new_rows == 0 || new_cols == 0)
       {
           new_rows = new_cols = 0;
       }
       rows = new_rows;
       columns = new_cols;
       values.assign(rows, vector<int> (columns));
    }

   int At(int num_r, int num_c) const
   {
       return values.at(num_r).at(num_c);
   }

   int& At(int num_r, int num_c)
   {
       return values.at(num_r).at(num_c);
   }

   int GetNumRows() const
   {
       return rows;
   }
   int GetNumColumns() const
   {
       return columns;
   }
private:
    int rows;
    int columns;
    vector<vector<int>> values;
};


istream& operator>>(istream& input, Matrix& data)
{
    int rows, columns, value;
    input >> rows >> columns;
    data.Reset(rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            input >> data.At(i, j);
        }
    }
    return input;
}

ostream& operator<<(ostream& output, const Matrix& data)
{
    output << data.GetNumRows() << " " << data.GetNumColumns() << endl;
    for (int i = 0; i < data.GetNumRows(); i++)
    {
        for (int j = 0; j < data.GetNumColumns(); j++)
        {
            output << data.At(i, j) << " ";
        }
        output << endl;
    }
    return output;
}

bool operator==(const Matrix& first, const Matrix& second)
{
    if (first.GetNumColumns() == second.GetNumColumns() && first.GetNumRows() == second.GetNumRows())
    {
        for (int i = 0; i < first.GetNumRows(); i++)
        {
            for (int j = 0; j < first.GetNumColumns(); j++)
            {
                if (first.At(i, j) != second.At(i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}


Matrix operator+(const Matrix& first, const Matrix& second)
{
    if (first.GetNumColumns() != second.GetNumColumns() || first.GetNumRows() != second.GetNumRows())
    {
        throw invalid_argument("Different number of rows or columns!");
    }
    Matrix matrix(first.GetNumRows(), first.GetNumColumns());
    for (int i = 0; i < first.GetNumRows(); i++)
    {
        for (int j = 0; j < first.GetNumColumns(); j++)
        {
            matrix.At(i, j) = first.At(i,j)+second.At(i,j);
        }
    }
    return matrix;
}


int main() {
  Matrix one;
  Matrix two;

  try
  {
      cin >> one >> two;
      cout << one + two << endl;
  }
  catch (exception& ex)
  {
      cout << ex.what() << endl;
  }
 
  return 0;
}
