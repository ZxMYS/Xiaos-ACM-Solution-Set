program rqnoj_51;
var
a,b,i:longint;
ch:char;
st:ansistring;
buf:array[1..10000] of byte;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);

a:=0;
b:=0;
repeat
read(ch);
if ch='W' then begin
inc(a);
if (a>=11)and(abs(a-b)>1) then begin writeln(a,':',b);a:=0;b:=0; end;
st:=st+ch;
end
else if ch='L' then
begin
inc(b);
if (b>=11)and(abs(a-b)>1) then begin writeln(a,':',b);a:=0;b:=0; end;
st:=st+ch
end;
until ch='E';
writeln(a,':',b);
writeln;
a:=0;b:=0;
for i:=1 to length(st) do
begin
ch:=st[i];
if ch='W' then begin
inc(a);
if (a>=21)and(abs(a-b)>1) then begin writeln(a,':',b);a:=0;b:=0; end;
st:=st+ch;
end
else if ch='L' then
begin
inc(b);
if (b>=21)and(abs(a-b)>1) then begin writeln(a,':',b);a:=0;b:=0; end;
st:=st+ch
end;
end;
writeln(a,':',b);
end.