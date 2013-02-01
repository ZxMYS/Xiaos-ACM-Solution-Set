/*
 * Problem: NOI1997 wildcard
 * Author: Guo Jiabao
 * Time: 2009.2.15 20:17
 * State: Solved
 
 这是NOI1997中最难的一道题，我在这道题上花费了一天时间才通过了。基本框架就是搜索，搜索出匹配串，对所有文件名按照规则匹配，判断是否可行，算出匹配的数目，更新最优值。

暴力的搜索连样例都过不了，我们需要深入分析，进行优化和剪枝。我的搜索顺序是从匹配串的第一位到最后一位(所有文件名长度最大值)。我们定义正文件为标记’+'的文件，负文件为标记’-'的文件。

优化1.记录下所有用过的字符，顺序存入线性表，以备搜索时使用。

优化2.去除多余的状态，例如多个*在一起是浪费的，*?和?*是一样的(但是和*不一样)，在产生状态时应避免出现。

优化3.关于判断文件名是否匹配，在搜索出一位时，不需要把整个串与文件名匹配，如果前面都是匹配的，只需判断最后一位是否成立，我们需要记录每个文件名已经前缀匹配到了哪一位。但是由于*的存在，使这个判断复杂性大大增加。例如当前的匹配串A*A对A1A2A前缀匹配，A*A可以匹配到第3位(A1A)，也可以匹配到第5位(A1A2A)。而且由于后面扩展出的状态未知，我们也无法知道究竟匹配到哪一位是合适的，所以必须都记录下。即对每个文件名开辟一个数组空间，存储该文件名可能匹配到的所有位置。在状态的扩展中，也需要对所有的可能分别扩展。在最终判断时，一个文件名只要有一种可能使得完全匹配，就算是匹配成功。

优化4.在搜索完匹配串的每一位，计算完全匹配的数目时，需要判断是否还有必要搜索下一位。对于以下三种情况，

   1. 如果所有的正文件全部不能严格匹配，则再搜索下一位已经没有意义，剪枝；
   2. 如果前缀匹配的正文件的个数小于已有答案，再搜索下一位答案一定不会增加，剪枝；
   3. 如果匹配串末字符是*，当前答案小于最优答案，继续搜索一定是不会使答案增加，剪枝。

优化5.在搜索前先对所有的文件排序，使负文件名排在前面，有利于剪枝的提前发生。

上述5个优化，其中优化3是核心，也是算法的重要内容，大量编程的工作都是优化3；而优化4是关键，优化4的三个强力剪枝可以去除许多无用的状态，大大减少运行时间。

这道题虽然写了一天才搞定，收获却是非同一般得大。我个人认为这类题很好，很能考验构造思维能力和编程能力，甚至意志力，但近些年不论在 NOI还是NOIP，却都销声匿迹了。我预测如果今年NOI考这类题，仍然是个难题，能拿到高分的人不会多的。搜索+优化永远是一个万能算法，即使不为了竞赛，真正掌握它也是很困难，确是很重要的。
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN=251,MAXS=62;
const char CharSet[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
struct File{int name[10],len,matchpre[10],precnt;bool permission;};
int N,N_p,pattern[10],Apt[10],Max_Length,Ans,Nowlen,Al,ccnt;
File F[MAXN];
bool used[200];
int chas[62];
void dfs(int len);
inline int CharToID(char c)
{
	if (c>='0' && c<='9')return c-'0';
	return (c>='A' && c<='Z')?c-'A'+10:c-'a'+36;
}
inline int cmp(const void *a,const void *b)
{return ((File *)a)->permission==false?-1:1;}
void init()
{
	int i,k;
	char c,Name[10];
	freopen("wildcard.in","r",stdin);
	freopen("wildcard.out","w",stdout);
	c=getchar();
	while (c!=EOF)
	{
		ungetc(c,stdin);
		scanf("%s",Name);
		N++;
		for (i=0;Name[i];i++)
		{
			F[N].name[i+1]=k=CharToID(Name[i]);
			used[k]=true;
		}
		F[N].len=i;
		if (i>Max_Length)
			Max_Length=i;
		c=getchar();c=getchar();
		if (c=='+')
		{
			N_p++;
			F[N].permission=true;
		}
		else
			F[N].permission=false;
		F[N].precnt=1;
		c=getchar();c=getchar();
	}
	qsort(F+1,N,sizeof(F[0]),cmp);
	for (i=0;i<MAXS;i++)
		if (used[i])
			chas[++ccnt]=i;
}
bool update(int k)
{
	int i,j,Newans=0,Pans=0;
	bool np=false,tb;
	for (i=1;i<=N;i++)
	{
		tb=false;
		for (j=1;j<=F[i].precnt;j++)
			tb|=F[i].matchpre[j]==F[i].len || ( F[i].matchpre[j]>=0 && pattern[k]==-1 );
		if (tb)
		{
			if (F[i].permission )
				Newans++;
			else
				np=true; //匹配了负串
		}
		if (F[i].permission && F[i].precnt==0)
			Pans++; //记录正串不匹配的个数
	}
	if (Pans==N_p || (N_p-Pans<Ans)) //若正串全部不匹配 或者 前缀匹配串的个数小于已有答案 剪枝
		return false;
	if (pattern[k]==-1 && Newans<Ans) //如果匹配串末字符是*，当前答案小于最优，继续添加一定是多余的  剪枝
		return false;
	if (!np)
	{
		if (Newans>Ans)
		{
			Ans=Newans;
			for(i=1;i<=k;i++)
				Apt[i]=pattern[i];
			Al=k;
		}
		else if (Newans==Ans && k<Al)
		{
			for(i=1;i<=k;i++)
				Apt[i]=pattern[i];
			Al=k;
		}
	}
	return true;
}
void match(File &F,int len)
{
	bool newpre[10]={false};
	int k,i;
	if (pattern[len-1]!=-1)
	{
		for (k=1;k<=F.precnt;k++)
			if (F.matchpre[k]+1<=F.len && (pattern[len]==-2 || F.name[F.matchpre[k]+1]==pattern[len]))
				newpre[F.matchpre[k]+1]=true;
	}
	else
	{
		for (k=1;k<=F.precnt;k++)
			for (i=F.matchpre[k]+1;i<=F.len;i++)
				if (F.name[i]==pattern[len] || pattern[len]==-2)
					newpre[i]=true;
	}
	F.precnt=0;
	for (k=1;k<9;k++)
		if (newpre[k])
			F.matchpre[ ++F.precnt ]=k;
}
void goon(int len,int p)
{
	if (p==N+1)
	{
		if (update(len))
			dfs(len+1);
		return;
	}
	int i,tprecnt,tmatch[10];
	if (F[p].precnt==0)
		goon(len,p+1);
	else
	{
		/*backup*/
		for (i=1;i<=F[p].precnt;i++)
			tmatch[i]=F[p].matchpre[i];
		tprecnt=F[p].precnt;
		/*backup*/
		if (pattern[len-1]==-1)
		{
			match(F[p],len);
			goon(len,p+1);
		}
		else
		{
			if (pattern[len]!=-1)
				match(F[p],len);
			goon(len,p+1);
		}
		/*restore*/
		F[p].precnt=tprecnt;
		for (i=1;i<=F[p].precnt;i++)
			F[p].matchpre[i]=tmatch[i];
		/*restore*/
	}
}
void dfs(int len) //-1:* -2:?
{
	if (len>Max_Length)
		return;
	int i;
	if (pattern[len-1]!=-1)//**不连用 但允许?*
	{
		pattern[len]=-1;
		goon(len,1);
	}
	if (pattern[len-1]!=-1)//不允许*?
	{
		pattern[len]=-2;
		goon(len,1);
	}
	for (i=1;i<=ccnt;i++)
	{
		pattern[len]=chas[i];
		goon(len,1);
	}
}
void print()
{
	printf("%d\n",Ans);
	for (int i=1;i<=Al;i++)
		if (Apt[i]>=0)
			putchar(CharSet[Apt[i]]);
		else if (Apt[i]==-1)
			putchar('*');
		else
			putchar('?');
	putchar('\n');
}
int main()
{
	init();
	dfs(1);
	print();
	return 0;
}


