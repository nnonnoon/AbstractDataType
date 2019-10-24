#include <iostream>
using namespace std;

typedef int valueType; 

struct ListNode{
    ListNode* next;
    ListNode* prev;
    valueType val;
    ListNode(valueType val, ListNode* next = 0 , ListNode* prev = 0)
    :val(val),next(next),prev(prev){}
};

void print_list(ListNode* node){
    while(node != NULL ){
        valueType a = node -> val;
        printf("%d\n",a);
        node = node -> next ;
    }
}

ListNode* station[100001];
ListNode* tail[100001];
int main(){
    int n ,x , y;
    char oper;
    scanf("%d",&n);
    for (int i = 1 ; i <= 100000 ; i++){
        station[i] = new ListNode(0) ; 
        tail[i]  = station[i];
    }
    for (int i = 0 ; i < n ; i++){
        cin >> oper >> x >> y ;
        if (oper == 'N' ){
            ListNode* k = new ListNode(x);
            if (station[y] -> next == NULL){
                station[y] -> next = k;
                k -> prev = station[y];
                tail[y] = k; 
            }
            else{
                tail[y] -> next = k;
                k -> prev = tail[y];
                tail[y] = tail[y] -> next;
            }
           
        } 
        else if (oper == 'M'){
            if (station[x] -> next == NULL){
                continue;
            }
            else if(station[x] -> next == NULL && station[y] -> next == NULL  ){
                continue;
            }
            else{
                ListNode* p = station[x] -> next;
                tail[y] -> next = p;
                p->prev = tail[y];
                tail[y] = tail[x];
                station[x] -> next = NULL;
                tail[x] = station[x] ;
            }
        }
    }
    for (int i = 1 ; i<= 100000 ; i++){
        print_list(station[i]->next);
    }
}