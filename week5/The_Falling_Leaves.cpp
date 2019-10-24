#include <iostream>
using namespace std;
int keep[100] ;

int  now(int index){
	int v;
	cin>>v;
	if (v == -1){
        return 0 ;     
    }
	keep[index]+=v;
	return now(index-1) ||  now(index+1);  
}

int  init(int num){ 
	keep[100/2]+=num;  
	return now(100/2-1) || now(100/2+1);    
}

int main(){
	int count = 1,start,root;
	while(true){
		cin>>root;
		if (root == -1){
            break;
        } 
        for(int i = 0 ; i<100; i++){
            keep[i]=0;
        }
		init(root);
		for(int i=0 ; i < 100 ; i++){
			if (keep[i]>0){  
				start=i;
				break;
			}
		}
		cout << "Case " << count <<":"<<endl;
		for(int i = start ;i < 100;i++){
			if (keep[i] > 0){
				if (i == start){
                    cout << keep[i];
                } 
				else{
                    cout <<" " << keep[i] ;
                }
			}else{
				break;
			}
		}
		cout << endl;
        cout << endl;
        count++;
	}
}

