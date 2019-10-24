#include <iostream>
using namespace std;
int main()
{
  int out[100];
  int d = 0;  

  int n;
  cin >> n;

  do {
      int z = n%2;
      out[d]=z;
      n/=2;
      d++;
  } while(n > 0);
    for (int j=d-1 ; j>=0 ; j--){
        cout<<out[j];
    }
    cout<<"\n";
}