#include<iostream>
#include<algorithm>
using namespace std;
 
int main()
{
    int y,p,i;
    while(cin>>y){
        cin>>p;
        int arr[p];
        for(i=0;i<p;i++)
        {
            cin>>arr[i];      
        }
        int st=0,end=0;
        int max=1;
        int max_st=arr[0];
        int max_end=arr[0];
        while(end<(p-1))   
        {
            end++;
            while((arr[end]-arr[st]) >= y)
            {
                st++;
            }
            if((end-st+1) > max)   {
                max=end-st+1;
                max_st=arr[st];
                max_end=arr[end];
            }       
        }
        cout<<max<<" "<<max_st<<" "<<max_end<<endl;
    } 
}



