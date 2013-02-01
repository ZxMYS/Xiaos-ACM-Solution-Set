#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
int i,j,k,a,m,n,s,t,l,tt=0;
char str[500],str2[500],str3[500],ctmp,strtmp[500];
const char bloodtype[10][5]={"AO+","AO-","BO+","BO-","AB+","AB-","O+","O-"};
vector<string> ans,ans2;
bool flag;
map<string,bool> tmap;
map<string,bool>::iterator tmapiter;
map<string,string> bmap;
map<string,string>::iterator bmapiter;
inline void retype(char a[]){
    if(a[0]>a[1]){
        ctmp=a[1];
        a[1]=a[0];
        a[0]=ctmp;
    }
    //cout<<"trying"<<a<<endl;
    bmapiter=bmap.find(a);
    tmapiter=tmap.find(bmapiter->second);
    if(tmapiter==tmap.end()){
        tmap.insert(pair<string,bool>(bmapiter->second,true));
        ans.push_back(bmapiter->second);
    }
    
}

inline void child(){
    tmap.clear();
    int ii=strlen(str)-1;
    int jj=strlen(str2)-1;
    bool flag=true;
    char wtf[3];
    wtf[2]=0;
    if(str[ii]=='-'&&str2[jj]=='-')
        flag=false;
    LOOPB(i,0,ii)
        LOOPB(j,0,jj)
            {
                wtf[0]=str[i];
                wtf[1]=str2[j];
                retype(wtf);
            }
    if(flag){
        ii=ans.size();
        LOOPB(i,0,ii){
            ans.push_back(ans[i]+"-");
            ans[i]+="+";
        }
    }else{
        ii=ans.size();
        LOOPB(i,0,ii){
            ans[i]+="-";
        }
    }

}

inline void parent(){
int i;
LOOPB(i,0,8){
     //cout<<"Ptrying "<<bloodtype[i]<<endl;
    strcpy(str2,bloodtype[i]);
    ans.clear();
    child();
    if(find(ans.begin(),ans.end(),str3)!=ans.end())
        ans2.push_back(bloodtype[i]);
}
}

int main()
{
//#ifndef ONLINE_JUDGE
//freopen("in.txt","r",stdin);
//freopen("out","w",stdout);
//#endif
bmap.insert(pair<string,string>("AA","A"));
bmap.insert(pair<string,string>("AB","AB"));
bmap.insert(pair<string,string>("AO","A"));
bmap.insert(pair<string,string>("BB","B"));
bmap.insert(pair<string,string>("BO","B"));
bmap.insert(pair<string,string>("OO","O"));
bmap.insert(pair<string,string>("+-","+"));
bmap.insert(pair<string,string>("-+","+"));
bmap.insert(pair<string,string>("--","-"));
bmap.insert(pair<string,string>("AA+","A+"));
bmap.insert(pair<string,string>("AB+","AB+"));
bmap.insert(pair<string,string>("AO+","A+"));
bmap.insert(pair<string,string>("BB+","B+"));
bmap.insert(pair<string,string>("BO+","B+"));
bmap.insert(pair<string,string>("OO+","O+"));
bmap.insert(pair<string,string>("AA-","A-"));
bmap.insert(pair<string,string>("AB-","AB-"));
bmap.insert(pair<string,string>("AO-","A-"));
bmap.insert(pair<string,string>("BB-","B-"));
bmap.insert(pair<string,string>("BO-","B-"));
bmap.insert(pair<string,string>("OO-","O-"));
bmap.insert(pair<string,string>("O+","O+"));
bmap.insert(pair<string,string>("O-","O-"));
bmap.insert(pair<string,string>("A+","A+"));
bmap.insert(pair<string,string>("A-","A-"));
bmap.insert(pair<string,string>("B+","B+"));
bmap.insert(pair<string,string>("B-","B-"));
scanf("%s%s%s",&str,&str2,&str3);
char orz;


while(str[0]!='E'){
    if(strlen(str)==2&&str[0]!='?'&&str[0]!='O'){
        orz=str[1];
        str[1]='O';
        str[2]=orz;
        str[3]=0;
    }
    if(strlen(str2)==2&&str2[0]!='?'&&str2[0]!='O'){
        orz=str2[1];
        str2[1]='O';
        str2[2]=orz;
        str3[3]=0;
    }
    printf("Case %d: ",++tt);
    if(str3[0]=='?'){
        ans.clear();
        cout<<(bmap.find(str)->second)<<" "<<(bmap.find(str2)->second)<<" ";
        child();
        if(ans.size()>1)
            printf("{");
        cout<<ans[0];
        LOOPB(i,1,ans.size())
            cout<<", "<<ans[i];
        if(ans.size()>1)
            printf("}");
        printf("\n");
    }else{
        bool flag=true;
        if(str[0]=='?'){
            strcpy(strtmp,str2);
            str2[0]='?';
            str2[1]=0;
            strcpy(str,strtmp);
            flag=false;
        }
        ans2.clear();
        parent();
        if(flag){
            cout<<bmap.find(str)->second<<' ';
            if(ans2.size()){
            if(ans2.size()>1)
                printf("{");
            cout<<bmap.find(ans2[0])->second;
            LOOPB(i,1,ans2.size())
                cout<<", "<<(bmap.find(ans2[i])->second);
            if(ans2.size()>1)
                printf("}");
            }else{
            cout<<"IMPOSSIBLE";
            }
            cout<<' '<<bmap.find(str3)->second<<endl;
        }else{
            if(ans2.size()){
            if(ans2.size()>1)
                printf("{");
            cout<<bmap.find(ans2[0])->second;
            LOOPB(i,1,ans2.size())
                cout<<", "<<(bmap.find(ans2[i])->second);
            if(ans2.size()>1)
                printf("}");
            }else{
            cout<<"IMPOSSIBLE";
            }
            cout<<' '<<bmap.find(str)->second<<' '<<bmap.find(str3)->second<<endl;
        }
    }
    scanf("%s%s%s",&str,&str2,&str3);
}
return 0;
}
