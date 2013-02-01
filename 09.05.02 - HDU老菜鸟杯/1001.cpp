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
#define MaxN 21

struct str
{
       str(){len = 0;}
       void in(char ch0)
       {
            len=0;
            scanf("%s",&s);
            len=strlen(s);
       }
       int len;
       char s[20];
};

int lva,lvd,lvhp;

struct infantry
{
       int in(int x)
       {
            int t;
            if (x)
            {
               name.in(' ');
               t = scanf("%d%d%d%d\n",&a,&d,&hp,&exp);  
            }
            else 
            {
               t = scanf("%d%d%d",&a,&d,&hp);
               exp = 0;
            }
            return t > 0;
       }
       void pk(infantry r)
       {
            int k1 = (a-r.d <= 0?1:a-r.d);
            int k2 = (r.a - d <= 0?1:r.a - d);
            while (hp > 0 && r.hp > 0)
            {
                  r.hp -= k1;
                  if (r.hp > 0) hp -= k2;
            } 
            if (hp <= 0) hp = 0;
            else 
            {
                 if (exp + r.exp >= 100) 
                 hp += lvhp;
            }
       }
       str name;
       int a,d,hp,exp;       
}e[MaxN];

void maxi(int &a,int b)
{
     if (b>a) a = b;
}

int f[1 << 21];

int main()
{
    freopen("1001.in","r",stdin);
    freopen("1001.out","w",stdout);
    infantry lb0;
    while (lb0.in(0))
    {
          memset(f,0,sizeof(f));
          cin >> lva >> lvd >> lvhp;scanf("\n");
          int n;
          scanf("%d\n",&n);
          for (int i = 0;i!=n;i++) e[i].in(1);
          f[0] = lb0.hp;
          for (int k = 0;k!=((1<<n)-1);k++)
          if (f[k])
          {
              infantry lb = lb0;
              lb.hp = f[k];
              for (int i = 0;i!=n;i++)
              if ((k | (1 << i)) == k) lb.exp += e[i].exp;
              while (lb.exp>=100)
              {
                    lb.a += lva;
                    lb.d += lvd;
                    lb.exp -= 100;
              }
              for (int i = 0;i!=n;i++)
              if ((k | (1 << i)) != k)
              {
                  infantry p;
                  p = lb;
                  p.pk(e[i]);
                  maxi(f[k | (1 << i)],p.hp);   
              }
          }
          int answer = f[(1 << n) - 1];
          if (!answer) printf("Poor LvBu,his period was gone.\n");
          else cout << answer << endl;
          scanf("\n");
    }    
    return 0;
}
