#include <cstdio>
int n,i,l;
int a[1000];
int main() {
  freopen("h.in","r",stdin);
  freopen("h.out","w",stdout);
  while (scanf("%d",&n)!=EOF) {
    if (n==0) {
      printf("%d\n",1);
      continue;
    }
    if (n==1) {
      printf("%d\n",0);
      continue;
    }
    l=0;
    while (n>=2) {
      a[++l]=8;
      n-=2;
    }
    if (n==1) {
      a[++l]=4;
    }
    for (i=l; i>=1; --i) 
      printf("%d",a[i]);
    printf("\n");
  }
  return 0;
}
