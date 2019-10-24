#include<iostream>
using namespace std;

struct node{
        int val;
        int ht;
        node* left;
        node* right;
};

node *newnode(int x){
    node *root=new node();
    root->val = x;
    root->left=NULL;
    root->right=NULL;
    root->ht=0;
    return root;
}

int height(node *root){
    if(root==NULL){return -1;}
    return root->ht;
}

int max(int a, int b)
{
    return (a >= b)? a : b;
}

int bf(node *root){
    if(root==NULL){return 0;}
    int b = height(root->left)-height(root->right);
    return b;
}

node *leftrotate(node *x){
    node *y = x->right;
    node *t2 = y->left;
    
    y->left=x;
    x->right=t2;
    
    x->ht =  1 +max(height(x->left), height(x->right));
    y->ht =  1 +max(height(y->left), height(y->right));
    
    return y;
}

node *rightrotate(node *x){
    node *y=x->left;
    node *t2 = y->right;
    
    y->right=x;
    x->left=t2;
    
    x->ht =  1 +max(height(x->left), height(x->right));
    y->ht =  1 +max(height(y->left), height(y->right));
    
    return y;
}

node * insert(node * root,int val)
{
 node *n=newnode(val);
    if(root==NULL){return n;}
    if(val<root->val){
        root->left=insert(root->left,val);
    }
    if(val>=root->val){
        root->right=insert(root->right,val);
    }
    
    root->ht = 1 +max(height(root->left), height(root->right));
    int b = bf(root);
    
    if(b>1 && bf(root->left)>0){
        return rightrotate(root);
    }
    if(b<-1 && bf(root->right)<0){
        return leftrotate(root);
    }
    if(b>1 && bf(root->left)<0){
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if(b<-1 && bf(root->right)>0){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    } 
    return root;
}


bool search(int x,node* t) {
	if(t == NULL) {
		return false;
	}
	else if(t->val == x) {
		return true;
	}
	else if(x <= t->val) {
		return search(x,t->left);
	}
	else if (x >= t->val) {
		return search(x,t->right);
	}
    return t;
}


int main(){
    int n,k,a,b;
    node *root = NULL; 
    scanf("%d",&n);
    for(int i = 0 ; i< n ; i++){
        scanf("%d",&k);
        if(k==1){
            scanf("%d",&a);
            root=insert(root,a);
        }
        else if (k==2){
           scanf("%d",&b);
            if(search(b,root) == true){
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
    }
    return 0;
}