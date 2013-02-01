#include<iostream>
#include<algorithm>
#include<string>
//这又是一道排列函数的应用
using namespace std;
int n,sum;
void slove(string s)
{
    next_permutation(s.begin(),s.end());
    int i,len=s.length();
    for(i=0;i<len;i++)
    {
        if(s[i]=='1')
        {
           sum=sum+(1<<(len-i-1));
           }
        }
    }
void set(int n)
{
    int temp=n;
    sum=0;
    string s="";
    while(temp)
    {
          if(temp%2)s="1"+s;
          else s="0"+s;
          temp/=2;
          }
    s="0"+s;//这里要注意下例如1，那么要找下一个排列，显然在起前面要进位
//    cout<<s<<endl;
    slove(s);
    cout<<sum<<endl;
    }
int main()
{
    while(cin>>n,n!=0)
    {
          set(n);
          }
    return 0;
    }
