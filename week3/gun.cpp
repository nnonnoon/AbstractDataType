#include<iostream>
using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;
  ListNode(valueType val, ListNode* next=0,ListNode* prev=0)
    : val(val), next(next) {}
};

void append(ListNode* header , ListNode* tail , valueType x){

}

int main(){
    ListNode* header = new ListNode(0);
    ListNode* tail = header-> next;
    for (int i = 1 ; i<=10 ; i++){ 
         append(header,tail,x);
    }
   
}
