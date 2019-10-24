#include "stdio.h"
int main(){
    int  n , m ;
    int count;
    char box[110][110] = {0};
    do {
        scanf("%d",&n);
        if(n == 0) break;
        scanf("%d",&m);
        count = 0;
        for (int row = 0 ; row<n; row++){
            scanf("%s", box[row]);
        }
        for (int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                for(int k = i ; k < n && box[k][j] == '1'; k++){
                    for(int l = j ; l < m && box[k][l] == '1'; l++){
                        bool count_check = true;
                        for(int row = i ; row <= k ; row++){
                            for (int col = j ; col <= l ; col++){                                
                                if(box[row][col] == '0'){
                                    count_check = false;
                                    goto fuck;
                                }
                            }
                        }
                        fuck:
                        if(count_check == true){
                            count++;
                        }
                    }
                }
            }
        }
        printf("%d\n",count);
    } while(1);
}