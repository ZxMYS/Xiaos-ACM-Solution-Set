program rqnoj_249;
var
ga,g2:array[0..101,0..101] of boolean;
n,m,a,b,j,i,t:longint;
c:char;
function check(x,y:longint):longint;
var
zz,zy,zx:longint;
begin
zx:=0;
for zz:=-1 to 1 do
for zy:=-1 to 1 do
if not((zz=0)and(zy=0)) then
if ga[x+zz,y+zy] then inc(zx);
check:=zx;
end;
begin
fillchar(ga,sizeof(ga),0);
readln(m,n,t);
for i:= 1 to n do
begin
        for j:= 1 to m do
        begin
        read(c);
        if c='1' then ga[i,j]:=true;
        end;
readln;
end;

g2:=ga;
for a:= 1 to t-1 do
begin
        for i:= 1 to n do
                for j:= 1 to m do
                begin
                  b:=check(i,j);
                  if (ga[i,j]) and (b<2) then g2[i,j]:=false;
                  if (ga[i,j]) and (b>3) then g2[i,j]:=false;
                  if not(ga[i,j]) and (b=3) then g2[i,j]:=true;
                end;
ga:=g2;
end;
for i:= 1 to n do
begin
for j:= 1 to m do
if ga[i,j] then write(1) else write(0);
writeln;
end;
end.
