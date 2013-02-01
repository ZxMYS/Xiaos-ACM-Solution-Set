program rqnoj_329;
type
letter=record
        t,h,w,v:longint;
        end;
group=record
        s,e:longint;
        end;
var
l:array[1..100] of letter;
f:array[0..100,0..100] of longint;
g:array[1..100] of group;
i,j,k,m,n,t,a,b:longint;

function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;

procedure qsort(lx,rx:longint);
var
i,j,t:longint;
x:letter;
begin
i:=lx;j:=rx;t:=l[(i+j) shr 1].v;
repeat
        while (l[i].v<t)and(i<rx)do
                inc(i);
        while (l[j].v>t)and(j>lx)do
                dec(j);
        if i<=j then
        begin
                x:=l[i];
                l[i]:=l[j];
                l[j]:=x;
                inc(i);dec(j);
        end
until i>=j;
if i<rx then qsort(i,rx);
if j>lx then qsort(lx,j);
end;

begin
assign(input,'f:\in.txt');
reset(input);

read(n,m,t);
dec(m);
for i:=1 to n do
        read(l[i].v,l[i].t,l[i].h,l[i].w);
qsort(1,n);
k:=0;
i:=0;
repeat
inc(k);
inc(i);
g[k].s:=i;
while (l[i].v=l[g[k].s].v)and(i<=n) do
inc(i);
dec(i);
g[k].e:=i;
until g[k].e=n;

for j:=1 to k do
for a:=m downto 0 do
for b:=t downto 0 do
for i:=g[j].s to g[j].e do
    if (a>=l[i].h)and(b>=l[i].t) then f[a,b]:=max(f[a,b],f[a-l[i].h,b-l[i].t]+l[i].w);
write(f[m,t]);
end.
