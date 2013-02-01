program rqnoj_21;
type
tree=record
        data:char;
        //father:longint;
     end;
var
t:array[1..10000] of tree;
x,p,i,j,k,n:longint;
z:char;
f1:text;
procedure out(num:longint);
begin
if num>2*k-1 then
begin
write(t[num].data);
end
else
begin
out(num*2);
out(num*2+1);
write(t[num].data);
end;
end;
begin
assign(f1,'f:\in.txt');
reset(f1);

readln(f1,n);
k:=trunc(exp(ln(2)*n));
p:=k;
for i:= 1 to k do
begin
read(f1,z);
if z='1' then
t[p].data:='I'
else
t[p].data:='B';
inc(p);
end;
for i:= n downto 0 do
begin
k:=trunc(exp(ln(2)*i));
p:=k;
for j:= 1 to k do
begin
if not(odd(p)) then
begin
        t[p div 2].data:='F';
        if (t[p].data=t[p+1].data) and (t[p].data='B') then
        t[p div 2].data:='B'
        else
        if (t[p].data=t[p+1].data) and (t[p].data='I') then
        t[p div 2].data:='I';

end;
inc(p);
end;
k:=trunc(exp(ln(2)*(n-1)));
end;
out(1);




end.