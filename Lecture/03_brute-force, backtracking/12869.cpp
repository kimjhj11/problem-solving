#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, hp[3], visited[64][64][64];
int pp[6][3] = {
	{9, 3, 1}, 
	{9, 1, 3}, 
	{3, 1, 9}, 
	{3, 9, 1}, 
	{1, 3, 9}, 
	{1, 9, 3}
};

struct A
{
    int aa;
    int bb;
    int cc;
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> hp[i];
    }

    queue<A> q;
    q.push({hp[0], hp[1], hp[2]});
    visited[hp[0]][hp[1]][hp[2]] = 1;

    while(q.size()){
        a = q.front().aa;
        b = q.front().bb;
        c = q.front().cc;
        q.pop();

        if(visited[0][0][0]){
            break;
        }

        for(int i = 0; i < 6; i++){
            int na = a - pp[i][0];
            int nb = b - pp[i][1];
            int nc = c - pp[i][2];
            if(na < 0) na = 0;
            if(nb < 0) nb = 0;
            if(nc < 0) nc = 0;
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }

    cout << visited[0][0][0] - 1 << '\n';
    return 0;
}

// 12869_뮤탈리스크
// 다이나믹 프로그래밍
// BFS