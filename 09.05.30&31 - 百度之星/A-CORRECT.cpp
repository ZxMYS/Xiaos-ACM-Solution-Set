#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

using namespace std ;

const int Base=1000000000;
const int Capacity=100;
typedef long long huge ;

struct BigInt{
    int Len;
    int Data[Capacity];
    BigInt() : Len(0) {}
    BigInt (const BigInt &V) : Len(V.Len) { memcpy (Data, V.Data, Len*sizeof*Data);}
    BigInt(int V) : Len(0) {for(;V>0;V/=Base) Data[Len++]=V%Base;}
    BigInt &operator=(const BigInt &V) {Len=V.Len; memcpy(Data, V.Data, Len*sizeof*Data); return *this;}
    int &operator[] (int Index) {return Data[Index];}
    int operator[] (int Index) const {return Data[Index];}
};

int compare(const BigInt &A, const BigInt &B){
    if(A.Len!=B.Len) return A.Len>B.Len ? 1:-1;
    int i;
    for(i=A.Len-1;i>=0 && A[i]==B[i];i--);
    if(i<0)return 0;
    return A[i]>B[i] ? 1:-1;
}

BigInt operator+(const BigInt &A,const BigInt &B){
    int i,Carry(0);
    BigInt R;
    for(i=0;i<A.Len||i<B.Len||Carry>0;i++){
        if(i<A.Len) Carry+=A[i];
        if(i<B.Len) Carry+=B[i];;
        R[i]=Carry%Base;
        Carry/=Base;
    }
    R.Len=i;
    return R;
}

BigInt operator-(const BigInt &A,const BigInt &B){
    int i,Carry(0);
    BigInt R;
    R.Len=A.Len;
    for(i=0;i<R.Len;i++){
        R[i]=A[i]-Carry;
        if(i<B.Len) R[i]-=B[i];
        if(R[i]<0) Carry=1,R[i]+=Base;
        else Carry=0;
    }
    while(R.Len>0&&R[R.Len-1]==0) R.Len--;
    return R;
}

BigInt operator*(const BigInt &A,const int &B){
    int i;
    huge Carry(0);
    BigInt R;
    for(i=0;i<A.Len||Carry>0;i++){
        if(i<A.Len) Carry+=huge(A[i])*B;
        R[i]=Carry%Base;
        Carry/=Base;
    }
    R.Len=i;
    return R;
}

istream &operator>>(istream &In,BigInt &V){
    char Ch;
    for(V=0;In>>Ch;){
        V=V*10+(Ch-'0');
        if(In.peek()<=' ') break;
    }
    return In;
}

ostream &operator<<(ostream &Out,const BigInt &V){
    int i;
    Out<<(V.Len==0 ? 0:V[V.Len-1]);
    for(i=V.Len-2;i>=0;i--) for(int j=Base/10;j>0;j/=10) Out<<V[i]/j%10;
    return Out;
}

bool map1[ 10 ][ 10 ] , map2[ 10 ][ 10 ] , map3[ 10 ][ 10 ] ;
char a[ 110 ] , b[ 110 ] , c[ 110 ] , s[ 110 ] , ans[ 100000 ][ 110 ] ;
char o[ 110 ] ;

int  f[ 100000 ] , sig ;

