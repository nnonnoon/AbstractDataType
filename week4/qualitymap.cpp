#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n , m ;
    int count = 0;
    int checkdao = 0;
    int checkdollar = 0;
    int checkpoint = 0;
    int keep_verygood = 0;
    int keep_good = 0;
    cin>>n>>m;

    char map[n][m];
    bool visited[n][m];
    typedef pair<int, int> mystructure;
    queue<mystructure> adj; //(i, j)
    // queue<pair<int,int> > adj 

    for(int i = 0 ; i<n ;i++){
        for(int j = 0 ; j<m ;j++){
            cin >> map[i][j];
            visited[i][j] = false;
        }
    }

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){

            if(visited[i][j] == false){
                visited[i][j] = true;
                adj.push(make_pair(i,j));

                while(!adj.empty()){
                    int x = adj.front().first;
                    int y = adj.front().second;
                    adj.pop();
                    
                    // cout << x << " " << y << endl;
                    if(map[x][y] == '*'){
                        checkdao +=1;
                        checkpoint += 1;
                    }
                    else if(map[x][y] == '$'){
                        checkdollar +=1;
                        checkpoint += 1;
                    }
                    else if(map[x][y] == '.'){
                        checkpoint += 1;
                    }

                    if(map[x][y+1] != '#' && y < m - 1){
                        if(!visited[x][y+1]){
                            visited[x][y+1] = true;
                            adj.push(make_pair(x,y+1));
                        }
                    }

                    if(map[x][y-1] != '#' && y > 0){
                        if(!visited[x][y-1]){
                            visited[x][y-1] = true;
                            adj.push(make_pair(x,y-1));
                        }
                    }

                    if(map[x+1][y] != '#' && x < n-1){
                        if(!visited[x+1][y]){
                            visited[x+1][y] = true;
                            adj.push(make_pair(x+1,y));
                        }
                    }

                    if(map[x-1][y] != '#' && x > 0){
                        if(!visited[x-1][y]){
                            visited[x-1][y] = true;
                            adj.push(make_pair(x-1,y));
                        }

                    }
                }

                if(checkdao > 0 && checkdollar > 0){
                    keep_verygood+=checkpoint;
                }
                else if(checkdao != 0 || checkdollar != 0 ) {
                    keep_good+=checkpoint;
                }
                
                // cout << keep_verygood << " " << keep_verygood<< " " << checkpoint << endl;
                checkdao=0;
                checkdollar=0;
                checkpoint=0;
            }
        }
    }
    cout<<keep_verygood<<" "<<keep_good<<endl;
}