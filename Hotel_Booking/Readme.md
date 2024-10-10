
# Hệ thống Quản lý Đặt phòng Khách sạn

## Giới thiệu
Hệ thống quản lý đặt phòng khách sạn cho phép khách hàng đặt phòng, kiểm tra phòng đã đặt, và ghi nhận các giao dịch vào file. Hệ thống sử dụng OOP, STL, multithreading và socket để đảm bảo hiệu suất và khả năng mở rộng.

## Chức năng chính
1. **Quản lý khách sạn (Hotel Management)**
   - Quản lý danh sách các phòng (bao gồm phòng đơn, phòng đôi, và phòng VIP).
   - Hiển thị danh sách phòng trống và cho phép khách hàng đặt phòng.

2. **Quản lý khách hàng (Customer Management)**
   - Thêm khách hàng mới và lưu thông tin khách hàng.
   - Mỗi khách hàng sẽ có thông tin cá nhân và danh sách các phòng họ đã đặt.

3. **Ghi nhận giao dịch (Transaction Logging)**
   - Ghi thông tin đặt phòng của khách hàng vào file (bao gồm tên khách hàng, loại phòng, thời gian đặt).
   - Tự động lưu giao dịch vào file sau khi có khách hàng đặt phòng.

4. **Multithreading**
   - Sử dụng multithreading để xử lý việc đặt phòng, đảm bảo nhiều khách hàng có thể đặt phòng cùng một lúc mà không bị xung đột dữ liệu.

5. **Socket Programming**
   - Xây dựng một server đơn giản để lắng nghe các yêu cầu đặt phòng từ các khách hàng thông qua socket.
   - Mỗi khách hàng có thể gửi yêu cầu đặt phòng thông qua client-side socket.

## Yêu cầu chi tiết
1. **Lớp Phòng (Room)**
   - Thuộc tính: Số phòng, loại phòng, trạng thái (trống hoặc đã đặt).
   - Phương thức: Hiển thị thông tin phòng, kiểm tra trạng thái phòng, đặt phòng.

2. **Lớp Khách hàng (Customer)**
   - Thuộc tính: Tên, số điện thoại, danh sách các phòng đã đặt.
   - Phương thức: Đặt phòng, hủy phòng, kiểm tra thông tin phòng đã đặt.

3. **Quản lý phòng bằng STL**
   - Sử dụng `std::vector` hoặc `std::map` để quản lý danh sách phòng và khách hàng.

4. **Ghi và đọc file**
   - Ghi thông tin phòng và khách hàng vào file (ví dụ: `transactions.txt`).
   - Đọc dữ liệu từ file khi khởi động chương trình.

5. **Multithreading**
   - Sử dụng `std::thread` để đảm bảo việc đặt phòng diễn ra đồng thời, không xung đột dữ liệu giữa các yêu cầu đặt phòng.

6. **Socket Programming**
   - Xây dựng một server và client bằng socket để xử lý yêu cầu đặt phòng từ khách hàng ở xa.

## Gợi ý cấu trúc
- `Room.h` và `Room.cpp`: Định nghĩa và triển khai lớp Phòng.
- `Customer.h` và `Customer.cpp`: Định nghĩa và triển khai lớp Khách hàng.
- `HotelManager.h` và `HotelManager.cpp`: Quản lý danh sách phòng và khách hàng, xử lý đặt phòng.
- `main.cpp`: Xử lý luồng chính, kết nối socket, và tương tác với người dùng.

## Kết luận
Bài tập này tổng hợp nhiều kiến thức về OOP, STL, file, multithreading và socket, giúp bạn rèn luyện nhiều khía cạnh quan trọng trong lập trình C++.
