program rqnoj_28;
var
line:array[1..1000000,1..2] of longint;
i,j,k,n,x,y,a,b:longint;
begin
assign(input,'f:\in.txt');
reset(input);

read(n);

line[1,1]:=0;
for i:=1 to n-1 do
begin
        read(x,y);
        line[y,1]:=x;
end;

read(a,b);
y:=b;
while y<>0 do
  begin
      line[y,2]:=1;
      y:=line[y,1];
  end;
y:=a;
while line[y,2]<>1 do
begin
        y:=line[y,1];
end;
write(y);
end.