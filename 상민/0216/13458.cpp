#include <iostream>
using namespace std;

int main(){
  int N, B, C;
  cin >> N;
  int applicant[N];
  long long answer = N;

  for(int ndx = 0; ndx < N; ndx++)
    cin >> applicant[ndx];

  cin >> B >> C;
  for(int ndx = 0; ndx < N; ndx++){
    applicant[ndx] -= B;

    if(applicant[ndx] > 0)
      answer += (applicant[ndx] + C - 1) / C;
  }
  cout << answer;
}
