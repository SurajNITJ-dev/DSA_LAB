#include <iostream>
using namespace std;

int main() {
    int m, n;

    cout << "Enter number of rows (m) and columns (n): ";
    cin >> m >> n;

    int matrix[m][n];
  
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            
        }
    }

    cout << "Row\tCol\tValue\n";
   
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]!=0){
                cout<<i<<"\t"<<j<<"\t"<<matrix[i][j]<<endl;
            }
            
        }
    }

    return 0;
}