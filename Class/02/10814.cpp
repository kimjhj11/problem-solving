#include <bits/stdc++.h>
using namespace std;

int n, age;
string name;
vector<pair<int, string>> v;

// 1. 나이순
bool cmp(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(){
    cin >> n;
    while(n--){
        cin >> age >> name;
        v.push_back({age, name});
    }

    // 2. 가입 순 (들어온 순서)
    stable_sort(v.begin(), v.end(), cmp);

    for(auto i : v) cout << i.first << " " << i.second << '\n';
    return 0;
}

// sort 퀵정렬 - 불안정 정렬 (원래 순서 보장 X)
// stable_sort 병합정렬 - 안정정렬 - 분할정복