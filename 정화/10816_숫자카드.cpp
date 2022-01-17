#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


unordered_map <int, int> M; //HashMap, 해당 숫자 카드가 몇개 있는지 담는 배열
//그냥 배열로 하면 시간초과가 뜬다.
vector<int> answer; //정답을 담는 배열

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0); //시간 줄이기

    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int a;
        cin >> a;
        M[a] += 1;//입력된 카드의 갯수를 하나씩 올린다.

    }
    int K;
    cin >> K;
    for(int i = 0 ; i < K ; i++){
        int b;
        cin >> b;
        answer.push_back(M[b]); //몇개있는지 알고싶은 카드의 갯수를 answer에 담는다.
    }

    for(int i = 0 ; i < answer.size(); i++){
        cout << answer[i] << " ";
    }

}