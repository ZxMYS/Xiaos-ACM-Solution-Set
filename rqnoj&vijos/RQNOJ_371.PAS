program rqnoj_371;
var
f:array[1..15,1..15,1..15,0..1] of longint;
n,m,k,p,i,j:longint;
begin
read(n,m);
for i:=1 to n do
        for j:=1 to n do
                begin
                f[i,j,1,0]:=1;
                f[i,j,1,1]:=1;
                end;
for k:=1 to m do
        for i:=1 to n do
        for j:=1 to n do
        begin
        for p:=1 to j-1 do
        inc(f[i,j,k,1],f[i,j-p,k-1,0]);
        for p:=1 to i-1 do
        inc(f[i,j,k,0],f[i-p,j,k-1,1]);
        end;
write(f[n,n,m,0]+f[n,n,m,1]);
end.