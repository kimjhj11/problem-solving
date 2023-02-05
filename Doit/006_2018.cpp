#include <bits/stdc++.h>
using namespace std;

int n, cnt = 1;
int sum = 1, start_idx = 1, end_idx = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(end_idx != n){
        if(sum == n){
            cnt++;
            end_idx++;
            sum = sum + end_idx;
        }
        else if(sum < n){
            end_idx++;
            sum = sum + end_idx;
            
        }
        else if(sum > n){
            sum = sum - start_idx;
            start_idx++;
        }
    }
    cout << cnt << '\n';
    return 0;
}

// 2018_수들의합5
// two-pointers