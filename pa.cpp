#include<stdio.h>
#include<memory.h>
char str[20];
int a[20];
bool b[20];
int s[20];
bool first[20];
int i,n,top,j,max,t,last,min,q;
int swap(int& x,int& y)
{
	int t;
	t=x;
	x=y;
	y=t;
	return 0;
}
int go(int x)
{
	int i;
	if (x==0)
		return x;
	if (first[x] && a[x]>0 && x<last)
	{
		for (i=1;i<=top;i++)
		{
			if (s[i]==a[x]-1) break;
			if (s[i]==a[x])
			{
				s[i]--;
				break;
			}
		}
		a[x]--;
		return x;
	}
	if (a[x]<=min) return(go(x-1));
	for (i=top;i>=1;i--)
		if (s[i]<a[x])
			break;
	a[x]=s[i];
	return x;
}
int main()
{
	FILE *fi;
	fi=fopen("a.in","r");
	while (fgets(str,20,fi))
	{
	    //char fk[200]="000010\0";

	    while(str[0]=='0'&&str[1]){q=0;//printf("0 %c 1 %c\n",fk[0],fk[1]);
            while(str[q]){str[q]=str[q+1];q++;}}
        //printf("~,%s",fk);
		memset(first,0,sizeof(first));
		memset(b,0,sizeof(b));
		for (i=0;i<=19;i++)
		{
			if (str[i]==10 || str[i]==str[14]) break;
			a[i+1]=str[i]-'0';
			b[a[i+1]]=1;
		}
		n=i;
		top=0;
		for (i=1;i<=n;i++)
			if (b[a[i]])
			{
				top++;
				s[top]=a[i];
				b[a[i]]=0;
				first[i]=1;
			}
		if (top==1)
		{
			printf("0\n");
			continue;
		}
		for (i=1;i<top;i++)
			for (j=i+1;j<=top;j++)
				if (s[i]>s[j])
					swap(s[i],s[j]);
		if (top==2 && s[1]==0 && s[2]==1)
		{
			for (i=1;i<n;i++)
				printf("9");
			printf("\n");
			continue;
		}
		for (last=n;last>=1;last--)
			if (first[last]) break;
		for (i=1;i<=top;i++)
			if (a[last]==s[i])
				break;
		for (j=i;j<top;j++)
			s[j]=s[j+1];
		min=s[1];
		top--;
		t=go(last);
		max=s[1];
		for (i=2;i<=top;i++)
			if (max<s[i]) max=s[i];
		for (i=t+1;i<=n;i++)
			a[i]=max;
		for (i=1;i<=n;i++)
			printf("%d",a[i]);
		printf("\n");
	}
	fclose(fi);
	return 0;
}
