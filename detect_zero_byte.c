/*
Determine if a word has zero byte:

To determine if a word (a 32-bit or 64-bit integer) contains a zero byte (a byte where all 8 bits are 0), you can use a classic, highly optimized bitwise trick.


*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
Function to detect if a 32-bit word has a zero byte:

The magic relies on how subtraction behaves when a byte is zero:

    v - 0x01010101: Subtracting 1 from a byte that is 0x00 causes a underflow, turning it into 0xFF. 
    Crucially, this sets the highest bit (the MSB) of that byte to 1.

    ~v: We invert the original value because we only care about bytes that were originally zero.
    If a byte was 0x80, subtracting 1 makes it 0x7F (MSB becomes 0, but it wasn't a zero byte). Inverting v ensures we only match bytes whose MSBs were not already set.

    & 0x80808080: This masks out everything except the highest bit (the sign bit) of each of the 4 bytes. 
    If any of those bits are 1, a zero byte was detected.
*/
bool has_zero_byte(unsigned int v) {
    // The bitwise magic formula
    return ((v - 0x01010101) & ~v & 0x80808080) != 0;
}

bool hasZeroByteSimple(unsigned int x)
{
    if((x & 0x000000FF) == 0)
        return true;
    if((x & 0x0000FF00) == 0)
        return true;
    if((x & 0x00FF0000) == 0)
        return true;
    if((x & 0xFF000000) == 0)
        return true;

    return false;    
}

int main(void) {
    // Test cases (32-bit hex values representing 4 bytes each)
    unsigned int word1 = 0x12345678; // No zero bytes
    unsigned int word2 = 0x12005678; // Second byte is zero
    unsigned int word3 = 0x00345678; // First byte is zero
    unsigned int word4 = 0x12345600; // Last byte is zero

    printf("Word: 0x%08X -> Has zero byte? %s\n", word1, has_zero_byte(word1) ? "YES" : "NO");
    printf("Word: 0x%08X -> Has zero byte? %s\n", word2, has_zero_byte(word2) ? "YES" : "NO");
    printf("Word: 0x%08X -> Has zero byte? %s\n", word3, has_zero_byte(word3) ? "YES" : "NO");
    printf("Word: 0x%08X -> Has zero byte? %s\n", word4, has_zero_byte(word4) ? "YES" : "NO");

    return 0;
}   