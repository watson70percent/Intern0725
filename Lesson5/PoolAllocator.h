#pragma once
#include <list>
#include <new>

// class Tを最大MAXSIZE個確保可能なPoolAllocatorを実装してください
template<class T, size_t MAXSIZE> class PoolAllocator
{
public:
	// コンストラクタ
	PoolAllocator() {
		// TODO: 必要に応じて実装してください
		freelist = new DATA[MAXSIZE];
		memory_head = freelist;
		for (int i = 0; i <= MAXSIZE - 2; i++) {
			freelist[i].next = &freelist[i + 1];
		}
		freelist[MAXSIZE - 1].next = nullptr;
	}
	// デストラクタ
	~PoolAllocator() {
		// TODO: 必要に応じて実装してください
		delete[] memory_head;
	}

	// 確保できない場合はnullptrを返す事。
	T* Alloc() {
		// TODO: 実装してください
		if (!freelist)return nullptr;
		DATA* result = freelist;
		freelist = freelist->next;
		return &result->data;
	}

	// Free(nullptr)で誤動作しないようにする事。
	void Free(T* addr) {
		// TODO: 実装してください
		if (addr) {
			DATA* elem = reinterpret_cast<DATA*>(addr);
			elem->next = freelist;
			freelist = elem;
		}
	}

private:
	// TODO: 実装してください
	struct DATA {
		T data; //データ
		DATA* next;
	};
	DATA* freelist;
	DATA* memory_head;
};
