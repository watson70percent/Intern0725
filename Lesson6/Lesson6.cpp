#include <iostream>
#include <thread>
#include <mutex>

/* 同じ変数を同時に複数のスレッドから操作すると、期待した動作にならない事がある。
 * std::mutexを使用し、期待した動作になるように修正してください。
 */
std::mutex mtx_;
int sum;

void worker()
{
    std::lock_guard < std::mutex> lock(mtx_);
    for (int i = 0; i < 100000; ++i) {
        sum += i;
    }
}


int main()
{
    {
        // スレッドを１つずつ実行
        sum = 0;
        std::thread a( worker);
        a.join();
        std::thread b( worker);
        b.join();
        std::thread c( worker);
        c.join();
        std::cout << sum << std::endl;
    }

    {
        // スレッドを同時に実行する
        sum = 0;
        std::thread a( worker);
        std::thread b( worker);
        std::thread c( worker);
        a.join();
        b.join();
        c.join();
        std::cout << sum << std::endl;
    }

    return EXIT_SUCCESS;
}