bool judge( )
{
    int k , la , lb , lc ;
    la = lb = lc = 0 ;
    for( k = 0 ; isdigit( s[ k ] ) ; k ++ ) a[ la ++ ] = s[ k ] ;
    if( s[ k ] == '+' ) sig = 1 ; else sig = -1 ;
    for( k ++ ; isdigit( s[ k ] ) ; k ++ ) b[ lb ++ ] = s[ k ] ;
    for( k ++ ; isdigit( s[ k ] ) ; k ++ ) c[ lc ++ ] = s[ k ] ;

    if( ( a[ 0 ] == '0' && la > 1 ) || ( b[ 0 ] == '0' && lb > 1 ) || ( c[ 0 ] == '0' && lc > 1 ) )
          return false ;

    BigInt x( 0 ) , y( 0 ) , z( 0 ) ;
    for( int i = 0 ; i < la ; i ++ )
             x = x * 10 + ( a[ i ] - '0' ) ;
    for( int i = 0 ; i < lb ; i ++ )
             y = y * 10 + ( b[ i ] - '0' ) ;
    for( int i = 0 ; i < lc ; i ++ )
             z = z * 10 + ( c[ i ] - '0' ) ;

    if( sig == -1 && ( compare( x , y ) < 0 ) ) return false ;

    if( sig == 1 && ( compare( x + y , z ) == 0 ) ) return true ;
    if( sig == -1 && ( compare( x - y , z ) == 0 ) ) return true ;

    return false ;
}

bool cmp( int x , int y )
{
    return strcmp( ans[ x ] , ans[ y ] ) < 0 ;
}

int main( )
{
    #ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
    int la, lb , lc , tot = 0 ;
    la = lb = lc ;
    memset( map1 , false , sizeof( map1 ) ) ;
    memset( map2 , false , sizeof( map2 ) ) ;
    memset( map3 , false , sizeof( map3 ) ) ;

    map1[ 0 ][ 9 ] = map1[ 9 ][ 0 ] = map1[ 0 ][ 6 ] = map1[ 6 ][ 0 ] = true ;
    map1[ 6 ][ 9 ] = map1[ 9 ][ 6 ] = map1[ 2 ][ 3 ] = map1[ 3 ][ 2 ] = true ;
    map1[ 5 ][ 3 ] = map1[ 3 ][ 5 ] = true ;

    map2[ 0 ][ 8 ] = map2[ 1 ][ 7 ] = map2[ 3 ][ 9 ] = true ;
    map2[ 6 ][ 8 ] = map2[ 9 ][ 8 ] = map2[ 5 ][ 6 ] = map2[ 5 ][ 9 ] = true ;

    map3[ 8 ][ 0 ] = map3[ 7 ][ 1 ] = map3[ 9 ][ 3 ] = true ;
    map3[ 8 ][ 6 ] = map3[ 8 ][ 9 ] = map3[ 6 ][ 5 ] = map3[ 9 ][ 5 ] = true ;

    scanf( "%s" , o ) ;
    int l = strlen( o ) ;


    for( int i = 0 ; i < l ; i ++ )
         for( int j = 0 ; j < l ; j ++ )
    {
        if( !isdigit( o[ i ] ) || !isdigit( o[ i ] ) ) continue ;
        memcpy( s , o , sizeof( s ) ) ;
        if( i == j )
        {
            for( int k = 0 ; k < 10 ; k ++ )
                     if( map1[ o[ i ] - '0' ][ k ] )
                     {
                         s[ i ] = k + '0' ;
                         if( judge( ) )
                         {
                             memset( ans[ tot ] , 0 , sizeof( ans[ tot ] ) ) ;
                             strcpy( ans[ tot ] , s ) ;
                             f[ tot ] = tot ;
                             tot ++ ;
                         }
                     }
        }
        else
        {
            for( int u = 0 ; u < 10 ; u ++ )
                 for( int v = 0 ; v < 10 ; v ++ )
                      if( map2[ o[ i ] - '0' ][ u ] && map3[ o[ j ] - '0' ][ v ] )
                      {
                          s[ i ] = u + '0' ;
                          s[ j ] = v + '0' ;
                          if( judge( ) )
                          {
                             memset( ans[ tot ] , 0 , sizeof( ans[ tot ] ) ) ;
                             strcpy( ans[ tot ] , s ) ;
                             f[ tot ] = tot ;
                             tot ++ ;
                          }
                      }
        }
    }

    sort( f , f + tot , cmp ) ;

    if( !tot ) printf( "-1\n" ) ;
    else
    {
        for( int i = 0 ; i < tot ; i ++ )
                         printf( "%s\n" , ans[ f[ i ] ] ) ;
    }

    return 0 ;
}
