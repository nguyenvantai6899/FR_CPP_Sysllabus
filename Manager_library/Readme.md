# Bài Tập Quản Lý Cửa Hàng Sách

Viết chương trình quản lý cửa hàng sách bằng C++ sử dụng các tính năng của ngôn ngữ như: class, inheritance, polymorphism, STL, và exception handling. Chương trình phải có khả năng lưu trữ và quản lý thông tin sách và hóa đơn bán hàng.

## Yêu Cầu Cụ Thể

### 1. Quản lý sách

- **Class `Book`**:
  - **Thuộc tính**:
    - `string id`: Mã sách.
    - `string title`: Tên sách.
    - `string author`: Tác giả.
    - `double price`: Giá tiền.
    - `int stock`: Số lượng tồn kho.
  - **Phương thức**:
    - `Book(string id, string title, string author, double price, int stock)`: Constructor để khởi tạo các thuộc tính.
    - `virtual double getPrice() const`: Phương thức ảo để lấy giá sách.
    - `string getID() const`: Phương thức để lấy mã sách.
    - `void sell(int quantity)`: Phương thức để bán sách, giảm số lượng tồn kho.
    - `virtual void display() const`: Phương thức hiển thị thông tin sách.

### 2. Quản lý hóa đơn

- **Class `Invoice`**:
  - **Thuộc tính**:
    - `string id`: Mã hóa đơn.
    - `string date`: Ngày bán.
    - `vector<pair<Book*, int>> items`: Danh sách sách và số lượng mua.
    - `double total`: Tổng tiền của hóa đơn.
  - **Phương thức**:
    - `Invoice(string id, string date)`: Constructor để khởi tạo mã hóa đơn và ngày bán.
    - `void addItem(Book* book, int quantity)`: Phương thức để thêm sách vào hóa đơn và tính tổng tiền.
    - `void display() const`: Phương thức hiển thị thông tin hóa đơn.

### 3. Kế thừa (Inheritance)

- **Class `SpecialBook`**:
  - Kế thừa từ `Book`.
  - **Phương thức**:
    - `double getPrice() const override`: Thay đổi giá sách đặc biệt, có thể có giá trị cao hơn (ví dụ, thêm 20%).
    - `void display() const override`: Hiển thị thông tin sách đặc biệt.

### 4. Đa hình (Polymorphism)

- Sử dụng các phương thức ảo để cho phép xử lý danh sách sách và sách đặc biệt một cách chung thông qua class `Book`. Điều này cho phép sử dụng danh sách chung chứa cả `Book` và `SpecialBook`.

### 5. Xử lý ngoại lệ (Exception handling)

- Sử dụng exception handling để bắt các lỗi trong chương trình:
  - Khi số lượng tồn kho không đủ khi bán sách, phát sinh ngoại lệ và in ra thông báo lỗi.
  - Khi không thể mở file để lưu hoặc nạp dữ liệu.

### 6. Sử dụng STL

- **Containers**:
  - Sử dụng `vector` để quản lý danh sách sách và hóa đơn.
  - Sử dụng `pair` để lưu trữ thông tin sách và số lượng trong hóa đơn.
- **Algorithm**:
  - Sử dụng thuật toán tìm kiếm từ STL để tìm sách theo mã hoặc tên (nếu cần).

### 7. Lưu trữ dữ liệu

- **Ghi dữ liệu**:
  - Lưu danh sách sách vào file khi chương trình kết thúc.
- **Đọc dữ liệu**:
  - Nạp danh sách sách từ file khi chương trình bắt đầu.
- **Format file**:
  - File có thể sử dụng định dạng CSV (comma-separated values) để lưu thông tin.

## Phân Tích Chương Trình

Chương trình quản lý cửa hàng sách sẽ có các bước sau:

1. **Khởi tạo dữ liệu**: Tạo một danh sách sách ban đầu và có thể đọc từ file.
2. **Thực hiện các thao tác**: Như thêm sách vào hóa đơn, tính tổng tiền, và hiển thị hóa đơn.
3. **Lưu và nạp dữ liệu**: Khi chương trình kết thúc, lưu danh sách sách vào file; khi bắt đầu, nạp từ file.

## Kết Luận

Chương trình này không chỉ giúp bạn thực hành với các tính năng của C++, mà còn tạo ra một ứng dụng thực tế có thể được mở rộng và bảo trì dễ dàng. Bạn có thể thêm nhiều tính năng hơn, chẳng hạn như quản lý khách hàng, tìm kiếm sách, hoặc thống kê doanh thu, để cải thiện thêm chương trình.
