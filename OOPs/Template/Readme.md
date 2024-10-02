# Template function

```cpp
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add<int>(3, 4) << endl;     // Sử dụng template với kiểu int
    cout << add<double>(2.5, 4.7) << endl; // Sử dụng template với kiểu double
    return 0;
}

```

# Template class

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Box {
private:
    T value;
public:
    Box(T v) : value(v) {}

    T getValue() {
        return value;
    }
};

int main() {
    Box<int> intBox(123);         // Sử dụng template với kiểu int
    Box<string> stringBox("Hello"); // Sử dụng template với kiểu string

    cout << "intBox: " << intBox.getValue() << endl;
    cout << "stringBox: " << stringBox.getValue() << endl;

    return 0;
}

```
