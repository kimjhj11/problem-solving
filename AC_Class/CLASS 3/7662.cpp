#include <bits/stdc++.h>
using namespace std;

int t, k, num;
char c;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--){
        multiset<int> ms; // 오름차순 정렬
        
        cin >> k;
        for(int i = 0; i < k; i++){
            cin >> c >> num;

            if(c == 'I'){
                ms.insert(num);
            }
            else if(c == 'D'){
                if(ms.size()){
                    if(num == -1){ // 최솟값 삭제
                        ms.erase(ms.begin());
                    }
                    else if(num == 1){ // 최대값 삭제
                        ms.erase(--ms.end());
                    }
                }
            }
        }
        if(ms.size()){
            cout << *--ms.end() << ' ' << *ms.begin() << '\n';
        }else{
            cout << "EMPTY" << '\n';
        }
    }
    return 0;
}

// 7662_이중우선순위큐