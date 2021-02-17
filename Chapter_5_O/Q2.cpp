#include <bitset>
#include <iostream>

std::bitset<4> rotl(std::bitset<4> bits) {
    // std::bitset<4> res{0b0000};
    // for (size_t i = 0; i < bits.size() - 1; i++) {
    //     if (bits.test(i))
    //         res.set(i + 1);
    // }
    // res[0] = (bits.test(3) ? 1 : 0);
    // return res;

    bool lsb = bits.test(3);
    bits <<= 1;
    bits[0] = lsb ? 1 : 0;
    return bits;
}

int main() {
    std::bitset<4> bits1{0b0001};
    std::cout << rotl(bits1) << std::endl;

    std::bitset<4> bits2{0b1001};
    std::cout << rotl(bits2) << std::endl;

    return 0;
}