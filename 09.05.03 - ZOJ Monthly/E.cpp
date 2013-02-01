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
#include<queue>
template <class T> void sw(T &a,T &b){T t; t = a; a = b; b = t;}
template <class T> T sqr(T x) {return x * x;}
using namespace std;
const double pi = acos(-1.0);

const int MaxN = 5100;

struct interval
{
       interval(int _x = 0,int _y = 0){x = _x;y = _y;}
       bool operator < (const interval a) const {return y < a.y;}
       void read() {scanf("%d%d",&x,&y);}
       int x,y;
};

interval a[MaxN];
int f[MaxN];

void mini(int &a,int b)
{
     if (b == -1) return;
     if (b < a || a == -1) a = b;
}

int main()
{
    int T;cin >> T;
    while (T--)
    {
          int n;cin >> n;
          for (int i = 0;i!=n;i++) a[i].read();
          sort(a,a+n);
          
          memset(f,-1,sizeof(f));
          f[0] = 0;
          for (int i = 0;i!=n;i++)
          {
              for (int j = a[i].x - 1;j<a[i].y;j++) 
              if (f[j] != -1) mini(f[a[i].y],f[j] + 1);
              for (int j = a[i].x - 1;j<a[i].y;j++) mini(f[j],f[a[i].y]);
          }
          cout << f[n] << endl;
    }    
    return 0;
}
