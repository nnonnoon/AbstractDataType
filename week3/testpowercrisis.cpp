#include<iostream>

using namespace std;

typedef int valueType;
struct ListNode
{
    valueType val;
    ListNode* next;
    ListNode(valueType val , ListNode* next = 0  )
    : val(val),next(next){}

};


void append(ListNode* header , ListNode ** tail , valueType x){
    ListNode* n = new ListNode(x);
    if (*tail == NULL){
        header -> next = n;
        *tail = n;
    }
    (*tail) -> next = n;
    *tail = n; 
}

void delete_node(ListNode* del){
    ListNode* tmp = del -> next;
    del -> next = del -> next -> next;
    tmp -> next = NULL;

}

void print_list (ListNode* node){
    while(node != NULL){
        cout << node -> val ;
        node = node -> next ;
    }
}


int main(){
    int n ;
    int ans[10000];
    int sum = 0; 
    while (cin >> n){
        if (n == 0 ){
            break;
        }

        int m = 1 ;
        while(m>0){

            ListNode* header = new ListNode(0);
            ListNode* tail = header -> next;
            for (int i = 1 ; i <= n ; i++ ){
                append(header,&tail,i);
            }
            tail -> next = header -> next;

            ListNode* del = tail;
            delete_node(del);

            while (del -> val  != del -> next -> val ){
                int count = 1 ;
                while (count != m){
                    del = del -> next;
                    count++;
                }
                delete_node(del);
            }
            if (del -> val == 13){
                ans[sum] = m;
                break;
            }
            m++;
        }
        sum++;
    }
    for (int i = 0 ; i <sum ; i++  )
    cout<< ans[i]<<endl;
}