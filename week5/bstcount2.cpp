#include<iostream>
using namespace std;

struct node{
    int val;
    int countright;
    int ht;
    node* left;
    node* right;
};

int nub = 0 ;

int max(int a,int b){   return (a>b)?a:b; }


node * NewNode(int k)
{
        node * T=new node;
        T->val=k;
        T->left=T->right=NULL;
        return T;
}

int height(node *S)
{
    return (S==NULL)?-1:S->ht;
}

int GetBalance(node *S)
{   if(S==NULL) return 0;
    else return height(S->left) - height(S->right); 
}

void UpdateHeight(node *S)
    {
    if(S==NULL) return;
    S->ht=max(height(S->left),height(S->right))+1;
}

 node *RightRotate(node * k2)
{   node * k1=k2->left; 
    node * B=k1->right;
    k2->left=B;
    UpdateHeight(k2);
    k1->right=k2;
    UpdateHeight(k1);
    return k1;
}

node *LeftRotate(node* k1)
{
   node * k2=k1->right;
   node * B=k2->left;
   k1->right=B;
   UpdateHeight(k1);
   k2->left=k1;
   UpdateHeight(k2);
   return k2; 
}

node * insert(node * &root,int val)
{   if(root==NULL) root=NewNode(val);
    else if (root->val < val ){
        root->countright+=1;
        root->right=insert(root->right,val);
    }
    else root->left=insert(root->left,val);
        
    UpdateHeight(root);
    int Balance=GetBalance(root);
    
    if(  Balance > 1 )
        {
            if(val > root->left->val   )
            {
                    root->left=LeftRotate(root->left);            
                
            }
            
            root=RightRotate(root);          
        }
   else if( Balance < -1)
        {
             if(val < root->right->val    )
            {
                root->right=RightRotate(root->right);
                
            }
             
            root=LeftRotate(root); 
        }
    return root;
}


int count (int x , node* &t ){
    if(t == NULL){
        return 0;
    }
    else if (x > t->val){
        return count(x,t->right);
    }
    else if (x < t->val){
        return count(x,t->left)+t->countright+1;
    }
    else if (x == t->val){
        return t->countright;
    }
    return 0;
}


int main(){
    int m,k,val;
    node* root = 0 ;
    scanf("%d",&m);
    for(int i = 0 ; i<m ; i++){
        scanf("%d",&k);
        if (k==1){
            scanf("%d",&val);
            insert(root,val);
        }
        else if (k == 2){
            scanf("%d",&val);
            nub = count(val,root);
            printf("%d\n",nub);
            nub=0;
        }
    }
}