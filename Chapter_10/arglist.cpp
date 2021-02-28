#include <cstdarg>
#include <iostream>
#include <string>

// ellipsis must be the last param
int sumOfList(int count, ...) {
    int sum{};

    // access the ellipsis through a va_list
    va_list list;

    // init va_list
    // first param: the list to init
    // second param: the last non-ellipsis param
    va_start(list, count);

    for (int i{0}; i < count; i++) {
        // use va_arg to get param out of ellipsis
        // first param: the va_list that using
        // second param: the type of the param
        sum += va_arg(list, int);
    }

    // cleanup the va_list
    va_end(list);
    return sum;
}

/* 
    Why ellipsis are dangerous: Type checking is suspended
    Why ellipsis are dangerous: ellipsis don’t know how many parameters were passed

    Solutions: 
        Method 1: Pass a length parameter
        Method 2: Use a sentinel value
        Method 3: Use a decoder string
*/

// Method 1, sumOfList is an example

// Method 2:
double findAvg(int first, ...) {
    int sum{first}, count{1};
    va_list list;

    va_start(list, first);

    while (true) {
        int arg{va_arg(list, int)};

        // -1 is the sentinel value
        if (arg == -1)
            break;

        sum += arg;
        count++;
    }

    va_end(list);

    return sum / static_cast<double>(count);
}

// Method 3
double findArg(std::string decoder, ...) {
    double sum{0};

    va_list list;
    va_start(list, decoder);

    int count{0};

    while (true) {
        char codeType{decoder[count]};

        // decode input string
        switch (codeType) {
            default:
            case '\0':
                va_end(list);
                return sum / count;
            case 'i':
                sum += va_arg(list, int);
                break;
            case 'd':
                sum += va_arg(list, double);
                break;
        }
        count++;
    }
}

int main(int argc, char** argv) {
    std::cout << sumOfList(5, 1, 2, 3, 4, 5) << std::endl;
    std::cout << findArg("iiidd", 1, 2, 3, 0.5, 6.5) << std::endl;
    return 0;
}