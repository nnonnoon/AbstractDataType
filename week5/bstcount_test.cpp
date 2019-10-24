#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	node* right;
	node* left;
	int data;
};

// add a node to the tree
node* insert( node* &t,int x){
    if(t == NULL){
        t = new node();
        t -> data = x;
        t -> left = NULL;
        t -> right = NULL; 
    }
    else if (x < t->data){  
        t->left = insert(t->left,x);
    }
    else if(x > t-> data){
        t->right = insert(t->right,x);
    }
    return t;
}

int count(node* t)
{
	if (t == NULL) {
		return 0;
	} else {
		return count(t->right)  + 1;
	}
}


int main()
{
	node* root = NULL;

	// test insert
  insert(root, 50);
  insert(root, 19);
  insert(root, 28);
  insert(root, 40);
  insert(root, 16);
  insert(root, 70);
  insert(root, 55);
  insert(root, 56);
  insert(root, 17);
  insert(root, 90);

  cout<<"\ncount: "<<count(root)<<endl;
}