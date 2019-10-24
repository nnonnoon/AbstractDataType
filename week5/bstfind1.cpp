#include<iostream>
using namespace std;

struct node{
        int data;
        node* left;
        node* right;
};

node* insert(int x, node* t){
    if(t == NULL){
        t = new node();
        t->data = x;
        t->left = NULL;
        t->right = NULL;
    }
    else if(x <= t->data)
        t->left = insert(x, t->left);
    else if(x >= t->data)
        t->right = insert(x, t->right);
    return t;
}


bool search(int x,node* t) {
	if(t == NULL) {
		return false;
	}
	else if(t->data == x) {
		return true;
	}
	else if(x <= t->data) {
		return search(x,t->left);
	}
	else if (x >= t->data) {
		return search(x,t->right);
	}
    return t;
}


int main(){
    int n,k,a,b;
    node *root = NULL; 
    cin>>n;
    for(int i = 0 ; i< n ; i++){
        cin>>k;
        if(k==1){
            cin>>a;
            root=insert(a,root);
        }
        else if (k==2){
            cin>>b;
            if(search(b,root) == true){
                cout<<"1"<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
        }
    }
    return 0;
}