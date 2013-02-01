program rqnoj_286;
const
p:array[1..14] of longint=(1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192);
var
x,ans:array[1..15] of longint;
l,m,n,i,k,min,j:longint;
procedure s(l:longint);
var
i,j:longint;
begin
if l>=min then exit;
if x[l]=n then begin
if l<min then begin
min:=l;
for i:=1 to min do
ans[i]:=x[i];
end;
exit;
end;
if(x[l]*p[min-l]<n) then exit;

for i:= l downto 1 do
for j:= l downto i-1 do
        if (x[i]+x[j]<=n)and(x[i]+x[j]>x[l]) then
        begin
        x[l]:=x[i]+x[j];
        s(l+1);
        end;
end;

begin
min:=11;
for i:=1 to 15 do
begin
ans[i]:=1;
x[i]:=1;
end;
l:=1;
read(n);
s(1);
writeln(min);
end.

