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

void print_list(ListNode* node){
    while(node!=NULL){
        cout<<node->val;
        node=node->next;
    }
}
ListNode* list[100001];
ListNode* tail[100001];

int main(){
    int a,b,n,keep=0,tod=1,number;
    ListNode** address[100001];
    int  nub[100001];
    char atv;
    cin>>a>>b;

    for (int i = 1 ; i<=a ; i++){
        list[i] = new ListNode(0) ; 
        tail[i]=list[i];
        cin>>n;
        keep=keep+n;
        for(int j = tod ; j<=keep ; j++){
            ListNode* p = new ListNode(j);
            address[j]=&p;
            if(list[i]->next == NULL){
                list[i] -> next = p;
                p -> prev = NULL;
                tail[i]=p;
            }
            else{
                tail[i]->next = p;
                p-> prev = tail[i];
                tail[i]=p;
            }
            tod+=1;
        }     
    }

    int count = 1;
    ListNode* p = list[1]->next;
    for (int k = 1 ; k<=b ;k++){
        cin>>atv;
        if (atv == 'F'){
            if(p->next == NULL){
                nub[k]=p->val;
                count=count+1;
                continue;
            }
            else{
                p=p->next;
                nub[k]=p->val;
                count=count+1;
            }
        }
        else if(atv == 'B'){
            if(p->prev == list[1]){
                nub[k]=p->val;
                count=count+1;
                continue;
            }
            else{
                p=p->prev;
                nub[k]=p->val;
                count=count+1;
            }
        }
        else if (atv == 'C'){
            cin>>number;
            if (p->next!= NULL){
                p->next->prev = NULL;
                p->next = NULL;
            }
            else if ([number]->prev=NULL){

            }
           
        }
    }
   
    for(int t = 1 ; t<count ;t++ ){
        cout<<nub[t];
    }
}