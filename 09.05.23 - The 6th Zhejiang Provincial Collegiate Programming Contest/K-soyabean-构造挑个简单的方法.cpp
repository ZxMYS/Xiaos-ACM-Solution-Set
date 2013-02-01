#include<cstdio>
#include<iostream>
int a[500][500];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
          int m,n,k;
          scanf("%d%d%d",&m,&n,&k);
          for (int i = 1;i<=m;i++)
          for (int j = 1;j<=n;j++)
          a[i][j] = 1;
          for (int i = 2;i<=m-1;i++)
          for (int j = 2;j<=n-1;j++)
          if (k)
          {
              {
                    k--;
                    a[i][j] = 0;
                    a[i][j-1] = 0;
                    a[i][j+1] = 0;
                    a[i-1][j] = 0;
                    a[i+1][j] = 0;
              }
          }
          for (int i = 1;i<=m;i++)
          for (int j = 1;j<=n;j++)
          printf("%d%c",a[i][j],(j==n?'\n':' '));
    }
    return 0;
}
