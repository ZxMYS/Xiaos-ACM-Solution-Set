program rqnoj_34;
const
xc:array[1..4] of integer=(1,0,-1,0);
yc:array[1..4] of integer=(0,1,0,-1);

var
ga:array[0..2001,0..2001] of boolean;
i,j,t,m,n,x1,y1,x2,y2,x,y,step,top,bottom:longint;
a:array[1..10000000,1..3] of longint;
k:char;
begin
assign(input,'f:\in.txt');
reset(input);
readln(n);
for i:=1 to n do
for j:=1 to n+2 do
        begin
        read(k);
        if k='0' then ga[i,j]:=true;
        end;
read(x1,y1,x2,y2);

a[1,1]:=x1;
a[1,2]:=y1;
a[1,3]:=0;
top:=1;
bottom:=1;
while bottom-top>=0 do
begin
x:=a[top,1];
y:=a[top,2];
step:=a[top,3];
top:=top mod 10000000 + 1;
if (x=x2)and(y=y2) then
begin
write(step);
halt;
end;
for i:=1 to 4 do
if (x+xc[i]>0)and(x+xc[i]<=n)and(y+yc[i]>0)and(y+yc[i]<=n)and(ga[x+xc[i],y+yc[i]]) then
begin
        bottom:=bottom mod 10000000 + 1;
        a[bottom,1]:=x+xc[i];
        a[bottom,2]:=y+yc[i];
        a[bottom,3]:=step+1;
        ga[x+xc[i],y+yc[i]]:=false;

end;
end;


end.