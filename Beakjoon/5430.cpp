#include <bits/stdc++.h>
using namespace std;

int t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> t;

    while(t--){
        // 명령문
        string cmd;
        cin >> cmd;

        // 원소 개수
        int n;
        cin >> n;
        
        // 원소 배열
        string str;
        cin >> str;

        // 에러 검사
        if(!n){
            cout << "[]\n";
            continue;
        }

        int cnt = 0;
        for(char c : cmd) if(c == 'D') cnt++;
        if(cnt > n){
            cout << "error\n";
            continue;
        }

        // 원소 입력
        deque<int> dq;
        string num;
        for(int i = 1; i < str.size(); i++){
            if(str[i] == ']' || str[i] == ','){
                dq.push_back(stoi(num));
                num = "";
            }else{
                num += str[i];
            }
        }

        // 명령 실행
        bool isR = false;
        for(char c : cmd){
            if(c == 'R') isR = !isR;
            if(c == 'D') isR ? dq.pop_back() : dq.pop_front();
        }

        // 출력
        cout << '[';
        if(dq.size()){
            if(isR){
                deque<int>::reverse_iterator it;
                for(it = dq.rbegin(); it < dq.rend() - 1; it++){
                    cout << *it << ',';
                }
                cout << dq.front();
            }
            else{
                deque<int>::iterator it;
                for(it = dq.begin(); it < dq.end() - 1; it++){
                    cout << *it << ',';
                }
                cout << dq.back();
            }
        }
        cout << "]\n";
    }

    return 0;
}