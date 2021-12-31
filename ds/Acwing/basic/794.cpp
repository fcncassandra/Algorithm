#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// C = A / b 商是C 余数是r
vector<int> div(vector<int> &A, int b){
    vector<int> C;
    int r = 0;
    // 反着存，从高到低计算要反着取
    for (int i = A.size() - 1; i >= 0; i--) 
    {
        r = r * 10 + A[i];
        // if(r >= b) 这里其实不用判断是否大于
        C.push_back(r / b);
        r %= b;
    }
    // 将结果也前后倒过来，因为最后printf也是从高位到低位
    reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(){
    string a;
    vector<int> A;
    int b;
    cin >> a >> b; // a ='123456'
    // 尽管除法是正着来算的，但是计算的时候很多时候+-*/都有，所以这里还是倒着存
    for (int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
    auto C = div(A, b); // auto可以自动推断类型
    for (int i = C.size()-1; i>=0; i--) printf("%d", C[i]);
    scanf("%*d");
    return 0;
}
