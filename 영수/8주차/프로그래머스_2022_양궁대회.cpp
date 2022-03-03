#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> lion;
int lion_diff_max;

bool better_check(vector<int> lion, vector<int> answer) {
    for (int i = 10; i >= 0; i--) {
        if (lion[i] > answer[i]) {
            return true;
        }
        else if (lion[i] < answer[i]) {
            return false;
        }
    }
    return false;

}
void sol(vector<int> info, vector<int>& lion, vector<int>& answer) {
    int lion_sum = 0;
    int apeach_sum = 0;
    for (int i = 0; i < 10; i++) {
        if (lion[i] > info[i]) {
            lion_sum += 10 - i;
        }
        else {
            if (info[i] > 0) {
                apeach_sum += 10 - i;
            }
        }
    }
    if (lion_sum > apeach_sum) {
        int diff = lion_sum - apeach_sum;
        if (lion_diff_max == diff) {
            if (better_check(lion, answer)) {
                answer = lion;
            }
        }
        else if (lion_diff_max < diff) {
            answer = lion;
            lion_diff_max = diff;
        }
    }
}

void back(int n, vector<int> info, vector<int>& lion, vector<int>& answer, int count) {
    if (count == n) {
        sol(info, lion, answer);
        return;
    }
    if (count > n) {
        return;
    }
    for (int i = 0; i < 11; i++) {
        if (i == 10 && n - count > 0) {
            lion[i] = n - count;
            back(n, info, lion, answer, n);
            lion[i] = 0;
        }
        if (lion[i] <= info[i]) {
            lion[i] = info[i] + 1;
            back(n, info, lion, answer, count + (info[i] + 1));
            lion[i] = 0;
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    for (int i = 0; i < 11; i++) {
        lion.push_back(0);
        answer.push_back(0);
    }
    back(n, info, lion, answer, 0);
    bool check = false;
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] > 0) {
            check = true;
            break;
        }
    }
    if (check == false) {
        answer.clear();
        answer.push_back(-1);
    }
    return answer;
}