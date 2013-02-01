program renoj_212;
var
s:set of 'A'..'z';
st:string;
i,j,a,b,c:longint;
f:boolean;
f1:text;
begin
assign(f1,'f:\in.txt');
reset(f1);
s:=['a','e','i','o','u','A','E','I','O','U'];
readln(f1,st);
for i:=1 to length(st) do
begin
if (st[i]>='A')and(st[i]<='z') then
begin
        inc(a);
        write('.')
end
else
        write(st[i]);
end;
writeln;

for i:=1 to length(st) do
begin
if (st[i]>='A')and(st[i]<='z') then
begin
inc(b);
if b<=round(a/3) then
begin
write(st[i]);
c:=i;
end
else
write('.');
end
else
write(st[i]);
end;
writeln;

b:=0;

for i:=c+1 to length(st) do
    if (st[i] in s) then
    begin
        f:=true;
        break;
    end;

if not(f) then
	for i:=1 to length(st) do
	begin
		if (st[i]>='A')and(st[i]<='z') then
		begin
			inc(b);
			if b<=round(2*a/3) then write(st[i])
			else
			write('.');
		end
		else
			write(st[i]);
	end
else
	for i:=1 to length(st) do
	begin
		if (st[i]>='A')and(st[i]<='z') then
		begin
			inc(b);
			if b<=round(a/3) then
			write(st[i])
			else
				if st[i] in s then write(st[i]) else write('.');
			end
		else
		write(st[i]);
	end;
writeln;
end.
