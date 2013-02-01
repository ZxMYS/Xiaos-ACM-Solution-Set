int RabinMillerKnl(unsigned long n)
{
unsigned long b, m, j, v, i, k=10;
//先计算出m、j，使得n-1=m*2^j，其中m是正奇数，j是非负整数
while(k--){
m=n - 1;
j=0;
while(!(m & 1))
{
++j;
m>>=1;
}
//随机取一个b，2<=b<n-1
b=random(2,m);
//计算v=b^m mod n
v=PowMod(b, m, n);
//如果v==1，通过测试
if(v == 1)
{
return 1;
}

i=1;
//如果v=n-1，通过测试
while(v != n - 1)
{
//如果i==l，非素数，结束
if(i == j)
{
return 0;
}
//v=v^2 mod n，i=i+1
v=PowMod(v, 2, n);
i++;
}
}
return 1;
}
