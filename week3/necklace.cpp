#include<iostream>
using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;
  ListNode* prev;
  ListNode(valueType val, ListNode* next=0,ListNode* prev=0)
    : val(val), next(next) ,prev(prev){}
};



void soi(ListNode* n , ListNode* x ){
    if (x ->next == NULL){
        x->next = n;
        n -> prev = x;
        ListNode* p = x;

        /*while(p!=NULL){
            cout<<p -> val+1;
            p=p->next;
        }*/
    }
    else if (x -> next != NULL){
        ListNode * tail = n;
        
        while (tail ->next != NULL){
            tail = tail ->next;
        }
        tail -> next = x ->next;
        x -> next -> prev = tail ; 
        x -> next = n;
        n -> prev = x;
    }
}

void printlist(ListNode* node){
  while(node != 0) {
    cout << node->val+1 << ' ';
    node = node->next;
  }
}

int main(){
    int n,a,b;
    cin>>n;
    ListNode *list[n];

    for (int i = 0 ; i<n ; i++ ){
        list[i] = new ListNode(i);
        //cout << list[i] -> val  ;
    }


    for (int i =0 ; i< n-1 ; i++){
        cin>>a;
        cin>>b;
        soi(list[a-1],list[b-1]);
    }

    ListNode * won = list[0];
    while (won -> prev != NULL ){
        won = won -> prev;
    }
    printlist(won);
}