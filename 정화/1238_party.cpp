#include <iostream>
#include <memory.h>

using namespace std;

int map[1001][1001]; //최단경로
int plus1[1001] = {0}; //파티장소까지 가기 + 돌아오기

int main(){
    int N , M , X;
    cin >> N >> M >> X;

    memset(map, 0x3f, sizeof(map)); //0x3f로 초기화

    for(int i = 0 ; i < M ; i++){ //map배열 입력받기

        int a , b, c;
        cin >> a >> b >> c;
        map[a][b] = c;
    }

    for(int idx = 1; idx < N; idx++) //map배열 의 대각선부분 0으로 초기화
      map[idx][idx] = 0;


    for(int k = 1 ; k < N + 1 ; k++){
        for(int i = 1; i < N+1 ; i++){
            for ( int j = 0 ; j < N+1 ; j++){
                if(map[i][k] + map[k][j] < map[i][j])
                    map[i][j] = map[i][k] + map[k][j]; 
            }
        }
    }

    for(int i = 1; i < N+1 ; i++){
        plus1[i] = map[i][X] + map[X][i]; //왕복거리 계산
    }
    int maxi = 0;
    for(int i = 1; i < N+ 1; i++){ 
        if (plus1[i] > maxi) //왕복거리의 최대 계산
            maxi = plus1[i];
    }
    cout << maxi;



}