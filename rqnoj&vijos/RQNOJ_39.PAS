program rqnoj_39;
var
f:array[0..35000] of longint;
m,v,n,i,j,k:longint;
c:array[1..21] of longint;
function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;

begin
assign(input,'f:\in.txt');
reset(input);
fillchar(f,sizeof(f),0);
fillchar(c,sizeof(c),0);
read(v,n);
for i:=1 to n do
        read(c[i]);


for i:=1 to n do
for j:=v downto c[i] do
        f[j]:=max(f[j],f[j-c[i]]+c[i]);

write(f[v],' ');

end.
