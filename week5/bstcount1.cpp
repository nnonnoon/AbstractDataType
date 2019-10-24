#include"stdio.h"
using namespace std;

struct node{
    int data;
    int countright;
    node* left;
    node* right;
};

int nub = 0;

node* insert(int x , node* &t){
    if(t == NULL){
        t = new node();
        t -> data = x;
        t -> left = NULL;
        t -> right = NULL; 
    }
    else if (x < t->data){  
        t->left = insert(x,t->left);
    }
    else if(x > t-> data){
        t->countright+=1;
        t->right = insert(x,t->right);
    }
    return t;
}

int count (int x , node* &t ){
    if(t == NULL){
        return 0;
    }
    else if (x > t->data){
        return count(x,t->right);
    }
    else if (x < t->data){
        return count(x,t->left)+t->countright+1;
    }
    else if (x == t->data){
        return t->countright;
    }
    return 0;
}



int main(){
    int m ; 
    int k , val ,nub;
    node* root = 0;
    scanf("%d",&m);

    for(int i = 0 ; i<m ; i++){
        scanf("%d",&k);
        if(k == 1){
            scanf("%d",&val);
            insert(val,root);
        }
        else if (k == 2){
            scanf("%d",&val);
            nub = count(val,root);
            printf("%d\n",nub);
            nub = 0; 
        }
    }
}