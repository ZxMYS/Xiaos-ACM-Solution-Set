program rqnoj_388;
var
st:ansistring;
ch:char;
i,j,k,a,m,n:longint;
buf:array[1..4096] of byte;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
assign(output,'f:\out.txt');
rewrite(output);
readln(n);
k:=0;
st:='';
while not(eof(input)) do
        begin
                read(ch);
                if (k>=n) and (ch in [',','.',' ','?','!']) then
                        begin
                                writeln(st);
                                st:='';
                                k:=0;
                        end;
                st:=st+ch;
                inc(k);
        end;
if st<>'' then writeln(st);
close(output);
end.