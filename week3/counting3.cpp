#include<iostream>
using namespace std;

int main(){
    int n,m,tmp;
    scanf("%d", &n);
    int count;
    char box[110][110] = {0};
    int s[110][110];

    while(n!=0){
        scanf("%d", &m);
        count = 0;
        for (int row = 0 ; row<n; row++){
            scanf("%s", box[row]);
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                s[i][j] = box[i][j] - '0';
                if (i>=0 && j >=0 ){
                    s[i][j]+= s[i-1][j-1];  
                }
                if(i>=0 && j-1 >=0){
                    s[i][j]+= s[i][j-1];  
                }
                if(i-1 >=0 && j-1 >=0){
                    s[i][j]-= s[i-1][j-1];
                }
            }
        }

        for(int i = 0 ; i < n  ; i++){
            for(int j = 0 ; j < m ; j++){
                for(int k = i ; k < n ; k++){
                    for(int l = j ; l < m ; l++){
                        tmp = s[k][l] - s[i-1][l] - s[i][j-1]+s[i-1][j-1];
                        if(tmp == s[k-i+1][l-j+1]){
                            count++;
                        }
                    }
                }
            }
        }
        printf("%d\n",count);
        scanf("%d", &n);
    }
}

