#include "stdio.h"

int main(){
     int n,m;

     scanf("%d", &n);
     int count;
     char box[110][110] = {0};
     while(n!=0){ 
        scanf("%d", &m);
        count=0;
        for (int row = 0 ; row<n; row++){
                scanf("%s", box[row]);
        }

        for (int nub_row = 1 ; nub_row<n+1; nub_row++){
            for (int nub_col = 1 ; nub_col<m+1 ; nub_col++){
                for (int row = 0 ; row<=n-nub_row ; row++){
                    for(int col = 0 ; col<=m-nub_col ; col++){
                       bool is_rect = true;
                       for (int check_row = 0 ; check_row<nub_row ; check_row++ ){
                           for (int check_col = 0 ; check_col<nub_col ; check_col++ ){
                                if (box[row+check_row][col+check_col] == '0'){
                                    is_rect = false;
                                    break;
                                }   
                           }
                           if(!is_rect) break;
                        }
                        if(is_rect){
                            count+=1;
                        }
                  }
                }
            }
        }
        printf("%d\n",count);
        scanf("%d", &n);
     } 
}


