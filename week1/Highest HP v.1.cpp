#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int hp = 100;
  int max_hp = hp ;
  int die = 0;
  for (int i=0; i<n; i++) {
    int a;
    cin >> a;
    hp+=a;
    if (hp>=max_hp){
        max_hp=hp;
    }
    if (hp<=die){
        break;
    }
    
}
cout<<max_hp<<endl;
}