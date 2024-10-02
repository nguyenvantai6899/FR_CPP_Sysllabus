# 1.Vector

#### Element Access Function

- at(index) : Access the element at the specified index
- front(): Access to the first element in the vector
- back(): Access to the last element in the vector

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v = {100, 200, 300, 400, 500};
    cout << "Duyet vector : \n";
    for(int i = 0; i < 5; i++){
        cout << v.at(i) << " "; // 100 200 300 400 500
    }
    cout << "\nPhan tu dau tien : " << v.front() << endl; // 100
    cout << "Phan tu cuoi cung : " << v.back() << endl; //500
}
```

#### Functions for size

- size() : returns the size of the vector
- empty() : returns the true if the vector is empty, otherwise returns false
- max_size() : returns the maximum size of the vector
- resize() : resizes the vector.

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v = {100, 200, 300, 400, 500};
    cout << "So luong phan tu : " << v.size() << endl; // 5
    cout << "Max size : " << v.max_size() << endl; //
    v.resize(3); // {100, 200, 300}
    cout << "So luong phan tu : " << v.size() << endl; // 3
    v.resize(0); // size = 0
    cout << "Vector rong : " << boolalpha << v.empty() << endl; // true
}
```

#### Add, Insert , Delete

- push_back(): add new element to the last vector
- emplace_back(): add new element to the last vector
- pop_back(): remove element from the last vector
- insert(): insert new element into the any location vector
- erase(): remove element from any location in the vector
- clear(): clear the vector
- assign(): assign values for elements in the vector
- swap(): swap the vector with the another vector

**_push_back(), emplace_back(), pop_back()_**

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v = {1, 2, 3};
    v.push_back(4);
    v.emplace_back(5);
    v.push_back(6);
    cout << "Duyet vector : \n";
    for(int x : v){
        cout << x << " "; // 1 2 3 4 5 6
    }
    v.pop_back();
    cout << "\nDuyet vector : \n";
    for(int x : v){
        cout << x << " "; // 1 2 3 4 5
    }
}
```

**_insert()_**

```cpp
iterator insert (iterator position, const value_type& val);
iterator insert (iterator position, size_type n, const value_type& val);
template <class InputIterator>
iterator insert (iterator position, InputIterator first, InputIterator last);

```

> 1.  insert (iterator position, const value_type& val)

```cpp
vector<int> v = {1, 2, 3, 5};
v.insert(v.begin() + 3, 4);  // Chèn số 4 vào vị trí thứ 3

```

> 2. insert (iterator position, size_type n, const value_type& val)

```cpp
vector<int> v = {1, 2, 3, 6};
v.insert(v.begin() + 3, 2, 4);  // Chèn hai số 4 vào vị trí thứ 3

```

> 3. insert (iterator position, InputIterator first, InputIterator last)

```cpp
vector<int> v1 = {1, 2, 3};
vector<int> v2 = {7, 8, 9};
v1.insert(v1.end(), v2.begin(), v2.end());  // Chèn các phần tử của v2 vào cuối v1

```

**_erase()_**

```cpp
iterator erase (iterator position); // delete a element from the vector
iterator erase (iterator first, iterator last); // delete a range of elements from the vector

```

> example

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50, 60};

    // Xóa phần tử 30
    v.erase(v.begin() + 2);

    // Xóa các phần tử từ vị trí 1 đến ngay trước vị trí 3 (tức là xóa 20, 40)
    v.erase(v.begin() + 1, v.begin() + 3);

    // In lại các phần tử sau khi xóa
    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}

```

**_clear()_**
delete all elements from the vector but not changed capacity

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    // In dung lượng ban đầu
    cout << "Dung lượng ban đầu: " << v.capacity() << endl;

    // Xóa các phần tử trong vector
    v.clear();

    // Dung lượng sau khi gọi clear()
    cout << "Dung lượng sau khi clear: " << v.capacity() << endl;

    // Thu nhỏ dung lượng cho khớp với size
    v.shrink_to_fit();

    // Dung lượng sau khi shrink_to_fit
    cout << "Dung lượng sau khi shrink_to_fit: " << v.capacity() << endl;

    return 0;
}

```

**_assign()_**

```cpp
void assign(size_type n, const T& val);

template <class InputIterator>
void assign(InputIterator first, InputIterator last);

```

> assign(size_type n, const T& val);

```cpp
   vector<int> v;

    // Gán 5 phần tử, mỗi phần tử có giá trị là 10
    v.assign(5, 10);

    // In các phần tử của vector
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
```

> assign(InputIterator first, InputIterator last);

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2;

    // Gán các phần tử từ v1 cho v2
    v2.assign(v1.begin(), v1.end());

    // In các phần tử của v2
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }

    return 0;
}

```

