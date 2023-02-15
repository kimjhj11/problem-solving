#include <bits/stdc++.h>
using namespace std;

int n, num, a[8004], mean, mid, mode, range, max_n;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        mean += num;
        v.push_back(num);
        a[num + 4000]++;
    }

    sort(v.begin(), v.end());
    mean = round((double)mean / n);
    mid = v[n / 2];
    range = v.back() - v.front();

    bool isSecond = false;
    for(int i = 0; i <= 8000; i++){
        if(a[i] == 0) continue;
        if(a[i] == max_n){
            if(isSecond){
                mode = i - 4000;
                isSecond = false;
            }
        }
        if(a[i] > max_n){
            max_n = a[i];
            mode = i - 4000;
            isSecond = true;
        }
    }

    cout << mean <<'\n';
    cout << mid <<'\n';
    cout << mode <<'\n';
    cout << range <<'\n';

    return 0;
}

// 2108_통계학
// 수학
// 정렬