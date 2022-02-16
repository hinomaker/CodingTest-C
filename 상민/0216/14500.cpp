#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
typedef pair<int, int> cod;

vector<vector<cod>> shape = {{{0,1}, {0,2}, {0,3}},
                             {{0,1}, {1,0}, {1,1}},
                             {{0,1}, {0,2}, {1,1}},
                             {{1,0}, {2,0}, {2,1}},
                             {{1,0}, {1,1}, {2,1}}};

cod transform(cod xy, int version, int L){
  int r = xy.first; int c= xy.second;
  switch(version){
    case 0: return {r, c};
    case 1: return {L-c-1, r};
    case 2: return {L-r-1, L-c-1};
    case 3: return {c, L-r-1};
    case 4: return {r, L-c-1};
    case 5: return {c, r};
    case 6: return {L-r-1, c};
    case 7: return {L-c-1, L-r-1};
  }
}

int main(){
  int N, M, L;
  cin >> N >> M;

  L = max(N, M);
  int map[L][L];
  memset(map, 0, sizeof(map));
  for(int ndx = 0; ndx < N; ndx++)
    for(int mdx = 0; mdx < M; mdx++)
      cin >> map[ndx][mdx];

  int answer = 0;
  for(int ndx = 0; ndx < L; ndx++){
    for(int mdx = 0; mdx < L; mdx++){
      for(int sdx = 0; sdx < 5; sdx++){
        for(int tdx = 0; tdx < 8; tdx++){
          cod curr = transform({ndx, mdx}, tdx, L);
          int curr_sum = map[curr.first][curr.second];
          for(int vdx = 0; vdx < 3; vdx++){
            cod next = {ndx + shape[sdx][vdx].first, mdx + shape[sdx][vdx].second};
            next = transform(next, tdx, L);
            if(min(next.first, next.second) < 0 || max(next.first, next.second) >= L)
              break;
            curr_sum += map[next.first][next.second];
          }
          answer = max(answer, curr_sum);
        }
      }
    }
  }
  cout << answer;
}
