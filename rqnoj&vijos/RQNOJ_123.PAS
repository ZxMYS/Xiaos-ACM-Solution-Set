program rqnoj_123;
type
    ss=array[1..100]of longint;
var
    f:array[0..10000]of ss;
    a,w:array[1..10000]of longint;
    v,i,j,n,k:longint;
function max(a,b:ss;x:longint):ss;
var
    i,j,l:longint;
    c:ss;
begin
    i:=1;j:=1;l:=0;
    while l<k do
    begin
        inc(l);
        if a[i]<b[j]+x then
        begin
            c[l]:=b[j]+x;inc(j);
        end
        else
        begin
            c[l]:=a[i];inc(i);
        end;
    end;
    exit(c);
end;
begin

    assign(input,'f:\in.txt');
    reset(input);


    read(k,v,n);
    for i:=1 to n do
        readln(a[i],w[i]);
    for i:=0 to v do
    for j:=1 to k do
        f[i,j]:=-maxlongint;
    f[0,1]:=0;
    for i:=1 to n do
    begin
        for j:=v downto a[i] do              {如果是完全背包则变成 for j:=a[i] to v 即可}
            f[j]:=max(f[j],f[j-a[i]],w[i]);
    end;
    n:=0;
    for i:=1 to k do
    if f[v,i]<0 then continue
    else inc(n,f[v,i]);
    write(n);
end.