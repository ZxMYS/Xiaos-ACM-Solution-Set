#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas;
vector<string> ans;
const int num[10]={6,2,5,5,4,5,6,3,7,6};
const int add1[10][3]={
    {1,8},{1,7},{0},{1,9},{0},{2,9,6},{1,8},{0},{0},{1,8}
};
const int del1[10][4]={
    {0},{0},{0},{0},{0},{0},{1,5},{1,1},{3,6,9,0},{2,5,3}
};
const int add1del1[10][3]={
    {2,9,6},{0},{1,3},{2,2,5},{0},{1,3},{2,9,0},{0},{0},{2,6,0}
};
bool oper;

class Bignum{
    public:
    int a[101];
    int operator [](const int& x) const{
        return a[x];
    }
	void operator +=(const Bignum& b){
		int i;
		for (i=1;i<=100;i++)
		{
			a[i]+=b[i];
		}
		int jw=0;
		for (i=1;i<=100;i++)
		{
			a[i]+=jw;
			jw=a[i]/10;
			a[i]%=10;
		}
        RLOOPB(i,100,1)
            if(a[i]) break;
        a[0]=i;
	}
	void operator -=(const Bignum& b){
		int i;
		for (i=1;i<=100;i++)
		{
			a[i]-=b.a[i];
		}
		for (i=1;i<=100;i++)
		{
			while (a[i]<0){a[i]+=10;a[i+1]--;}
		}
        RLOOPB(i,100,0)
            if(a[i]) break;
        a[0]=i;
	}
    bool operator ==(const Bignum& b) const{
        if(b[0]!=a[0])return false;
        int i;
        LOOP(i,1,a[0]){
            if(b[i]!=a[i])
                return false;
        }
        return true;
    }

    string str() const{
        int i;
        string tmp="";
        RLOOP(i,a[0],1){
            tmp+=a[i]+'0';
        }
        return tmp;
    }

    Bignum(){
        memset(a,0,sizeof(a));
        a[0]=1;
        a[1]=0;
    }
    Bignum(const string& s){
        memset(a,0,sizeof(a));
        if(s.length()==0){
            Bignum();
            return;
        }
        int i,j=0;
        RLOOP(i,s.length()-1,0){
            a[++j]=s[i]-'0';
        }
        a[0]=s.length();
    }
    Bignum(const Bignum& b){
        memset(a,0,sizeof(a));
        int i;
        LOOP(i,0,b[0])
            a[i]=b[i];
    }
};

