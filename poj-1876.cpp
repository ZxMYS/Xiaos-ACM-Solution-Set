#include<iostream>
#include<vector>
#define MaxMTA 1100
#define MaxLetter 1100000

using namespace std;

vector<string> MTA[MaxMTA];
vector<string> extra;
vector<string> content[MaxLetter];

struct letter
{
       int contnum; 
       pair<int , int> from;
       vector < pair<int , int> > to;
       void kg(){printf("     ");}
       void outpair(int x,int y)
       {
            if (x < 0 || y < 0)
            {
                  kg();cout << "RCPT TO:<" << extra[-y] << "@";
                  if (x < 0) cout << extra[-x];
                  else cout << MTA[x][0];
                  cout << ">"<< endl;
                  kg();cout << "550" << endl;
                  return;
            }
            ok++;
            kg();cout << "RCPT TO:<" << MTA[x][y] << "@" << MTA[x][0] << ">" << endl;;
            kg();printf("250\n");
       }
       void out()
       {
            cout << "Connection between " << MTA[from.first][0] << " and "<< MTA[to[0].first][0] << endl;       
            kg();cout << "HELO " << MTA[from.first][0] << endl;
            kg();printf("250\n");
            kg();cout << "MAIL FROM:<" << MTA[from.first][from.second] << "@" << MTA[from.first][0] << ">" << endl;
            kg();printf("250\n");
            ok = 0;
            for (int i = 0;i!=to.size();i++)
            outpair(to[i].first,to[i].second);
            if (ok)
            {
               kg();cout << "DATA\n";
               kg();cout <<"354\n";
               for (int i = 0;i!=content[contnum].size();i++)
               {
                   kg();
                   cout << content[contnum][i] << endl;
               }
               kg();cout << ".\n";
               kg();cout << "250\n";
            }
            kg();cout << "QUIT\n";
            kg();cout << "221\n";
       }
       int ok;
};

int n = 0,m;
vector<letter> Letter;

vector<string> split(string s,char ch)
{
    s+=ch;
    vector<string> U;
    U.clear();
    string ss = "";
    for (int i = 0;i!=s.length();i++)
    if (s[i] == ch) 
    {
        U.push_back(ss);
        ss = "";
    }
    else ss += s[i];
    return U;
}

pair<int,int> find(string s)
{ 
   vector<string> U;
   U = split(s,'@');
   int i1 = -1,i2 = -1;
   for (int i = 0;i!=n;i++)
   if (U[1] == MTA[i][0])
   {
            i1 = i;
            break;
   }
   
   if (i1 != -1)
   {
      for (int i = 1;i!=MTA[i1].size();i++)
      if (U[0] == MTA[i1][i])
      {
            i2 = i;
            break;
      }
   }
   else
   {
       extra.push_back(U[1]);
       i1 = - (extra.size() - 1);
   }
   
   if (i2 == -1)
   {
       extra.push_back(U[0]);
       i2 = - (extra.size() - 1);
   }
   return make_pair(i1,i2);
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
    extra.push_back("XuXu");
    string s;
    for(;;)
    {
           while (cin >> s)
           {
               if (s == "*")
               {
                   scanf("\n");
                   break;
               }
               MTA[n].clear();
               cin >> s;
               MTA[n].push_back(s);
               cin >> m;
               while (m--)
               {
                     cin >> s;
                     MTA[n].push_back(s);
               }
               n++;
           }
           m = 0;
           getline(cin,s);
           while (s != "*")
           {
                 letter tmp;
                       
                 while (s!="*")
                 {
                       //cout << s << endl;
                       vector<string> U = split(s,' ');      
                       /*/
                       cout << U.size() << endl;
                       for (int i = 0;i!=U.size();i++)
                       cout << U[i] << endl;
                       /*/
                       for (int i = 0;i!=U.size();i++)
                       tmp.to.push_back(find(U[i]));              
                       getline(cin,s);
                 }
                 
                 
                 tmp.from = tmp.to[0];
                 tmp.to.erase(tmp.to.begin());
                 sort(tmp.to.begin(),tmp.to.end());
                 tmp.to.push_back(make_pair(n + 1,1));
                 
                 letter o;
                 o.from = tmp.from;
                 o.contnum = m;
                 o.to.clear();
                 
                 for (int i = 0;i!=tmp.to.size();i++)
                 {
                     if (i && tmp.to[i].first != tmp.to[i - 1].first)
                     {
                         Letter.push_back(o);
                         o.to.clear();  
                     }
                     o.to.push_back(tmp.to[i]);
                 }
                 
                 getline(cin,s);
                 while (s!="*")
                 {
                       content[m].push_back(s);
                       getline(cin,s);
                 }
                 getline(cin,s);
                 tmp.contnum = m;
                 m++;
                 
           }
           
           for (int i = 0;i!=Letter.size();i++) Letter[i].out();
           break;
    }
    return 0;
}
