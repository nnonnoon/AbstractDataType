#include<iostream>
using namespace std;

bool visited[30][30];
char map[30][30];

int walk(int i , int j , int k , int l,int key,int n ){
    // cout << i << ' ' << j << endl;
    //cout << "qweqwrt";
    if(i<0 || j<0 || i>=n || j>=n){
        return 0;
    }
    if(visited[i][j]){
        return 0;
    }
    visited[i][j] = 1;
    if(map[i][j] == '#'){
        return 0;
    }
    if(map[i][j] == 'O'){
        if(key == 1)
            key=0;
        else
            return 0;
    }
    if(map[i][j] == '.' && i==k && j==l){
        return 1;
    }
    
    return walk(i-1,j,k,l,key,n) || walk(i,j-1,k,l,key,n) || walk(i+1,j,k,l,key,n) || walk(i,j+1,k,l,key,n);
}

int main(){
    int n , q ,r,c,a,b;
    cin>>n>>q;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>map[i][j];
        }
    }

    for(int i = 0 ; i < q ; i++){
        cin>>r>>c>>a>>b;
        int key=1;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j < n ; j++){
                visited[i][j] = 0;
            }
        }

        if(walk(r-1,c-1,a-1,b-1,key,n)){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
}