program rqnoj_124;
var
t,n,i,j,k:longint;
buf:array[1..10000] of byte;
st:ansistring;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);

read(n);
for j:=1 to n do
begin
        st:='';
        read(k);
        if (k<=0)or(k>=67108864) then begin writeln('None');Continue; end;
        for i:=0 to 31 do
                if (k shr i)and 1=1 then st:=st+chr(i+ord('A'))+' ';
        writeln(copy(st,1,length(st)-1))
end;
end.