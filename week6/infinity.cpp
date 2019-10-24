#include<iostream>
#include <stdlib.h>
using namespace std;


int main(){
    int num_dao,tod;
    cin>>num_dao;
    int x[num_dao];
    int y[num_dao];
    int r[num_dao];
    int min = 0;

    for (int i = 0 ; i < num_dao ; i++){
        cin>>x[i]>>y[i]>>r[i];
    }

    for (int i = 0 ; i < num_dao ; i++){
        tod = 0;
        if(x[i] == 0 && y[i] == 0){
            min = -1;
            break;
        }
        if (y[i]>0){
            tod = y[i]-r[i];
            if (tod > 0){  
                if (min == 0){
                    min = tod;
                }
                else if (tod<min){
                    min = tod;
                }
            }
            else{
                min = -1;
                break;
            }
        }
        else if (y[i]<0){
            tod = y[i]+r[i];
            if (tod<0 ){
                if (min == 0){
                    min = abs(tod);
                }
                else if (abs(tod)<min){
                    min = abs(tod);
                }
            }
            else{
                min = -1;
                break;
            }
        }
        else if (y[i]== 0){
            min = -1;
            break;
        }
    }
    cout<<min<<endl;
}