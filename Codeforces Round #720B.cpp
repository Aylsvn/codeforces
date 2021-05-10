/*
B. Nastia and a Good Array
https://codeforces.com/contest/1521/problem/B

题意：给你一个数组，最多执行n次改动，最终目标让每个元素与前一个元素互质。
改动是自己选择两个数，然后选择数组里的两个数进行交换，
要求是选择的两个数的最小值要等于被选择的两个数的较小值

思路：在数组中，每次选取两个数，他们的最小值不变。
对于整个数组的最小值，也是不会变的。所以我们将除了最小值以外的数都换成质数
1 ≤ ai ≤ 1e9,1 ≤ x,y ≤ 2e9
为了排除最小值与其他质数相同的情况，
则用1e9+7与1e9+9来填充；

代码：*/
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
long long zhishu1=1e9+7;
long long zhishu2=1e9+9;
struct node
{
    long long x;
    long long y;
    long long z;
    long long k;
};
long long a[maxn];
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<node>ans;
        long long flag=1;
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        long long minn=a[1];
        for(int j=2; j<=n; j++){
            if(a[j]<minn){
                minn=a[j];
                flag=j;
            }
        }
        for(int i=1; i<=n; i++){
            if(i==flag) 
                continue;
            if(i%2==1)
                ans.push_back({i,flag,zhishu1,a[flag]});
            else
                ans.push_back({i,flag,zhishu2,a[flag]});
        }
        cout<<n-1<<endl;
        for(int i=0;i<n-1;i++)
        {
            printf("%lld %lld %lld %lld\n",ans[i].x,ans[i].y,ans[i].z,ans[i].k);
        }
    }
    return 0;
}
