#include <iostream>
#include <algorithm>
#include <string>
#include<cstdio>

using namespace std;

int main()
{
    string id;

    while(cin>>id){
        //int n = id.length();
        if (id[0] == '#'){
            break;
        }
        else if (next_permutation(id.begin() , id.end() )){
            cout << id <<endl;
        }
        else {
            cout << "No Successor" <<endl;
        }
    }
}
