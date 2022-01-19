#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <pair<int, int>> graph[1001];
int dist[1001];
int backhome_dist[1001];

int answer;

void dijkstra(int start) {
    for (int i = 0; i < 1001; i++) {
        dist[i] = 9999999;
    }
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = -1 * pq.top().first;
        int current = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i].second;
            int n_cost = graph[current][i].first;
            if (dist[next] > cost + n_cost) {
                dist[next] = cost + n_cost;
                pq.push({ -dist[next],next });
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; int m; int x;    // n - 인원 수 ,x - target
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int a; int b; int c; // a node to b node, cost
        cin >> a >> b >> c;
        graph[a].push_back({ c,b });  //push_back({cost, node})
    }
    dijkstra(x);    // x에서 집으로 가는데 걸리는 dist
    for (int i = 1; i <= n; i++) {
        backhome_dist[i] = dist[i];
    }
    for (int i = 1; i <= n; i++) { // 각 지점에서 타겟으로 가는 dist
        if (i == x) continue;
        dijkstra(i);
        if (answer < backhome_dist[i] + dist[x]) {
            answer = backhome_dist[i] + dist[x];
        }
    }
    cout << answer;
}