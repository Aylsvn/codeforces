/*
A. Nastia and Nearly Good Numbers
https://codeforces.com/contest/1521/problem/A

题意：给两个正整数AB，规定了两种形式，
如果一个整数是好的话，它可以整除A*B；
如果它是近似好的，就只能整除A；
输出三个数x,y,z.使得两个数只能整除A，一个数整除A*B，且x + y = z;

思路：最好的情况就是让最大的数，能够整除A*B，且刚好等于A*B；
则 X + Y = B, X != Y;
则B要分情况，B = 1时，则不满足题意；
否则将B分成两个正整数，最简单的方法就是分成1与B-1；
当B = 2时，就将Z扩大为2AB，则X = A.Y = 3A;

代码如下：*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<stack>
#include<queue>
using namespace std;
const int maxn = 1e7+10;
const int mod = 1e8-3;
const int inf = 0x3f3f3f;
int main(int argc, char const *argv[])
{
    long long T;
    cin>>T;
    while(T--){
        long long a,b;
        cin>>a>>b;
        if(b==1)
            cout<<"NO"<<endl;
        else if(b==2){
            cout<<"YES"<<endl;
            cout<<a<<" "<<3*a<<" "<<2*a*b<<endl;
        }
        else{
            cout<<"YES"<<endl;
            cout<<a<<" "<<(b-1)*a<<" "<<a*b<<endl;
        }
    }
    return 0;
}
