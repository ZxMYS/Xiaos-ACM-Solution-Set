#include<stdio.h>
#include<string.h>
bool ga[10][10];
int i,j,k,top,bot,tx,ty;
const int jump[8][2]={1,2,2,1,-1,2,-2,1,-2,-1,-1,-2,1,-2,2,-1};
char tmp;
struct zb{int x,y,step;}qu[30000],tar,now;
int main(){
freopen("knight.in","r",stdin);
freopen("out.txt","w",stdout);
  while(scanf("%c",&tmp)!=EOF){
  memset(ga,0,sizeof(ga));
  scanf("%d ",&i);
  top=1;
  bot=1;
  qu[1].x=int(tmp)-int('a')+1;
  qu[1].y=i;
  qu[1].step=0;
  ga[qu[1].x][qu[1].y]=true;
  scanf("%c",&tmp);
  scanf("%d\n",&i);
  tar.x=int(tmp)-int('a')+1;
  tar.y=i;
  while(top<=bot){
       now=qu[top++];
       if(now.x==tar.x&&now.y==tar.y){
                                      printf("To get from %c%d to %c%d takes %d knight moves.\n",(char)(qu[1].x-1+(int)'a'),qu[1].y,(char)(tar.x-1+(int)'a'),tar.y,now.step);
                                      break;
                                      }  
       for(i=0;i<8;i++){
                        tx=now.x+jump[i][0];
                        ty=now.y+jump[i][1];
                        if(tx>=1&&tx<=8&&ty>=1&&ty<=8)
                        if(!ga[tx][ty]){
                                        qu[++bot].x=tx;
                                        qu[bot].y=ty;
                                        qu[bot].step=now.step+1;
                                        ga[qu[bot].x][qu[bot].y]=true;
                                        }
                        }          
  }
  
  }
}
