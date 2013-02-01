#include<iostream>
#define MaxN 110
#define MIN(x,y) ((x)<(y)?(x):(y))
using namespace std;

int a[MaxN];
int f[MaxN][MaxN];
int t;

int main()
{
#ifdef ONLINE_JUDGE
#else
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++) cin >> a[i];
    for (int i = 1;i<=n;i++)
    for (int j = 1;j<=n;j++)
        f[i][j]=10000;
    for (int i = 1;i<=n-2;i++)
    f[i][i+2] = a[i] * a[i+1] * a[i+2];    

    for (int len = 4;len <= n;len++)
    for (int start = 1;start + len - 1<=n;start++)
    {
        int end = start + len - 1;
        for (int k = start+1;k<end;k++)
        {
        t=0;
        if(end-k>=2&&k-start>=2)
        t=(MIN(a[start]*a[k-1]*a[k+1]+a[start]*a[k]*a[end],a[start]*a[k-1]*a[end]+a[k-1]*a[k]*a[end]));
        else if(end-k==1&&k-start>=2)
        t=a[start]*a[k-1]*a[end];
        else if(k-start==1&&end-k>=2)
        t=a[start]*a[k+1]*a[end];
        f[start][end]=MIN(f[start][end],f[start][k-1] + f[k+1][end] + (a[k-1] * a[k] * a[k+1])+t);
        }
    } 
    
    cout << f[1][n];
    system("pause");
    return 0;
}
