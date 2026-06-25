#include <stdio.h>


/*
That macro is a classic bit of C "wizardry" found all over the Linux kernel.
 It’s the standard way to perform integer division that always rounds up to the nearest whole number.
 
In standard C integer division, the fractional part is simply truncated (it rounds toward zero). 
While that's fine for some logic, it’s a headache when you’re calculating things like "How many memory pages do I need for X bytes?" 
where even one extra byte requires a whole new page.


Example:
Imagine you are writing a driver and need to figure out how many 4096-byte blocks are needed to store 5000 bytes of data.

Standard Division: 5000 / 4096 results in 1. 

Your data gets cut off.

Using the Macro:n=5000,d=4096Formula:
 ((5000)+(4096)−1)/4096
Result: 9095/4096=2
You successfully allocate two blocks and nothing is lost.

*/

#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))

/*
If you had the input 0xFFFF (all 16 bits set):
Pairs: The first line res - (res >> 1) & 0x5555 turns every binary 11 into 10 (which is 2 in decimal).
 Now you have eight "2s" stored in 2-bit fields.
Nibbles: The next line adds those 2-bit counts together. 
Now you have four "4s" stored in 4-bit fields.

Bytes: It adds the nibbles. 
Now you have two "8s" stored in 8-bit fields.
Final Sum: It adds the high byte to the low byte. 8+8=16.
*/

unsigned int hweight16(unsigned int w)
{
	unsigned int res = w - ((w >> 1) & 0x5555);
	res = (res & 0x3333) + ((res >> 2) & 0x3333);
	res = (res + (res >> 4)) & 0x0F0F;
	return (res + (res >> 8)) & 0x00FF;
}

/*
 * bitmap consists of blocks filled with 16bit words
 * bit set == busy, bit clear == free
 * endianness is a mess, but for counting zero bits it really doesn't matter...
 */
unsigned int count_free(char *b_data, unsigned blocksize, unsigned int numbits)
{
	unsigned int sum = 0;
	unsigned blocks = DIV_ROUND_UP(numbits, blocksize * 8);

	while (blocks--) {
		unsigned words = blocksize / 2;
		unsigned short int *p = (unsigned short int *)(b_data++);
		while (words--)
			sum += 16 - hweight16(*p++);
	}

	return sum;
}


int main(void)
{
	char *b_data = {"fdhvikfhfbfdlhlofdhlipkgfhglfsghidfgihfdgfdlogdhghdlsgddgkhshgos"};

	printf("no of free blocks = %d \n",count_free(b_data,12,40));

return 0;
}
