program rqnoj_282;
var
i,j,k,m,n,a,b,c:longint;
ga:array[1..100,1..100] of longint;
path:array[1..100,1..100] of qword;
sum:array[1..100] of real;
f1:text;
begin
assign(f1,'f:\in.txt');
reset(f1);

read(f1,n,m);
for i:=1 to n do
for j:=1 to n do
ga[i,j]:=maxint;

for i:=1 to m do
begin
read(f1,a,b,c);
ga[a,b]:=c;
ga[b,a]:=c;
end;
for i:=1 to n do
        for j:=1 to n do
                path[i,j]:=1;

for i:=1 to n do
        for j:=1 to n do
        begin
                for k:=1 to n do
                begin
                        if (j=k)or(i=j)or(i=k) then continue;
                        if (ga[j,k]>ga[j,i]+ga[i,k]) then
                                begin
                                ga[j,k]:=ga[j,i]+ga[i,k];
                                path[j,k]:=path[j,i]*path[i,k];
                                end
                                else if ga[j,k]=ga[j,i]+ga[i,k] then
                                        path[j,k]:=path[j,k]+path[j,i]*path[i,k];
                end;
        end;
for i:=1 to n do
        for j:=1 to n do
                for k:=1 to n do
                begin
                if (j=k)or(k=i)or(i=k) then continue;
                if ga[i,j]=ga[i,k]+ga[k,j] then
                        sum[k]:=sum[k]+path[i,k]*path[k,j]/path[i,j];
                end;
for i:=1 to n do
writeln(sum[i]:3:3);
end.