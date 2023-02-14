#include <bits/stdc++.h>
using namespace std;

int N, L, num;
deque<pair<int,int>> dq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L;
    for(int i = 0; i < N; i++){
        cin >> num;

        // 들어오는 수보다 앞의 수가 크면 제거
        while(dq.size() && dq.back().second > num){
            dq.pop_back();
        }
        dq.push_back({i, num});

        // 인덱스가 L의 범위에서 벗어나면 제거
        if(dq.front().first <= i - L){
            dq.pop_front();
        }

        cout << dq.front().second << " ";
    }

    return 0;
}

// 11003_최솟값 찾기
// 덱
// 슬라이딩 윈도우
// 데이터 범위가 5,000,000개이므로 nlogn의 정렬을 사용한다면 시간초과