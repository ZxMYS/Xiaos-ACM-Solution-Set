program rqnoj_384;
var
f:array[1..1000,1..1000] of longint;
ga:array[1..1000,1..1000] of longint;
w,i,j,k,ans,o,m,n:longint;
buf:array[1..4096] of byte;
function min(x,y:longint):longint;
begin
if x>y then exit(y) else exit(x);
end;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
fillchar(f,sizeof(f),1);
read(n,m,k,w);
for i:=1 to m do
        for j:=1 to n do
                read(ga[i,j]);

for j:=1 to m do
        f[1,j]:=ga[j,1];
for i:=2 to n do
        for j:=1 to m do
        begin
                f[i,j]:=f[i-1,j]+ga[j,i];
        for o:=1 to m do
                f[i,j]:=min(f[i-1,o]+ga[j,i]+w,f[i,j]);
        end;
ans:=maxint;
for i:=1 to m do
begin
        ans:=min(ans,f[n,i]);
end;
writeln(ans);
end.
