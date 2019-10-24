#include <iostream>
#include <cmath>
using namespace std;

int main (){
    int n, x ,y , score ;
    float dis;
    cin>>n;
    int boxx[n];
    int boxy[n];
    for (int i = 0 ; i<n ; i++ ){
        cin>>boxx[i]>>boxy[i];
    }

    for (int i = 0 ; i<n ; i++ ){
        dis = sqrt(pow(boxx[i],2)+pow(boxy[i],2));

        if (dis<=2){
            score+=5;
        }
        else if (2<dis && dis <=4){
            score+=4;
        }
        else if (4<dis&& dis<=6){
            score+=3;
        }
        else if (6<dis && dis <=8){
            score+=2;
        }
        else if (8<dis && dis<=10){
            score+=1;
        }
        else{
            score+=0;
        }
    }

    cout<<score;

}