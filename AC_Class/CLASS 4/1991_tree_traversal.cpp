#include <bits/stdc++.h>
using namespace std;

int tree[26][2];

void preorder(int n){
    if(n == -1) return;
    cout << (char)(n + 'A');
    preorder(tree[n][0]);
    preorder(tree[n][1]);
}

void inorder(int n){
    if(n == -1) return;
    inorder(tree[n][0]);
    cout << (char)(n + 'A');
    inorder(tree[n][1]);
}

void postorder(int n){
    if(n == -1) return;
    postorder(tree[n][0]);
    postorder(tree[n][1]);
    cout << (char)(n + 'A');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char a, b, c;
        cin >> a >> b >> c;

        a = a - 'A';

        if(b == '.') tree[a][0] = -1;
        else tree[a][0] = b - 'A';

        if(c == '.') tree[a][1] = -1;
        else tree[a][1] = c - 'A';
    }

    preorder(0);
    cout << '\n';

    inorder(0);
    cout << '\n';

    postorder(0);
    cout << '\n';

    return 0;
}

// 1991_트리순회
// 트리