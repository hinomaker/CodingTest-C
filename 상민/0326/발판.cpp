#include <string>
#include <vector>
#include <limits.h>
using namespace std;

vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

/* returns {t, n} if player can always win in n steps with optimal strategy
   returns {f, n} if player can't win, but staying for n steps in maximum */
pair<bool, int> dfsearch(vector<vector<int>> &board, vector<int> play, vector<int> wait)
{
  if(!board[play[0]][play[1]])
    return {true, 0};

  int row = board.size();
  int col = board[0].size();

  bool win = false;
  int count = 0;
  int min_turn = INT_MAX;
  int max_turn = 0;

  for(int ddx = 0; ddx < 4; ddx++)
  {
    vector<int> next = {play[0] + dir[ddx][0], play[1] + dir[ddx][1]};

    if(next[0] < 0 || next[1] < 0 || next[0] >= row || next[1] >= col)
      continue;

    if(!board[next[0]][next[1]])
      continue;

    count++;
    board[play[0]][play[1]] = 0;
    pair<bool, int> result = dfsearch(board, wait, next);
    board[play[0]][play[1]] = 1;

    if(result.first)
    {
      win = true;
      min_turn = min(min_turn, result.second);
    }
    else if(win)
      continue;
    else
      max_turn = max(max_turn, result.second);
  }

  if(!count)
    return {true, 0};
  else
    return {!win, win? min_turn + 1 : max_turn + 1};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc)
{
    return dfsearch(board, aloc, bloc).second;
}
