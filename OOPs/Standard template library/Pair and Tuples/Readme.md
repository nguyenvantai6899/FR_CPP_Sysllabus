# Pair

#### Khai bao

- Sử dụng constructor trực tiếp: pair<int, string> p1(1, "one");
- Sử dụng make_pair: pair<int, string> p1 = make_pair(1, "one");

#### Truy cập

- first: Truy cập giá trị đầu tiên.
- second: Truy cập giá trị thứ hai.

#### Gán cập

- Có thể gán giá trị từ một cặp khác cùng kiểu: pair<int, string> p2 = p1

**_ex_**

```cpp
#include <iostream>
#include <utility>
using namespace std;

int main() {
    // Khởi tạo một cặp với int và string
    pair<int, string> p1 = make_pair(100, "John");

    // Truy cập phần tử của pair
    cout << "ID: " << p1.first << ", Name: " << p1.second << endl;

    // Tạo một cặp khác với hai kiểu dữ liệu khác nhau
    pair<string, double> p2 = make_pair("Apple", 10.5);

    // Truy cập giá trị
    cout << "Product: " << p2.first << ", Price: $" << p2.second << endl;

    // Gán giá trị từ một cặp khác
    pair<int, string> p3;
    p3 = p1;

    cout << "ID: " << p3.first << ", Name: " << p3.second << endl;

    return 0;
}

```

**_pair lồng nhau_**

```cpp
#include <iostream>
#include <utility>  // Để sử dụng std::pair
using namespace std;

int main() {
    // Tạo một cặp lồng nhau
    pair<int, pair<string, float>> nested_pair = make_pair(1, make_pair("Apple", 9.99));

    // Truy cập các giá trị
    cout << "ID: " << nested_pair.first << endl;          // Phần tử đầu tiên (kiểu int)
    cout << "Product: " << nested_pair.second.first << endl;  // Phần tử thứ hai (cặp thứ hai, kiểu string)
    cout << "Price: $" << nested_pair.second.second << endl;  // Phần tử thứ ba (kiểu float)

    return 0;
}

```

# Tuple

#### Cú pháp

```cpp
#include <iostream>
#include <tuple>  // Thư viện để sử dụng tuple

using namespace std;

int main() {
    // Tạo một tuple với các kiểu dữ liệu khác nhau
    tuple<int, string, float> my_tuple = make_tuple(1, "Laptop", 1200.50);

    // Truy cập các phần tử trong tuple
    cout << "ID: " << get<0>(my_tuple) << endl;        // Phần tử thứ nhất (kiểu int)
    cout << "Product: " << get<1>(my_tuple) << endl;   // Phần tử thứ hai (kiểu string)
    cout << "Price: $" << get<2>(my_tuple) << endl;    // Phần tử thứ ba (kiểu float)

    return 0;
}
    /*
    ID: 1
    Product: Laptop
    Price: $1200.5
    */
```

1. Truy cập
   get<index>(tuple) để truy cập phần tử tại chỉ số index trong tuple.

```cpp
cout << get<0>(my_tuple);  // Truy cập phần tử thứ nhất

```

2. Khởi tạo
   make_tuple dùng để khởi tạo tuple với nhiều kiểu dữ liệu khác nhau.

```cpp
auto my_tuple = make_tuple(1, "Laptop", 1200.50);

```

3. số lượng phần tử
   tuple_size<decltype(tuple_variable)>::value để lấy số lượng phần tử trong tuple.

```cpp
cout << "Size of tuple: " << tuple_size<decltype(my_tuple)>::value << endl;

```

4. so sánh

```cpp
tuple<int, string, float> tuple1 = make_tuple(1, "Laptop", 1200.50);
tuple<int, string, float> tuple2 = make_tuple(1, "Laptop", 1200.50);

if (tuple1 == tuple2) {
    cout << "The tuples are equal." << endl;
}

```

5. gán giá trị

```cpp
int id;
string product;
float price;

tie(id, product, price) = my_tuple;

cout << "ID: " << id << ", Product: " << product << ", Price: $" << price << endl;

```

6. cập nhập giá trị
   get<index>() để gán giá trị mới.

```cpp
get<1>(my_tuple) = "Smartphone";  // Cập nhật sản phẩm

```

7. tuple_cat()
   tuple_cat() dùng để gộp nhiều tuple lại với nhau.

```cpp
tuple<int, string> t1 = make_tuple(1, "Apple");
tuple<float, char> t2 = make_tuple(5.5, 'A');

auto result = tuple_cat(t1, t2);  // Gộp t1 và t2 thành một tuple

cout << get<0>(result) << ", " << get<1>(result) << ", " << get<2>(result) << ", " << get<3>(result) << endl;

// 1, Apple, 5.5, A

```
