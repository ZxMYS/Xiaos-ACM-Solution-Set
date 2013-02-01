program rqnoj_319(input,output);
var
ga:array[1..100,1..100] of longint;
b,c,i,j,k,n:longint;
pop:array[1..100] of longint;
f1:text;
begin
assign(f1,'f:\in.txt');
reset(f1);
read(f1,n);
for i:=1 to n do
        for j:=1 to n do
                ga[i,j]:=maxint;
for i:=1 to n do
begin
readln(f1,pop[i],c,b);
if (b<>0) then
begin
ga[i,b]:=1;
ga[b,i]:=1;
end;
if (c<>0) then
begin
ga[i,c]:=1;
ga[c,i]:=1;
end;
end;
for k:=1 to n do
        for i:=1 to n do
        begin
                if i=k then continue;
                for j:=1 to n do
                begin
                if (i=j)or(k=j) then continue;
                if (ga[i,j]>ga[i,k]+ga[k,j])and(ga[i,k]<>maxint)and(ga[k,j]<>maxint) then
                        ga[i,j]:=ga[i,k]+ga[k,j];
                end;
        end;

c:=maxlongint;
for i:=1 to n do
begin
b:=0;
for j:=1 to n do
begin
if j<>i then
inc(b,pop[j]*ga[i,j]);
end;
if b<c then c:=b;
end;
write(c);
end.
