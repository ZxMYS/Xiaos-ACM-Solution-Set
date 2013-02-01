#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MaxN 1100000
#include<vector>

using namespace std;

int a[MaxN];
int d[MaxN];
int u[MaxN << 1];
int ifq[MaxN << 1];
int E;
vector<int> g[MaxN];

int bs(int x)
{
    int left = 0;
    int right = E - 1;
    while (left != right)
    {
          int mid = (left + right + 1) / 2;
          if (u[mid] == x) return mid;
          if (u[mid] > x) right = mid - 1;
          else left = mid + 1;
    }
    return left;
}

bool exist[MaxN];

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
    int datanum;
    cin >> datanum;
    for (int num = 1;num<=datanum;num++)
    {
        memset(exist,0,sizeof(exist));
        int cnt = 0;
        int n,D;
        cin >> n >> D;
        for (int i = 0;i!=n;i++) scanf("%d",&a[i]),u[cnt++] = a[i];
        n = unique(a , a + n) - a;
        for (int i = 0;i!=D;i++) scanf("%d",&d[i]),u[cnt++] = d[i];
        sort(u , u+cnt);
        E = unique(u , u+cnt) - u;
        for (int i = 0;i!=n;i++) a[i] = bs(a[i]);
        for (int i = 0;i!=D;i++) ifq[bs(d[i])] = num;
        
        /*/
        for (int i = 0;i!=E;i++) cout << u[i] << " ";
        cout << endl;
        for (int i = 0;i!=n;i++) cout << a[i] << " ";
        cout << endl;
        for (int i = 0;i!=E;i++) cout << ifq[i] << " ";
        cout << endl;
        /*/
        
        for (int i = 0;i!=E;i++) g[i].clear();
        for (int i = 0;i!=n;i++) exist[i] = 1,g[a[i]].push_back(i);
        
        int answer = 1;
        int printed = 0;
        for (int i = 0;i!=E;i++)
        {
            vector<int>::iterator j;
            for (j = g[i].begin();j!=g[i].end();j++)
            {
                int v = *j;
                exist[v] = 0;
                int y1 = 0; int y2 = 0;
                if (v && exist[v - 1]) y1 = 1;
                if (v != n && exist[v + 1]) y2 = 1;
                if ( y1 && y2 ) answer++;
                if ( !y1 && !y2) answer--; 
            }
            if (ifq[i] == num) 
            {
                        if (printed) printf(" ");
                        cout << answer;
                        printed = 1;
            }
        }   
        cout << endl;
    }
    return 0;
}
