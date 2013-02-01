program rqnoj_261;
var
t:array[0..5000,0..5000] of longint;
p:array[1..10000] of boolean;
i,j,k,m,n,h:longint;

function d(m,n,i:longint):longint;
var
s,temp:longint;
begin
s:=0;
temp:=m+1-n;
while temp mod i= 0 do
begin
s:=s+1;
temp:=temp div i;
end;
temp:=(m+n) div i;
while temp>0 do
begin
s:=s+temp;
temp:=temp div i;
end;
temp:=(m+1) div i;
while temp>0 do
begin
s:=s-temp;
temp:=temp div i;
end;
temp:=n div i;
while temp>0 do
begin
s:=s-temp;
temp:=temp div i;
end;
d:=s;
end;

begin
assign(input,'f:\in.txt');
reset(input);

read(m,n);
if m<n then begin write(0);halt; end;
for i:=1 to m do
a[i,0]:=1;
for i:=1 to m do
for j:=1 to i do
        a[i,j]:=a[i-1,j]+a[i,j-1];
write(a[m,n]);
end.