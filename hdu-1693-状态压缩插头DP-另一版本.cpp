#include<iostream>
using namespace std;
int pic[14][14];
__int64 dp[14][14][1<<14];
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
    int t,cases;
    scanf("%d",&cases);
    for(t=1;t<=cases;++t)
    {
        int m,n;
        int i,j,k;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                scanf("%d",&pic[i][j]);
        dp[0][m][0]=1;
        for(i=1;i<=n;++i)
        {
            for(k=0;k<(1<<m);++k)
                dp[i][0][k<<1]=dp[i-1][m][k];
            for(j=1;j<=m;++j)
            {
                for(k=0;k<(1<<(m+1));++k)
                {
                    int l,r;
                    l=k&(1<<(j-1));
                    r=k&(1<<j);
                    if(pic[i][j]==1)
                    {
                        if(l==0&&r==0)
                            dp[i][j][k]=dp[i][j-1][k|(1<<j)|(1<<(j-1))];
                        else if(l!=0&&r!=0)
                            dp[i][j][k]=dp[i][j-1][k&(~(1<<j))&(~(1<<(j-1)))];
                        else if(l!=0&&r==0)
                            dp[i][j][k]=dp[i][j-1][(k|(1<<j))&(~(1<<(j-1)))]+dp[i][j-1][k];
                        else if(l==0&&r!=0)
                            dp[i][j][k]=dp[i][j-1][(k&(~(1<<j)))|(1<<(j-1))]+dp[i][j-1][k];
                    }
                    else
                    {
                        if(l||r)
                            dp[i][j][k]=0;
                        else
                            dp[i][j][k]=dp[i][j-1][k];
                    }
                }
            }
        }
        printf("Case %d: There are %I64d ways to eat the trees.\n",t,dp[n][m][0]);
    }
    return 0;
}