**_swap()_**

```cpp
vector_name1.swap(vector_name2);

```

# 2.Iterator

Iterators are objects that allow you to traverse through elements in various containers, such as arrays, vectors, sets, and maps (we'll look at sets and maps soon).

#### Declarations and initialization

- container_type: iterator it = container_begin();
- container_type: iterator it = container_end();

#### Iterating Through the Container

```cpp
vector<int> v = {1, 2, 3, 4, 5}
for (vector<int> iterator it = v.begin(); it != v.end(); ++it){
    cout << *it << endl;
}
```

#### Using auto with iterating

> **_Từ khoá auto:_**
> Từ khóa auto giúp tự suy luận ra kiểu dữ liệu phù hợp với biến thông qua giá trị bạn gán cho biến đó
> Sử dụng từ khóa auto, kiểu dữ liệu của biến sẽ được xác định lúc runtime thay vì compile-time như trước.

```cpp
#include <iostream>
#include "typeinfo"

using namespace std;

int main(){
   auto x = 100;
   auto y = 30.5f;
   auto z = '@';
   auto t = 1000000000000000;
   auto p = make_pair(10, 20);
   auto l = 30.5d;
   cout << "Kieu du lieu cua x : " << typeid(x).name() << endl; // i (integer)
   cout << "Kieu du lieu cua y : " << typeid(y).name() << endl; // f (float)
   cout << "Kieu du lieu cua z : " << typeid(z).name() << endl; // c (char)
   cout << "Kieu du lieu cua t : " << typeid(t).name() << endl; // x (long)
   cout << "Kieu du lieu cua p : " << typeid(p).name() << endl; // St4pairIiiE (pair)
   cout << "Kieu du lieu cua l : " << typeid(l).name() << endl; // d (double)
   return 0;
}
```

```cpp
   vector<int> vec = {1, 2, 3, 4, 5};

    // Using auto with iterator
    for (auto it = vec.begin(); it != vec.end(); ++it) {
      cout << *it << " "; // 1 2 3 4 5
    }


    // Using auto with range-based for loop
    for (auto& num : vec) {
        num *= 2; // Modify each element since iterator num is using reference
    }

    // Printing modified vector
    for (const auto& num : vec) {
        std::cout << num << " "; // 2 4 6 8 10
    }

```

#### Reverse Iterator

```cpp
 vector<int> vec = {1, 2, 3, 4, 5};

   // Using a reverse iterator to traverse the vector in reverse
   for(vector<int>:: reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it) {
      cout << *it << " "; // 5 4 3 2 1
   }
   // or with auto keyword
   for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
      cout << *it << " "; // 5 4 3 2 1
   }
```

```cpp
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int mul(int acc, int x)
{
    return acc * x;
}
int myop(int x, int y)
{
    return x + y;
}
int main()
{
    vector<int> arr = {2, 3, 5, 6, 7};
    vector<int> res(arr.size());
    vector<int> res_2(arr.size());

    partial_sum(arr.begin(), arr.end(), res.begin(), myop);

    // min and max
    auto min = std::min_element(arr.begin(), arr.end());
    auto max = std::max_element(arr.begin(), arr.end());

    int result = accumulate(res.begin(), res.end(), 1, mul);
    cout << *min << ": " << *max << endl;
    if (result % *min == 0 && result % *max == 0)
    {
        cout << result << " Yes!" << endl;
    }
    else
    {
        cout << result << " No!" << endl;
    }
}

```

**_replace()_**

```cpp
void replace(InputIterator first, InputIterator last, const T& old_value, const T& new_value);

```

- first, last: Đây là các iterator xác định phạm vi mà bạn muốn áp dụng việc thay thế (từ first đến last, không bao gồm last).
- old_value: Giá trị cần thay thế.
- new_value: Giá trị thay thế mới.

```cpp
std::vector<int> v = {1, 2, 3, 2, 4, 2, 5};

    std::replace(v.begin(), v.end(), 2, 10);

    for (int x : v) {
        std::cout << x << " "; // 1, 10, 3, 10, 4, 10, 5
    }
```

**_merge()_**

```cpp
template <class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator merge(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, InputIterator2 last2,
                     OutputIterator result);

```

- first1, last1: Iterator xác định phạm vi đầu tiên đã được sắp xếp.
- first2, last2: Iterator xác định phạm vi thứ hai đã được sắp xếp.
- result: Iterator cho vị trí bắt đầu của nơi kết quả hợp nhất sẽ được lưu.

```cpp
std::vector<int> v1 = {1, 3, 5, 7};
    std::vector<int> v2 = {2, 4, 6, 8};
    std::vector<int> v3(v1.size() + v2.size());  // Container để chứa kết quả hợp nhất

    // Hợp nhất hai vector v1 và v2
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    // In ra các phần tử sau khi hợp nhất
    for (int x : v3) {
        std::cout << x << " ";
    }

```

> Hàm merge() yêu cầu hai dãy đầu vào phải được sắp xếp trước. Nếu không, kết quả sẽ không đúng.

# 3.Algorithm

#### sorting

**_sort(first_iterator, last_iterator)_**

- sắp xếp vector đã cho theo thứ tự tăng dần.

**_sort(first_iterator, last_iterator, greater<int>())_**

- sắp xếp theo thứ tự giảm dần.

**_reverse(first_iterator, last_iterator)_**

- đảo ngược 1 vector

**_nth_element(start_iterator, nth_position_iterator, end_iterator);_**

- thay vì sắp xếp toàn bộ container, nó chỉ sắp xếp sao cho phần tử thứ n (theo thứ tự) đứng đúng vị trí của nó trong container. Tất cả các phần tử trước phần tử thứ n sẽ nhỏ hơn hoặc bằng phần tử đó, và tất cả các phần tử sau phần tử thứ n sẽ lớn hơn hoặc bằng phần tử đó.

```cpp
std::vector<int> arr = {10, 4, 2, 15, 23, 7, 5};

    // Sắp xếp sao cho phần tử thứ 3 (tính từ 0) đứng đúng vị trí
    std::nth_element(arr.begin(), arr.begin() + 3, arr.end());
    // Mảng sau khi gọi nth_element: 4 2 5 7 23 15 10
```

**_nth_element(start_iterator, middle_iterator, end_iterator);_**

- Nó sẽ sắp xếp các phần tử từ vị trí bắt đầu đến một vị trí cụ thể trong container theo thứ tự tăng dần hoặc giảm dần, trong khi các phần tử sau vị trí đó có thể không cần được sắp xếp.

- Sắp xếp phạm vi từ first đến middle theo thứ tự tăng dần.
- Các phần tử từ middle đến last không nhất thiết phải được sắp xếp, nhưng chúng sẽ lớn hơn hoặc bằng các phần tử trước đó.

```cpp
    vector<int> arr = {7, 3, 9, 4, 1, 5, 8, 6, 2};

    // Sắp xếp 5 phần tử đầu tiên của mảng theo thứ tự tăng dần
    partial_sort(arr.begin(), arr.begin() + 5, arr.end());
    // cout : 1 2 3 4 5 9 8 6 7
```

**_accumulate(first_iterator, last_iterator, giá trị ban đầu của tổng)_**

- tổng các phần tử vector

```cpp

```

#### Searching

**_count(first_iterator, last_iterator,x)_**

- Đếm số lần xuất hiện của x trong vector.

**_find(first_iterator, last_iterator, x)_**

- trả về một iterator trỏ đến phần tử đầu tiên khớp với giá trị cần tìm. Nếu không tìm thấy phần tử nào có giá trị tương ứng, hàm sẽ trả về iterator trỏ đến phần tử ngay sau phần tử cuối cùng của phạm vi tìm kiếm (thường được biểu diễn bằng .end()

```cpp
auto it = find(arr.begin(), arr.end(), 23);

    if (it != arr.end()) {
        cout << "Phần tử 23 được tìm thấy tại vị trí: " << distance(arr.begin(), it) << endl;
    } else {
        cout << "Phần tử 23 không tồn tại trong mảng." << endl;
    }
```

**_bool binary_search(ForwardIterator first, ForwardIterator last, const T& value);_**

> Hàm binary_search chỉ hoạt động chính xác khi dãy các phần tử đã được sắp xếp theo thứ tự tăng dần.

```cpp
 vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};

    // Tìm kiếm giá trị 7
    if (binary_search(arr.begin(), arr.end(), 7)) {
        cout << "Found 7 in the array." << endl;
    } else {
        cout << "7 is not in the array." << endl;
    }
```

**_ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& value);_**

- Trả về iterator trỏ đến phần tử đầu tiên trong phạm vi (first, last) mà không nhỏ hơn value.
- Nếu không có phần tử nào trong phạm vi đó thỏa mãn điều kiện, trả về last.

> Phạm vi được chỉ định phải được sắp xếp theo thứ tự tăng dần để hàm lower_bound hoạt động chính xác.

```cpp
vector<int> arr = {10, 20, 30, 40, 50};

    // Tìm vị trí đầu tiên không nhỏ hơn 35
    auto it = lower_bound(arr.begin(), arr.end(), 35);

    if (it != arr.end()) {
        cout << "The first element greater than or equal to 35 is " << *it << endl;
    } else {
        cout << "All elements are smaller than 35." << endl;
    }

    // cout : The first element greater than or equal to 35 is 40
    // it = 40

```

**_ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, const T& value);_**

