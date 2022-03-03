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
        //자동차 번호 중복 제거 저장
        car_num_set.insert(car_num);
        // 차량 번호에 분단위 정보 저장
        int total_min = hour * 60 + min;
        car_min[car_num].push_back(total_min);
    }
    for (set<int>::iterator iter = car_num_set.begin(); iter != car_num_set.end(); iter++) {
        int sub_min = 0;
        // 짝수면 in, out pair 형성, 2개씩 분단위 계산
        if (car_min[*iter].size() % 2 == 0) {
            for (int i = 0; i < car_min[*iter].size(); i += 2) {
                sub_min += (car_min[*iter][i + 1] - car_min[*iter][i]);
            }
        }
        // 홀수면, 마지막자리 23:59와 빼기
        else {
            for (int i = 0; i < car_min[*iter].size() - 1; i += 2) {
                sub_min += (car_min[*iter][i + 1] - car_min[*iter][i]);
            }
            sub_min += ((23 * 60 + 59) - car_min[*iter][car_min[*iter].size() - 1]);
        }
        if (sub_min <= fees[0]) {
            //기본요금보다 적게 주차했으면
            answer.push_back(fees[1]);
        }
        else {
            int time_check = 0;
            int pay = 0;
            if ((sub_min - fees[0]) % fees[2] != 0) {
                // 단위시간 안떨어지면
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