#include <iostream>
#include<queue>

using namespace std;
int N, M, V;
int map[1001][1001];
int visited_BFS[1001];
int visited_DFS[1001];

void DFS(int start){
    cout << start << ' ';
    visited_DFS[start] = 1;
    for(int i = 1; i <= N ; i++){
        if(visited_DFS[i] == 0 && map[start][i] == 1)
            DFS(i);
        
    }
}


void BFS(int start){
    queue<int> q;
    q.push(start);
    visited_BFS[start] = 1;
    while(!q.empty()){
        cout << q.front() << ' ';
        int a = q.front();
        q.pop();
        for(int i =1; i<=N ; i++){
            if(map[a][i] == 1 && visited_BFS[i] == 0){
                q.push(i);
                visited_BFS[i] = 1;
            }
        }
        
    }

}

int main(){
    cin >> N >> M >> V;
    for(int i = 0 ; i < M ; i++){
        int x , y;
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
    }
    DFS(V);
    cout << '\n';
    BFS(V);


}