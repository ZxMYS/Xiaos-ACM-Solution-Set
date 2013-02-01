program rqnoj_199;
var
ga:array[1..1000,1..1000] of boolean;
ch:array[1..1000] of boolean;
match:array[1..1000] of longint;
a,b,i,j,x,y,m,n:longint;
f1:text;
function find(p:longint):boolean;
var
i:longint;
begin
for i:= 1 to m do
        if ga[p,i] and not(ch[i]) then
        begin
        ch[i]:=true;
        if (match[i]=0) or find(match[i]) then
        begin
        match[i]:=p;
        exit(true);
        end;
        end;
exit(false);
end;
begin
assign(f1,'f:\in.txt');
reset(f1);
read(f1,n,m);
for i:= 1 to n do
begin
read(f1,x);
for j:=1 to x do
begin
read(f1,y);
ga[i,y]:=true;
end;
end;
y:=0;
for i := 1 to n do
begin
fillchar(ch,sizeof(ch),0);
if find(i) then inc(y);
end;
write(y);
end.