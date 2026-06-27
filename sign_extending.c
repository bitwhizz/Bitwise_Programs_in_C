/*
Sign extending from a bit-width:

Sign extension is automatic for built-in types, such as chars and ints. But suppose you have a signed two's complement number, x, that is stored using only b bits. 
Moreover, suppose you want to convert x to an int, which has more than b bits. A simple copy will work if x is positive, but if negative, the sign must be extended.
For example, if we have only 4 bits to store a number, then -3 is represented as 1101 in binary.
If we have 8 bits, then -3 is 11111101. The most-significant bit of the 4-bit representation is replicated sinistrally to fill in the destination when we convert to a representation with more bits; this is sign extending.
In C, sign extension from a constant bit-width is trivial, since bit fields may be specified in structs or unions.

int x; // convert this from using 5 bits to a full int
int r; // resulting sign extended number goes here
struct {signed int x:5;} s;
r = s.x = x;

Sometimes we need to extend the sign of a number but we don't know a priori the number of bits, b, in which it is represented.

Dynamic double shift (Fastest on Modern Hardware):
Shifts the target bit to the most significant bit (MSB) position of a signed container and right shifts it back.
*/

#include<stdio.h>

struct sign_struct{volatile signed int x:5;volatile signed int b:27;} s;

signed int sign_extend(struct sign_struct s,unsigned int b)
{
    int r = 0;
    //b = bit-width (EX : 5 for 5-bit integer)
    if(b >= sizeof(s)*__CHAR_BIT__) return (signed int )s.x;

    int const shift = __CHAR_BIT__ * sizeof(s) - b;
    r = (s.x << shift) >> shift;

    return r;
}

int main(void)
{
    int r; // resulting sign extended number goes here
    r = s.x = -5;
    s.b = 0;

    printf("signed bit field number s.x is %d\n",s.x);
    printf("signed bit field number s.b is %d\n",s.b);
    printf("size of sign_struct is %ld\n",sizeof(s));

    signed int result =  sign_extend(s,5);

    printf("full signed number is %d\n",result);

    return 0;
}

/*
(gdb) p/t s
$4 = {x = 11111111111111111111111111111011, b = 0}
(gdb) p/x s
$5 = {x = 0xfffffffb, b = 0x0}
(gdb) p/t s.x
$6 = 11111111111111111111111111111011
(gdb) p/t (unsigned int)s.x
$7 = 11111111111111111111111111111011
(gdb) ptype s
type = struct sign_struct {
    volatile int x : 5;
    volatile int b : 27;
}
(gdb) p/t s.x & 0x1f
$8 = 11011
*/