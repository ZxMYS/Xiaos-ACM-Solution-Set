program rqnoj_277;
var
n:dword;
function d(n:dword):ansistring;
var
i:longint;
begin
if n=0 then exit('0');
d:='';
for i:=16 downto 1 do
        if ((n shr (i-1))) and 1 = 1 then
                begin
                        if i=2 then d:=d+'2+' else
                        d:=d+'2('+d(i-1)+')+';
                end;
d:=copy(d,1,length(d)-1);
end;
begin
read(n);
write(d(n));
end.
