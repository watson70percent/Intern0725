#include <iostream>
#include <thread>
#include <atomic>

/* 同じ変数を同時に複数のスレッドから操作すると、期待した動作にならない事がある。
 * std::atomicを使用し、期待した動作になるように修正してください。
 */

std::atomic_int sum;

void worker()
{
    //while(!ready.load(std::memory_order_acquire)){}//足すのをガマン
    for (int i = 0; i < 100000; ++i) {
        sum.fetch_add(i);
    }
}


int main()
{
    {
        // スレッドを１つずつ実行
        sum = 0;
        std::thread a(worker);
        a.join();
        std::thread b(worker);
        b.join();
        std::thread c(worker);
        c.join();
        std::cout << sum << std::endl;
    }

    {
        // スレッドを同時に実行する
        sum = 0;
        std::thread a(worker);
        std::thread b(worker);
        std::thread c(worker);
        a.join();
        b.join();
        c.join();
        std::cout << sum << std::endl;
    }

    return EXIT_SUCCESS;
}
