#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<string, int> mp; // �Ű� Ƚ�� ����
vector<string> v[1001]; //�� �ε����� id_list �ε���, ���Ͱ��� �Ű�����

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for (int i = 0; i < id_list.size(); i++) {
        mp.insert({ id_list[i],0 });// ���̵� �Ű�Ƚ�� �ʱ�ȭ;
    }
    for (int i = 0; i < report.size(); i++) {
        int index = -1;
        index = report[i].find(" ");
        string user;
        string out;
        user = report[i].substr(0, 0 + index); //�Ű���
        out = report[i].substr(index + 1);    //�Ű� ����
        int user_index = find(id_list.begin(), id_list.end(), user) - id_list.begin();
        v[user_index].push_back(out);
    }
    // �Ű��� ���� �Ű����� �ߺ�����
    for (int i = 0; i < id_list.size(); i++) {
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }
    // �Ű��ں� �Ű����� ���� ���
    for (int i = 0; i < id_list.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            mp[v[i][j]]++;
        }
    }
    // �Ű����� ������� k �̻��� �� üũ
    vector<string> confirm_out; // Ȯ�� out��
    for (int i = 0; i < id_list.size(); i++) {
        if (mp[id_list[i]] >= k) {
            //kȸ �̻� �� ���� ���� ����
            confirm_out.push_back(id_list[i]);
        }
    }

    // �� id_list���� ���� �� ���� �ִ��� �˻�
    for (int i = 0; i < id_list.size(); i++) {
        int count = 0; // ��� ���� count
        for (int j = 0; j < confirm_out.size(); j++) {
            // �� �Ű��� ����Ʈ���� outȮ���� �ִ��� Ȯ��
            int index = find(v[i].begin(), v[i].end(), confirm_out[j]) - v[i].begin();
            if (index != v[i].size()) {
                count++;
            }
        }
        answer.push_back(count);
    }

    return answer;
}