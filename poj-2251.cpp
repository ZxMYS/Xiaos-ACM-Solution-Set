#include<stdio.h>
#define qlen 3000000
struct que{int x,y,z,t;}q[qlen],qt,qt2;
int top,bot,len,sx,sy,sz,ex,ey,ez,l,r,c,x,y,z,i;//l:z.r:x.c:y.
const int st[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
bool ga[32][32][32],ga2[32][32][32];
char tmp;

int main(){
freopen("dungeon.in","r",stdin);
freopen("out","w",stdout);
while(1){
         scanf("%d%d%d\n",&l,&r,&c);
         if(l==0)break;
         for(z=1;z<=l;z++){
         for(x=1;x<=r;x++){ga[x][0][z]=false;ga[x][c+1][z]=false;}
         for(y=1;y<=c;y++){ga[0][y][z]=false;ga[r+1][y][z]=false;}
                              }
         for(x=1;x<=r;x++)
         for(y=1;y<=c;y++){ga[x][y][0]=false;ga[x][y][z]=false;
                              }
         for(z=1;z<=l;z++){
         for(x=1;x<=r;x++){
         for(y=1;y<=c;y++){
                 scanf("%c",&tmp);
                 ga2[x][y][z]=false;
                 if(tmp=='#') ga[x][y][z]=false;
                 if(tmp=='.') ga[x][y][z]=true;
                 if(tmp=='S') {ga[x][y][z]=true;sx=x;sy=y;sz=z;}
                 if(tmp=='E') {ga[x][y][z]=true;ex=x;ey=y;ez=z;}
                 }
                 scanf("\n");
                 }
                 scanf("\n");
                 }
         top=bot=0;len=1;
         q[0].x=sx;q[0].y=sy;q[0].z=sz;q[0].t=0;
         ga[sz][sy][sz]=true;
         while(len>0){
                    qt=q[top];
                    top=(top+1)%qlen;
                    len--;
                    qt2.t=qt.t+1;
                    //printf("%d %d %d %d\n",qt.x,qt.y,qt.z,len);
                    for(i=0;i<=5;i++){
                                      qt2.x=qt.x+st[i][0];
                                      qt2.y=qt.y+st[i][1];
                                      qt2.z=qt.z+st[i][2];
                                      if(qt2.x==ex&&qt2.y==ey&&qt2.z==ez)goto L1;
                                      //printf("!!%d %d %d %d\n",qt2.x,qt2.y,qt2.z,i);
                                      if(ga[qt2.x][qt2.y][qt2.z]&&(!ga2[qt2.x][qt2.y][qt2.z]))
                                      {
                                      //printf("~~%d %d %d %d\n",qt2.x,qt2.y,qt2.z,len);
                                      bot=(bot+1)%qlen;
                                      len++;
                                      q[bot]=qt2;
                                      ga2[qt2.x][qt2.y][qt2.z]=true;
                                      }                                                     
                    }
                    }
         printf("Trapped!\n");
         continue;
         L1:
         printf("Escaped in %d minute(s).\n",qt2.t);
}
}
