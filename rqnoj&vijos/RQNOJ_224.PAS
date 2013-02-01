program rqnoj_224;
const
a:array['a'..'z'] of longint=(1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4);
var
ans:longint;
ch:char;
buf:array[1..4096] of byte;
begin
settextbuf(input,buf);
repeat
read(ch);
if ('a'<=ch) and ('z'>=ch) then inc(ans,a[ch]);
if ch=' ' then inc(ans);
until eof(input);
writeln(ans);
end.