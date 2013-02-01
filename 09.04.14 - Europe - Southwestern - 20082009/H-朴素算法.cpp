#include<iostream>
#define MaxN 175
#pragma comment(linker, "/STACK:16777216") 

using namespace std;

int n;
long long S,L,R,X;

struct matrix
{
       matrix(int _m = 0,int _n = 0){m = _m;n = _n;memset(a,0,sizeof(a));}
       int m;
       int n;
       long long a[MaxN][MaxN];
       void out()
       {
            for (int i = 0;i!=m;i++)
            {
            for (int j = 0;j!=n;j++)
            {
                if (j) cout << " ";
                cout << a[i][j];
            }
            cout << endl;
            }   
       }
};

matrix c;

matrix operator * (const matrix &a,const matrix &b)
{
       memset(c.a,0,sizeof(c,a));
       c.m = a.m;
       c.n = b.n;
       for (int i = 0;i!=a.m;i++)
       for (int j = 0;j!=b.n;j++)
       {
           for (int k = 0;k!=a.n;k++)
           c.a[i][j] =  (c.a[i][j] + a.a[i][k] * b.a[k][j]) % X; 
       }
       return c;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
    int T;cin >> T;
    while (T--)
    {
          int Xx;
          cin >> n >> S >> L >> R >> Xx;
          X = 1; 
          for (int i = 0;i!=Xx;i++) X *= 10;
          matrix a(n,1);
          matrix g(n,n);
          for (int i = 0;i!=n;i++) cin >> a.a[i][0];
          for (int i = 0;i!=n;i++)
          {
              g.a[i][i] = 1;
              if (i) g.a[i][i-1] = L;
              else g.a[i][n-1] = L;
              if (i + 1 != n) g.a[i][i+1] = R;
              else g.a[i][0] = R;
          }
          
          while (S)
          {
                if (S & 1) a = g * a;
                g = g * g;
                //g.out();
                S /= 2; 
          }
          for (int i = 0;i!=n - 1;i++) cout << a.a[i][0] << " ";
          cout << a.a[n - 1][0] << endl;
    }
    
    return 0;
}
