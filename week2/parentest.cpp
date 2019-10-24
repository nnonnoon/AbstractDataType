#include<iostream>
using namespace std;

int main(){
    int n ,count1 = 0,count2 = 0,count3 = 0,count4 = 0,count5 = 0,count6 = 0; 
    cin >> n ;
    string b[n];
    if (n>=1 && n<=20){
        for (int i =0 ; i < n ; i++){
            cin >> b[i];
        }
    }
    for(int i =0 ; i < n ; i++){
        if (b[i].length()<=100){
          for (int j = 0 ; j<b[i].length() ; j++){
            if (b[i][j] == '('){
                count1+=1;
            }
            else if (b[i][j] == '['){
                count2+=1;
            }
            else if (b[i][j] == '{'){
                count3+=1;
            }
            else if (b[i][j] == ')'){
                count4+=1;
            }
            else if (b[i][j] == ']'){
                count5+=1;
            }
            else if (b[i][j] == '}'){
                count6+=1;
            }
          }
        }
        if (count1 == count4 && count2 == count5 && count3 == count6){
            cout<< "yes"<<endl; 
        }
        else{
            cout<< "no"<<endl; 
        }
        count1 = 0;
        count2 = 0;
        count3 = 0;
        count4 = 0;
        count5 = 0;
        count6 = 0;
        }     
}