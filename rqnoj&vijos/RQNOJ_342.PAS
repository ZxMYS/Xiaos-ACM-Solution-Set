program rqnoj_342;
const
dir:array[1..4,1..2] of longint=((-1,0),(0,1),(1,0),(0,-1));
var
f:array[0..1,1..100,1..100,1..4] of longint;
ga:array[0..101,0..101] of boolean;
order:array[1..1000] of 1..4;
ch:char;
i,j,z,a,b,c,n,m,x,y,x0,y0,d,dx,dy,dd:longint;
function min(x,y:longint):longint;
begin
if x>y then exit(y) else exit(x);;
end;
begin
assign(input,'f:\in.txt');
reset(input);

read(n,m,x0,y0);
for i:=1 to n do
begin
	for j:=1 to n do
        begin
        	read(ch);
                if ch='.' then
        	ga[i,j]:=true;
                for d:=1 to 4 do
                begin
                f[0,i,j,d]:=maxint;
                end;
        end;
readln;
end;
f[0,x0,y0,1]:=0;
for i:=1 to m do
        begin
        read(ch);
        case ch of
        'F':begin order[i]:=1; end;
        'L':begin order[i]:=4; end;
        'R':begin order[i]:=2; end;
        'B':begin order[i]:=3; end;
        end;
        readln;
        end;
b:=0;
for i:=1 to m do
begin
a:=b;
b:=i mod 2;
                for x:=1 to n do
                for y:=1 to n do
                for d:=1 to 4 do
                begin
                f[b,x,y,d]:=maxint;
                end;
//writeln(order[i]);
for x:=1 to n do
for y:=1 to n do
begin
if not(ga[x,y]) then continue;
for d:=1 to 4 do
begin
if f[a,x,y,d]=maxint then continue;
//writeln(i,' ',order[i],' ',x,' ',y,' ',d,' ',f[a,x,y,d]);
dx:=x;dy:=y;dd:=d;
case order[i] of
1:begin dx:=x+dir[d,1];dy:=y+dir[d,2]; end;
2:begin dd:=(d) mod 4 + 1; end;
3:begin dx:=x-dir[d,1];dy:=y-dir[d,2]; end;
4:begin dd:=(d+2) mod 4 + 1; end;
end;
f[b,x,y,d]:=min(f[b,x,y,d],f[a,x,y,d]+1);
if ga[dx,dy] then
begin
f[b,dx,dy,dd]:=min(f[b,dx,dy,dd],f[a,x,y,d]);
//writeln(i,' ',order[i],' ',dx,' ',dy,' ',dd,' ',f[b,dx,dy,dd],' ',f[b,x,y,d]);
end;
//writeln('*********************');
end;
end;
end;
z:=maxint;
for x:=1 to n do
for y:=1 to n do
begin
if not(ga[x,y]) then continue;
for d:=1 to 4 do
z:=min(z,f[b,x,y,d]);
end;
        write(z);
end.