- Trả về iterator trỏ đến phần tử đầu tiên trong phạm vi (first, last) mà lớn hơn value.
- Nếu không có phần tử nào thỏa mãn điều kiện, trả về last.

```cpp
vector<int> arr = {10, 20, 30, 40, 50};

    // Tìm vị trí đầu tiên lớn hơn 30
    auto it = upper_bound(arr.begin(), arr.end(), 30);

    if (it != arr.end()) {
        cout << "The first element greater than 30 is " << *it << endl;
    } else {
        cout << "No element is greater than 30." << endl;
    }
```

#### Manipulation

**_OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result);_**

- first: Iterator trỏ đến phần tử đầu tiên trong phạm vi cần sao chép.
- last: Iterator trỏ đến phần tử ngay sau phần tử cuối cùng trong phạm vi cần sao chép.
- result: Iterator trỏ đến vị trí bắt đầu nơi các phần tử được sao chép tới.

> Đảm bảo vùng đích (nơi các phần tử được sao chép tới) có đủ kích thước để chứa các phần tử được sao chép, nếu không sẽ dẫn đến hành vi không xác định (undefined behavior).

```cpp
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2(5);  // Mảng đích để chứa các phần tử sau khi sao chép

    // Sao chép các phần tử từ v1 sang v2
    copy(v1.begin(), v1.end(), v2.begin());
    // cout v2 = {1, 2, 3, 4, 5};
```

