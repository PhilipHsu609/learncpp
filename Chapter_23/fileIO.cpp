#include <fstream>
#include <iostream>
#include <string>

namespace file {
    const std::string file_path{"./Data.txt"};
}

int main() {
    std::fstream ioFile{"./empty_file", std::ios::in | std::ios::out};  // For both reading and writing to file.
    std::ofstream outFile{file::file_path, std::ios::trunc};

    // std::ios::beg, std::ios::cur, std::ios::end
    // moving file pointer for random file access
    outFile.seekp(0, std::ios::beg);  // move to begining of file

    if (!outFile.is_open()) {
        std::cerr << "Open file failed! Abort." << std::endl;
        return -1;
    }

    outFile << "This is line 1." << std::endl;
    outFile << "This is line 2." << std::endl;

    outFile.close();  // We can manually close the file.
    // OR outFile goes out of scope, the destructor of ofstream will close the
    // file

    std::ifstream inFile{file::file_path};

    if (!inFile.is_open()) {
        std::cerr << "Open file failed! Abort." << std::endl;
        return -1;
    }

    // move the end of file
    inFile.seekg(0, std::ios::end);
    // get the absolute position of the file pointer
    std::cout << "File size: " << inFile.tellg() << " bytes." << std::endl;
    inFile.seekg(0, std::ios::beg);

    while (!inFile.eof()) {
        std::string str;
        std::getline(inFile, str);
        std::cout << str << std::endl;
    }

    inFile.close();  // Same as above.

    return 0;
}