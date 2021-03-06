/*--> Brian Kernighan’s Algorithm
Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit.
for example :
10 in binary is 00001010
9 in binary is 00001001
8 in binary is 00001000
7 in binary is 00000111
So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)), we unset the rightmost set bit. If we do n & (n-1) in a loop and count the no of times loop executes we get the set bit count.
The beauty of this solution is the number of times it loops is equal to the number of set bits in a given integer.

1  Initialize count: = 0
   2  If integer n is not zero
      (a) Do bitwise & with (n-1) and assign the value back to n
          n: = n&(n-1)
      (b) Increment count by 1
      (c) go to step 2
   3  Else return count
   */
   
// C++ program to Count set 
// bits in an integer 
#include <iostream> 
using namespace std; 
class gfg { 
	/* Function to get no of set bits in binary 
representation of passed binary no. */
public: 
	unsigned int countSetBits(int n) 
	{ 
		unsigned int count = 0; 
		while (n) { 
			n &= (n - 1); // n << 1 can be used too
			count++; 
		} 
		return count; 
	} 
}; 
/* Program to test function countSetBits */
int main() 
{ 
	gfg g; 
	int i = 9; 
	cout << g.countSetBits(i); 
	return 0; 
} 
