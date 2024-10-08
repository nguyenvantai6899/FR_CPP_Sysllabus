# Process Synchronization

dùng để đảm bảo rằng nhiều tiến trình (processes) hoặc luồng (threads) có thể thực thi đồng thời mà không gây ra xung đột, hoặc dẫn đến trạng thái bất nhất trong dữ liệu.

#### Vấn đề

- Race condition
- Deadlock
- Starvation

#### Giải pháp

1. Mutex
   Là cơ chế dùng để đảm bỏ chỉ có một tiến trình hoặc luồng được phép truy cập vào tài nguyên chia sẻ tại một thời điểm. Nó hoạt động như một chìa khóa: khi một tiến trình nắm giữ chìa khóa (lock), các tiến trình khác phải đợi cho đến khi chìa khóa được trả lại (unlock).

```cpp
std::mutex mtx;
mtx.lock(); // Bắt đầu vùng tới hạn
// Truy cập tài nguyên chung
mtx.unlock(); // Kết thúc vùng tới hạn

```

2. Semaphores
   Là biến có thể được sử dụng để kiểm soát quyền truy cập vào tài nguyên chia sẻ bởi nhiều tiến trình. Khác với mutex chỉ cho phép một tiến trình nắm giữ "khóa", semaphore cho phép một số lượng giới hạn tiến trình truy cập vào tài nguyên cùng lúc.

- Semaphore có hai loại:
  - Counting Semaphore: Cho phép nhiều tiến trình cùng truy cập tài nguyên dựa trên giá trị đếm.
  - Binary Semaphore: Hoạt động tương tự mutex, chỉ cho phép một tiến trình tại một thời điểm.

```cpp
sem_t sem;
sem_init(&sem, 0, 1); // Khởi tạo semaphore với giá trị ban đầu 1
sem_wait(&sem); // Vào vùng tới hạn
// Truy cập tài nguyên
sem_post(&sem); // Kết thúc vùng tới hạn

```

3. Monitors
   Là một đối tượng hoặc cấu trúc dữ liệu dùng để bao gói một loạt các hoạt động trên tài nguyên chia sẻ, đồng thời kiểm soát quyền truy cập để tránh xung đột giữa các tiến trình.

4. Condition Variables
   Là cơ chế đồng bộ hóa cho phép các tiến trình hoặc luồng chờ trong khi một điều kiện cụ thể chưa được thỏa mãn. Khi điều kiện được thỏa mãn, các luồng bị chặn sẽ được đánh thức để tiếp tục thực thi.

```cpp
std::condition_variable cv;
std::mutex mtx;
std::unique_lock<std::mutex> lck(mtx);
cv.wait(lck); // Chờ điều kiện
cv.notify_one(); // Đánh thức một luồng đang chờ
cv.notify_all(); // Đánh thức tất cả các luồng đang chờ

```

# Lock guard

**_Example_**

```cpp
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex myMutex;          // Define a mutex
long sharedCounter = 0; // Shared counter variable

void incrementCounter(long numIterations)
{
    for (long i = 0; i < numIterations; ++i)
    {
        lock_guard<mutex> lock(myMutex); // Lock the mutex to protect the sharedCounter
        ++sharedCounter;                 // Safely increment the shared counter
    }
}
void printfAnything()
{
    lock_guard<mutex> lock(myMutex);
    for (int i = 0; i < 5; i++)
    {
        cout << "--------------------- " << i << endl;
    }
}
int main()
{
    long numIterations = 100000;

    // Create two threads that will increment the sharedCounter
    // thread thread1(incrementCounter, numIterations);
    // thread thread2(incrementCounter, numIterations);

    // // Wait for both threads to finish
    // thread1.join();
    // thread2.join();

    // // Output the final value of the shared counter
    // cout << "Final value of sharedCounter: " << sharedCounter << endl;

    thread thread3(printfAnything);
    thread thread4(printfAnything);

    thread3.join();
    thread4.join();
    return 0;
}

```

# Unique lock

#### Điểm khác biệt giữa std::unique_lock và std::lock_guard:

- Khả năng linh hoạt hơn: Với std::unique_lock, bạn có thể khóa và mở khóa mutex thủ công, trong khi với std::lock_guard, mutex sẽ được khóa ngay khi đối tượng được tạo và tự động mở khóa khi đối tượng bị hủy.
- Khả năng kiểm soát thời gian khóa: std::unique_lock cho phép khóa có thời hạn (timed locks) và thử khóa (try locks).
- Quản lý mutex bằng con trỏ: std::unique_lock hỗ trợ quản lý mutex dựa trên con trỏ.

```cpp
std::unique_lock<std::mutex> lock(myMutex);

```

Một số phương thức cơ bản của std::unique_lock:

- lock(): Khóa mutex (có thể khóa lại sau khi mở khóa).
- unlock(): Mở khóa mutex thủ công.
- try_lock(): Thử khóa mutex, trả về true nếu khóa thành công và false nếu không khóa được (khác với lock_guard chỉ có thể khóa khi tạo).
- owns_lock(): Kiểm tra xem mutex có đang được giữ bởi unique_lock không.

**_Example_**

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex myMutex;

void task(const string& threadName) {
    unique_lock<mutex> lock(myMutex); // Khóa mutex
    cout << threadName << " acquired the lock!" << endl;

    // Thực hiện thao tác với tài nguyên chia sẻ
    this_thread::sleep_for(chrono::seconds(1)); // Giả lập công việc kéo dài 1 giây

    cout << threadName << " releasing the lock!" << endl;
    lock.unlock(); // Mở khóa thủ công

    // Tiếp tục thực hiện công việc sau khi mở khóa
    cout << threadName << " is doing something else after unlocking." << endl;
}

int main() {
    thread t1(task, "Thread 1");
    thread t2(task, "Thread 2");

    t1.join();
    t2.join();

    return 0;
}

```

# Condition variable

là một công cụ đồng bộ hóa mạnh mẽ được sử dụng để quản lý sự chờ đợi giữa các luồng. Nó giúp một hoặc nhiều luồng tạm dừng (chờ đợi) cho đến khi một điều kiện cụ thể được đáp ứng bởi một luồng khác.

# Khai báo

condition_variable cv; - tạo một biến điều kiện
cv.wait(); - tạm dừng và chờ đợi 1 sự kiện được thông báo.
cv.notify_one(); - thông báo một luồng
cv.notify_all(); - thông báo tất cả các luồng.

**_example_**

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx; // Mutex để bảo vệ tài nguyên chia sẻ
condition_variable cv; // Biến điều kiện
bool ready = false; // Biến điều kiện

void waitingThread() {
    unique_lock<mutex> lock(mtx); // Khóa mutex
    cout << "Thread is waiting for the condition..." << endl;

    // Chờ đợi điều kiện "ready" trở thành true
    cv.wait(lock, [] { return ready; });

    // Khi điều kiện được đáp ứng, tiếp tục thực hiện
    cout << "Thread resumed, condition met!" << endl;
}

void notifyingThread() {
    this_thread::sleep_for(chrono::seconds(2)); // Giả lập công việc kéo dài 2 giây
    cout << "Notifying thread is about to set the condition..." << endl;

    // Đặt điều kiện và thông báo cho luồng chờ đợi
    {
        lock_guard<mutex> lock(mtx); // Khóa mutex
        ready = true;
    }

    // Thông báo cho các luồng đang chờ
    cv.notify_one();
}

int main() {
    thread t1(waitingThread);  // Luồng chờ đợi điều kiện
    thread t2(notifyingThread); // Luồng đặt điều kiện và thông báo

    t1.join();
    t2.join();

    return 0;
}

```
