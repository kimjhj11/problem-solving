#include <bits/stdc++.h>
using namespace std;

int n, m, a[100004];

void binarySearch(int val){
    int first = 0;
    int last = n - 1;
    int mid;
    
    while(first <= last){
        mid = (first + last) / 2;
        if(a[mid] == val) {
            cout << 1 << '\n';
            return;
        }
        if(a[mid] > val) last = mid - 1;
        else first = mid + 1;
    }
    cout << 0 << '\n';
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        a[i] = num;
    }

    cin >> m;
    sort(a, a + n); //이진탐색을 위해 정렬
    for(int i=0; i<m; i++){
        int num;
        cin >> num;
        binarySearch(num);
    }
    return 0;
}

// 재귀 이진 탐색
// int bSearch(T arr[], T val, int first, int last)
// {
//     if (first > last) return -1;
//     int mid = (first + last) / 2;
//     if (val == arr[mid])
//         return mid;
//     else if (val < arr[mid])
//         return bSearch(arr, val, first, mid - 1);
//     else
//         return bSearch(arr, val, mid + 1, last);
// }

// 알고리즘 분류
// 자료 구조
// 정렬
// 이분 탐색