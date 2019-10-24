#include<iostream>
using namespace std;

int main() {

	int kase ;
	cin >> kase;
    int nub = 0;
	while (nub<kase) {
		int D = 0, I = 0;
		cin >> D >> I;
        int pos = 1;

	    for (int i = 0; i < D - 1; i++) {
            if (I % 2 == 1){ 
                pos = pos * 2; 
                I = (I + 1) / 2; 
            }
            else{ 
                pos = pos * 2 + 1; 
                I /= 2; 
            }
        }
		cout << pos << endl;
        nub++;
	}
}