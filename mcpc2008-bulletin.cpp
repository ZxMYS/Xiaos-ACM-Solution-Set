#include<stdio.h>
#include<algorithm>
using namespace std;

//本质上就是枚举各个坐标能分割出的各个矩形，然后再逐一检查。
int n,x[202],nx,ny,y[202],xl[101],yl[101],xh[101],yh[101];
int uniqueSeq(int a[]) {
    sort(a,a+2*n+2);
    int inSeq=0;
    for (int next=1;next<2*n+2;next++)
    if (a[inSeq]!=a[next]) {
        inSeq++;
        a[inSeq]=a[next];
    }
    return inSeq+1;
}

int main(){
    freopen("bulletin.in","r",stdin);
    freopen("out","w",stdout);
    scanf("%d",&n);
    while(n>0){
        scanf("%d",&x[2*n+1]);
        scanf("%d",&y[2*n+1]);
        x[2*n]=y[2*n]=0;
        for (int i=0;i<n;i++){
            scanf("%d",&x[i]);
            xl[i]=x[i];
            scanf("%d",&y[i]);
            yl[i]=y[i];
            scanf("%d",&x[i+n]);
            xh[i]=x[i+n];
            scanf("%d",&y[i+n]);
            yh[i]=y[i+n];
        }
        nx=uniqueSeq(x);
        ny=uniqueSeq(y);
        int clearArea = 0;
        int maxDepth = 0;
        int maxDepthArea = 0;
        for (int i=1;i<nx;i++)
        for (int j=1;j<ny;j++){
            int depth=0;
            for (int k=0;k<n;k++)
            if(xl[k]<=x[i-1]&&x[i]<=xh[k]&&yl[k]<=y[j-1]&&y[j]<=yh[k])
                depth++;
            int area=(x[i]-x[i-1])*(y[j]-y[j-1]);
            if(depth==0)
            clearArea+=area;
            else if(depth==maxDepth)
            maxDepthArea+=area;
            else if(depth>maxDepth){
            maxDepthArea=area;
            maxDepth=depth;
            }
        }
        printf("%d %d %d\n",clearArea,maxDepth,maxDepthArea);
        scanf("%d",&n);
    }
    return 0;
}
