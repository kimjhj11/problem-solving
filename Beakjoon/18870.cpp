#include <bits/stdc++.h>
using namespace std;

int n, num;
vector<int> v, v1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--){
        cin >> num;
        v.push_back(num);
    }
    
    v1 = v;
    sort(v1.begin(), v1.end());
    v1.erase(unique(v1.begin(), v1.end()), v1.end()); // 중복제거

    // 찾아낸 이터레이터에서 벡터 시작 주소값을 빼줌으로 순서 출력
    for(int i = 0; i < v.size(); i++){
        auto it = lower_bound(v1.begin(), v1.end(), v[i]);
        cout << it - v1.begin() << " ";
    }
    cout << '\n';

    return 0;
}

// 18870_좌표압축
// 정렬
// 값 / 좌표압축