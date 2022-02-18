#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n;
int k;
int l;
int mp[101][101];	//맵
char dir[10001];	// L - 왼쪽 ,D - 오른쪽
pair<int, int> dir_int[4] = { {-1,0},{0,1},{1,0},{0,-1} };
int t = 0;

struct snake {
	deque<int> x;	// 맨위
	deque<int> y;	// 맨좌측 시작
	pair<int,int> move_dir;	// 첫시작 우측
};

void change_dir(snake &s,char dir) {
	if (s.move_dir.first == 1 && s.move_dir.second == 0) {
		if (dir == 'L') {
			s.move_dir = dir_int[1];
		}
		if (dir == 'D') {
			s.move_dir = dir_int[3];
		}
	}
	else if (s.move_dir.first == 0 && s.move_dir.second == 1) {
		if (dir == 'L') {
			s.move_dir = dir_int[0];
		}
		if (dir == 'D') {
			s.move_dir = dir_int[2];
		}
	}
	else if (s.move_dir.first == -1 && s.move_dir.second == 0) {
		if (dir == 'L') {
			s.move_dir = dir_int[3];
		}
		if (dir == 'D') {
			s.move_dir = dir_int[1];
		}
	}
	else if (s.move_dir.first == 0 && s.move_dir.second == -1) {
		if (dir == 'L') {
			s.move_dir = dir_int[2];
		}
		if (dir == 'D') {
			s.move_dir = dir_int[0];
		}
	}
}

void sol() {
	snake s;
	s.x.push_back(0);	//맨위
	s.y.push_back(0);		//맨좌측
	mp[0][0] = 9;	// 뱀 몸통
	s.move_dir.first = 0;	// 최초 오른쪽
	s.move_dir.second = 1;
	t = 0;
	while (1) {
		t++;

		//cout << "start "<<t  << endl;
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		cout << mp[i][j] << " ";
		//	}
		//	cout << endl;
		//}


		int next_i = s.x.back() + s.move_dir.first;		// 가장 최신 좌표 꺼내
		int next_j = s.y.back() + s.move_dir.second;

		if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < n) {	// 범위 안 이라면
			if (mp[next_i][next_j] == 2) {	// 다음좌표 사과인지 체크
				mp[next_i][next_j] = 9;	// 뱀 몸통
				s.x.push_back(next_i);
				s.y.push_back(next_j);
			}
			else if (mp[next_i][next_j] == 9) {	// 뱀 몸통이라면
				return;	// 게임끝
			}
			else {	// 걍 땅바닥이라면
				//cout << "땅바닥" << endl;
				s.x.push_back(next_i);	// 다음 좌표 넣어주고
				s.y.push_back(next_j);
				mp[next_i][next_j] = 9;
				mp[s.x.front()][s.y.front()] = 0;
				s.x.pop_front();	// 꼬리 자르기
				s.y.pop_front();

			}
		}
		else{	//범위 밖이면 끝
			return;
		}


		if (dir[t] == 'L' || dir[t] == 'D') { // 해당 시간에 방향전환 있는지 확인
			change_dir(s, dir[t]);
		}

	}
 

}



int main() {
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a_i;
		int a_j;
		cin >> a_i >> a_j;
		mp[a_i-1][a_j-1] = 2;	// 사과는 2
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		dir[x] = c; // x초에 c방향으로 전환
	}
	sol();
	cout << t << endl;
}