program rqnoj_345;
type
ti=record
        m,s,f:longint;
        str:ansistring;
        end;
var
i,j,k,n,m,a,b,c,d,x,y,z:longint;
ch,ch2,ch3,ch4:string;
st,st2:ansistring;
lrc:array[1..100] of ti;
temp,temp2:ti;
begin
assign(input,'f:\in.txt');
reset(input);
readln(n);
k:=1;
for i:=1 to n do
        begin
        readln(st);
        st2:=st;
        a:=pos('[',st2);
        d:=pos(']',st2);

        repeat
        st2:=copy(st2,1,a-1)+copy(st2,d+1,length(st2)-d);
        a:=pos('[',st2);
        d:=pos(']',st2);
        until a=0;


        a:=pos('[',st);
        b:=pos(':',st);
        c:=pos('.',st);
        d:=pos(']',st);
        ch:=copy(st,a+1,1);
        val(ch,x,z);
        repeat
        if(a<b)and(b<d)and(z<>1) then
        begin
                ch2:=copy(st,a+1,b-a-1);
                if c<>0 then
                begin
                ch3:=copy(st,b+1,c-b-1);
                ch4:=copy(st,c+1,d-c-1);
                end
                else
                ch3:=copy(st,b+1,d-b-1);
                val(ch2,x,z);
                lrc[k].m:=x;
                val(ch3,x,z);
                lrc[k].s:=x;
                val(ch4,x,z);
                lrc[k].f:=x;

                lrc[k].str:=st2;
                inc(k);
        end;
           st:=copy(st,1,a-1)+copy(st,d+1,length(st)-d);
           a:=pos('[',st);
           b:=pos(':',st);
           c:=pos('.',st);
           d:=pos(']',st);
           ch:=copy(st,a+1,1);
           val(ch,x,z);
        until a=0;
        end;
        dec(k);

        for i:=1 to k do
        begin
        temp.m:=maxint;temp.s:=maxint;temp.f:=maxint;
        x:=0;
                for j:=i to k do
                        if (lrc[j].m<temp.m)or((lrc[j].m=temp.m)and(lrc[j].s<temp.s))or((lrc[j].m=temp.m)and(lrc[j].s=temp.s)and(lrc[j].f<temp.f)) then
                         begin
                          x:=j;temp:=lrc[j];
                         end;
        lrc[x]:=lrc[i];
        lrc[i]:=temp;
        end;
        for i:=1 to k-1 do
        //writeln('[',lrc[i].m,':',lrc[i].s,'.',lrc[i].f,']',lrc[i].str);
        writeln(lrc[i].str);
        write(lrc[k].str);
end.
