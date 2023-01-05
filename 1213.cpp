#include <bits/stdc++.h>
using namespace std;

string s, ans, a;
int apb[26], ex;
char mid;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> s;
    for(char i : s) apb[i - 'A']++;

    for(int i=0; i<26; i++){
        if(apb[i]){ // 있는지
            if(apb[i] & 1){ // 홀수인지
                mid = i + 'A';
                apb[i]--;
                ex++;
            }
            if(ex == 2) break;
            for(int j=0; j<apb[i]/2; j++){
                ans += i + 'A';
            }
        }
    }

    if(ex == 2) cout << "I'm Sorry Hansoo\n";
    else {
        a = ans;
        reverse(a.begin(), a.end());
        if(mid) ans += mid;
        ans += a;
        cout << ans << '\n';
    }

    return 0;
}

// & 1 로 %2 == 1을 대체
// 홀수는 비트의 끝이 1, 짝수는 0