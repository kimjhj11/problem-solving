#include <bits/stdc++.h>
using namespace std;

int n, num, i, j, ans;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for(int k = 0; k < n; k++){
        i = 0;
        j = n - 1;

        while(i < j){
            if(v[i] + v[j] == v[k]){
                if(i != k && j != k){
                    ans++;
                    break;
                }
                else if(i == k){
                    i++;
                }
                else if(j == k){
                    j--;
                }
            }
            else if(v[i] + v[j] < v[k]){
                i++;
            }
            else if(v[i] + v[j] > v[k]){
                j--;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}

// 1253_좋다
// two-pointers
// 처음에는 양수만 생각하여 목표 숫자의 앞부분 인덱스만 사용했으나 이는 X
// 음수도 고려하여 벡터 전체를 두 포인터 사용