inline void vali(const Bignum& a,const Bignum& b,const Bignum& c){
    //cout<<a.str()<<' '<<b.str()<<' '<<c.str()<<endl;
    //cout<<"-"<<a[0]<<' '<<b[0]<<' '<<c[0]<<endl;
    if((a[a[0]]==0&&a[0]!=1)||(b[b[0]]==0&&b[0]!=1)||(b[b[0]]==0&&b[0]!=1)&&(c[c[0]]==0&&c[0]!=1)||(c[c[0]]==0&&c[0]!=1))
        return;
    if(oper){
        Bignum t(a);
        t+=b;
        if(t==c){
            string tmp;
            tmp=a.str();
            tmp+=(oper?'+':'-');
            tmp+=b.str();
            tmp+='=';
            tmp+=c.str();
            ans.push_back(tmp);
        }
    }else{
        Bignum t(c);
        t+=b;
        if(t==a){
            string tmp;
            tmp=a.str();
            tmp+=(oper?'+':'-');
            tmp+=b.str();
            tmp+='=';
            tmp+=c.str();
            ans.push_back(tmp);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
string in;
cin>>in;
LOOPB(i,0,in.length()){
    if(!isdigit(in[i]))
        break;
}
Bignum a(in.substr(0,i));
oper=(in[i]=='+');
i++;
j=i;
LOOPB(i,i,in.length()){
    if(!isdigit(in[i]))
        break;
}
Bignum b(in.substr(j,i-j));
j=++i;
Bignum c(in.substr(j,in.length()-j));
//cout<<a.str()<<' '<<b.str()<<' '<<c.str()<<endl;
//cout<<"-"<<a[0]<<' '<<b[0]<<' '<<c[0]<<endl;
LOOP(i,1,a[0]){
    LOOP(j,1,a[0])
        if(i==j){
                if(add1del1[a[i]][0]){
                    LOOP(k,1,add1del1[a[i]][0]){
                        s=a[i];
                        a.a[i]=add1del1[a[i]][k];
                        vali(a,b,c);
                        a.a[i]=s;
                    }
                }
            }else{
                if(del1[a[i]][0]&&add1[a[j]][0]){
                    LOOP(k,1,del1[a[i]][0]){
                        LOOP(l,1,add1[a[j]][0]){
                            s=a[i];
                            t=a[j];
                            a.a[i]=del1[a[i]][k];
                            a.a[j]=add1[a[j]][l];
                            vali(a,b,c);
                            a.a[i]=s;
                            a.a[j]=t;
                        }
                    }
                }
            }
    LOOP(j,1,b[0]){
        if(del1[a[i]][0]&&add1[b[j]][0]){
            LOOP(k,1,del1[a[i]][0]){
                LOOP(l,1,add1[b[j]][0]){
                    s=a[i];
                    t=b[j];
                    a.a[i]=del1[a[i]][k];
                    b.a[j]=add1[b[j]][l];
                    vali(a,b,c);
                    a.a[i]=s;
                    b.a[j]=t;
                }
            }
        }
    }
    LOOP(j,1,c[0]){
        if(del1[a[i]][0]&&add1[c[j]][0]){
            LOOP(k,1,del1[a[i]][0]){
                LOOP(l,1,add1[c[j]][0]){
                    s=a[i];
                    t=c[j];
                    a.a[i]=del1[a[i]][k];
                    c.a[j]=add1[c[j]][l];
                    vali(a,b,c);
                    a.a[i]=s;
                    c.a[j]=t;
                }
            }
        }
    }
}
LOOP(i,1,b[0]){
    LOOP(j,1,b[0])
        if(i==j){
            if(add1del1[b[i]][0]){
                LOOP(k,1,add1del1[b[i]][0]){
                    s=b[i];
                    b.a[i]=add1del1[b[i]][k];
                    vali(a,b,c);
                    b.a[i]=s;
                }
            }}else{
                if(del1[b[i]][0]&&add1[b[j]][0]){
                    LOOP(k,1,del1[b[i]][0]){
                        LOOP(l,1,add1[b[j]][0]){
                            s=b[i];
                            t=b[j];
                            b.a[i]=del1[b[i]][k];
                            b.a[j]=add1[b[j]][l];
                            vali(a,b,c);
                            b.a[i]=s;
                            b.a[j]=t;
                        }
                    }
                }
            }
    LOOP(j,1,a[0]){
        if(del1[b[i]][0]&&add1[a[j]][0]){
            LOOP(k,1,del1[b[i]][0]){
                LOOP(l,1,add1[a[j]][0]){
                    s=b[i];
                    t=a[j];
                    b.a[i]=del1[b[i]][k];
                    a.a[j]=add1[a[j]][l];
                    vali(a,b,c);
                    b.a[i]=s;
                    a.a[j]=t;
                }
            }
        }
    }
    LOOP(j,1,c[0]){
        if(del1[b[i]][0]&&add1[c[j]][0]){
            LOOP(k,1,del1[b[i]][0]){
                LOOP(l,1,add1[c[j]][0]){
                    s=b[i];
                    t=c[j];
                    b.a[i]=del1[b[i]][k];
                    c.a[j]=add1[c[j]][l];
                    vali(a,b,c);
                    b.a[i]=s;
                    c.a[j]=t;
                }
            }
        }
    }
}
LOOP(i,1,c[0]){
    LOOP(j,1,c[0])
        if(i==j){
            if(add1del1[c[i]][0]){
                LOOP(k,1,add1del1[c[i]][0]){
                    s=c[i];
                    c.a[i]=add1del1[c[i]][k];
                    vali(a,b,c);
                    c.a[i]=s;
                }
            }}else{
                if(del1[c[i]][0]&&add1[c[j]][0]){
                    LOOP(k,1,del1[c[i]][0]){
                        LOOP(l,1,add1[c[j]][0]){
                            s=c[i];
                            t=c[j];
                            c.a[i]=del1[c[i]][k];
                            c.a[j]=add1[c[j]][l];
                            vali(a,b,c);
                            c.a[i]=s;
                            c.a[j]=t;
                        }
                    }
                }
            }
    LOOP(j,1,a[0]){
        if(del1[c[i]][0]&&add1[a[j]][0]){
            LOOP(k,1,del1[c[i]][0]){
                LOOP(l,1,add1[a[j]][0]){
                    s=c[i];
                    t=a[j];
                    c.a[i]=del1[c[i]][k];
                    a.a[j]=add1[a[j]][l];
                    vali(a,b,c);
                    c.a[i]=s;
                    a.a[j]=t;
                }
            }
        }
    }
    LOOP(j,1,b[0]){
        if(del1[c[i]][0]&&add1[b[j]][0]){
            LOOP(k,1,del1[c[i]][0]){
                LOOP(l,1,add1[b[j]][0]){
                    s=c[i];
                    t=b[j];
                    c.a[i]=del1[c[i]][k];
                    b.a[j]=add1[b[j]][l];
                    vali(a,b,c);
                    c.a[i]=s;
                    b.a[j]=t;
                }
            }
        }
    }
}
sort(ans.begin(),ans.end());
LOOPB(i,0,ans.size()){
    cout<<ans[i]<<endl;
}
if(ans.size()==0){
    cout<<"-1"<<endl;
}
}
