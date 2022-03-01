#include<iostream>
#include<vector>

using namespace std;
int N, M;
int map[1001][1001];
int answer = 0 ;
int visited_DFS[1001];

void DFS(int start){
    answer += 1;
    visited_DFS[start] = 1;
    for(int i = 1; i <= N ; i++){
        if(visited_DFS[i] == 0 && map[start][i] == 1)
            DFS(i);
        
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0 ; i < M ;i ++){
        int a , b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    DFS(1);
    cout << answer - 1;
}
