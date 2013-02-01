program rqnoj_193;
var
r:char;
ga:array[1..1000,1..1000] of longint;
l:array[1..1000] of longint;
s:array[1..1000] of boolean;
a,b,m,n,i,j,x,y,min:longint;
f1:text;
procedure findmin;
begin
for x:= 2 to n do
begin
        min:=maxint;
        for j:= 2 to n do
        if not(s[j]) and (l[j]<=min) then
        begin
                min:=l[j];
                b:=j;
        end;
        if min<>maxint then
        begin
                s[b]:=true;
                a:=a+min;
                for i:= 2 to n do
                        if not(s[i]) and (ga[b,i] < l[i]) then
                        l[i]:=ga[b,i];
        end;
end;
end;


begin
assign(f1,'f:\in.txt');
reset(f1);
a:=0;
readln(f1,n,m);
for i:= 1 to 1000 do
begin
for j:= 1 to 1000 do
ga[i,j]:=maxint;
s[i]:=false;
end;

for i:= 1 to m do
                begin
                        read(f1,x,y,b);
                        if b<ga[x,y] then
                        begin
                        ga[x,y]:=b;
                        ga[y,x]:=ga[x,y];
                        end;
                end;
s[1]:=true;
for i:=1 to n do
l[i]:=ga[1,i];

findmin;

write(a);

end.
