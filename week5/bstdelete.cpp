#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* insert(node* t, int x){
    if(t == NULL){
        t = new node();
        t->data = x;
        t->left = NULL;
        t->right = NULL;
    }
    else if (x <= t->data){
        t->left = insert(t->left,x);
    }
    else if (x >= t->data){
        t->right = insert(t->right,x);
    }
    return t;
}

bool search (node*t , int x){
    if(t == NULL  ){
        return false;
    }
    else if (x == t->data){
        return true;
    }
    else if (x <= t->data){
        return search(t->left, x);
    }
    else if (x >= t->data){
        return search(t->right, x);
    }
    return t;
}

node* findmin(node* t){
    if (t->left != NULL){
        return findmin(t->left);
    }
    return t;
}

node* delete_node (node* t , int x){
   if (t == NULL){
       return t;
   }
   else if (x < t->data){
       t->left = delete_node(t->left,x);
   }
   else if (x > t->data){
       t->right = delete_node(t->right,x);
   }
   else{
        if (t->left == NULL){
           node * temp = t;
           t = t-> right;
           delete temp;
        }
       else if (t->right == NULL){
           node* temp  = t;
           t = t->left;
           delete temp;
       }
       else{
            node *temp = findmin(t->right);
			t->data = temp->data;
			t->right = delete_node(t->right,temp->data);
		}
    }
    return t;
}

int main(){
    int n,fun , val ;
    node* root = NULL;
    cin>>n;
    for (int i = 0 ; i < n ; i++){
        cin>>fun;
        if (fun == 1){
            cin>>val;
            root=insert(root,val);
        }
        else if (fun == 2){
            cin>>val;
            if(search(root,val) == true){
                cout <<"1"<<endl;
            }
            else{
                cout <<"0"<<endl;
            }
        }
        else if (fun == 3){
            cin>>val;
            root=delete_node(root,val);
        }
    }
    return 0 ;
}