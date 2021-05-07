#include <iostream>

class Base {
   public:
    Base() {}
};

class Derived : public Base {
   public:
    Derived() {}
};

void runGame() {
    throw Derived();
}

void saveState() {}

int main() {
    try {
        runGame();
    }
    // Derived exception class must catched before base exception class
    catch (const Derived &derived) {
        std::cerr << "Caught derived\n";
    }
    // Base class will be caught when fall through
    catch (const Base &base) {
        std::cerr << "Caught base\n";
    }
    // catch-all handler
    catch (...) {
        // catch unhandled exception, prevent main from terminating
        std::cerr << "Abnormal termination\n";
    }

    saveState();  // Save user's game
    return 0;
}