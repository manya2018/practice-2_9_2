#include <iostream>
#include <vector>
using namespace std;
class matrix // TASK 1
{
public:
    int row;
    int col;
    vector<vector<int> > mass;
public:                 
    matrix( int row,int col)
    {
         this -> row=row;
         this -> col=col;
        vector< int> c(col, 0);
        for (int i = 0; i < row; i++)
        {
            mass.push_back(c) ;
        }
    }
    matrix operator +( const matrix & other)                              // TASK 4
    {
        matrix A(other.row,other.col);
        for (int i=0; i< other.row;i++)
        {
            for (int j=0; j<other.col;j++)
            {
                A.mass[i][j]=other.mass[i][j]+ this -> mass[i][j];
            }
        }
        return A;

    }

    void fill()                                                         
    {
        int x;
        int j=0;
        cout << " enter an array " << endl;
        for (int i=0; i<row;i++)
        {
            for (int j=0; j<col;j++)
            {
                cin >> x;
                mass[i][j]=x;
            }
            cout << endl;

        }
    };
    void print()                                                    
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                cout << mass[i][j] << ' ';
            cout << endl;
        }
    }
    void transposition()                                                // TASK 3
    {
        vector<vector<int>> A;
        vector<int> B;
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                B.push_back(mass[j][i]);
            }
            A.push_back(B);
            B.clear();
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mass[i][j]=A[i][j];
            }
        }

    }


};
void summation(matrix A, matrix B)                                                  // TASK 2
{
    vector<vector<int>> C(A.row,vector<int>(A.col));

    for (int i = 0; i < A.row ; i++)
    {
            for (int k = 0; k < A.col ; k++)
            {
                C[i][k] = A.mass[i][k] + B.mass[i][k];
                cout << C[i][k] << " ";
            }
            cout<< endl;

    }

}

int main() {
    matrix A(2,2);
    A.fill();
    matrix B(2,2);
    B.fill();
    matrix C= A + B;
    C.print();





    return 0;
}
