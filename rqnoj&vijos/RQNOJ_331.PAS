program rqnoj_331;
var
line:array[1..5000,1..3] of longint;
m,n,p,x,y,i,j,k:longint;
begin
assign(input,'f:\in.txt');
reset(input);

read(n,m,p);
for i:=1 to n do
begin
        line[i,1]:=i;
        line[i,2]:=0;
        line[i,3]:=i;
end;

for i:=1 to m do
        begin
                read(x,y);
                y:=line[y,1];
                if line[x,1]<>line[y,1] then line[line[x,3],2]:=y;
                k:=0;
                while(y<>0) do
                        begin
                        line[y,1]:=line[x,1];
                        k:=y;
                        y:=line[y,2];
                        end;
                x:=line[x,1];
                while(line[x,3]<>k) do
                        begin
                        line[x,3]:=k;
                        x:=line[x,2];
                        end;
        end;

for i:=1 to p do
begin
        read(x,y);
        if line[x,1]=line[y,1] then writeln('Yes') else writeln('No');
end;
end.