#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

int problems = 0;

void f(int N){

    
    int map[126][126] = { 0, };//입력으로 받는 좌표당 감소루피
    int visited[126][126] = { 0, }; //누적 감소 루피
    vector<int> answer;
    int dx[4] = {-1, 1, 0 , 0};
    int dy[4] = {0, 0, -1, 1};



    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N; j++){
            int a;
            cin >> a;
            map[i][j] = a;
        }
    }

    queue<pair<pair<int, int>, int> > q;
    q.push( { { 0, 0 }, map[0][0]});

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N; j++){
            visited[i][j] = 2147483647;
        }
    }

    while(!q.empty()){
        auto item = q.front();

        if(item.first.first == N - 1 && item.first.second == N-1)//끝까지 도달했을때
            answer.push_back(item.second);
            
        q.pop();
        for(int i = 0 ; i < 4 ; i ++){
            

            int nx = item.first.first + dx[i];//주변으로 이동
            int ny = item.first.second + dy[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){//적정 범위에 있으면
                int cost = item.second + map[nx][ny];
                if(cost < visited[nx][ny]){//원래 알고있던 누적 값보다 작으면
                    q.push({{nx, ny}, cost}); //다시 탐색할것이다
                    visited[nx][ny] = cost;//누적 루피 값 갱신
                }
            }
        }

    }

    sort(answer.begin(), answer.end());

    cout << "Problem " << problems << ": "<< answer[0] << "\n";

}



int main(){

    while(true){
        int N;
        cin >> N;
        
        if(N == 0)
            break;
        else{
            problems += 1;
            f(N);
            
        }
    }
    
    


}