#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> car_min[10001];
set<int> car_num_set;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for (int i = 0; i < records.size(); i++) {
        int hour;
        int min;
        int car_num;
        string status;
        hour = stoi(records[i].substr(0, 2));
        min = stoi(records[i].substr(3, 2));
        car_num = stoi(records[i].substr(6, 4));
        status = records[i].substr(11);
        //�ڵ��� ��ȣ �ߺ� ���� ����
        car_num_set.insert(car_num);
        // ���� ��ȣ�� �д��� ���� ����
        int total_min = hour * 60 + min;
        car_min[car_num].push_back(total_min);
    }
    for (set<int>::iterator iter = car_num_set.begin(); iter != car_num_set.end(); iter++) {
        int sub_min = 0;
        // ¦���� in, out pair ����, 2���� �д��� ���
        if (car_min[*iter].size() % 2 == 0) {
            for (int i = 0; i < car_min[*iter].size(); i += 2) {
                sub_min += (car_min[*iter][i + 1] - car_min[*iter][i]);
            }
        }
        // Ȧ����, �������ڸ� 23:59�� ����
        else {
            for (int i = 0; i < car_min[*iter].size() - 1; i += 2) {
                sub_min += (car_min[*iter][i + 1] - car_min[*iter][i]);
            }
            sub_min += ((23 * 60 + 59) - car_min[*iter][car_min[*iter].size() - 1]);
        }
        if (sub_min <= fees[0]) {
            //�⺻��ݺ��� ���� ����������
            answer.push_back(fees[1]);
        }
        else {
            int time_check = 0;
            int pay = 0;
            if ((sub_min - fees[0]) % fees[2] != 0) {
                // �����ð� �ȶ�������
                time_check = (sub_min - fees[0]) / fees[2] + 1;
            }
            else {
                time_check = (sub_min - fees[0]) / fees[2];
            }
            answer.push_back(time_check * fees[3] + fees[1]);
        }
    }

    return answer;
}