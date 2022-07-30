#include <iostream>
#include "PoolAllocator.h"

/* Pool Allocatorを実装しよう！
 * PoolAllocator.hを編集してください。
 */

/* 簡易テストプログラムです。
 * 変更する必要はありません。
 */

int main()
{
    struct POINT
    {
        int x;
        int y;
    };

    const int TEST_SIZE = 100;
    PoolAllocator<POINT, TEST_SIZE> a;
 
    // メモリ確保テスト
    POINT* ptr[TEST_SIZE];
    for (int i = 0; i < TEST_SIZE; ++i) {
        ptr[i] = a.Alloc();
        if (nullptr == ptr[i]) {
            std::cout << i << "個目のメモリ確保に失敗" << std::endl;
            return EXIT_FAILURE;
        }
        ptr[i]->x = i;
        ptr[i]->y = i+i;
    }

    {
        POINT* p;
        p = a.Alloc();
        if (nullptr != p) {
            std::cout << TEST_SIZE << "個以上のメモリ確保が出来た" << std::endl;
            return EXIT_FAILURE;
        }
    }

    // nullptr開放
    a.Free(nullptr);

    // 半分開放
    for (int i = 0; i < TEST_SIZE; i+=2) {
        a.Free(ptr[i]);
        ptr[i] = nullptr;
    }

    //メモリ破壊チェック
    for (int i = 0; i < TEST_SIZE; ++i) {
        if (ptr[i]) {
            if (ptr[i]->x != i || ptr[i]->y != i + i) {
                std::cout << "メモリが壊れています" << std::endl;
                return EXIT_FAILURE;
            }
        }
    }
    std::cout << "簡易テスト完了" << std::endl;
    return EXIT_SUCCESS;
}
