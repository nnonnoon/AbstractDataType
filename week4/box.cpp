#include<iostream>
using namespace std;

char map[40][40];
bool visited[40][40];
char box[40][40];

int walk(int i , int j,int n, int m){
    if(i<0 || j<0 || i> n || j>m){
        return 0;
    }
    if(visited[i][j]){
        return 0;
    }
    visited[i][j] = 1;
    if(map[i][j] == '#'){
        return 0;
    }
    if(map[i][j] == '.' && i==n-1){
        return 1;
    }
    // cout << "qweqwrt";
    return walk(i-1,j,n,m)||walk(i+1,j,n,m)||walk(i,j+1,n,m)||walk(i,j-1,n,m);
}



int main(){
    int row , col;
    int check = 0;
    cin>>row>>col;

    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin>>box[i][j];
        }
    }

    for(int i = 0 ; i < row; i++ ){
        for(int j = 0 ; j < col;j++){
            if(box[i][j]=='.' && box[i+1][j]=='.' && box[i][j+1]=='.' && box[i+1][j+1]=='.'){
                map[i][j]='.';
            }
            else{
                map[i][j]='#';
            }
        }
    }
    // for(int i = 0 ; i < row ; i++ ){
    //     for(int j = 0 ; j < col ;j++){
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }

    for(int j = 0 ; j < col ; j++){
        if(walk(0,j, row-1, col-1)){
            check +=1;
        }
    } 

    if(check>0){
        cout<<"yes"<<endl;
    }  
    else{
        cout<<"no"<<endl;
    }
}
