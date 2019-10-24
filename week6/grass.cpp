#include<iostream>
using namespace std;

int main(){
    int n , m;
    cin >> n; 
    cin>> m;
    char map [n][n];
    char  a[m];
    int b[m];

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            cin >> map[i][j];
        }
    }

    for (int i = 0 ; i < m ; i++){
        cin>>a[i];
        cin>>b[i];
    }

    for (int i = 0 ; i < m ; i++){
        if (a[i] == 'L'){
            for (int col  = 0 ; col < n ; col++){
                if (map[b[i]-1][col] == 'x'){
                    if (map[b[i]-1][col+1] != '.' || map[b[i]-1][col+1] != '#'){
                       map[b[i]-1][col] = '.';
                    }
                }
                else{
                        break;
                }
            }
        } 
        else if (a[i] == 'R'){
            for (int col  = n-1 ; col >= 0 ; col--){
                if (map[b[i]-1][col] == 'x'){
                    if (map[b[i]-1][col-1] != '.' || map[b[i]-1][col-1] != '#'){
                       map[b[i]-1][col] = '.';
                    }
                }
                else{
                    break;
                }
            }
        }
        else if (a[i] == 'U'){
            for (int row = 0 ; row < n ; row++){
                if (map[row][b[i]-1] == 'x'){
                    if (map[row+1][b[i]-1] != '.' || map[row+1][b[i]-1] != '#'){
                       map[row][b[i]-1] = '.';
                    }
                }
                else{
                    break;
                }
            }
        }
        else if (a[i] == 'D'){
            for (int row = n-1 ; row >=0 ;row--){
                if (map[row][b[i]-1] == 'x'){
                    if (map[row-1][b[i]-1] != '.' || map[row-1][b[i]-1] != '#'){
                       map[row][b[i]-1] = '.';
                    }
                }
                else{
                    break;
                }
            }
        }
        else if (a[i]  == 'A'){
            for (int col = 0 ; col < n ; col++){
                if (map[b[i]-1][col] != '#'){
                    map[b[i]-1][col] = 'x';
                }
            }
        }
        else if (a[i]  == 'B'){
            for (int col = 0 ; col < n ; col++){
                if (map[col][b[i]-1] != '#'){
                    map[col][b[i]-1] = 'x';
                }
            }
        }
    }

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            cout << map[i][j];
        }
        cout<<endl;
    }
}