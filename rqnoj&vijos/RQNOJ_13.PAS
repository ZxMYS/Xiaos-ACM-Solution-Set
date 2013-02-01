program rqnoj_13;
var
ga:array[0..10000] of longint;
i,j,k,a,m,n,x,y,z:longint;
begin
assign(input,'f:\in.txt');
reset(input);

read(n,m);
for i:=1 to m do
begin
read(x,y);
z:=x;
repeat
if (ga[z]=0) then begin ga[z]:=y;inc(z);end else if z<>ga[z] then z:=ga[z] else inc(z);
//writeln(x,y);
until z>y;
end;
z:=0;
repeat
x:=z;
if ga[z]=0 then inc(z) else
begin
        repeat
        z:=ga[z];
        //writeln(x,' ',z,' ',ga[z]);
        until ga[z]=z;
//writeln(z-x+1);
inc(a,z-x+1);
inc(z);
end;
until z>=n;
writeln(n-a+1);
end.
