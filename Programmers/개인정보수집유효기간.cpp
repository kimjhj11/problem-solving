#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    int yy = stoi(today.substr(0, 4));
    int mm = stoi(today.substr(5, 2));
    int dd = stoi(today.substr(8, 2));
    int now = yy * 28 * 12 + mm * 28 + dd;

    vector<pair<char, int>> nt;
    for(int i = 0; i < terms.size(); i++){
        nt.push_back({terms[i][0], stoi(terms[i].substr(2)) * 28});
    }

    vector<pair<char, int>> np;
    for(int i = 0; i < privacies.size(); i++){
        int yy = stoi(privacies[i].substr(0, 4));
        int mm = stoi(privacies[i].substr(5, 2));
        int dd = stoi(privacies[i].substr(8, 2));
        int now = yy * 28 * 12 + mm * 28 + dd;
        np.push_back({privacies[i][11], now});
    }

    for(int i = 0; i < np.size(); i++){
        for(int j = 0; j < nt.size(); j++){
            if(np[i].first == nt[j].first){
                if(now - np[i].second >= nt[j].second){
                    answer.push_back(i + 1);
                }
                break;
            }
        }
    }

    return answer;
}

// 2023 KAKAO BLIND RECRUITMENT
// 개인정보 수집 유효기간