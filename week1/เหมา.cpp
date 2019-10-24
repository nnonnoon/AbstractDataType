#include<iostream>
using namespace std;

int main(){
    int box[3];
    int n,count1=0,count2=0,count3=0;
    int sum1=0,sum2=0,sum3=0;


    for (int i = 0 ; i<3 ; i++ ){
        cin>>box[i];
    }

    cin>>n;
    int boxtype[n];

    if (3<=n && n<=1000){
        for (int i = 0 ; i<n ; i++){
            cin>>boxtype[i];

            if (boxtype[i]==1){
                count1+=1;
                sum1=count1*box[0];
            }

            else if (boxtype[i]==2){
                count2+=1;
                sum2=count2*box[1];
            }
            else if (boxtype[i]==3){
                count3+=1;
                sum3=count3*box[2];
            }

        }
        cout<<min(min(sum1,sum2),sum3);
            
    }
 }