#include <bitset>
#include <iostream>

int main() {
    std::bitset<8> bits{0b0000'0101};
    bits.set(3);    // set bit position 3
    bits.flip(4);   // flip bit 4
    bits.reset(4);  // set bit 4 to 0

    std::cout << "All the bits: " << bits << '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';  // get bit position 3
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';  // get bit position 4

    return 0;
}