#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c, ans;

ll dc(ll a, ll b, ll c){
    if(b == 0) return 1;
    if(b == 1) return a % c;

    ans = dc(a, b/2, c); // 한번 호출 및 저장하기
    ans = (ans * ans) % c;
    if(b % 2) return (ans * a) % c; //홀수일때
    else return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c;
    cout << dc(a, b, c) << '\n';

    return 0;
}

// (a*b)%c = (a%c)*(b%c) 오버플로우 방지를 위해 미리 모듈러
// 재귀호출을 너무 많이하면 실패

// 알고리즘 분류
// 수학
// 분할 정복을 이용한 거듭제곱