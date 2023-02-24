#include <bits/stdc++.h>
using namespace std;

int n, s, ans = -999999;
vector<int> v_num;
vector<char> v_oper;
string str;

int cal(int a, char oper, int b){
    if(oper == '+') return a + b;
    if(oper == '-') return a - b;
    if(oper == '*') return a * b;
    return 0;
}

void solve(int idx, int num){
    if(idx == v_num.size() - 1){
        ans = max(ans, num);
        return;
    }

    // (v1 + v2) + v3
    solve(idx + 1, cal(num, v_oper[idx], v_num[idx + 1])); // 3, '+', 8

    // v1 + (v2 + v3)
    if(idx + 2 <= v_num.size() - 1){
        int temp = cal(v_num[idx + 1], v_oper[idx + 1], v_num[idx + 2]);
        solve(idx + 2, cal(num, v_oper[idx], temp));
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> str;
    for(int i = 0; i < n; i++){
        !(i % 2) ? v_num.push_back(str[i] - '0') : v_oper.push_back(str[i]);
    }

    solve(0, v_num[0]);

    cout << ans << '\n';
    return 0;
}

// 16637_괄호추가하기
// 브루트포스 알고리즘