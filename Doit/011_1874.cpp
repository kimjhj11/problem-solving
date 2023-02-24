#include <bits/stdc++.h>
using namespace std;

int n, num, cnt;
char c;
stack<int> s;
vector<char> ans;
bool isTrue = true;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cnt = 1;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(num >= cnt){
            while(num >= cnt){
                s.push(cnt);
                ans.push_back('+');
                cnt++;
            }
            s.pop();
            ans.push_back('-');
        }
        else{
            if(s.top() == num){
                s.pop();
                ans.push_back('-');
            }
            else{
                cout << "NO" << '\n';
                isTrue = false;
                break;
            }
        }
    }

    if(isTrue){
        for(char i : ans) cout << i << '\n';
    }

    return 0;
}

// 1874_스택수열
// 스택