#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

    // insert 的过程就是构建差分序列b的过程
    for (int i = 1; i <= n; i ++ ) insert(i, i, a[i]);

    // 循环接受操作
    while (m -- )
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        // 边界操作即可，所以是O(n)
        insert(l, r, c);
    }

    for (int i = 1; i <= n; i ++ ) b[i] += b[i - 1];

    for (int i = 1; i <= n; i ++ ) printf("%d ", b[i]);

    return 0;
}
