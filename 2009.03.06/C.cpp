
// Author : SOYA

#include<iostream>
#define MaxN 1100

using namespace std;

int n;
int index[MaxN];
int pindex;
int g1[MaxN][MaxN];
int g2[MaxN][MaxN];
int g[MaxN][MaxN];
int p1[MaxN];
int p2[MaxN];
int v[MaxN];
int color;
int q[MaxN];
int inner[MaxN];
int inq[MaxN];

void connect(int x,int y)
{
     if (x < 0) x = - x + n;
     if (y < 0) y = - y + n;
     g1[x][++p1[x]] = y;
     g2[y][++p2[y]] = x;
}

void dfs1(int x)
{
     if (v[x]) return;
     v[x] = 1;
     for (int i = 1;i<=p1[x];i++)
     dfs1(g1[x][i]);
     index[++pindex] = x;
}

void dfs2(int x)
{
     if (v[x]) return;
     v[x] = color;
     for (int i = 1;i<=p2[x];i++)
     dfs2(g2[x][i]);
}

bool top_logical_sort()
{
     for (int i = 1;i<=n/2;i++)
     if (v[i] == v[i+n/2]) return 0;

     /*memset(inner,0,sizeof(inner));
     memset(inq,0,sizeof(inq));
     int n = color;
     for (int i = 1;i<=n;i++) g[n+1][i] = 1;
     n++;
     for (int i = 1;i<=n;i++)
     for (int j = 1;j<=n;j++)
     if (g[i][j]) inner[j]++;

     int s = 0; int t = 1;
     q[t] = n;inq[n] = 1;
     while (s != t)
     {
           s++;
           for (int j = 1;j<=n;j++)
           {
               if (g[q[s]][j]) inner[j]--;
               if (!inner[j] && !inq[j])
               {
                  q[++t] = j;
                  inq[j] = 1;
               }
           }
     }
     if (t == n) return 1;
     else return 0;
     */
     return 1;
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    while (scanf("%d",&n) == 1)
    {
          memset(p1,0,sizeof(p1));
          memset(p2,0,sizeof(p2));
          int pairs;
          scanf("%d",&pairs);
          while (pairs--)
          {
                int i,j;
                scanf("%d%d",&i,&j);
                i = -i;j = -j;
                //now i and j can not be selected together
                connect(i,-j);
                connect(j,-i);
          }

          n = n + n;
          /*/test1
             for (int i = 1;i<=n;i++)
             {
                 cout << i << ":" << endl;
                 for (int j = 1;j<=p1[i];j++)
                 cout << g1[i][j] << " " << endl;
                 cout << endl;
             }
          /*/

          /*/test2
             for (int i = 1;i<=n;i++)
             {
                 cout << i << ":" << endl;
                 for (int j = 1;j<=p2[i];j++)
                 cout << g2[i][j] << " " << endl;
                 cout << endl;
             }
          /*/


          memset(v,0,sizeof(v));
          pindex = 0;
          for (int i = 1;i<=n;i++) if (!v[i]) dfs1(i);
          /*/test3
                 for (int i = 1;i<=pindex;i++)
                 cout << index[i] << endl;
          /*/
          memset(v,0,sizeof(v));
          color = 0;
          for (int i = n;i>=1;i--)
          if (!v[index[i]])
          {
                     color++;
                     dfs2(index[i]);
          }

          /*/test4
                 for (int i = 1;i<=n;i++)
                 cout << v[i] << endl;
          /*/

          memset(g,0,sizeof(g));
          for (int i = 1;i<=n;i++)
          for (int j = 1;j<=p1[i];j++)
          {
              int jj = g1[i][j];
              // i , jj
              if (v[i] == v[jj]) continue;
              g[v[i]][v[jj]] = 1;
          }

          /*/test5
                 for (int i = 1;i<=n;i++)
                 {
                 for (int j = 1;j<=n;j++) cout << g[i][j] << " ";
                 cout << endl;
                 }
          /*/

          if (top_logical_sort()) cout << "1" << endl;
          else cout << "0" << endl;
    }
    //system("pause");
    return 0;
}
