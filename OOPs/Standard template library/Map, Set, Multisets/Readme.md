# Map

- Các phần tử được sắp xếp: map sắp xếp các phần tử theo thứ tự khóa.
- Khóa duy nhất: Mỗi khóa trong map là duy nhất. Nếu thêm phần tử với khóa đã tồn tại, giá trị cũ sẽ bị ghi đè.
- Hiệu suất: map dựa trên cấu trúc cây nhị phân cân bằng, nên các thao tác tìm kiếm, thêm, xóa có độ phức tạp trung bình là O(log n).

1. Khai bao , khoi tao

```cpp

map<KeyType, ValueType> map_name;
```

2. thêm phần tử vào map

```cpp
my_map.insert(pair<int, string>(4, "Four"));
my_map.insert(make_pair(5, "Five"));

```

hoặc

```cpp
map[key] = value
```

3. truy cap gia tri
   thông qua khoá

```cpp
cout << my_map[1];  // In ra giá trị tương ứng với khóa 1

```

4. duyệt các phần tử trong map

```cpp
for (auto &entry : my_map) {
    cout << "Key: " << entry.first << ", Value: " << entry.second << endl;
}

```

5. tìm kiếm

```cpp
auto it = my_map.find(2);
if (it != my_map.end()) {
    cout << "Found: " << it->second << endl;
} else {
    cout << "Not found!" << endl;
}

```

6. xoá phần tử

```cpp
my_map.erase(3);  // Xóa phần tử có khóa là 3

```

7. kiểm tra kích thước

```cpp
cout << "Size of map: " << my_map.size() << endl;

```

8. kiểm tra rỗng

```cpp
if (my_map.empty()) {
    cout << "The map is empty." << endl;
} else {
    cout << "The map is not empty." << endl;
}

```

```cpp
    // đếm tần suất xuất hiện của mảng kí tự
    vector<string> s = {"a", "b", "c", "d", "d", "a", "a"};
    map<string, int> freq; // giá trị mặc định của int = 0
    for (string &c : s)
    {
        freq[c] = freq[c] + 1; // 0 + 1
    }
    cout << freq.size() << endl;
    for (auto &it : freq)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
```

# unordered_map

Tương tự map nhưng sắp xếp không theo thứ tự

# Set

- Phần tử duy nhất: Mỗi phần tử trong set là duy nhất, không có phần tử trùng lặp.
- Sắp xếp tự động: Phần tử trong set được sắp xếp tự động theo thứ tự tăng dần.
- Tìm kiếm nhanh: set sử dụng cấu trúc dữ liệu cây đỏ-đen, cho phép tìm kiếm, chèn và xóa với độ phức tạp trung bình là O(log n).
- Không có chỉ số: Bạn không thể truy cập phần tử bằng chỉ số, thay vào đó, bạn có thể duyệt qua set bằng iterator.

**_ex_**

```cpp
set <int> s1{1, 2, 3}, s2{1, 2, 2, 3};
if (s1 == s2) cout << “Yes” << endl;
else cout << “No” << endl; //YES

// Vì các bộ chỉ lưu trữ các phần tử duy nhất nên 2 lặp lại sẽ không thực sự được thêm vào s2. Do đó, s1 và s2 giống hệt nhau.
```

```cpp
// in ra phần tử trùng của 2 mảng
    vector<int> arr1 = {2, 6, 2, 9, 6};
    vector<int> arr2 = {2, 3, 6, 8};

    set<int> set1(arr1.begin(), arr1.end());
    set<int> set2(arr2.begin(), arr2.end());

    for (auto &s1 : set1)
    {
        if (set2.find(s1) != set2.end()) // tìm kiếm s1 trong s2
        {
            cout << s1 << " ";
        }
    }
    return 0;
```

# Multiset

tương tự như set, nhưng với điểm khác biệt chính là multiset cho phép lưu trữ nhiều giá trị trùng lặp (duplicate values), trong khi set chỉ lưu trữ các giá trị duy nhất.

```cpp
#include <iostream>
#include <set>  // Thư viện cho set và multiset

int main() {
    std::multiset<int> multiSet1;

    // Thêm các phần tử vào multiset
    multiSet1.insert(10);
    multiSet1.insert(20);
    multiSet1.insert(10);  // Giá trị trùng lặp được phép

    // In các phần tử trong multiset
    for (int num : multiSet1) {
        std::cout << num << " ";
    }

    return 0;
}

```

- Các phần tử trong multiset được sắp xếp theo thứ tự tăng dần (tương tự như set).
- Bạn có thể chèn các giá trị trùng lặp.
- Hàm count() cho phép đếm số lần xuất hiện của một phần tử cụ thể.

# Unordered set

- Không lưu trữ giá trị trùng lặp: Giống như set, mỗi giá trị trong unordered_set là duy nhất.
- Không có thứ tự: Các phần tử không được lưu trữ theo thứ tự cụ thể, vì vậy việc in ra các phần tử sẽ không theo một trình tự cố định.
- Hiệu suất cao cho các thao tác tìm kiếm, thêm và xóa nhờ vào cấu trúc bảng băm.
