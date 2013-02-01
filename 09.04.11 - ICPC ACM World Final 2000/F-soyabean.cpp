#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define VI vector<int>
#define MaxN 110

using namespace std;

template <class T> T sqr(T x) {return x * x;}

int g[MaxN][MaxN];

int main()
{
    //freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
    int datanum = 0;
    for(;;)
    {
          string s;
          getline(cin,s);
          if (s == "0 0") break;
          istringstream fin(s);
          memset(g,-1,sizeof(g));
          int a,b;
          while (fin >> a >> b)
          {
                if (!a || !b) break;
                g[a][b] = 1;
          }
          
          for (int k = 1;k<=100;k++)
          for (int i = 1;i<=100;i++)
          for (int j = 1;j<=100;j++)
          {
              if (i == j || j == k|| i == k) continue;
              if (g[i][k] == -1 || g[k][j] == -1) continue;
              if (g[i][j] == -1 || g[i][k] + g[k][j] < g[i][j])
              g[i][j] = g[i][k] + g[k][j]; 
          }
          
          int sum = 0;
          int tot = 0;
          for (int i = 1;i<=100;i++)
          {
              for (int j = 1;j<=100;j++)
              if (i != j && g[i][j] != -1) 
              {
                 sum += g[i][j];
                 tot++;
              }
          }
          
          //cout << tot << endl;
          double aver = (double)sum / tot;
          
          datanum++;
          printf("Case %d: average length between pages = ",datanum);
          cout.precision(3);
          cout << fixed << aver << " clicks" << endl; 
    }
    return 0;
}
