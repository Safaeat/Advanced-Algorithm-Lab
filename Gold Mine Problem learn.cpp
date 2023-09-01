#include <bits/stdc++.h>
using namespace std;

int GoldMine(int** Gold_Mine, int rows, int columns)
{
//creating the table for updated values
int max_gold[rows][columns];
memset(max_gold, 0, sizeof(max_gold));
for (int i = 0; i < rows; i++)
  max_gold[i][0] = Gold_Mine[i][0];
  //traversing columns one by one
  for (int j = 1; j < columns; j++) {
     for (int i = 0; i < rows; i++) {
     //original value of cell
     max_gold[i][j] = Gold_Mine[i][j];
     //temporary variable 'temp' to find maximum out of possible moves
     int temp = max_gold[i][j - 1];           //cell to immediate left
     if (i - 1 >= 0) {                        //if there exists a row above,
        if (temp < max_gold[i - 1][j - 1])    //compare immediate left to
                                              //left upper diagonal
            temp = max_gold[i - 1][j - 1];
          }
        if (i + 1 < rows) {                   //if there exists a row below,
           if (temp < max_gold[i + 1][j - 1]) //compare immediate left to
                                              //left lower diagonal
               temp = max_gold[i + 1][j - 1];
               }
               max_gold[i][j] += temp;        //add maximum of immediate left,
                                              //left upper diagonal or left
        }                              //lower diagonal to original value of cell
   }
// selecting maximum from the last column
int gold = max_gold[0][columns - 1];
   for (int i = 1; i < rows; i++) {
       if (max_gold[i][columns - 1] > gold)
          gold = max_gold[i][columns - 1];
   }
 return gold;
}
int main()
{
int rows, item, columns;
cout << "Enter the number of rows    : ";
cin >> rows;
cout << "Enter the number of columns : ";
cin >> columns;
cout << "Enter values of the matrix row-wise : \n";
int** Gold_Mine = (int**)(malloc(sizeof(int*) * rows));
//Taking input of matrix cells
  for (int j = 0; j < rows; j++) {
      Gold_Mine[j] = (int*)(malloc(sizeof(int) * columns));
      for (int k = 0; k < columns; k++){
          cout<<"Enter matrix value at position ("<<j<<","<<k<<"): ";
          cin >> Gold_Mine[j][k];
      }
  }
  cout << "\n Max amount of gold that can be collected by the miner is: " << GoldMine(Gold_Mine, rows, columns) << " units "<<endl;
return 0;
}

