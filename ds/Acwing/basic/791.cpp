#include <iostream>
#include <vector>

using namespace std;

// C = A + B
vector<int> add(vector<int> &A, vector<int> &B){
    vector<int> C;
    int t = 0; // 进位
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if(t) C.push_back(1);
    return C;
}

int main(){
    string a, b;
    vector<int> A, B;
    cin >> a >> b; // a ='123456'
    // 反着推到向量里面，因为里面是字符串，所以要减去'0'变成数字
    // C++中单引号是字符型， 双引号是字符串型
    for (int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');
    auto C = add(A, B); // auto可以自动推断类型
    for (int i = C.size()-1; i>=0; i--) printf("%d", C[i]);
    scanf("%*d");
    return 0;
}
