#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int ,greater <int> > noon;
    noon.insert(20);
    noon.insert(20);
    noon.insert(30);
    noon.insert(50);
    noon.insert(70);
    noon.insert(100);

    set<int ,greater <int> >::iterator j = noon.begin();

    noon.erase(noon.begin() , noon.find(70));
    

    for( j = noon.begin() ; j!=noon.end() ; j++ ){
        cout<< *j<< endl;
    }
    noon.clear();

}