#include <iostream>

namespace foo {
    int x;
}

namespace bar {
    int y;
}

// inline namespace, act like global namespace, useful for version control
inline namespace v1 {
    void goo() {}
}
namespace v2 {
    void goo() {}
}

// anonymous namespace, same as global namespace
namespace {
    void koo() {}
}

int main() {
    {
        using namespace foo;
        // call foo:: here
    }  // namespace foo expired

    {
        using namespace bar;
        // call bar:: here
    }  // namespace bar expired

    v1::goo();
    v2::goo();

    goo();  // call inline version

    return 0;
}