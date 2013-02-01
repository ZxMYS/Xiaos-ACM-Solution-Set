program rqnoj_114;
var
n:qword;
i,j:longint;
begin
read(n);
i:=2;
while i<=n do
begin
        if n mod i = 0 then
                repeat
                        n:=n div i;
                        write(i,' ');
                until n mod i<>0;
        inc(i);
end;
end.