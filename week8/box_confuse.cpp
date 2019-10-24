#include<iostream>
using namespace std;

int main(){
    int n;
    char rub;
    cin >> n;

    int map [n][n];

    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < n ;j++){
            cin >> rub;
            if(rub == '.'){
                map[i][j] = 1;
            }
            else if (rub == '\\'){
               map[i][j] = 2;
            }
            else if (rub == '/'){
               map[i][j] = 3;
            }
        }
    }

    // state = 1; ขวา
    // state = 2; ซ้าย
    // state = 3; ลง
    // state = 4; ขึ้น
    int up_end = n - 1;
    int zero = 0;
    int row ;
    int colum ;
    int state,setState;
    bool isZeroToEnd = true;
    
    for(int sum = 0 ; sum < 4 ;sum++){
        int *tmp_r;
        int *tmp_c;
        int start, end, dis;
        int i;
        if(sum == 0){ // start at left
                start = 0;
                end = n;
                dis = -1;
                setState = 1;
                tmp_r = &i;
                tmp_c = &zero;
                isZeroToEnd = true;
                
        }
        else if(sum == 1){ // bot
                start = 0;
                end = n;
                dis = -1;
                setState = 4;
                tmp_r = &up_end;
                tmp_c = &i;
                isZeroToEnd = true;
        }
        else if(sum == 2){ // right
                start = n-1;
                end = 0;
                dis = 1;
                setState = 2;
                tmp_r = &i;
                tmp_c = &up_end;
                isZeroToEnd = false;
        }  
        else if(sum == 3){ // top
                start = n-1;
                end = 0;
                dis = 1;
                setState = 3;
                tmp_r = &zero;
                tmp_c = &i;
                isZeroToEnd = false;
        }
        // cout<< "sum : " << sum << " ---------\n";
        for(i = start ; (isZeroToEnd)? (i<end) : (i>=0) ;i = i - dis){
        state = setState;
        row = *tmp_r;
        colum = *tmp_c;        
      
        while(row>=0 && row<n && colum>=0 && colum<n){
            // cout << row << " " << colum << " debug" << endl;
            if(map[row][colum] == 1){ // .
                if (state == 1){ // r
                    colum++;
                    state = 1;
                }
                else if (state == 2){ // l
                    colum--;
                    state = 2;
                }
                else if (state == 3){ // d
                    row++;
                    state = 3;
                }
                else if (state == 4){ // u
                    row--;
                    state = 4;
                }
            }
            
            else if(map[row][colum] == 2){ /* \ */
                if (state == 1){ // r
                    row++;
                    state = 3;
                }
                else if (state == 2){ // l
                    row--;
                    state = 4;
                }
                else if (state == 3){ // d
                    colum++;
                    state = 1;
                }
                else if (state == 4){ // u
                    colum--;
                    state = 2;
                }
            }

            else if(map[row][colum] == 3){ // /
                if (state == 1){ // r
                    row--;
                    state = 4;
                }
                else if (state == 2){ // l
                    row++;
                    state = 3;
                }
                else if (state == 3){ // d
                    colum--;
                    state = 2;
                }
                else if (state == 4){ // u
                    colum++;
                    state = 1;
                }
            }
        }

        
        if(state == 1){ // r
            colum--;
            cout << 3*n - row << endl;
        }
        else if (state == 2){ // l
            colum++;
            cout << row+1 <<  endl;
        }
        else if (state == 3){ // d
            row--;
            cout << n+colum+1 << endl;
        }
        else if (state == 4){ // u
            row++;
            cout << 4*n-colum << endl;
        }
        // cout << row << "," << colum << endl << ' ';
        }

    }
}
    
