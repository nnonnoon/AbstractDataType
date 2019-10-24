#include<iostream>
using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;

  ListNode(valueType val, ListNode* next=0)
    : val(val), next(next) {}
};

class LinkedList
{
private:
  ListNode* header;
  ListNode* tail;
  void free_list();

public:
  LinkedList();
  void print_list();
  void insert_front(valueType x);
  void append(valueType x);
  void pointer(valueType x);
};


LinkedList::LinkedList()
{
  header = new ListNode(0);
  tail = header;
}


void LinkedList::print_list()
{
  ListNode* node = header->next;
  while(node != 0) {
    cout << node->val<< endl;
    node = node->next;
  }
}

void LinkedList::insert_front(valueType x ){
    ListNode* n = new ListNode(x);
    n->next = header -> next;
    if (header -> next == NULL){
        tail = n ;
    }
    header -> next = n;
}

void delete_node(ListNode* p , ListNode* pnext , valueType x){
    p->next = pnext->next;
    pnext->next = NULL;
    free(pnext);
}

void LinkedList::append(valueType x){
    ListNode* n = new ListNode(x);
    tail -> next = n;
    tail =  n;
   
}

void LinkedList::pointer(valueType x){
    ListNode* p  = header;
    for (int j = 0 ; j < x-1 ; j++ ){
        if (p->next == NULL){
            break;
        }
        p = p->next;

    }
    if (p->next != NULL && p->next->next!=NULL){
        delete_node(p,p->next,x);
    } 
    else if(p->next != NULL)
    {
        tail = p;
        delete_node(p,p->next,x);
    }
    

}


int main(){
    LinkedList list;
    int n , number ; 
    char ida;
    cin>>n;
    for (int i = 0 ; i<n ; i++){
        cin>>ida;
        cin>>number;
        if (ida == 'I'){
            list.insert_front(number);
        }
        else if (ida == 'D'){  
            list.pointer(number);
        }
        else if (ida == 'A'){
            list.append(number); 
        }
    }
    list.print_list();
}