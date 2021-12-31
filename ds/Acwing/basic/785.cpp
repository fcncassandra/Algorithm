#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if(l >= r) return; // 第一步是看边界
    // 先移动再判断，所以先放在边界的左右两侧
    int x = q[l], i = l - 1, j = r + 1;  //这里一定不能是q[r]，不然也会有边界问题
    while (i < j){ // 循环执行迭代
        do i ++; while (q[i] < x); //迭代先往后移
        do j --; while (q[j] > x); // 迭代先往前移
        if (i < j) swap(q[i], q[j]); // 如果小于就交换

    }
    // 相当于分治成两段再去递归
    quick_sort(q, l, j); // 每次都是从0开始数，确保最小的在最前面
    quick_sort(q, j+1, r); // 每次从后一个指针开始，确保最大的在后面

    // // 对称来写也可以
    // 如果输入是：1, 2  第一轮结束时i=0, j=0
    // int x = q[(1+r+1)/2] //这里也要改，不然会超过边界
    // quick_sort(q, l, i-1; // 上面l和r输入是0,1 这里是 0, -1
    // quick_sort(q, i, r) // 上面l和r输入是0,1，这里是是 0,1，这个位置死循环了
}

int main()
{
    scanf("%d", &n); 
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    quick_sort(q, 0, n-1);
    for (int i = 0; i < n; i ++) printf("%d", q[i]);
    return 0;
}