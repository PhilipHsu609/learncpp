#include <iostream>

class PoweredDevice {
   public:
    PoweredDevice(int power) {
        std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner : public PoweredDevice {
   public:
    Scanner(int scanner, int power)
        : PoweredDevice{power} {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer : public PoweredDevice {
   public:
    Printer(int printer, int power)
        : PoweredDevice{power} {
        std::cout << "Printer: " << printer << '\n';
    }
};

class Copier : public Scanner, public Printer {
   public:
    Copier(int scanner, int printer, int power)
        : Scanner{scanner, power}, Printer{printer, power} {
    }
};

int main() {
    Copier c{1, 2, 3};
    // create a Copier class object, this will end up with two copies of the PowerDevice class
    // one from Printer, and one from Scanner
    // Using virtual base class to let Printer and Scanner shared the same base class
    return 0;
}