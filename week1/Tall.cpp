#include <iostream>
using namespace std;
int main()
{
    int n;
    int count =0;
    cin>>n;

    int box[n];
    for (int i =0 ; i<n; i++){
        cin>>box[i];
    }
     for (int i = 0 ;i<n; i++){
         for (int j = 0 ; j<n ; j++){
             if (i != j){
                 if (box[i]<box[j]){
                     count +=1;
                }
             }
         }
        cout<<count<<endl;
        count=0;
     }
}