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

#define MaxN 1100

int a[MaxN];
int b[MaxN];
int x[MaxN];

int main()
{
    int T;cin >> T;
    while (T--)
    {
          int n;
          cin >> n;
          for (int i = 0;i!=n;i++) scanf("%d%d",&a[i],&b[i]);
          sort(a,a+n);
          sort(b,b+n);
          
          x[1 - 1] = a[2 - 1] - a[1 - 1]; 
          for (int i = 2;i<=n - 1;i++) x[i - 1] = a[i+1-1] - a[i-1-1];
          x[n - 1] = a[n - 1] - a[n - 1 - 1]; 
          
          sort(x,x+n);
          double sum = 0;
          for (int i = 0;i!=n;i++) sum += x[i] * b[i];
    
          sum /= 2;
          cout.precision(1);
          cout << fixed << sum << endl;
    }
    return 0;
}
