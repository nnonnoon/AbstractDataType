#include "stdio.h"
#include <stdlib.h>
#include <math.h> 
using namespace std;

int main(){
    int L,R,j,i;
    int nub = 0;
    scanf("%d",&L);
    scanf("%d",&R);

    int box[R];

    for( i = L ; i<= R ; i++ ){
        //float keep = sqrt(i);
        for( j = 2 ; j <= sqrt(i) ; j++){
            if(i%j==0)
			{
				break;
			}
        }
        if(j==i)
		{
            box[nub] = i;
            nub++;
		}
    }
    
    // for(int n = 0 ; n < nub;  n++){
    //     cout<<box[n]<<" ";
    // }
    // cout<<endl;

    int count = 0 ;
    for(int k = 0 ; k < nub ; k++){
        //for(int p = k ; p < nub ; p++){
            if(abs(box[k]-box[k+1])==2){
                count+=1;
            }
        //}
    }
    printf("%d\n",count);
}

