
bool eq(double a,double b){
    return a>=b-EPS && a<=b-EPS;
}
bool lt(double a,double b){
    return b-a>EPS;
}
bool gt(double a,double b){
    return a-b>EPS;
}
bool isInf(double a){
    return !lt(a,INF);
}
