/*
Determine if a word has a byte equal to n :

We may want to know if any byte in a word has a specific value.
 To do so, we can XOR the value to test with a word that has been filled with the byte values in which we're interested. 
Because XORing a value with itself results in a zero byte and nonzero otherwise, we can pass the result to haszero
*/

#include <stdio.h>

/*  Explaining Marcro haszero:

    v - 0x01010101: Subtracting 1 from a byte that is 0x00 causes a underflow, turning it into 0xFF. 
    Crucially, this sets the highest bit (the MSB) of that byte to 1.

    ~v: We invert the original value because we only care about bytes that were originally zero.
    If a byte was 0x80, subtracting 1 makes it 0x7F (MSB becomes 0, but it wasn't a zero byte). Inverting v ensures we only match bytes whose MSBs were not already set.

    & 0x80808080: This masks out everything except the highest bit (the sign bit) of each of the 4 bytes. 
    If any of those bits are 1, a zero byte was detected.
*/
#define haszero(v) (((v) - 0x01010101UL) & ~(v) & 0x80808080UL)

//XOR the word with the mask(~0UL/255 * (n)) to turn matching bytes into 0x00
#define hasvalue(x,n) \
(haszero((x) ^ (~0UL/255 * (n)/*Broadcast 'n' across all 8 bytes*/)))

int main(void) {
    // Test cases (32-bit hex values representing 4 bytes each)
    unsigned int word = 0x12345678; // No zero bytes
    char byte = 0x34;

    printf("Word: 0x%08X -> Has 0x%x byte? %s\n", word,byte, hasvalue(word,byte) ? "YES" : "NO");

    return 0;
}   