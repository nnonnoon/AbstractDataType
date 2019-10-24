#include<iostream>
#include <algorithm> 

using namespace std;

int problem(int x){
    int i=0;
    int count = 0 , sum=0;
    if (x==1){
        return 0;
    }
    while(sum!=1 && i>=0){
        if(x%2==0){
            sum = x/2;
            count+=1;
        }
        else if(x%2==1){
            sum = (3*x)+1;
            count+=1;
        }
        x=sum;
        i++;
    }
    return count;
}


int main(){
    int a,b;
    int count=0,max_noon=0;
    int sumsum;
    int ans[100000][3]; 
    int counting = 0;
    while (cin >> a >> b){
        ans[counting][0] = a;
        ans[counting][1] = b;
        int tmp_max_noon = max(a,b);
        int tmp_min = min(a,b);
        a = tmp_min;
        b = tmp_max_noon;
        max_noon = problem(tmp_min);
        for (int i= a ; i <= b ; i++ ){
            count +=1;
        }
        for (int i= a ; i <= b ; i++ ){
            sumsum = problem(i);
            if(sumsum>=max_noon){
                max_noon = sumsum;
            }
        }
        
        ans[counting][2] = max_noon;
        max_noon=0;
        counting++;
    }
    for(int i=0; i<counting;i++)
    cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] + 1 << endl;
}
