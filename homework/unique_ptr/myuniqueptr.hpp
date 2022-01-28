#pragma once

#include <ostream>

template <typename T>
class MyUniquePtr {
public:
    MyUniquePtr() {}
    MyUniquePtr(T* pointer) : pointer_{pointer} {}
    MyUniquePtr(const MyUniquePtr<T>& other) = delete;
    MyUniquePtr& operator=(const MyUniquePtr<T>& other) = delete;

    MyUniquePtr(MyUniquePtr<T>&& other) { 
        pointer_ = other.release();
    }

    MyUniquePtr& operator=(MyUniquePtr<T>&& other) {
        if (other != *this) {
            pointer_ = other.release();
        }
        return *this;
    }

    ~MyUniquePtr() {
        delete pointer_;
    }

    T operator*() {
        return *pointer_;
    }

    T operator->() {
        return *pointer_;
    }

    T* get() const {  // const?
        return pointer_;
    }

    T* release() {
        T* tempPointer = pointer_;
        pointer_ = nullptr;
        return tempPointer;
    }

    void reset(T* other) { //should I check if it's another MyUnique?
        if (other != this) {  //derefrenacja na this?
            delete pointer_;
            pointer_ = other;
        }
    }

    operator bool() {
        return pointer_ != nullptr;
    }

    bool operator!=(const MyUniquePtr<T>& other) {
        return pointer_ != other.get();
    }

    bool operator==(const MyUniquePtr<T>& other) {
        return pointer_ == other.get();
    }

    friend std::ostream& operator<<(std::ostream& os, const MyUniquePtr<T>& myPtr) {
        os << myPtr.get();
        return os;
    }

    // get()
    // release()
    

    // reset()

    //operator bool
    //operator << ?

private:
    T* pointer_ = nullptr;
};