#include <iostream>
using namespace std;

int main()
{
  int height[1000];
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> height[i];
  }

  int max_height = height[0];
  int max_count = 0;
  for (int i =0 ; i<n ;i++){
      int z;
      z = height[i];
      if (z>=max_height){
          max_height=z;
      }
  }
  for (int i =0 ; i<n ;i++){
      if ( height[i] == max_height ){
          max_count+=1;
      }
  }

  cout << max_count << endl;
}