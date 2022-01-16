#include <iostream>
#include <vector>

using namespace std;

vector<int> seq;

void B_S(vector<int> &seq, int key){
    int start = 0;
    int end = seq.size()-1;
    int mid;

    if(key > seq[seq.size()-1]){//새로 들어온값이 배열의 마지막값보다 큰 경우 push back 하고 함수에서 빠져나온다.
        seq.push_back(key);
        return;
    }
    if(key <= seq[0]){
        seq[0] = key;
        return;
    }
    

    while(end != start){//중간에 있을 경우 적절한 위치를 찾는다
        mid = (end + start)/2;
        
        if(key > seq[mid])
            start = mid+1;
        else
            end = mid;

    }
    
    seq[start] = key;
    
}




int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false); //속도를 빠르게 해줌
    int N;
    cin >> N;
    int a;
    cin >> a;
    seq.push_back(a);

    for(int i = 0 ; i < N-1 ; i++){
        int b;
        cin >> b;
        B_S(seq, b);
    }
    cout << seq.size();
    

}