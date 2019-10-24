#include <iostream>
using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;

  ListNode(valueType val, ListNode* next=0)
    : val(val), next(next) {}
};

void print_list(ListNode* node)
{
  while(node != 0) {
    cout << node->val << endl;
    node = node->next;
  }
}

void insert_front(ListNode* header, valueType x)
{
  
   ListNode* n =  new ListNode(x);
   n->next = header -> next;
   header -> next = n; 
}

void delete_node(ListNode* p ,ListNode* pnext)
{
    p->next  = pnext->next;
    pnext->next  = NULL;
    free(pnext);
}

int main(){
    ListNode* header = new ListNode(0);
    int n ; 
    cin >> n ;
    char id;
    int number;
    for (int i = 0 ; i < n ; i++){
        cin>>id;
        cin>>number;
        if (id == 'I'){
            insert_front(header,number);
        }
        else if (id == 'D'){
            ListNode* p = header;
            int j =0;
            for (j = 0 ; j<number-1; j++){
                if (p->next == NULL){
                    break;
                }
                p = p->next;
            }
            
            if (p->next != NULL){
                delete_node(p,p->next);
            }
        }
    }
     print_list(header->next);
}