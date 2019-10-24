#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* insert(node* t,int x){
    if (t==NULL){
        t = new node();
        t->data = x;
        t->left = NULL;
        t->right = NULL;
    }
    else if (x <= t->data){
        t->left = insert(t->left,x);
    }
    else if (x >= t->data){
        t->right =  insert(t->right,x);
    }
    return t;
}

node* print_tree(node* t,int x){
    if (t != NULL){
        print_tree(t->right,x+1);
        for(int i = 0 ; i < x ; i++){
            cout<<"...";
        }
        cout<<"*"<<" "<<t->data<<endl;
        print_tree(t->left,x+1);
    }
    return t;
}

int main(){
    int n,k;
    cin>>n;
    node* root = NULL;

    for (int i = 0 ; i<n ; i++){
        cin>>k;
        root=insert(root,k);
    }
    print_tree(root,0);
}