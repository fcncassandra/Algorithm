#include <iostream>
#include <vector>

using namespace std;

// C = A * b
vector<int> mul(vector<int> &A, int b){
    vector<int> C;
    int t = 0; // 进位
    // 这样写是只要t有值就是有进位，就继续执行
    for (int i = 0; i < A.size() || t; i++) 
    {
        if(i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    // if(t) C.push_back(t); //上面如果没有 || t就要加
    return C;
}

int main(){
    string a;
    vector<int> A;
    int b;
    cin >> a >> b; // a ='123456'
    // 反着推到向量里面，因为里面是字符串，所以要减去'0'变成数字
    // C++中单引号是字符型， 双引号是字符串型
    for (int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
    auto C = mul(A, b); // auto可以自动推断类型
    for (int i = C.size()-1; i>=0; i--) printf("%d", C[i]);
    scanf("%*d");
    return 0;
}