**_void iota(ForwardIterator first, ForwardIterator last, T value);_**

- first: Iterator trỏ đến phần tử đầu tiên của phạm vi cần điền giá trị.
- last: Iterator trỏ đến phần tử ngay sau phạm vi cần điền giá trị.
- value: Giá trị bắt đầu, từ giá trị này các giá trị tiếp theo sẽ được tăng dần lên.

```cpp
    vector<int> v(5);

    // Điền giá trị vào vector bắt đầu từ 10
    iota(v.begin(), v.end(), 10);
    // cout : 10 11 12 13 14

```

**_void fill(ForwardIterator first, ForwardIterator last, const T& value);_**

- fill() sẽ gán giá trị value cho tất cả các phần tử trong phạm vi (first, last).
- Nó không trả về giá trị nào (void function)

```cpp
    vector<int> v(10); // Tạo vector có 10 phần tử

    // Sử dụng fill để gán giá trị 5 cho tất cả phần tử
    fill(v.begin(), v.end(), 5);
    //cout :5 5 5 5 5 5 5 5 5 5

```

#### Permutation

**_bool next_permutation(BidirectionalIterator first, BidirectionalIterator last);_**

- next_permutation() sẽ hoán đổi các phần tử của phạm vi (first, last) thành hoán vị tiếp theo theo thứ tự từ điển.
- Nếu không có hoán vị nào lớn hơn (đã ở hoán vị cuối cùng), nó sẽ sắp xếp các phần tử theo thứ tự tăng dần và trả về false.

```cpp
    vector<int> v = {1, 2, 3};

    do {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
    /*cout  1 2 3
            1 3 2
            2 1 3
            2 3 1
            3 1 2
            3 2 1 */

```

**_bool prev_permutation(BidirectionalIterator first, BidirectionalIterator last);_**

- Ngược lại của next_permutation()

#### Minimum and Maximum

**_\*max_element(first_iterator, last_iterator)_**

- Trả về iterator trỏ đến phần tử lớn nhất trong phạm vi (first_iterator, last_iterator).
- Nếu có nhiều phần tử lớn nhất, nó trả về iterator trỏ đến phần tử đầu tiên gặp phải.

**_\*min_element(first_iterator, last_iterator)_**

- Trả về iterator trỏ đến phần tử nhỏ nhất trong phạm vi (first_iterator, last_iterator).
- Nếu có nhiều phần tử nhỏ nhất, nó trả về iterator trỏ đến phần tử đầu tiên gặp phải.

```cpp
 vector<int> v = {10, 20, 5, 23, 42, 15};

    // Tìm phần tử lớn nhất
    auto max_it = max_element(v.begin(), v.end());
    cout << "Phan tu lon nhat: " << *max_it << endl;

    // Tìm phần tử nhỏ nhất
    auto min_it = min_element(v.begin(), v.end());
    cout << "Phan tu nho nhat: " << *min_it << endl;

    //cout Phan tu lon nhat: 42 ; Phan tu nho nhat: 5

```
