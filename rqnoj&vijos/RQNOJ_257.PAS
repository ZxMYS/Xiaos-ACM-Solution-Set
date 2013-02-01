program rqnoj_257(input,output);
var
 n:longint;
ch,ch2:char;
i,str:string;
x,z,y:longint;
begin
readln(n);
readln(str);
ch2:=str[1];
z:=2;
repeat
ch:=str[z];
if ch>ch2 then
begin
i:=i+ch;
ch2:=ch
end
else
inc(x);
inc(z);
writeln(x,' ',z);
until (x=n) or (z>length(str));
if (z>length(str))and(x<>n) then
i:=i+copy(str,length(str)-(n-x)+1,n-x-1);
write(i);
end.
