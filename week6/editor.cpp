#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n ;
    int cursor=0;
    bool BB = false ; 
    char func;
    string word;
    cin>>n;

    vector<string> data; 

    for(int i = 0 ; i < n ; i++){
        cin>>func;
        if(func == 'i'){
            cin>>word;
            if (BB){
                cursor++;
                data.insert(data.begin()+cursor,word);
            }
            else{
                data.insert(data.begin()+cursor,word);
            }
            BB = true;
        }
        else if (func == 'l'){
           if(BB){
               if(cursor == 0){
                   BB = false;
               }
               else {
                   cursor--;
               }
           }
        }
        else if (func == 'r'){
            if(!data.empty()){
                if(!BB){
                    BB = true;
                }
                else{
                    if(cursor+1 != data.size()){
                        cursor++;
                    }
                    BB = true;
                }
            }
            
        }
        else if (func == 'b'){
            if(!data.empty()){
                if(BB){
                    if(cursor == 0){
                        data.erase(data.begin() + cursor);
                        BB = false;
                    }
                    else{
                        data.erase(data.begin()+cursor);
                        cursor--;
                    }
                }
                if(data.empty()){
                    BB = false;
                }

            }
            
        }
        else if (func == 'd'){
            if(!data.empty()){
                if(BB){
                    if(cursor+1 != data.size() ){
                        data.erase(data.begin()+cursor+1);
                    }
                }
                else{
                    data.erase(data.begin() + cursor);
                }
                if(data.empty()){
                    BB = false;
                }
            }
        }
    }
   for(int i = 0 ; i < data.size() ; i++ ){
       cout<<data[i]<<" ";
   }
   cout<<endl;

//    for(vector<string>::iterator ptr = data.begin() ; ptr < data.end() ; ptr++){
//        cout<<*ptr;
//    }

// int maxValue(struct node* node) 
// {    
//     /* loop down to find the rightmost leaf */
//     struct node* current = node; 
//     while (current->right != NULL)  
//         current = current->right; 
      
//     return (current->data); 
// } 

}