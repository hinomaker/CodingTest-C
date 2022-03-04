#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<string, int> mp; // 신고 횟수 저장
vector<string> v[1001]; //각 인덱스는 id_list 인덱스, 벡터값은 신고유저

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for (int i = 0; i < id_list.size(); i++) {
        mp.insert({ id_list[i],0 });// 아이디별 신고횟수 초기화;
    }
    for (int i = 0; i < report.size(); i++) {
        int index = -1;
        index = report[i].find(" ");
        string user;
        string out;
        user = report[i].substr(0, 0 + index); //신고자
        out = report[i].substr(index + 1);    //신고 유저
        int user_index = find(id_list.begin(), id_list.end(), user) - id_list.begin();
        v[user_index].push_back(out);
    }
    // 신고자 별로 신고유저 중복제거
    for (int i = 0; i < id_list.size(); i++) {
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }
    // 신고자별 신고유저 누적 기록
    for (int i = 0; i < id_list.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            mp[v[i][j]]++;
        }
    }
    // 신고유저 누적기록 k 이상인 것 체크
    vector<string> confirm_out; // 확정 out자
    for (int i = 0; i < id_list.size(); i++) {
        if (mp[id_list[i]] >= k) {
            //k회 이상 인 리폿 유저 저장
            confirm_out.push_back(id_list[i]);
        }
    }

    // 각 id_list별로 리폿 된 유저 있는지 검사
    for (int i = 0; i < id_list.size(); i++) {
        int count = 0; // 결과 통지 count
        for (int j = 0; j < confirm_out.size(); j++) {
            // 각 신고자 리스트에서 out확정자 있는지 확인
            int index = find(v[i].begin(), v[i].end(), confirm_out[j]) - v[i].begin();
            if (index != v[i].size()) {
                count++;
            }
        }
        answer.push_back(count);
    }

    return answer;
}