#include<iostream>
#include<string>
#define MaxN 1000
#include<vector>
#include<cstdio>

using namespace std;

vector<int> a[MaxN];

int main()
{
    int datanum = 0;
    for(;;)
    {
           datanum++;
           int n = 0;
           string s;
           getline(cin,s);
           if (s == "end") break;
           for (int i = 0;i!=s.length();i++)
           {
               int t = s[i] - 'A';
               int ii = -1;
               int aii = 26;
               for (int j = 0;j!=n;j++)
               if (a[j][a[j].size() - 1] >= t && a[j][a[j].size() - 1] < aii)
               {
                    ii = j;
                    aii = a[j][a[j].size() - 1];
               }
               if (ii == -1) 
               {
                      ii = n;
                      a[ii].clear();
                      n++;
               } 
               a[ii].push_back(t);
           }
           printf("Case %d: %d\n",datanum,n);
    }
    return 0;
}
