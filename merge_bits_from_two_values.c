#include <stdio.h>

// Function to print a byte in binary format for easy visualization
void print_binary(const char* label, unsigned int num) {
    printf("%-8s: ", label);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf(" (0x%02X)\n", num);
}

int main() {
    // Input values
    //value to merge in non-masked bits
    unsigned int a    = 0xAAAAAAAA; // 10101010101010101010101010101010
    //value to merge in masked bits
    unsigned int b    = 0xCC; // 11001100
    //1 where bits from b should be selected ; 0 where from a
    unsigned int mask = 0xF0; // 11110000 (Take upper 4 bits from b, lower 4 from a)

    // Apply the bit-merge formula
    // (a & ~mask) keeps bits of 'a' where mask is 0
    // (b & mask)  keeps bits of 'b' where mask is 1
    unsigned int result = a ^ ((a ^ b) & mask);

    // Display the results
    printf("--- Bit Merging Demonstration ---\n");
    print_binary("Value A", a);
    print_binary("Value B", b);
    print_binary("Mask", mask);
    printf("---------------------------------\n");
    print_binary("Result", result);

    return 0;
}

/*
--- Bit Merging Demonstration ---
Value A : 10101010101010101010101010101010 (0xAAAAAAAA)
Value B : 00000000000000000000000011001100 (0xCC)
Mask    : 00000000000000000000000011110000 (0xF0)
---------------------------------
Result  : 10101010101010101010101011001010 (0xAAAAAACA)
*/