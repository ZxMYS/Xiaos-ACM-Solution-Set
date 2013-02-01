

void mult(long int p1,long int p2[]){
for(int i=1;i<=p2[0];i++){
    p2[i]*=p1;
}
for(int i=1;i<=p2[0];i++){
    p2[i+1]+=p2[i+1]/10;
    p2[i]%=10;
}
if(p2[p2[0]+1])p2[0]++;
}
