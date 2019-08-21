#ifndef deepPtr_hpp
#define deepPtr_hpp

#include <memory>

template <typename T>
class DeepPtr {
 public:
  DeepPtr(std::nullptr_t null = nullptr) : uptr(nullptr) {}

  DeepPtr(const T& obj) : uptr(std::make_unique<T>(obj)) {}
  DeepPtr(T&& obj) : uptr(std::make_unique<T>(obj)) {}

  DeepPtr(const DeepPtr<T>& other) : uptr(std::make_unique<T>(*other)) {}
  DeepPtr(DeepPtr<T>&& other) noexcept : uptr(nullptr) { other.swap(*this); }

  DeepPtr(std::unique_ptr<T>&& other) noexcept : uptr(nullptr) {
    using std::swap;
    swap(this->uptr, other);
  }

  void swap(DeepPtr<T>& other) noexcept {
    using std::swap;
    swap(this->uptr, other.uptr);
  }

  DeepPtr& operator=(const DeepPtr<T>& other) {
    DeepPtr<T> tmp(other);
    this->swap(tmp);
    return *this;
  }

  DeepPtr& operator=(DeepPtr<T>&& other) noexcept {
    this->swap(other);
    return *this;
  }

  DeepPtr& operator=(std::unique_ptr<T>&& other) noexcept {
    DeepPtr<T> tmp(std::move(other));
    this->swap(tmp);
    return *this;
  }

  T& operator*() { return *uptr; }
  const T& operator*() const { return *uptr; }

  T* operator->() { return uptr.operator->(); }
  const T* operator->() const { return uptr.operator->(); }

  const T* const get() const { return uptr.get(); }

  operator bool() const { return bool(uptr); }

 private:
  std::unique_ptr<T> uptr;
};

template <typename T>
void swap(DeepPtr<T>& left, DeepPtr<T>& right) noexcept {
  left.swap(right);
}

#endif