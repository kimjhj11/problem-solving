#include <bits/stdc++.h>
using namespace std;

int n, a[1000004], ans[1000004];
stack<int> s;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    memset(ans, -1, sizeof(ans));

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        // stack�� �ε����� �ְ� ū�� ������ ��ü���
        while(s.size() && a[s.top()] < a[i]){
            ans[s.top()] = a[i]; //-1 ������ �ֱ⿡ -1 �迭�� ���� �ֱ�
            s.pop();
        }
        s.push(i); // �ٽ� ���� ����
    }
    
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}

// 17298_��ū��
// stack