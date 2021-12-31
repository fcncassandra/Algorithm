#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int q[N];

// 假设输入 1 2 2 3 3 4
// 找3 返回 3 4
// 先找>=x的第一个数，mid满足大于x，r就往左移一半，不满足l就右移一半
// 第一轮：l=0 r=5 mid=2 q[2]=2<3 所以l=mid+1=3
// 第二轮：l=3 r=5 mid=4 q[4]=3>=3 所以r=mid=4
// 第三轮：l=3 r=4 mid=3 q[3]=3>=3 所以r=mid=3 跳出循环
// 然后开始输出：q[3]=3，所以继续输出，先输出l=3
// 再找<=的最后一个数，mid满足小于x，l就往右移一半，不满足r就左移一半
// 第一轮：l=0 r=5 mid=3 q[3]=3<=3 所以l=mid=3
// 第二轮：l=3 r=5 mid=4 q[4]=3<=3 所以l=mid=4
// 第三轮：l=4 r=5 mid=5 q[5]=4>3 所以r=mid-1=4 跳出循环
// 最后输出 3 4

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    while (m--)
    {
        int x;
        scanf("%d", &x);
        int l = 0, r = n-1;
        while(l < r) // 跳出循环时l=r
        {
            int mid = l + r >> 1; // 因为r=mid，所以这里不要+1
            if (q[mid] >= x) r = mid; // 相当于check函数
            else l = mid + 1; // 正确答案不在，由于升序所以+1直接选第二个区间
        }
        if (q[l] != x) cout << "-1 -1 " << endl;
        else
        { 
            cout << l << ' ';
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1; //由于下面是l=mid，所以+1
                if (q[mid] <= x) l = mid;
                else r = mid - 1;
            }
            cout << l << endl;

        }
    }
    scanf("%*d");
    return 0;
}