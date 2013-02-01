program rqnoj_322;
type
tree=^node;
node=record
        child:array[-100..100] of tree;
        end;
var
ch:char;
bt,root:tree;
i,j,m,n,k,a:longint;
begin
assign(input,'f:\in.txt');
reset(input);
new(bt);
root:=bt;
a:=1;
repeat
        read(ch);
        if (ch>='A')and(ch<='Z')  then
            begin
                if bt^.child[ord(ch)-ord('A')]=nil then
                begin
                        new(bt^.child[ord(ch)-ord('A')]);
                        inc(a);
                        bt:=bt^.child[ord(ch)-ord('A')];
                end
                else
                    bt:=bt^.child[ord(ch)-ord('A')];
            end
        else
        begin
                bt:=root;
        end;
until eof(input);
write(a);
end.