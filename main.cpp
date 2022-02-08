#include <iostream>
#include <vector>
#include <utility>
#include "dst/superHashTable.h" /* i wrote this one myself because the hasfunction of
                        unordered_Map cannot hash pair*/
#include "dst/hashTable.h" /*also, wrote this one myself*/
#include <cmath>
#include <fstream>


using namespace std;

bool findSquareOneMatrix(int** matrix, int m, int n);
int** matrixTranspose(int** matrix, int m, int n);
void readMatrix(int** matrix, string filename);
void printMatrix(int** matrix, int m, int n);

int main(int argc, char *argv[]) {

    if(argc != 2){
        throw runtime_error("invalid number of inputs: should be 2");
    }

    int m, n;
    string filename = argv[1];
    ifstream input;
    input.open(filename);
    input >> m >> n;
    int** matrix;
    matrix = new int*[m];
    for(int i=0; i<m; i++) {
        matrix[i] = new int[n];
    }

    cout<<"inspecting "<< m <<" by "<< n <<" matrix: "<<filename<<"\n";


    readMatrix(matrix, filename);
    printMatrix(matrix, m, n);


    if(n>m){
        matrix = matrixTranspose(matrix,m,n);
        int temp = m;
        m = n;
        n = temp;
    }
    

    bool result = findSquareOneMatrix(matrix, m, n);
    if(result){
        cout<<"has square of one\n";
    }
    else{
        cout<<"does not have square of one\n";
    }

    for(int i=0; i<m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

bool findSquareOneMatrix(int** matrix, int m, int n) {
    /*
    This SuperHashTable S hashes pairs of columns with one in the same row to
    another HashTable.
    */
    SuperHashTable* S = new SuperHashTable();

    for(int row=0; row<m; row++) {
        vector<int> C;
        for(int col=0; col<n; col++) {
            if(matrix[row][col]==1) {
                C.push_back(col);
              }
        }
        for(int i=0; i<C.size(); i++) {
            for(int j=i+1; j<C.size(); j++) {
                pair<int,int> pairOfColumnsWithOne;
                pairOfColumnsWithOne.first = C[i];
                pairOfColumnsWithOne.second = C[j];

                if(!S->contains(pairOfColumnsWithOne)) {
                    /*
                    This HashTable rowNeeded hash int to int HashTable that
                    stores rows that we need inorder to
                    form a square of ones with the previoses rows.

                    For example, if we found a pair of columns (3,6) at row 7,
                    a (K,V) of (10,10) will be inserted.
                    If we found a pair of columns (9,10) at row 1,
                    a (K,V) of (2,2) will be inserted

                    ***This is possible because we scan from up down***
                    */
                    HashTable* rowNeeded = new HashTable();
                    int columnDifference = pairOfColumnsWithOne.first
                                            - pairOfColumnsWithOne.second;
                    columnDifference = abs(columnDifference);
                    rowNeeded->insert(row+columnDifference,row+columnDifference);
                    S->insert(pairOfColumnsWithOne, rowNeeded);
                }
                else {
                    if (S->get(pairOfColumnsWithOne)->contains(row)) {
                        /*
                        If row is already in rowNeeded of this key:pairOfColumnsWithOne,
                        it means that the program successfully find a square.
                        */
                        delete S;
                        return true;
                    }
                    /*
                    If row is NOT already in rowNeeded of this key:pairOfColumnsWithOne,
                    the program insert another row into the HashTable.
                    */
                    int columnDifference = pairOfColumnsWithOne.first
                                            - pairOfColumnsWithOne.second;
                    columnDifference = abs(columnDifference);
                    S->get(pairOfColumnsWithOne)
                     ->insert(row+columnDifference,row+columnDifference);
                }
            }
        }

    }
    delete S;
    return false;
}



int** matrixTranspose(int** matrix, int m, int n){
    int** newMatrix = new int*[n];
    for(int i =0; i<n; i++) {
        newMatrix[i] = new int[m];
        for(int j = 0; j<m; j++){
            newMatrix[i][j] = matrix[j][i];
        }
    }

    for(int i=0; i<m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return newMatrix;
}

void readMatrix(int** matrix, string filename) {
  ifstream input;
  input.open(filename);
  int m, n;
  input >> m >> n;
  for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
          input >> matrix[i][j];
      }
  }
}

void printMatrix(int** matrix, int m, int n){
  cout<<"--------------------------------------------\n";
  for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
          cout << matrix[i][j] << "   ";
      }
      cout<<endl;
  }
  cout<<"--------------------------------------------\n";
}
