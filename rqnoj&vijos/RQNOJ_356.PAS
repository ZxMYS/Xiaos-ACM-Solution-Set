program rqnoj_356;
var
a,b,c,z,s,t,i,j,m,n,p:longint;
x,y:array[1..1000] of longint;
f:array[0..1000,0..1000] of longint;
buf:array[1..100000] of byte;
function min(x,y:longint):longint;
begin
if x>y then exit(y) else exit(x);
end;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
read(n,m,p);
for i:=1 to p do
        read(x[i],y[i]);
for i:=0 to m do
        for j:=0 to n do
                f[i,j]:=maxint;
for j:=1 to m do
        f[j,0]:=0;
for i:=1 to p do
        for j:=y[i]+1 to m do
                for z:=x[i] to n do
                begin
                        f[j,z]:=min(f[j,z],f[j-y[i],z-x[i]]+1);
                end;



if f[m,n]=32767 then writeln('mty zhen mei yong!') else writeln(f[m,n]);

end.


