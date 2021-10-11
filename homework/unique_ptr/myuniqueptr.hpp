#pragma once

template <typename T>
class MyUniquePtr {
public:
    MyUniquePtr() {}
    MyUniquePtr(T* pointer) : pointer_{pointer} {}

    T operator*() {
        return *pointer_;
    }

    T operator->() {
        return *pointer_;
    }
    // get()
    // release()
    // reset()


private:
    T* pointer_ = nullptr;
};