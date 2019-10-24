#include<iostream>
using namespace std;


typedef int valueType;
struct ListNode
{
    valueType val;
    ListNode* next;
    ListNode(valueType val , ListNode* next = 0)
    : val(val),next(next) {}
};

void append(ListNode* header,ListNode** tail,valueType x){
    ListNode* n = new ListNode(x);
    if (*tail == NULL){
        header->next = n;
        *tail  = n; 

    }

    else {
        (*tail)->next = n;
        *tail = n ;
        //n -> next = header->next;
    }
    (*tail)->next = header->next;
}


// void delete_node(ListNode*d,ListNode* dnext, ListNode *tail){
void delete_node(ListNode *del){
    // d->next = dnext -> next;
    // tail->next = dnext->next;
    // dnext -> next = NULL;
    ListNode *tmp = del->next;
    del->next = del->next->next;
    tmp  = 0;
    

}

void printlist(ListNode* node){
       ListNode* pp = node;
       for(int i=0;i<20;i++){
           cout << pp->val << " ";
           pp = pp->next;
       }
}

int main(){
   int n;
   int ans[1000000]; 
   int sum = 0;


    while (cin>>n){
        if (n == 0){
            break;
        }
        int m = 1;
        while(m>0){
            ListNode* header = new ListNode(0); 
            ListNode* tail = header->next;
            for (int i = 1 ; i<=n ; i++){
                append(header,&tail,i);
            }
            tail->next = header -> next;
            // cout << header->next->val << endl;
            // cout << tail->val ;

            // delete_node(header,header->next,tail);
            // printlist(header->next);
            // return 0;

            ListNode *del = tail;
               delete_node(del);
            while(del -> next != del){
                    int count=1;
                    while(count != m){
                        del = del->next;
                        count++;
                    }

                    delete_node(del);
            }
            if (del -> val == 13){
                ans[sum]=m;
                break;
            }
            // cout << "test";
            m++;
        }
        sum++;
    } 
    for (int i =0 ; i < sum ; i++){
        cout << ans[i] << endl;
    }      
}
