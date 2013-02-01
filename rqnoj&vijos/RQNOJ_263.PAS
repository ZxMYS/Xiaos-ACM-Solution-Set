program rqnoj_263(input,output);
var
ga:array[1..500,1..500] of longint;
b,c,i,j,m,n,k,x,y:longint;
a:array[1..500] of longint;
used:array[1..500] of boolean;
f:boolean;
ch:char;
f1:text;

procedure dijkstra();
begin
fillchar(used,sizeof(used),0);
for i:=2 to n do
begin
        a[i]:=ga[1,i];
end;
used[1]:=true;
for k:=1 to n-2 do
begin
   x:=maxint;y:=1;
   for j:=2 to n do
       if not(used[j]) and (a[j]<x) then
        begin
        y:=j;
        x:=a[j];
        end;
   if y<>1 then used[y]:=true else exit;
   for j:=1 to n do
        if(not(used[j]))and(a[y]+ga[y,j]<a[j]) then
                a[j]:=a[y]+ga[y,j];
end;
end;

begin
assign(f1,'f:\in.txt');
reset(f1);

readln(f1,m,n);
for i:=1 to 500 do
for j:=1 to 500 do
        ga[i,j]:=maxint;

for i:=1 to m do
begin
m:=0;
f:=false;
repeat
        read(f1,b);
        inc(m);
        a[m]:=b;
        if not eof(f1) then read(f1,ch);
        if (ch=chr(13))or(ch=chr(10))or(eof(f1)) then
        begin
        for x:=1 to m do
        for y:=x to m do
                ga[a[x],a[y]]:=1;
        f:=true;
        end;
until f;
end;

{for i:=1 to n do
begin
for j:=1 to n do
        if ga[i,j]<>maxint then write(ga[i,j],' ') else write(0,' ');
writeln;
end; }

fillchar(a,sizeof(a),0);
if (ga[1,n]=1)or(n=1) then
begin
write(0);halt;
end;
dijkstra;

{for j:=1 to n do
        if a[j]<>maxint then write(a[j],' ') else write(0,' ');
}
if a[n]<>maxint then
write(a[n]-1)
else
write('NO');
end.