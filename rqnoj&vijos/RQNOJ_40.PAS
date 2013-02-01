program rqnoj_40;
var
s:array[1..100000] of string[71];
st:string;
i,j,k,m,n,top,p:longint;
begin
assign(input,'f:\in.txt');
reset(input);



s[1]:='http://www.acm.org/';
p:=1;
top:=p;
repeat
readln(st);
k:=pos(' ',st);
if k<>0 then //visit
        begin
        st:=copy(st,k+1,length(st)-k);
        p:=p+1;
        top:=p;
        s[p]:=st;
        writeln(s[p]);
        end
else
        if st='BACK' then
                if p=1 then writeln('Ignored')
                else
                begin
                p:=p-1;
                writeln(s[p]);
                end
else
        if st='FORWARD' then
                if p=top then writeln('Ignored')
                else
                begin
                p:=p+1;
                writeln(s[p]);
                end
else
        halt
until false;
end.


