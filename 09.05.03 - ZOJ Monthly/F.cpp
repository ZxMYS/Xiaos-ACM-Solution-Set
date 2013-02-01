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

const int MaxN = 110000;
int a[MaxN];
int b[MaxN];

int main()
{
    //freopen("F.in","r",stdin);
    int T;cin >> T;
    while (T--)
    {
          int n1,n2;
          cin >> n1;
          for (int i = 0;i!=n1;i++) scanf("%d",&a[i]);
          cin >> n2;
          for (int i = 0;i!=n2;i++) scanf("%d",&b[i]);
          
          int j = 0,answer = 0;
          for (int i = 0;i!=n1;i++)
          {
              while (j != n2 && b[j]<a[i]) j++;
              if (j != n2 && b[j] == a[i]) answer++;  
          }
          cout << answer << endl;
    }    
    return 0;
}
