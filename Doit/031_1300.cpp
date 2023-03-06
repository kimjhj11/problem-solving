#include <bits/stdc++.h>
using namespace std;

long long n, k, sp, mp, ep, cnt, ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> k;

    // binary search
    sp = 1; ep = k; // ��ǥ�� k�� �ε����� k���� Ŭ�� ����
    while(sp <= ep){
        mp = (sp + ep) / 2;
        cnt = 0;

        // mp���� ���� ���� ����
        for(int i = 1; i <= n; i++){
            cnt += min(mp/i, n); // ���� �� ī��Ʈ
        }

        if(cnt < k){
            sp = mp + 1;
        }
        else{
            ans = mp;   // �߾Ӱ� ����
            ep = mp - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}

// 1300_K��°��
// �̺�Ž��
// �������� ũ��� ������ ���� ����Ž�� �˰����� ���ø��� ���� �߿