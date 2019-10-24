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

int main(){
    ListNode* list[100001];
    ListNode* tail[100001];
    ListNode* append[100001];
    int a,b,n,keep=0,tod=1,number;
    char atv;

    scanf("%d",&a);
    scanf("%d",&b);
    int  nub[b];

    for (int i = 1 ; i<=a ; i++ ){
        append[i] = new ListNode(0);
        tail[i]=append[i]; 
        cin>>n;
        keep=keep+n;
        for(int j = tod ; j<=keep ; j++){
            list[j]=new ListNode(j);
            ListNode* p = list[j];
            if(append[i]->next == NULL){
                append[i] -> next = p;
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

    ListNode* p = append[1]->next;
    for (int k = 1 ; k<=b ;k++){
        scanf(" %c",&atv);
        if (atv == 'F'){
            if(p->next == NULL){
                nub[k]=p->val;
                continue;
            }
            else{
                p=p->next;
                nub[k]=p->val;
                
            }
        }
        else if(atv == 'B'){
            if(p->prev == NULL){
                nub[k]=p->val;
                continue;
            }
            else{
                p=p->prev;
                nub[k]=p->val;
                
            }
        }
        else if (atv == 'C'){
            scanf("%d",&number);
            if (p->next!= NULL){
                p->next->prev = NULL;
                p->next = NULL;
            }
            if (list[number]->prev == NULL){
                p->next = list[number];
                list[number]->prev = p;
                p=p->next;
                nub[k]=p->val;
            }
            else if(list[number]->next == NULL) {
                /*ListNode* r = list[number];
                ListNode* d = list[number];
                while(r!= NULL){
                    ListNode* tmp = r->next;
                    r->next = r-> prev;
                    r->prev = tmp;
                    r=r->next;
                }
                p->next = d;
                d->prev= p;
                p=p->next;
                nub[k]=p->val;*/

                p->next=list[number];
                list[number]->next=list[number]->prev;
                list[number]->prev=p;
                p=p->next;
                nub[k]=p->val;
            }
        }
        if (p->next != NULL){
            if(p->next->next == p){
                p->next->next = p->next->prev; 
                p->next ->prev = p;
            }
        }
    }
    for (int j = 1 ; j<=b ; j++ ){
        printf("%d\n",nub[j]);
    }
}
