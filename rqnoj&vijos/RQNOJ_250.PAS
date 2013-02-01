program rqnoj_250;
var
s1:array[1..300] of set of '0'..'z';
st:array[1..300] of char;
ch3,ch4,ch5:string[1];
ch2:string;
ch:char;
st2:array of string;
i,j,a,b,x,y,flag3,k:longint;
flag1,flag2,flag4:boolean;

f1:text;

begin
assign(f1,'f:\in.txt');
reset(f1);
readln(f1,ch2);
flag3:=1;
for i := 1 to length(ch2) do
begin
   ch4:=copy(ch2,i,1);
   ch:=ch4[1];
   case ch of
   '[':flag1:=true;
   ']':begin flag1:=false;inc(flag3);end;
   '{':flag2:=True;
   '}':begin flag2:=false;
   str(45):flag4:=true
   else
   begin
        if ('0'<=ch)and('9'>=ch) then
        begin
                if flag1 and not(flag4) then
                begin
                val(ch,a,b);
                s1[k]:=s1[k]+[a]
                end;
                else
                        if flag1 and flag4 then
                        begin
                           ch3:=copy(ch2,i-2,1);
                        end;

        end
   end;
   end;
end;
end.