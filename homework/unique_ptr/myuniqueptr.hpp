#pragma once
#include <iostream> //temporary
#include <ostream>

template <typename T>
class MyUniquePtr {
public:
    MyUniquePtr() noexcept {}

    explicit MyUniquePtr(T* pointer) noexcept : pointer_{pointer} {}

    MyUniquePtr(const MyUniquePtr<T>& other) = delete;

    MyUniquePtr& operator=(const MyUniquePtr<T>& other) = delete;

    MyUniquePtr(MyUniquePtr<T>&& other) noexcept { 
        // if (&other != this) { //not necessary
            pointer_ = other.release();
        // }
    }

    MyUniquePtr& operator=(MyUniquePtr<T>&& other) noexcept {
        if (&other != this) {
            pointer_ = other.release();
            // std::cout << "Ctor\n";
        }
        return *this;
    }

    ~MyUniquePtr() {
        delete pointer_;
    }

    T& operator*() {
        return *pointer_;
    }

    const T& operator*() const {
        return *pointer_;
    }

    T* operator->() {
        return pointer_;
    }

    const T* operator->() const  {
        return pointer_;
    }

    const T* get() const {  // const?
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

    operator bool() const {
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

private:
    T* pointer_ = nullptr;
};