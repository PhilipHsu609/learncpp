#include <iostream>

// enum class makes it storngly typed and strongly scoped (Color::something)
// compiler will no longer implicitly convert enum to int
enum class Color {
    red,
    yellow,
    blue,
    black,
    white
};

enum class Fruit {
    apple,
    banana,
    pineapple
};

int main() {
    Color bg{Color::black}; // strongly scoped
    Fruit f{Fruit::apple};

    bool isFalse = (bg == f); // compile error, strongly typed
    bool isTrue = (bg == Color::black); // it's fine

    std::cout << bg; // nope, compile error
    std::cout << static_cast<int>(bg); // it's fine

    return 0;
}