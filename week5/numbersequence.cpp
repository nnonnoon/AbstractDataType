#include<iostream>
#include<math.h>
using namespace std;
int K;
long long int sum[100000];
char box[1000000];

int pan(int x)
{
    int n=0;
    while(x){
        x/=10;
        n++;
    }
    return n;
}


void init()
{
    int i,j,a;
    K=sqrt(2147483647)+1;
    j=1;
    for(i=1;i<=K;i++)
    {
        sprintf(&box[j],"%d",i);
        while(isdigit(box[j]))
            j++;
    }
    a=sum[0]=0;
    for(i=1;i<=K;i++)
    {
        a+=pan(i);
        sum[i]=sum[i-1];
        sum[i]+=a;
    }
}

int main(){
    int n,location,mid,max,min,keep;
    init();
    cin>>n;

    for(int i = 0 ; i<n ;i++){
        cin>>location;
        min = 0 ;
        max = K;
        while(true){
            mid=(min+max)/2;
            if(mid==min)
                break;
            if(sum[mid]>=location)
                max=mid;
            else
                min=mid;
        }
        keep=location-sum[mid];
        cout<<box[keep]<<endl;
    }
}