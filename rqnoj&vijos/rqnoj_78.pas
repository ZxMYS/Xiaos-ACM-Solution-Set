program rqnoj_78;
var
s,t:string;
n,m,i,j:integer;
e:array[1..255] of string[1];
k:string[1];
begin
readln(s);
readln(n);
for i := 1 to n do readln(e[i]);

writeln(s);
for i := 1 to n do
begin
m:=pos(e[i],s);
if ((odd(length(s))) and (m>(round(length(s))/2)+1)) or ((not (odd(length(s)))) and (m>length(s)/2)) then
begin
t:=copy(s,m+1,length(s)-m);
delete(s,m,length(s)-m+1);
for j := 1 to length(t) do
begin
k:=copy(t,length(t),1);
delete(t,length(t),1);
insert(k,s,length(s)+1);
end;
end
else
begin
t:=copy(s,1,m-1);
delete(s,1,m);
for j:= 1 to length(t) do
begin
k:=copy(t,1,1);
delete(t,1,1);
insert(k,s,1);
end;
end;
writeln(s);
end;
end.
