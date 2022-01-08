#include <iostream>


using namespace std;
int map[1001][1001] = {101};
int MAX_Ti = 101;
bool visited[1001][1001] = {false};

int min_Ti(int N, int X){
    int min1 = 101;
    int answer;
    for(int i = 1; i <= N ; i++){
        if (map[X][i] < min1 && visited[X][i] == false){
            min1 = map[X][i];
            answer = i;
        }
    }
    cout << min1;
    return answer;
}


int min_Ti2(int N, int X){
    int min1 = 101;
    int answer;
    for(int i = 1; i <= N ; i++){
        if (map[i][X] < min1 && visited[i][X] == false){
            min1 = map[i][X];
            answer = i;
        }
    }
    return answer;
}




void da(int N, int X){
    
    int min2;
    
    for(int i = 0 ; i< N ; i++){
        min2 = min_Ti(N, X);
        visited[X][min2] = true;
        for(int j = 1; j <= N; j++){
            if (!visited[X][j]){
                if(map[X][j] >= map[X][min2] + map[min2][j])
                    map[X][j] = map[X][min2] + map[min2][j];
            }

        }


    }
}


void da2(int N, int X){
    
    int min2;
    
    for(int i = 0 ; i< N ; i++){
        min2 = min_Ti2(N, X);
        visited[min2][X] = true;
        for(int j = 1; j <= N; j++){
            if (map[j][min2] != 101){
                if(map[j][X] >= map[min2][X] + map[j][min2])
                    map[j][X] = map[min2][X] + map[j][min2];
            }

        }


    }
}





int main(){

    
    
    int N, M , X;
    cin >> N >> M >> X;
    for(int i = 0 ; i <= N ;i ++){
        for (int j = 0 ; j <= N ; j++)
            map[i][j] = 101;
    }
    for(int i = 0  ; i < M ; i++){

        int a, b, c;
        cin >> a >> b >> c;
        map[a][b] = c;


    }
    for( int i = 1;i <= N; i ++){
        map[N][N] = 0;
        visited[N][N] = true;
    }
    da(N, X);
    da2(N, X);
    
    int a = 0;
    for(int i = 1 ; i <= N ; i ++ ){
        if(map[X][i] + map[i][X] > a)
            a = map[X][i] + map[i][X]; 
    }
    cout << a;
    

}