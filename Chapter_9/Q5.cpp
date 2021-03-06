
// (a) ----------------------------------------------------------------------

int mainA() {
    int array[]{0, 1, 2, 3};

    for (std::size_t count{0}; count < std::size(array); ++count) {
        std::cout << array[count] << ' ';
    }

    std::cout << '\n';

    return 0;
}

//---------------------------------------------------------------------------

// (b) ----------------------------------------------------------------------

int mainB() {
    int x{5};
    int y{7};

    int* ptr{&x};
    std::cout << *ptr << '\n';
    *ptr = 6;
    std::cout << *ptr << '\n';
    ptr = &y;
    std::cout << *ptr << '\n';

    return 0;
}

//---------------------------------------------------------------------------

// (c) ----------------------------------------------------------------------

void printArray(int array[], int len) {
    for (std::size_t i{0}; i < len; i++) {
        std::cout << array[i] << ' ';
    }
}

int mainC() {
    int array[]{9, 7, 5, 3, 1};

    printArray(array, 5);

    std::cout << '\n';

    return 0;
}

//---------------------------------------------------------------------------

// (d) ----------------------------------------------------------------------

int* allocateArray(const int length) {
    int* temp{new int[length]{}};
    return temp;
}

//---------------------------------------------------------------------------

// (e) ----------------------------------------------------------------------

int main() {
    double d{5.5};
    double* ptr{&d};
    std::cout << ptr << '\n';

    return 0;
}

//---------------------------------------------------------------------------