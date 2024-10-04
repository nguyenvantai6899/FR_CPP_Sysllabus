Smart pointers trong C++ là những đối tượng quản lý tự động vòng đời của các con trỏ (dynamically allocated memory), giúp tránh các lỗi bộ nhớ như rò rỉ bộ nhớ (memory leaks) và giải phóng bộ nhớ nhiều lần (double delete). Chúng nằm trong thư viện <memory> và cung cấp tính năng tự động giải phóng bộ nhớ khi đối tượng không còn được sử dụng nữa.

1. std::unique_ptr

- unique_ptr là smart pointer sở hữu độc quyền một tài nguyên (không thể sao chép).
- Khi unique_ptr bị hủy (out of scope), tài nguyên nó quản lý sẽ được giải phóng tự động.
- Không thể sao chép unique_ptr, nhưng có thể chuyển quyền sở hữu (move semantics).

```cpp
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(10);  // Tạo ra một unique_ptr trỏ đến giá trị 10
    std::cout << "Giá trị: " << *ptr << std::endl;  // Truy xuất giá trị thông qua unique_ptr
    return 0;  // ptr tự động giải phóng bộ nhớ
}

```

chuyển quyền sở hữu

```cpp
std::unique_ptr<int> ptr2 = std::move(ptr);  // Chuyển quyền sở hữu từ ptr sang ptr2

```

2. shared_ptr

- shared_ptr cho phép nhiều smart pointer cùng chia sẻ quyền sở hữu tài nguyên.
- Bộ đếm tham chiếu (reference count) được sử dụng để theo dõi số lượng shared_ptr đang quản lý cùng một tài nguyên. Khi bộ 1 đếm bằng 0 (không còn shared_ptr nào trỏ tới tài nguyên), tài nguyên sẽ tự động được giải phóng.

```cpp
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(20);  // Tạo ra một shared_ptr trỏ đến giá trị 20
    std::shared_ptr<int> ptr2 = ptr1;  // ptr2 và ptr1 cùng quản lý tài nguyên
    std::cout << "Giá trị: " << *ptr1 << std::endl;  // Truy xuất giá trị thông qua ptr1
    std::cout << "Bộ đếm tham chiếu: " << ptr1.use_count() << std::endl;  // Số lượng shared_ptr đang quản lý tài nguyên
    return 0;  // Tài nguyên sẽ chỉ được giải phóng khi không còn shared_ptr nào trỏ tới nó
}

```

3. std::weak_ptr

- weak_ptr là smart pointer không sở hữu tài nguyên, mà chỉ giữ một tham chiếu yếu (weak reference) tới tài nguyên được quản lý bởi shared_ptr.
- Mục đích chính của weak_ptr là để tránh vòng tham chiếu (cyclic reference) giữa các shared_ptr, điều có thể dẫn tới rò rỉ bộ nhớ.
- weak_ptr không ảnh hưởng tới bộ đếm tham chiếu của tài nguyên.

```cpp
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(30);
    std::weak_ptr<int> weakPtr = ptr1;  // weak_ptr trỏ đến cùng tài nguyên với ptr1, nhưng không tăng bộ đếm tham chiếu

    if (auto sharedPtr = weakPtr.lock()) {  // Kiểm tra nếu tài nguyên còn tồn tại và truy xuất thông qua shared_ptr
        std::cout << "Giá trị: " << *sharedPtr << std::endl;
    } else {
        std::cout << "Tài nguyên đã bị giải phóng." << std::endl;
    }

    return 0;
}

```

#### Khi nào sử dụng smart pointer

**_unique_ptr_**: Khi bạn muốn đảm bảo rằng chỉ có một đối tượng duy nhất sở hữu tài nguyên.
**_shared_ptr_**: Khi bạn cần chia sẻ quyền sở hữu tài nguyên giữa nhiều đối tượng.
**_weak_ptr_**: Khi bạn cần giữ một tham chiếu yếu tới tài nguyên được quản lý bởi shared_ptr để tránh vòng tham chiếu.
