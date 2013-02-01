// BEGIN CUT HERE
// PROBLEM STATEMENT
// ***Note:  Please keep programs under 7000 characters in length.  Thank you


Class Name: HowEasy
Method Name: pointVal
Parameters: String
Returns: int
 
TopCoder has decided to automate the process of assigning problem difficulty
levels to problems.  TopCoder developers have concluded that problem difficulty
is related only to the Average Word Length of Words in the problem statement:

If the Average Word Length is less than or equal to 3,  the problem is a 250
point problem.
If the Average Word Length is equal to 4 or 5, the problem is a 500 point
problem.
If the Average Word Length is greater than or equal to 6, the problem is a 1000
point problem.
 
Definitions:
Token - a set of characters bound on either side by spaces, the beginning of
the input String parameter or the end of the input String parameter.
Word - a Token that contains only letters (a-z or A-Z) and may end with a
single period. A Word must have at least one letter.
Word Length - the number of letters in a Word. (NOTE: a period is NOT a letter)

The following are Words :
"ab",  "ab."

The following are not Words :
"ab..", "a.b", ".ab", "a.b.", "a2b.", "."

Average Word Length - the sum of the Word Lengths of every Word in the problem
statement divided by the number of Words in the problem statement.  The
division is integer division. If the number of Words is 0, the Average Word
Length is 0.
 
Implement a class HowEasy, which contains a method pointVal.  The method takes
a String as a parameter that is the problem statement and returns an int that
is the point value of the problem (250, 500, or 1000). The problem statement
should be processed from left to right.
 
Here is the method signature (be sure your method is public):
int pointVal(String problemStatement);
 
problemStatement is a String containing between 1 and 50 letters, numbers,
spaces, or periods.  TopCoder will ensure the input is valid.
 
Examples:
 
If problemStatement="This is a problem statement", the Average Word Length is
23/5=4, so the method should return 500.
If problemStatement="523hi.", there are no Words, so the Average Word Length is
0, and the method should return 250.
If problemStatement="Implement a class H5 which contains some method." the
Average Word Length is 38/7=5 and the method should return 500.
If problemStatement=" no9 . wor7ds he8re. hj.." the Average Word Length is 0,
and the method should return 250.


DEFINITION
Class:HowEasy
Method:pointVal
Parameters:string
Returns:int
Method signature:int pointVal(string param0)

// END CUT HERE
#line 72 "HowEasy.cpp"
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<iostream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
int i,j,k,a,m,n,s,t,l,tt,f[60][60][2];
char tmp,str[500];
float f1,f2;
class HowEasy {
	public:
	int pointVal(string param0) {
		
	}
}temp;
