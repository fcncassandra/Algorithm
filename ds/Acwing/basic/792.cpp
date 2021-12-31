#include <iostream>
#include <vector>

using namespace std;

// 判断是否有A >= B
bool cmp(vector<int> &A, vector<int> &B){
    // 先比较长度，长度一样再比较每一位数
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size()-1; i>= 0; i--){
        if(A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}

// C = A - B
vector<int> sub(vector<int> &A, vector<int> &B){
    vector<int>  C;
    int t = 0; // 进位
    for (int i = 0; i < A.size(); i++)
    {
        t = A[i] - t; // 可能之前有借1位
        if (i < B.size()) t -= B[i];
        // 如果 t < 0 那么要+10 如果t > 0, 那么就是自己
        C.push_back((t+10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }
    // 如果最后几位的恰好为0（前导零），那么要去掉
    while (C.size() > 1 && C.back()==0) C.pop_back();
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
    if (cmp(A, B)){
        auto C = sub(A, B);
        for (int i = C.size()-1; i>=0; i--) printf("%d", C[i]);
    }else{
        auto C = sub(B, A);
        printf("-"); //前面加上负号
        for (int i = C.size()-1; i>=0; i--) printf("%d", C[i]);
    }
    scanf("%*d");
    return 0;
}
