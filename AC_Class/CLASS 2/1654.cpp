#include <bits/stdc++.h>
using namespace std;

int k, n, num, max_n, cnt;
vector<int> v;
long long ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> n;
    for(int i = 0; i < k; i++){
        cin >> num;
        v.push_back(num);
        max_n = max(max_n, num); 
    }

    long long start = 1, end = max_n, point;
    while(start <= end){
        point = (start + end) / 2;

        cnt = 0;
        for(int i : v){
            cnt += i / point;
        }

        if(cnt >= n){
            ans = max(ans, point);
            start = point + 1;
        }
        else{
            end = point - 1;
        }
    }
    cout << ans << '\n';

    return 0;
}
// 1654_랜선자르기
// 이분탐색
// 매개변수탐색
// 입력이 많으니 이분탐색으로
