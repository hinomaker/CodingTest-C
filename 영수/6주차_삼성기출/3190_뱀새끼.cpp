#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n;
int k;
int l;
int mp[101][101];	//��
char dir[10001];	// L - ���� ,D - ������
pair<int, int> dir_int[4] = { {-1,0},{0,1},{1,0},{0,-1} };
int t = 0;

struct snake {
	deque<int> x;	// ����
	deque<int> y;	// ������ ����
	pair<int,int> move_dir;	// ù���� ����
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
	s.x.push_back(0);	//����
	s.y.push_back(0);		//������
	mp[0][0] = 9;	// �� ����
	s.move_dir.first = 0;	// ���� ������
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


		int next_i = s.x.back() + s.move_dir.first;		// ���� �ֽ� ��ǥ ����
		int next_j = s.y.back() + s.move_dir.second;

		if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < n) {	// ���� �� �̶��
			if (mp[next_i][next_j] == 2) {	// ������ǥ ������� üũ
				mp[next_i][next_j] = 9;	// �� ����
				s.x.push_back(next_i);
				s.y.push_back(next_j);
			}
			else if (mp[next_i][next_j] == 9) {	// �� �����̶��
				return;	// ���ӳ�
			}
			else {	// �� ���ٴ��̶��
				//cout << "���ٴ�" << endl;
				s.x.push_back(next_i);	// ���� ��ǥ �־��ְ�
				s.y.push_back(next_j);
				mp[next_i][next_j] = 9;
				mp[s.x.front()][s.y.front()] = 0;
				s.x.pop_front();	// ���� �ڸ���
				s.y.pop_front();

			}
		}
		else{	//���� ���̸� ��
			return;
		}


		if (dir[t] == 'L' || dir[t] == 'D') { // �ش� �ð��� ������ȯ �ִ��� Ȯ��
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
		mp[a_i-1][a_j-1] = 2;	// ����� 2
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		dir[x] = c; // x�ʿ� c�������� ��ȯ
	}
	sol();
	cout << t << endl;
}