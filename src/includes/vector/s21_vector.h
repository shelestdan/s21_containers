#ifndef __S21_VECTOR_H__
#define __S21_VECTOR_H__

#include <utility>

namespace s21 {
#define VECTOR_DEFAULT_CAPACITY 10

#define VECTOR_CAPACITY_MULT_LIMIT 10000
#define VECTOR_CAPACITY_ADDITION 1000

template <typename Ty>
class vector {
 public:
  using value_type = Ty;
  using reference = Ty&;
  using const_reference = const Ty&;
  using iterator = Ty*;
  using const_iterator = const Ty*;
  using size_type = size_t;

  vector() {}

  vector(size_type n) {
    if (n > 0) {
      reallocDataIfNeeded(n);
      size_ = n;
    }

    for (size_type i = 0; i < n; ++i) {
      data_[i] = value_type{};
    }
  }

  vector(std::initializer_list<value_type> const& items) {
    if (items.size() > 0) {
      reallocDataIfNeeded(items.size());
    }

    for (const_reference item : items) {
      push_back(item);
    }
  }

  vector(const vector& v) { copyHere(v); }

  ~vector() { clearData(); }

  vector(vector&& v) { moveHere(std::move(v)); }

  vector& operator=(const vector& v) {
    if (data_ != v.data_) {
      clearData();
      copyHere(v);
    }
    return *this;
  }

  vector& operator=(vector&& v) {
    if (data_ != v.data_) {
      clearData();
      moveHere(std::move(v));
    }
    return *this;
  }

  reference at(size_type pos) {
    if (pos >= size_) {
      throw std::out_of_range("Vector: Index out of range");
    }
    return data_[pos];
  }

  reference operator[](size_type pos) { return data_[pos]; }

  const_reference front() const { return data_[0]; }

  const_reference back() const { return data_[size_ - 1]; }

  value_type* data() { return data_; }

  iterator begin() { return const_cast<iterator>(cbegin()); }

  iterator end() { return const_cast<iterator>(cend()); }

  const_iterator cbegin() const { return data_; }

  const_iterator cend() const { return data_ + size_; }

  bool empty() const { return size_ == 0; }

  size_type size() const { return size_; }

  size_type max_size() { return PTRDIFF_MAX / sizeof(value_type); }

  void reserve(size_type size) {
    if (size > capacity_) {
      reallocDataIfNeeded(size);
    }
  }

  size_type capacity() { return capacity_; }

  void shrink_to_fit() {
    if (size_ != capacity_) {
      moveData(allocRawData(size_));
      capacity_ = size_;
    }
  }

  void clear() { size_ = 0; }

  iterator insert(iterator pos, const_reference value) {
    std::ptrdiff_t offset = pos - data_;

    reallocDataIfNeeded();

    pos = data_ + offset;
    std::move(pos, data_ + size_, pos + 1);
    *pos = value;

    size_ += 1;

    return pos;
  }

  template <typename... Args>
  iterator emplace(const_iterator pos, Args&&... args) {
    std::initializer_list<value_type> items = {args...};

    std::ptrdiff_t offset = pos - data_;

    iterator iter = const_cast<iterator>(pos);
    for (const_reference item : items) {
      iter = insert(iter, item);
      iter += 1;
    }

    return data_ + offset;
  }

  template <typename... Args>
  void emplace_back(Args... args) {
    std::initializer_list<value_type> items = {args...};

    for (const_reference item : items) {
      push_back(item);
    }
  }

  void erase(iterator pos) {
    value_type* posPtr = pos;
    std::move(posPtr + 1, data_ + size_, posPtr);
    size_ -= 1;
  }

  void push_back(const_reference value) {
    reallocDataIfNeeded();
    size_ += 1;
    data_[size_ - 1] = value;
  }

  void pop_back() {
    if (size_ > 0) {
      size_ -= 1;
    }
  }

  void swap(vector& other) {
    value_type* tmpData = data_;
    data_ = other.data_;
    other.data_ = tmpData;

    size_type tmpSize = size_;
    size_ = other.size_;
    other.size_ = tmpSize;

    tmpSize = capacity_;
    capacity_ = other.capacity_;
    other.capacity_ = tmpSize;
  }

 private:
  void reallocDataIfNeeded(size_type exactly = 0) {
    size_type startCapacity = capacity_;

    if (exactly != 0) {
      // Если пользователю нужен конкретный размер
      // Устанавливаем его как capacity
      capacity_ = exactly;
    } else if (capacity_ == 0) {
      // В противном случае если capacity равен нулю
      // Берём capacity по умолчанию
      capacity_ = VECTOR_DEFAULT_CAPACITY;
    }

    if (size_ > capacity_) {
      // Если размер больше capacity - мы должны его срезать
      // Это может произойти если был передан exactly отличный от 0
      size_ = capacity_;
    }

    if (size_ == capacity_) {
      // Если size совпадает с capacity массива - нужно увеличить capacity
      if (capacity_ > VECTOR_CAPACITY_MULT_LIMIT) {
        capacity_ += VECTOR_CAPACITY_ADDITION;
      } else {
        capacity_ *= 2;
      }
    }

    if (capacity_ != startCapacity) {
      if (capacity_ > max_size()) {
        throw std::length_error("vector: capacity biggest then max_size()");
      }

      moveData(allocRawData(capacity_));
    }
  }

  value_type* allocRawData(size_type nvalues) {
    int8_t* data = new int8_t[sizeof(value_type) * nvalues];
    return reinterpret_cast<value_type*>(data);
  }

  void clearData() {
    if (data_ != nullptr) {
      delete[] data_;
      data_ = nullptr;
    }
    capacity_ = 0;
    size_ = 0;
  }

  void moveData(value_type* newData) {
    if (data_ != nullptr) {
      std::copy(data_, data_ + size_, newData);
      delete[] data_;
    }
    data_ = newData;
  }

  void copyHere(const vector& vec) {
    if (vec.size_ > 0) {
      reallocDataIfNeeded(vec.size_);
    }

    std::copy(vec.data_, vec.data_ + vec.size_, data_);
    size_ = vec.size_;
  }

  void moveHere(vector&& vec) {
    data_ = vec.data_;
    capacity_ = vec.capacity_;
    size_ = vec.size_;

    vec.data_ = nullptr;
    vec.capacity_ = 0;
    vec.size_ = 0;
  }

  value_type* data_ = nullptr;
  size_type capacity_ = 0;
  size_type size_ = 0;
};
}  // namespace s21

#endif  // __S21_VECTOR_H__