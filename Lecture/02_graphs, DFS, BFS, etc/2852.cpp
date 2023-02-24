#include <bits/stdc++.h>
using namespace std;

int n, mm, ss, team, s_time;
int atime, btime, a, b, *t;
string gtime;
vector<pair<int,int>> v;

string print(int v){
    string a = "00" + to_string(v / 60);
    string b = "00" + to_string(v % 60);
    return a.substr(a.size() - 2, 2) + ":" + b.substr(b.size() - 2, 2); // 뒤에 두개만
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    cin >> n;
    while(n--){
        cin >> team >> gtime;
        mm = atoi(gtime.substr(0,2).c_str());
        ss = atoi(gtime.substr(3,2).c_str());
        s_time = mm * 60 + ss;
        v.push_back({team, s_time});
    }

    for(int i = 0; i < v.size(); i++){
        v[i].first == 1 ? a++ : b++;

        if(a == b) continue;
        if(a > b) t = &atime;
        else t = &btime;

        if(i == v.size() - 1) *t += 48 * 60 - v[i].second;
        else *t += v[i+1].second - v[i].second;
    }

    cout << print(atime) << '\n';
    cout << print(btime) << '\n';
    return 0;
}

// 2852_NBA농구
// string