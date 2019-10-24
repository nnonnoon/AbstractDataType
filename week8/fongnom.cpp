#include<iostream>
using namespace std;

int box[1000001];
int find (int val){
    if(box[val] == val){
        return val;
    }
    else {
        return find(box[val]);
    }
}


int main(){
    int n,q;
    char ask; 
    int fong1 , fong2;
    scanf("%d",&n);
    scanf("%d",&q);
    for(int i = 1 ; i<=n ; i++){
        box[i] = i;
    }
    for (int i = 1 ; i<=q ; i++){
        scanf(" %c",&ask);
        scanf("%d",&fong1);
        scanf("%d",&fong2);
        if (ask == 'q'){
            //printf("fong1 = %d fong2 = %d\n",find(fong1),find(fong2));
            if (find(fong1) == find (fong2)){
                printf("yes\n");
            }
            else
                printf("no\n");
        }   
        else if (ask == 'c'){
            int x=find(fong1);
            int y=find(fong2);
            if(x<y){
                box[y]=x;
            }
            else if(y<x){
                box[x]=y;
            }
        }
    }
}