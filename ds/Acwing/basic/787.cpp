#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];
int tmp[N]; //辅助数组

void merge_sort(int q[], int l, int r){
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid+1, r);
    int k = 0, i = l, j = mid+1;
    while (i <= mid && j <= r) // i指向左半边，j指向右半边
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    // 左右两边如果有一边没有循环完，把剩下的数直接接到答案里面去
    while (i <= mid) tmp[k++] = q[i++]; 
    while (j <= r) tmp[k++] = q[j++];
    for (i=l, j=0; i<=r; i++, j++) q[i] = tmp[j]; //再把结果存回来
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    merge_sort(q, 0, n-1);
    for (int i = 0; i < n; i ++) printf("%d", q[i]);
    scanf("%*d");
    return 0;
}