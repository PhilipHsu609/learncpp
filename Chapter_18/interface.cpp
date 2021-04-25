
// Interface for error log, class name starting with I
class IErrorlog {
   public:
    // pure virtual functions
    virtual bool openLog(const char *filename) = 0;
    virtual bool closeLog() = 0;
    virtual bool writeError(const char *errorMessage) = 0;
    // virtual destructor
    virtual ~IErrorlog() {}
};

// Derived classes from interface
class FileLog : public IErrorlog {
   public:
    virtual bool openLog(const char *filename) override {
        // open file log
    }
    virtual bool closeLog() override {
        // close file log
    }
    virtual bool writeError(const char *errorMessage) override {
        // write message to file log
    }
    virtual ~FileLog() {
        // destructor for file log
    }
};

class ScreenLog : public IErrorlog {
   public:
    virtual bool openLog(const char *filename) override {
        // open screen log
    }
    virtual bool closeLog() override {
        // close screen log
    }
    virtual bool writeError(const char *errorMessage) override {
        // write message to screen log
    }
    virtual ~ScreenLog() {
        // destructor for screen log
    }
};

#include <cmath>

// example using interface
double mySqrt(double value, IErrorlog &log) {
    if (value < 0.0) {
        log.writeError("Tried to take square root of value less than 0.");
        return 0.0;
    } else {
        return std::sqrt(value);
    }
}