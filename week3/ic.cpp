#include<iostream>
using namespace std;

typedef int valueType;

struct ListNode
{
    valueType val ;
    ListNode* next;
    ListNode* prev;
    ListNode(valueType val , ListNode* next  = 0 ,ListNode* prev=0)
    : val(val),next(next) , prev(prev) {}
};

void ri (ListNode* header,ListNode** tail , valueType x){
    ListNode* n = new ListNode(x);

    if (*tail == NULL){
        header -> next = n;
        n -> prev = header;
        *tail = n;
    }
    else{
        (*tail) -> next = n;
        n -> prev = *tail ;
        *tail = n;
        (*tail) -> next = NULL;
    }
}


void li (ListNode* header ,ListNode** tail, valueType x){
    ListNode* n = new ListNode(x);
    if (*tail == NULL){
        header -> next = n;
        n -> prev = header;
        *tail = n;
    }
    else {
        n -> next = header -> next;
        header -> next -> prev = n;
        header -> next = n; 
        n -> prev = header;
    }
}

void lr (ListNode*header,ListNode**tail){
    if (header -> next == NULL){
        return ;
    }
    ListNode* p = header->next;

    if ((*tail) -> prev == header){
        return;
    }

    header -> next = p -> next;
    p -> next = (*tail) -> next;
    (*tail) -> next = p;
    p->prev = *tail;
    header->next->prev = header;
    *tail = p;
}

void rr (ListNode*header,ListNode** tail){
    if (header -> next == NULL){
        return ;
    }
    ListNode*p = (*tail) -> prev;

    if ((*tail) -> prev == header){
        return;
    }

    (*tail) -> next = header -> next; 
    header -> next = *tail;
    (*tail) -> prev = header; 
    (*tail) -> next -> prev = (*tail);
    *tail = p;
    p -> next = NULL; 

}

void print_list (ListNode* node){
    while( node != NULL){
        cout << node -> val <<endl ;
        node = node -> next;
    }
} 



int main(){
    ListNode* header = new ListNode(0);
    ListNode* tail = header -> next;
    int n , b ;
    string a ; 
    cin>>n;
    int count =0 ;

    for (int i = 0 ; i < n ; i++ ){
        cin >> a;
        if (a == "ri" || a == "li"){
            cin >> b ;
        }

        if (a == "ri" ){
            ri(header,&tail,b);
            //print_list(header->next);
        }
        else if (a == "li"){
            li(header,&tail,b);
            //print_list(header->next);
        }
        else if (a == "lr"){
                lr(header,&tail);
                //print_list(header->next);
        }
        else if (a == "rr"  ){
                rr(header,&tail);
                //print_list(header->next);

        }
    }
    print_list(header->next);
}