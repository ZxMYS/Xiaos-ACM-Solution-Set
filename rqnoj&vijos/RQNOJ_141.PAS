program rqnoj_141;
var
ga:array[1..200,1..200] of boolean;
match:array[1..200] of longint;
ch:array[1..200] of boolean;
i,j,m,n,x,y:longint;
f1:text;
function find(p:longint):boolean;
var
i:longint;
begin
for i:= 1 to n do
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
y:=0;
read(f1,n);
for i:= 1 to n do
begin
        for j:= 1 to n do
                ga[i,j]:=true;
        read(f1,x);
        for j:= 1 to x do
        begin
        read(f1,m);
                ga[i,m]:=false;
        end;
end;
for i := 1 to n do
begin
fillchar(ch,sizeof(ch),0);
if find(i) then inc(y);
end;
write(y);
end.