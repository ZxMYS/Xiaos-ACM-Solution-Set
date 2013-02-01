#include<iostream>
#include<cstdio>
#define MaxLen 6000
#define MaxN 20
#include<memory.h>

using namespace std;

struct str
{
       void read(int lines)
       {
            char ch;
            len = 0;
            for (int i = 1;i<=lines;i++)
            {
                scanf("%c",&ch);
                while (ch != '\n')
                {
                      s[++len] = ch;
                      scanf("%c",&ch);
                }
            }
       }
       void kmp(str &p,bool f[])
       {
            int pi[MaxN],m;
            memset(f,0,sizeof(f));
            pi[1] = 0;m = 0;
            for (int i = 2;i<=p.len;i++)
            {
                while (m && p.s[m + 1] != p.s[i]) m = pi[m];
                if (p.s[m + 1] == p.s[i]) m++;
                pi[i] = m; 
                if (m == p.len) m = pi[m];
            }      
            m = 0;
            for (int i = 1;i<=len;i++)
            {
                while (m && p.s[m + 1] != s[i]) m = pi[m];
                if (p.s[m + 1] == s[i]) m++;
                if (m == p.len) f[i - p.len + 1] = 1;
                if (m == p.len) m = pi[m];
            }
       }
       int len;
       char s[MaxLen];
};

str p[MaxN];
str t;
bool match[MaxN][MaxLen];
bool f[MaxLen][1 << 15];

int main()
{
    //freopen("G.in","r",stdin);
    //freopen("G.out","w",stdout);
    int n,lines;
    while (scanf("%d%d\n",&n,&lines) > -1)
    {
          if (n == 0 && lines == 0) break;
          memset(match,0,sizeof(match));
          for (int i = 0;i!=n;i++) p[i].read(1);
          t.read(lines);
          for (int i = 0;i!=n;i++)
          t.kmp(p[i],match[i]);
          /*/test1
          for (int i = 0;i!=n;i++)
          {
           for (int j = 1;j<=t.len;j++) cout << match[i][j];
           cout << endl;
          }
          /*/
          memset(f,0,sizeof(f));
          for (int i = 0;i<=t.len;i++) f[i][0] = 1;
          
          for (int j = 0;j != ((1 << n) - 1);j++)
          for (int i = 0;i<=t.len;i++)
          if (f[i][j])
          {
              for (int k = 0;k!=n;k++)
              if ((j | (1 << k)) != j)
              if (match[k][i + 1])
              f[i + p[k].len][j | (1 << k)] = 1;
          }
          
          int answer = 0;
          for (int i = 1;i<=t.len;i++)
          if (f[i][(1 << n) - 1]) 
          {
                      answer++;
                      //cout << i << endl;            
          }
          cout << answer << endl;
          //cout << endl;
    }
    return 0;
}
