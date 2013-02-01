program rqnoj_152(input,output);
var
a,b,c,i,j:longint;
x,y:array[1..100000] of longint;
ch:char;
flag:boolean;
begin
i:=1;
j:=1;
repeat
read(ch);
if (ch=chr(13)) or (ch=chr(10)) then break;
if (ch<>' ') and (not(flag)) then
begin
val(ch,a,b);
x[i]:=a;
inc(i);
end
else
        if ch=' ' then
                flag:=true
        else
                begin
                val(ch,a,b);
                y[j]:=a;
                inc(j);
                end;

until false; //eof(input);
dec(i);dec(j);
for a:=1 to i do
        for b:=1 to j do
                begin
                //writeln(x[a], ' ',y[b]);
                c:=c+x[a]*y[b];
                end;
write(c);
end.