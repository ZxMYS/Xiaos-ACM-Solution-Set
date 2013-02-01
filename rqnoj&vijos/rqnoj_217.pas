program rqnoj_217;
var
j,i,k,m,n,min,maxn,r:longint;
a,s:array[1..10000] of longint;
function max(i,j:longint):longint;
begin
if i>j then exit(i) else exit(j);
end;
begin
assign(input,'f:\in.txt');
reset(input);

read(n);
for i:=1 to n do
begin
read(s[i]);
end;
a[1]:=1;
for i:=1 to n do
begin
maxn:=1;
for j:=1 to i-1 do
   if (s[j]>=s[i]) then maxn:=max(maxn,a[j]+1);
   a[i]:=maxn;
end;
maxn:=1;
for i:=1 to n do
        maxn:=max(maxn,a[i]);
write(maxn,' ');
a[1]:=s[1];
k:=1;
for i:=2 to n do
begin
min:=maxint;
for j:=1 to k do
begin
if (min>a[j])and(a[j]>=s[i]) then
        begin min:=a[j];r:=j; end;
end;
if min=maxint then begin
        inc(k);
        a[k]:=s[i];
        end
        else
        begin
        a[r]:=s[i];
        end;
end;
write(k);
end.
