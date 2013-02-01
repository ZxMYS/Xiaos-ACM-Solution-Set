program VIJOS_1456;
type
g=array[1..16,1..16] of longint;
var
f:array[1..16,0..16] of qword;
g2:array[1..16,0..16] of g;
ga:g;
a,b,c,i,j,k,m,n:longint;
begin
assign(input,'f:\in.txt');
reset(input);

readln(n);
for i:=1 to n do
        for j:=1 to n do
        begin
                read(ga[i,j]);
        end;


for i:=1 to n do
begin
        f[i,0]:=0;
        g2[i,0]:=ga;
end;
for i:=1 to n do
        for j:=1 to n do
                f[i,j]:=maxlongint;

for i:=1 to n do
        for j:=1 to n-1 do
                for k:=1 to n do
                        begin
                                if g2[k,j-1][k,i]<>-1 then
                                if f[i,j]>f[k,j-1]+g2[k,j-1][k,i] then
                                begin
                                        f[i,j]:=f[k,j-1]+g2[k,j-1][k,i];
                                        g2[i,j]:=g2[k,j-1];
                                        g2[i,j][k,i]:=-1;
                                        g2[i,j][i,k]:=-1;
                                end;
                        end;
a:=maxlongint;
for i:=1 to n do
     if a>f[i,n-1] then a:=f[i,n-1];
write(a);
end.
