#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,mm,i,j,k,a,b,need[101],top,use[51];
struct aa{int number, needed,id;bool f;} an[51],now;
bool box[51][101],needb[101];

int cmp(aa a,aa b){
    if((a).needed!=(b).needed)
        return (a).needed-(b).needed;
    else
        return (a).number-(b).number;
}

int main(){
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
scanf("%d%d",&k,&n);
for(i=0;i<n;i++){
for(j=0;j<k;j++)
    box[i][k]=false;
an[i].f=false;
}

for(i=0;i<n;i++){
    scanf("%d",&a);
    for(j=0;j<a;j++){
    scanf("%d",&b);
    box[i][b]=true;
    }
    an[i].number=a;
    an[i].needed=0;
    an[i].id=i;
}
scanf("%d",&m);
for(i=0;i<m;i++){
    scanf("%d",&need[i]);
    needb[need[i]]=true;
    for(j=0;j<n;j++)
        if(box[j][need[i]]){an[j].needed++;an[j].f=true;}
    }
mm=m;
if(mm==0){printf("0\n");exit(0);}
//for(i=0;i<n;i++)
//    printf("%d %d %d\n",an[i].id,an[i].needed,an[i].number);

//printf("%d",.id);
top=0;
int max;
while(mm!=0){
if(top/mm>200)break;
max=0;
while(!an[max].f&&max<n)max++;
if(max==n)break;
for(i=0;i<n;i++)
    if(cmp(an[max],an[i])<0&&an[i].f)max=i;
if(!an[max].f)break;
now=an[max];
//printf("!!!%d\n",now.id);
use[top++]=now.id;
if(now.needed==0)break;
//for(i=0;i<n;i++)
//    printf("%d %d %d\n",an[i].id,an[i].needed,an[i].number);
an[now.id].number=0;
for(i=0;i<m;i++)
    if(box[now.id][need[i]]){
//    printf("box[%d][%d]\n",now.id,need[i]);
        mm--;
        for(j=0;j<n;j++){
            if(box[j][need[i]]){
//                printf("--box[%d][%d] %d\n",j,need[i],an[j].id);
                box[j][need[i]]=false;
                an[j].needed--;}
        }
    }
//for(i=0;i<n;i++)
//    printf("%d %d %d\n",an[i].id,an[i].needed,an[i].number);

}
sort(use,use+top);
printf("%d\n",top);
for(i=0;i<top-1;i++)
    printf("%d ",use[i]+1);
printf("%d\n",use[top-1]+1);
}
