#include <cstddef>    // for std::size_t
#include <exception>  // for std::exception
#include <iostream>
#include <limits>
#include <stdexcept>  // for std::runtime_error, std::range_error......
#include <string>     // for this example

class MyException : public std::exception {
   public:
    MyException(const std::string& message) : m_msg{message} {}
    virtual const char* what() const noexcept override { return m_msg.c_str(); }

   private:
    std::string m_msg{};
};

void rethrow() {
    try {
        // do something, get an exception
    } catch (const std::exception& exception) {
        // handle exception here
        throw;  // rethrow the exact same exception to the caller of rethrow()
    }
}

int main() {
    try {
        // Your code using standard library goes here
        // We'll trigger one of these exceptions intentionally for the sake of the example
        std::string s;
        s.resize(std::numeric_limits<std::size_t>::max());  // will trigger a std::length_error or allocation exception

        // Other standard library exception classes, all derived from std::exception
        throw std::runtime_error("This is a runtime error");
        throw std::range_error("This is a range error");
        throw MyException("My Exception");
    }
    // Catch MyException
    catch (const MyException& exception) {
        std::cerr << "Custom exception: " << exception.what() << "\n";
    }
    // This handler will catch std::length_error (and any exceptions derived from it) here
    catch (const std::length_error& exception) {
        std::cerr << "You ran out of memory!" << '\n';
    }
    // This handler will catch std::exception and all the derived exceptions too
    catch (const std::exception& exception) {
        std::cerr << "Standard exception: " << exception.what() << '\n';
    }

    return 0;
}