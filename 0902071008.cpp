#include<stdio.h>
#include<string.h>
#include<limits.h>
#define INF 1<<30
#define QLEN 3000000
#define fxx(x) ((x)>0?1:-1)
#define min(a,b) ((a)>(b)?(b):(a))
int fx[8][2]={1,0,-1,0,0,1,0,-1,0,0,0,0,0,0,0,0};
bool flag,flag2;
int ga[22][22],step,k,top,t,bot,adis,n,m,btotal,b,xxxx,i,j,l,sx,sy,ex,ey,best[22][22][400],bestb[22][22];
//到达某处穿越某次漩涡后最小,到达某处越漩涡最少
int bestreach[400],mincy;//到达目的地穿越次数最少，最少穿越次数
struct sail{int x,y,b,d,e;} qu[QLEN],now,tmp; //坐标,b剩余,穿越漩涡次数，移动次数

int bfs(){
flag2=false;
top=bot=0;l=1;
qu[top].x=sx;
qu[top].y=sy;
qu[top].b=btotal;
qu[top].d=0;
qu[top].e=0;
while(l>0){
now=qu[top];
top=(top+1)%QLEN;
l--;
for(i=0;i<=7;i++){
    flag=true;
    tmp.x=now.x+fx[i][0];
    tmp.y=now.y+fx[i][1];
    //printf("trying %d:%d(from %d:%d) b:%d step:%d i:%d\n",tmp.x,tmp.y,now.x,now.y,tmp.b,tmp.e,i);
    if(tmp.x>n||tmp.y>m||tmp.x<=0||tmp.y<=0)continue;
    tmp.d=now.d;
    tmp.b=now.b;
    tmp.e=now.e+1;
    step=fxx(fx[i][0]);
    for(j=now.x;j!=tmp.x+step;j+=step){
        if(ga[j][tmp.y]=='#'){flag=false;break;}
        else if(ga[j][tmp.y]=='*'){tmp.d++;tmp.b-=b;if(tmp.b<0||i>=4){flag=false;break;}}
        }
    //if(flag)printf("%d:%d x check passed\n",tmp.x,tmp.y,best[tmp.x][tmp.y][tmp.d]);
    if(flag){
    step=fxx(fx[i][1]);
    for(j=now.y;j!=tmp.y+step;j+=step){
        if(ga[tmp.x][j]=='#'){flag=false;break;}
        else if(ga[tmp.x][j]=='*'){tmp.d++;tmp.b-=b;if(tmp.b<0||i>=4){flag=false;break;}}
        }
    }
    //if(flag)printf("%d:%d y check passed\n",tmp.x,tmp.y,best[tmp.x][tmp.y][tmp.d]);
    if(flag){
        if(tmp.e>best[tmp.x][tmp.y][tmp.d])flag=false;
        //else if(tmp.e==best[tmp.x][tmp.y][tmp.d]&&tmp.b<bestb[tmp.x][tmp.y])flag=false;
        if(tmp.d>mincy)flag=false;
        if(tmp.d>bestb[tmp.x][tmp.y])flag=false;
}
    //if(flag)printf("%d:%d best check passed\n",tmp.x,tmp.y,best[tmp.x][tmp.y][tmp.d]);
    if(flag){
        if(tmp.x==ex&&tmp.y==ey){bestreach[tmp.d]=min(tmp.e,bestreach[tmp.d]);flag2=true;
        /*printf("!!!!reached %d\n",tmp.e);*/
        mincy=min(mincy,tmp.d);
        }else{
        bot=(bot+1)%QLEN;
        l++;
        qu[bot]=tmp;
        best[tmp.x][tmp.y][tmp.d]=tmp.e;
        bestb[tmp.x][tmp.y]=tmp.d;
        //printf("%d:%d,%d\n",tmp.x,tmp.y,best[tmp.x][tmp.y][tmp.d]);
        }
    }
    }
}
return flag2?0:-1;
}


int main(){
    freopen("in.txt","r",stdin);
freopen("out","w",stdout);
scanf("%d",&xxxx);
for(i=0;i<22;i++)
    ga[0][i]=ga[i][0]='#';
while(xxxx--){
mincy=INF;
    scanf("%d%d\n",&n,&m);
for(i=0;i<n;i++)
    ga[i][m+1]='#';
for(i=0;i<n;i++)
    ga[n+1][i]='#';
t=n*m;
for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
        scanf("%c",&ga[i][j]);

        bestb[i][j]=INF;
        for(k=0;k<=t;k++)
            {best[i][j][k]=INF;}
        if(ga[i][j]=='S'){sx=i;sy=j;ga[i][j]=' ';}
        else if(ga[i][j]=='E'){ex=i;ey=j;ga[i][j]=' ';}
        }
     for(k=0;k<=t;k++)
        bestreach[k]=INF;
scanf("\n");
}
scanf("%d%d%d",&adis,&btotal,&b);
//printf("a now case:adis %d btotal %d beach %d\n",adis,btotal,b);
fx[5][0]=fx[4][1]=adis;
fx[6][0]=fx[7][1]=-adis;
t=bfs();
if(t==-1)printf("can not reach!\n");
else{
i=0;
while(bestreach[i]==INF)i++;
printf("%d\n", bestreach[i]);
}
//printf("%d %d:%d %d\n",sx,sy,ex,ey);
}
}
