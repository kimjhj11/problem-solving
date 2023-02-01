#include <bits/stdc++.h>
using namespace std;

int n, node, dnode, root, ans;
vector<int> v[50];

int dfs(int root){
    int ans = 0;
    bool leaf = true;
    for(auto i : v[root]){
        if(i == dnode) continue;
        ans += dfs(i);
        leaf = false;
    }
    if(leaf) ans = 1;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> node;
        if(node == -1) root = i;
        else v[node].push_back(i);
    }

    cin >> dnode;
    if(dnode == root){
        cout << 0 << '\n';
        return 0;
    }
    cout << dfs(root) << '\n';
    return 0;
}

// 1068_Æ®¸®
// tree
// dfs