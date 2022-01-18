#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
int answer = 0;


int main(){

int N;
cin >> N;
for(int i = 0 ; i < N ;i ++){
    int a;
    cin >> a;
    nums.push_back(a);
}
sort(nums.begin(), nums.end());

for(int i = 0 ; i < N ; i ++ ){
    int standard = nums[i]; //기준숫자
    int left = 0 ;
    int right = N-1;
    while(left < right){
        int sum1 = nums[left] + nums[right]; 
        if(sum1 > standard)//더한값이 기준숫자보다 클 때
            right -= 1;
        else if(sum1 < standard)//더한값이 기준숫자보다 작을 때
            left += 1;
        else if (sum1 == standard){//같을때
            if(left != i && right != i){
                answer += 1;
                break;
            }
            else if (i == left)
                left += 1;
            else if (i == right)
                right -= 1;
        }
    }
}

cout << answer;
    
}