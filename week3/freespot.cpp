#include<iostream>

using namespace std;

int main(){
    int W,H,N;
    int x1,x2,y1,y2;
    int won = 0;
    int count=0;
    int n_loop;
    int ans[100000] = {0};

    while(cin >> W >> H >> N){
        int box[W][H];

        if (W == 0 && H == 0 && N == 0)
            break;

        n_loop = N;

        for (int i = 0 ; i < W ; i++ ){
            for (int j = 0 ; j < H ; j++  ){
                box[i][j] = 1; 
            }
        }
        for (int i = 0 ; i<N ;i++){
            cin >> x1 >> y1 >> x2 >> y2 ;
            for (int j = min(x1,x2) - 1 ; j<=max(x1,x2) - 1 ; j++){
                for (int k = min(y1,y2) - 1; k <= max(y1,y2) -1 ; k++){

                    box[j][k] = 0;
                }
            }
        } 

        for (int i = 0 ; i < W ; i++ ){
            for (int j = 0 ; j < H ; j++  ){
                // cout << box[i][j] << " ";
                if (box[i][j] == 1){
                    count += 1;
                }
            }
            // cout << endl;
        }
        ans[won]=count;
        count=0;
        won++;
    }
    
    for (int i = 0 ; i< won ; i++){
        if (ans[i] == 0 ){
            cout<<"There is no empty spots.";
        }
        else if (ans[i] == 1 ){
            cout<<"There is one empty spot.";
        }
        else{
            cout<<"There are "<<ans[i]<<" empty spots.";
        }  
        cout << endl;
    }
}