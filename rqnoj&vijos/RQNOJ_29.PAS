program rqnoj_29;
{$asmmode Intel}
var
i,j,n,k:longint;
a:array[1..4096] of byte;
begin
SetTextBuf(input,a,SizeOf(a));
read(j);
for i:=1 to j do
        begin
        read(n,k);
        asm
        mov eax,n
        and eax,k
        mov n,eax
        end;
        n:=n;
        if n=k then writeln(1) else writeln(0);
        end;
end.