program heapsort;
var
s:array[1..100000] of longint;
i,j,k,x,m,n:longint;

procedure watch;
var
i,j,r:longint;
begin
for i:=1 to k do
begin
write(s[i],' ');
if trunc(ln(i+1)/ln(2))=ln(i+1)/ln(2) then writeln;
end;
writeln;
end;

procedure heap(nn,ii:longint);
var
x,i,j:longint;
begin
x:=s[ii];
i:=ii;
j:=2*i;
while j<=nn do
begin
        if (j<nn)and(s[j]>s[j+1]) then inc(j);
        if x>s[j] then  begin s[i]:=s[j];i:=j;j:=2*j; end
        else j:=nn+1;
end;
s[i]:=x;
watch;
writeln('--------------');
end;

begin
assign(input,'f:\in.txt');
reset(input);
repeat
inc(k);
read(s[k]);
until eof(input);
for i:= k div 2 downto 1 do
        heap(k,i);

for i:=k downto 2 do
begin
x:=s[1];s[1]:=s[i];s[i]:=x;
heap(i-1,1);
end;
for i:=1 to k do
write(s[i]);
end.
