program rqnoj_156;
var
j,i,k,m,n,r:longint;
s:array[1..10000] of longint;
function search(lx,rx,num:longint):longint;
var
mid:longint;
begin
if lx=rx then exit(lx);
mid:=(lx+rx) shr 1;
if num<=s[mid] then exit(search(lx,mid,num))
else exit(search(mid+1,rx,num));
end;

begin
assign(input,'f:\in.txt');
reset(input);

read(n);
read(s[1]);
m:=1;
r:=1;
for i:=1 to n do
begin
read(j);
if j>s[r] then
begin
inc(r);
s[r]:=j;
end
else
begin
s[search(1,r,j)]:=j;
end;
end;
write(r);
end.