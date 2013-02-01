program rqnoj_380;
type
hugenum=array[0..1000] of byte;
var
i,j,k,n,a:longint;
ans,i1,i2,i3:hugenum;

function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;

operator > (fa1,fa2:hugenum)r:boolean;
var
k,i:longint;
begin
k:=max(fa1[0],fa2[0]);
for i:=k downto 1 do
        if fa1[i]>fa2[i] then exit(true) else if fa1[i]<fa2[i] then exit(false);
exit(true);
end;


operator + (fa1,fa2:hugenum)r:hugenum;
var
k,i:longint;
begin
fillchar(r,sizeof(r),0);
k:=max(fa1[0],fa2[0]);
for i:=1 to k do
begin
        r[i]:=r[i]+fa1[i]+fa2[i];
        if r[i]>=10 then begin inc(r[i+1]);dec(r[i],10); end;
end;
if r[k+1]>0 then r[0]:=k+1 else r[0]:=k;
end;

operator - (fa1,fa2:hugenum)r:hugenum;
var
k,i:longint;
t:hugenum;
begin
fillchar(r,sizeof(r),0);
if fa2>fa1 then begin t:=fa1; fa1:=fa2; fa2:=t; end;
k:=max(fa1[0],fa2[0]);
for i:=1 to k do
begin
        r[i]:=r[i]+fa1[i]-fa2[i];
        if r[i]<0 then begin inc(r[i],10);dec(r[i+1]); end;
end;
i:=k;
while (r[i]=0)and(i>1) do dec(i);
r[0]:=i;
end;

operator * (fa1,fa2:hugenum)r:hugenum;
var
k,i,j:longint;
t,g:hugenum;
begin
fillchar(r,sizeof(r),0);
r[0]:=1;
for j:=1 to fa2[0] do
begin
for i:=1 to fa1[0] do
        r[j+i-1]:=r[j+i-1]+fa1[i]*fa2[j];
end;
for j:=1 to 1000 do
        if r[j]>=10 then begin inc(r[j+1],r[j] div 10);r[j]:=r[j] mod 10 end;
i:=1000;
while (r[i]=0)and(i>1) do dec(i);
r[0]:=i;
end;


{function add(fa1,fa2:hugenum):hugenum;
var
i,k:longint;
begin
if fa1[0]>fa2[0] then k:=fa1[0] else k:=fa2[0];
for i:=1 to k do
        fa1[i]:=fa1[i]+fa2[i];

for i:=1 to k do
begin
        if fa1[i] >= 10 then begin inc(fa1[i+1],fa1[i] div 10);fa1[i]:=fa1[i] mod 10; end;
end;
if fa1[k+1]>0 then fa1[0]:=k+1 else fa1[0]:=k;
exit(fa1);
end;

function m(n,a,b,c:longint):hugenum;
var i:hugenum;
begin
fillchar(i,sizeof(i),0);
i[0]:=1;
i[1]:=0;
if n=1 then
        if ((a=1)and(c=2)) or ((a=2)and(c=3)) or ((a=3) and (c=1)) then
        i:=add(i,i2)
        else
        i:=add(i,i1)
else
i:=add(add(m(n-1,a,c,b),m(1,a,b,c)),m(n-1,b,a,c));
exit(i);
end;

function m2(n,a,b,c:longint):hugenum;
var i:hugenum;
begin
fillchar(i,sizeof(i),0);
i[0]:=1;
i[1]:=0;
if n=1 then
        if ((a=1)and(c=2)) or ((a=2)and(c=3)) or ((a=3) and (c=1)) then
        i:=add(i,i1)
        else
        i:=add(i,i1)
else
i:=add(add(m2(n-1,a,c,b),m2(1,a,b,c)),m2(n-1,b,a,c));
exit(i);
end;  }

begin
fillchar(i1,sizeof(i1),0);
fillchar(i2,sizeof(i2),0);
ans[0]:=1;
ans[1]:=1;
i1[0]:=1;
i2[0]:=1;
i1[1]:=1;
i2[1]:=2;
i3:=i1;
read(n);
if n=0 then begin write(0);halt; end;
if n=1 then begin write(1);halt; end;
for i:=1 to n do
ans:=ans*i2;
ans:=ans-i3;
for i:=1 to (((n) div 2) *2-1) do
        if (i1[1] and 1)=0 then i1:=i1*i2+i3 else i1:=i1*i2;
ans:=ans+i1;
for i:= ans[0] downto 1  do
write(ans[i]);
writeln;
{for n:=1 to 100 do begin
writeln(n);
ans:=m(n,1,2,3);
for i:= ans[0] downto 1  do
write(ans[i]);
write(' ');
ans:=m2(n,1,2,3);
for i:= ans[0] downto 1  do
write(ans[i]);
writeln;
end;}
end.
