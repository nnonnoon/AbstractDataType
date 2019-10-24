#include <iostream>
using namespace std;

int main() {
    int n,m;
    char box[110][110];
    do {
        scanf("%d", &n);
        if(n == 0) break;
        scanf("%d", &m);
        for(int i=0;i<n;i++)
            scanf("%s", box[i]);
        int count = 0;
        for(int i=0;i<n;i++) 
            for(int j=0;j<m;j++)
                for(int k=i;k<n&&box[k][j]=='1';k++)
                    for(int l=j;l<m&&box[k][l]=='1';l++) {
                        int check = 1;
                        for(int r=i;r<=k;r++)
                            for(int c=j;c<=l;c++)
                                if(box[r][c] == '0')
                                    check = 0;
                        if(check)
                            count++;
                    }
        printf("%d\n", count);
    } while(1);
}