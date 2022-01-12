#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;


bool visited1[100000]; 
queue<pair<int, int> > q;
vector<int> answer;
int plus1, nx;

int main(){
    int N ;
    int K ;

    cin >> N >> K ;

    q.push({ N, 0 });

    while(!q.empty()){

        auto item = q.front();
        if(item.first == K){
            answer.push_back(item.second);
            break;
        }
        q.pop();
        for(int i = 0 ; i < 3; i++){
            if(i == 0 && item.first * 2 <= 100000 &&!visited1[item.first*2] ){
                q.push({item.first * 2, item.second});
                visited1[item.first*2] = true;
                
            }
            if(i == 1 && item.first - 1 >= 0 && !visited1[item.first-1]){
                q.push({item.first -1, item.second +1});
                visited1[item.first-1] = true;
                
            }
            if(i == 2 && item.first + 1 <= 100000 && !visited1[item.first+1]){
                q.push({item.first +1, item.second +1});
                visited1[item.first+1] = true;
                
            }
        }
        
    }
    sort(answer.begin(), answer.end());
    cout << answer[0];

}