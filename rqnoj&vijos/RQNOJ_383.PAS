program rqnoj_383;
var
op:array[1..100] of char;
ex1,ex2:array[0..100] of string;
st:string;
ch:char;
i,j,f,k,a,m,n,a1,a2:longint;
pri:array[chr(1)..chr(127)] of longint;
buf:array[1..4096] of byte;
//f:1= 2< 3> 4<= 5>=
function calc(x:longint):longint;
var
i,j,a,b,p,a1,a2:longint;
sa:array[1..100] of longint;
begin
        //ex1
i:=1;p:=0;
repeat
        val(ex1[i],a,b);
        if b=0 then begin
                inc(p);sa[p]:=a end
                else if ex1[i]='x' then begin inc(p);sa[p]:=x; end

        else
                begin
                        case ex1[i][1] of
                        '+':sa[p-1]:=sa[p-1]+sa[p];
                        '-':sa[p-1]:=sa[p-1]-sa[p];
                        '*':sa[p-1]:=sa[p-1]*sa[p];
                        end;
                        p:=p-1;
                end;
inc(i);
until ex1[i]='';
a1:=sa[1];
        //ex1 end;
i:=1;p:=0;
repeat
        val(ex2[i],a,b);
        if b=0 then begin
                inc(p);sa[p]:=a end
                else if ex2[i]='x' then begin inc(p);sa[p]:=x; end

        else
                begin
                        case ex2[i][1] of
                        '+':sa[p-1]:=sa[p-1]+sa[p];
                        '-':sa[p-1]:=sa[p-1]-sa[p];
                        '*':sa[p-1]:=sa[p-1]*sa[p];
                        end;
                        p:=p-1;
                end;
inc(i);
until ex2[i]='';
a2:=sa[1];
if a1=a2 then exit(1);
if a1<a2 then exit(2);
if a1>a2 then exit(3);
if a1<=a2 then exit(4);
if a1>=a2 then exit(5);
end;


function check(ex1,ex2:array of string):boolean;
var
i,a1,a2,a,b:longint;
begin
a1:=0;
a2:=0;
i:=1;
repeat
repeat
inc(i);
until (ex1[i]='')or(ex1[i]='x');
if ex1[i]='x' then begin
        val(ex1[i-1],a,b);
        inc(a1,a);
        end;
until ex1[i]='';
i:=1;
repeat
repeat
inc(i);
until (ex2[i]='')or(ex2[i]='x');
if ex2[i]='x' then begin
        val(ex2[i-1],a,b);
        inc(a2,a);
        end;
until ex2[i]='';
if a1=a2 then exit(true) else exit(false);
end;


procedure pro(st:string;var ex:array of string);
var
i,j,k,p,a,b:longint;
st1:string;
begin
k:=0;
p:=0;
st1:='';

for i:=1 to length(st) do
begin
        case st[i] of
        '0'..'9':st1:=st1+st[i];
        'x':begin
                        if st1<>'' then
                                begin
                                     inc(k);
                                     ex[k]:=st1;
                                     st1:='';
                                     inc(k);
                                     ex[k]:='x';
                                     inc(k);
                                     ex[k]:='*';
                                end
                        else if (i>1)and(st[i-1]='*') then
                                begin
                                        dec(p);
                                        inc(k);
                                        ex[k]:='x';
                                        inc(k);
                                        ex[k]:='*';
                                end
                                else
                                begin
                                    inc(k);
                                    if (i=1)or(i>1)and(st[i-1]<>'-') then
                                     ex[k]:='1'
                                     else if (i>1)and(st[i-1]='-') then
                                     ex[k]:='-1';
                                     inc(k);
                                     ex[k]:='x';
                                     inc(k);
                                     ex[k]:='*';
                                end;
                end;
        else
                begin
                if st1<>'' then begin
                inc(k);ex[k]:=st1;st1:='';
                end;
                                if(p<1)or(pri[st[i]]>pri[op[p]]) then
                                begin
                                        inc(p);
                                        op[p]:=st[i];
                                end
                                else
                                begin
                                        while(p>0)and(pri[st[i]]<=pri[op[p]]) do
                                        begin inc(k);ex[k]:=op[p];dec(p); end;
                                        inc(p);
                                        op[p]:=st[i];
                                end;
                end;
        end;
end;
while p>0 do
begin
inc(k);ex[k]:=op[p];dec(p);
end;

end;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
pri['+']:=1;
pri['-']:=1;
pri['*']:=2;
st:='';
repeat
read(ch);
if ch<>' ' then
st:=st+ch;
until ch in ['=','<','>'];
st:=copy(st,1,length(st)-1);
pro(st,ex1);
case ch of
'=':f:=1;
'<':f:=2;
'>':f:=3;
end;
read(ch);
if not(ch in [' ','=']) then
        st:=ch else st:='';
if ch='=' then inc(f,2);

repeat
read(ch);
if ch<>' ' then
st:=st+ch;
until eoln;
pro(st,ex2);
i:=1;
{while ex1[i]<>'' do begin write(ex1[i],' ');inc(i); end;
i:=1;
writeln();
while ex2[i]<>'' do begin write(ex2[i],' ');inc(i); end;  }
if check(ex1,ex2) then begin writeln('Are you sure?');halt; end;

readln(n);
for i:=1 to n do
        begin
                readln(m);
                a:=calc(m);
                if (f=a)or((f=5)and((a=3)or(a=1)))or((f=4)and((a=2)or(a=1))) then writeln(m);        end;
end.