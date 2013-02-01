program rqnoj_165;
var
ch:char;
f,b,i:longint;
begin
assign(input,'f:\in.txt');
reset(input);
repeat
read(ch);
case ch of
'F':inc(f);
'B':inc(b,f);
'I':inc(i,b);
end;
until eof(input);
write(i);
end.