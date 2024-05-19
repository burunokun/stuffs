### Invert BITS
To simply invert bits use `~` operator
```c
int main(void) {
    uint8_t b = 0b11111111; // == 0b00000000000000000000000011111111
    ~b;                     // ~~ 0b11111111111111111111111100000000
    return 0;
}
```

---

### Reverse BITS
To reverse the bits, you must extract bit by bit from right to left and `or` it left to right.

- Extract `rightmost` bit
- Shift and or it to `leftmost` bit
- Shift right the result by one
- Repeat and rinse

```c
/*
 * n      = 0b11111111111111111111111111111101
 * return = 0b10111111111111111111111111111111
*/
uint32_t reverseBit(uint32_t n) {
    // return var zero initialized
    uint32_t reversed = 0;

    // for loop to iterate through all the bits of 'n'
    // 32 is the total amount of bits 4 bytes can hold
    for (size_t i = 0; i < 32; ++i) {
        // extract rightmost bit from 'n'
        uint32_t bit = n & 1;
        // set bits left to right on each iteration or'ing current bit
        // rev = 0b00000000000000000000000000000000 | bit = 1 << 31 - 0
        // rev = 0b10000000000000000000000000000000 | bit = 0 << 31 - 1
        // rev = 0b10100000000000000000000000000000 | bit = 1 << 31 - 2
        // ...
        reversed |= bit << (31 - i);
        // right shift 'n' by one to extract next bit
        // n = 0b11111111111111111111111111111101
        // n = 0b1111111111111111111111111111110
        // n = 0b111111111111111111111111111111
        // ...
        n >>= 1;
    }

    // reversed = 0b10111111111111111111111111111111
    return reversed;
}
```