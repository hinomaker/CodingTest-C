#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;
    int N = board.size();
    int M = board[0].size();

    /* accumulative sum array of (N+1)x(M+1) */
    vector<vector<int>> delta(N + 1, vector<int>(M + 1, 0));

    /*
    for example, r1 = 0, r2 = 2, c1 = 0, c2 = 2, ty = 5, dg = +

    0  0  0  0  0
    0  0  0  0  0
    0  0  0  0  0
    0  0  0  0  0
    0  0  0  0  0

    ->

    5  0  0 -5  0
    0  0  0  0  0
    0  0  0  0  0
    -5 0  0  5  0
    0  0  0  0  0

    */
    for(int sdx = 0; sdx < skill.size(); sdx++)
    {
      vector<int> curr = skill[sdx];
      int r1 = curr[1];
      int r2 = curr[3];
      int c1 = curr[2];
      int c2 = curr[4];
      int ty = curr[0];
      int dg = (ty == 1)? -curr[5] : curr[5];

      delta[r1][c1] += dg;
      delta[r2 + 1][c2 + 1] += dg;
      delta[r1][c2 + 1] -= dg;
      delta[r2 + 1][c1] -= dg;
    }

    for(int rdx = 0; rdx < N; rdx++)
      for(int cdx = 0; cdx < M; cdx++)
        delta[rdx][cdx + 1] += delta[rdx][cdx];

    for(int cdx = 0; cdx < M; cdx++)
      for(int rdx = 0; rdx < N; rdx++)
        delta[rdx + 1][cdx] += delta[rdx][cdx];

    for(int rdx = 0; rdx < N; rdx++)
      for(int cdx = 0; cdx < M; cdx++)
        if(delta[rdx][cdx] + board[rdx][cdx] > 0)
          answer++;

    return answer;
}
