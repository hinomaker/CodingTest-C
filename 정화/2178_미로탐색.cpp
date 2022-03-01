#include <iostream>
#include <queue>

using namespace std;


int n, m;
bool check[100][100]; // 방문 여부 저장
int a[100][100];
int length[100][100]; // 이동 거리 저장
int dx[4] = {0, 0, 1, -1}; // x 축 이동 (열 이동)
int dy[4] = {1, -1, 0, 0}; // y 축 이동 (행 이동)

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    length[y][x] = 1;
    check[y][x] = true;

    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i]; // 2. 이동 가능한 다음 좌표 계산
            int next_y = y + dy[i];

            if (next_x >= 0 && next_y >= 0 && next_x < m && next_y < n && a[next_y][next_x] == 1 && check[next_y][next_x] == false) {
                length[next_y][next_x] = length[y][x] + 1; // 3. 총 이동 거리 계산
                check[next_y][next_x] = true;
                q.push(make_pair(next_y, next_x));
            }
        }
    }
}

int main(void) {
        scanf("%d %d", &n, &m);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%1d", &a[j][k]); // 1. 붙어있는 수 나눠서 저장
            }
        }
        bfs(0, 0);
        printf("%d\n", length[n - 1][m - 1]);
}
