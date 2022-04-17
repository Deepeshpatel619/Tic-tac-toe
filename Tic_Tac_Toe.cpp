//This Project is created by Deepesh Patel  
#include <iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void getInput(char mat[][3], int n, char symbol)
{
    int row, col;
    while(true)
    {
       cout << "Enter row and col : \n";
       cin >> row >> col;
       if(row < n && col < n)
       {
        if(mat[row][col]=='.')
        {  mat[row][col] = symbol;
           return ;
        }   

      }

    }
}

//return 1 if player1 win ,return 2 if player2 win ,else return 0
int Win(char mat[][3], int n)  
{
    bool flag;
    char symbol;
    // check for rows
    for (int i = 0; i < n; i++)
    {
        flag = true;
        symbol = mat[i][0];
        int symbolCount=0;
        if (symbol == '.') // first symbol of a row is '.' then continue
            continue;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == '.'||symbol!=mat[i][j])
            {
                flag = false;
                break;
            }
            if(mat[i][j]==symbol){
                symbolCount++;
            }
        }

    
       if (flag&&symbolCount==3)
        {
            if (symbol == 'o')
                return 1;
            else if (symbol == 'x')
                return 2;
        }
    }

    // check for columns
    for (int i = 0; i < n; i++)
    {
        flag = true;
        symbol = mat[0][i];
       int symbolCount=0;
        if (symbol == '.') // first symbol of a column is '.' then continue
            continue;
        for (int j = 0; j < n; j++)
        {
         
            if (mat[j][i] == '.'||symbol!=mat[j][i])
            {
                flag = false;
                break;
            }
            if(mat[j][i]==symbol){
                symbolCount++;
            }
        }
        if (flag&&symbolCount==3)
        {
            if (symbol == 'o')
                return 1;
            else if (symbol == 'x')
                return 2;
        }
    }
    // check for major diagonals
    flag = true;
    symbol = mat[0][0];
    if (symbol != '.') // first symbol of a diagonal is '.' then continue
    {
        int symbolCount=0;
        for (int i = 0, j = 0; i < n; i++, j++)
        {
            if (mat[i][j] != '.'||symbol!=mat[i][j])
            {
                flag = false;
                break;
            }
          if(mat[i][j]==symbol){
                symbolCount++;
            }
        }

        if (flag&&symbolCount==3)
        {
            if (symbol == 'o')
                return 1;
            else if (symbol == 'x')
                return 2;
        }
    }
    // check for minor diagonals
    flag = true;
    symbol = mat[0][n - 1];
    if (symbol != '.')
    {
        int symbolCount=0;
        for (int i = 0, j = n - 1; i < n; i++, j--)
        {
            if (mat[i][j] == '.'||symbol!=mat[i][j])
            {
                flag = false;
                break;
            }
            if(mat[i][j]==symbol){
                symbolCount++;
            }
        }
        if (flag&&symbolCount==3)
        {
            
            if (symbol == 'o')
                return 1;
            else if (symbol == 'x')
                return 2;
        }
    }
    //none of the above condions are satisfied then return 0;
    return 0;
}
bool isDraw(char mat[][3],int n){
    
      for (int  i = 0; i < n; i++)
     {
       for (int  j = 0; j < n; j++)
       {
          if(mat[i][j]=='.'){
            return false;
          }
       }  
    }
    return true;
}
//shows matrix every time
void Show(char mat[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    
      cout << "\n\n\t\t\t#####################\n\n\t\t\t";
                  cout<<"    GAME STARTED!    ";
      cout << "\n\n\t\t\t#####################\n\n\t\t\t\n\n";    
    

    char mat[3][3];
    int n = 3;
    string message;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = '.';
        }
    }
    Show(mat, n);
    int player1 = 1, player2 = 0;
    char symbol;
  
    while (true)
    {

        if (player1 == 1 && player2 == 0)
        {
            cout << "palyer1 chance ...\n";
            symbol = 'o';
            player1 = !player1;
            player2 = !player2;
        }
        else if (player1 == 0 && player2 == 1)
        {
            cout << "palyer2 chance ...\n";
            symbol = 'x';
            player2 = !player2;
            player1 = !player1;
        }
        getInput(mat, n, symbol);
    
        Show(mat, n);

        int p =Win(mat, n);

        if(p)
        {
            if(p==1)
              message="\n\t\t\t    PLAYER1 WON!    \n";
            else
              message="\n\t\t\t    PLAYER2 WON!    \n";
            
            break;
        }

        //if all element of matrix filled and no one won then it is the condition of Draw!
        if(isDraw(mat,n)){
           message="\n\t\t\t      DRAW!    \n";   
           break;         
        }
    }
           cout << "\n\n\t\t\t#####################\n\n\t\t\t";
                        cout<<"    GAME OVER !    ";
                        cout<<message;
          cout << "\n\n\t\t\t#####################\n\n\t\t\t\n\n";    
    

    return 0;
} 
