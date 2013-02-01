#include<stdio.h>
char s[513][513];
char str[512];
int n,i,j;
char c;
char c1,c2;
int dfs(int x,int y,int z,int w)
{
	int i,j;
	char ch;
	ch=s[x][y];
	for (i=x;i<=z;i++)
	{
		for (j=y;j<=w;j++)
			if (s[i][j]!=ch)
				break;
		if (j==w+1) continue;
		if (s[i][j]!=ch) break;
	}
	if (i>z) printf("%c",ch);
	else
	{
		printf("Q");
		dfs(x,y,(x+z-1)/2,(y+w-1)/2);
		dfs(x,(y+w+1)/2,(x+z-1)/2,w);
		dfs((x+z+1)/2,y,z,(y+w-1)/2);
		dfs((x+z+1)/2,(y+w+1)/2,z,w);
	}
	return 0;
}
int convert(char ch,int x,int y)
{
	int i;
	int t;
	if ('0'<=ch && ch<='9') t=ch-'0';
	if ('a'<=ch && ch<='f') t=ch-'a'+10;
	for (i=0;i<=3;i++)
	{
		if (t%2==1) s[x][y+i]='B';
		else s[x][y+i]='W';
		t=t/2;
	}
	return 0;
}
int main()
{
	scanf("%s%s",&str,&str);
	scanf("%d",&n);
	printf("%d\n",n);
	for (i=1;i<=8;i++)
		scanf("%s",&str);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n/8;j++)
		{
			scanf("%c%c",&c,&c);
			if (c=='0' || c==10)
				scanf("%c",&c);
			scanf("%c%c",&c1,&c2);
			convert(c2,i,(j-1)*8+1);
			convert(c1,i,(j-1)*8+5);
		}
		if (scanf("%c",&c)==-1) break;
	}
	dfs(1,1,n,n);
	return 0;
}
