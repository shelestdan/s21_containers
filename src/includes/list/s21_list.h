#ifndef S21_LIST_H_
#define S21_LIST_H_

#include <limits>
#include <stdexcept>
#include <utility>

namespace s21 {

template <typename Ty>
class list {
 public:
  using value_type = Ty;
  using reference = Ty &;
  using const_reference = const Ty &;
  using size_type = std::size_t;

 private:
  struct Node {
    value_type value_;
    Node *prev_ = nullptr;
    Node *next_ = nullptr;

    explicit Node(const value_type &value, Node *prev = nullptr,
                  Node *next = nullptr)
        : value_(value), prev_(prev), next_(next) {}

    void setNext(Node *next) {
      next_ = next;
      if (next != nullptr) {
        next->prev_ = this;
      }
    }

    void setPrev(Node *prev) {
      prev_ = prev;
      if (prev != nullptr) {
        prev->next_ = this;
      }
    }
  };

  Node *head_ = nullptr;  // Указатель на головной элемент списка
  Node *end_ = nullptr;  // Указатель на последний элемент списка
  size_type size_ = 0;  // Текущий размер списка

 public:
  class iterator;  // Прототип класса итератора
  class const_iterator;  // Прототип класса константного итератора

  list() {}

  // Конструктор, создающий список с заданным количеством элементов n
  list(size_type n) {
    for (size_type i = 0; i < n; i++) {
      push_back(value_type());
    }
  }

  // Конструктор, создающий список из элементов в инициализационном списке
  list(std::initializer_list<value_type> const &items) {
    for (const_reference item : items) {
      push_back(item);
    }
  }

  // Конструктор копирования
  list(const list &other) {
    for (const_iterator iter = other.cbegin(); iter != other.cend(); ++iter) {
      push_back(*iter);
    }
  }

  // Конструктор перемещения
  list(list &&other) noexcept { moveHere(std::move(other)); }

  // Деструктор
  ~list() { clear(); }

  // Оператор присваивания копированием
  list &operator=(const list &other) {
    if (this != &other) {
      list temp(other);
      swap(temp);
    }
    return *this;
  }

  // Оператор присваивания перемещением
  list &operator=(list &&other) noexcept {
    if (this != &other) {
      clear();
      moveHere(std::move(other));
    }
    return *this;
  }

  // Возвращает ссылку на первый элемент списка
  const_reference front() const { return *cbegin(); }

  // Возвращает ссылку на последний элемент списка
  const_reference back() const { return *const_iterator(end_); }

  // Возвращает итератор, указывающий на первый элемент списка
  iterator begin() { return iterator(head_); }

  // Возвращает итератор, указывающий на элемент, следующий за последним
  // элементом списка
  iterator end() { return iterator(nullptr); }

  iterator rbegin() { return iterator(end_); }

  // Возвращает константный итератор, указывающий на первый элемент списка
  const_iterator cbegin() const { return const_iterator(head_); }

  // Возвращает константный итератор, указывающий на элемент, следующий за
  // последним элементом списка
  const_iterator cend() const { return const_iterator(nullptr); }

  // Проверяет, пуст ли список
  bool empty() const { return size_ == 0; }

  // Возвращает размер списка
  size_type size() const { return size_; }

  // Возвращает максимально возможный размер списка
  size_type max_size() const { return PTRDIFF_MAX / sizeof(Node); }

  // Очищает список, удаляя все элементы и освобождая память
  void clear() {
    for (Node *nodePtr = head_; nodePtr != nullptr;) {
      Node *nextPtr = nodePtr->next_;
      delete nodePtr;
      nodePtr = nextPtr;
    }
    head_ = nullptr;
    end_ = nullptr;
    size_ = 0;
  }

  // Вставляет элемент со значением value перед позицией, указанной итератором
  // pos
  iterator insert(iterator pos, const_reference value) {
    if (pos.ptr_ == nullptr) {
      push_back(value);
      return iterator(end_);
    } else {
      Node *current = pos.ptr_;
      Node *newNode = new Node(value, current->prev_, current);
      if (current->prev_ != nullptr) {
        current->prev_->next_ = newNode;
      } else {
        head_ = newNode;
      }
      current->prev_ = newNode;
      size_ += 1;
      return iterator(newNode);
    }
  }

  // Удаляет элемент, указанный итератором pos
  void erase(iterator pos) {
    if (pos.ptr_ == nullptr) {
      throw std::out_of_range("erase() was given an invalid iterator.");
    }
    Node *current = pos.ptr_;
    if (current->prev_ == nullptr) {
      pop_front();
      return;
    }
    if (current->next_ == nullptr) {
      pop_back();
      return;
    }
    Node *left = current->prev_;
    Node *right = current->next_;
    left->next_ = right;
    right->prev_ = left;
    delete current;
    size_ -= 1;
  }

  // Добавляет элемент со значением value в конец списка
  void push_back(const_reference value) {
    Node *newNode = new Node(value);
    if (!newNode) {
      throw std::runtime_error("Failed to allocate memory for the new node");
    }
    if (end_ != nullptr) {
      end_->next_ = newNode;
    } else {
      head_ = newNode;
    }
    newNode->prev_ = end_;
    end_ = newNode;
    size_ += 1;
  }

  // Удаляет последний элемент списка
  void pop_back() {
    if (end_ == nullptr) {
      throw std::runtime_error("List is empty, can't pop back element");
    }
    Node *temp = end_->prev_;
    delete end_;
    end_ = temp;
    if (end_) {
      end_->next_ = nullptr;
    } else {
      head_ = nullptr;
    }
    if (size_ > 0) {
      --size_;
    } else {
      throw std::runtime_error("Invalid state: size is already 0");
    }
  }

  // Добавляет элемент со значением value в начало списка
  void push_front(const_reference value) {
    Node *newNode = new Node(value);
    if (!newNode) {
      throw std::runtime_error("Failed to allocate memory for the new node");
    }
    if (head_ != nullptr) {
      head_->prev_ = newNode;
    } else {
      end_ = newNode;
    }
    newNode->next_ = head_;
    head_ = newNode;
    size_ += 1;
  }

  // Удаляет первый элемент списка
  void pop_front() {
    if (head_ == nullptr) {
      throw std::runtime_error("List is empty, can't pop front element");
    }
    Node *temp = head_->next_;
    delete head_;
    head_ = temp;
    if (head_) {
      head_->prev_ = nullptr;
    } else {
      end_ = nullptr;
    }
    if (size_ > 0) {
      --size_;
    } else {
      throw std::runtime_error("Invalid state: size is already 0");
    }
  }

  // Обменивает содержимое списка с другим списком
  void swap(list &other) noexcept {
    using std::swap;
    swap(head_, other.head_);
    swap(end_, other.end_);
    swap(size_, other.size_);
  }

  // Объединяет данный список с другим списком, предварительно сортируя оба
  // списка
  void merge(list &other) { merge_sorted(*this, other); }

  // Вставляет содержимое другого списка в текущий список перед позицией,
  // указанной итератором pos
  void splice(const_iterator pos, list &other) {
    if (other.empty()) {
      return;
    }

    Node *before = (pos == begin()) ? nullptr : pos.ptr_->prev_;
    Node *after = (pos == end()) ? nullptr : pos.ptr_;

    if (before != nullptr) {
      before->next_ = other.head_;
    } else {
      head_ = other.head_;
    }
    other.head_->prev_ = before;

    if (after != nullptr) {
      after->prev_ = other.end_;
    } else {
      end_ = other.end_;
    }
    other.end_->next_ = after;

    size_ += other.size_;
    other.size_ = 0;
    other.head_ = nullptr;
    other.end_ = nullptr;
  }

  // Разворачивает список, меняя порядок элементов на противоположный
  void reverse() {
    Node *temp = nullptr;
    Node *current = head_;

    while (current != nullptr) {
      temp = current->prev_;
      current->prev_ = current->next_;
      current->next_ = temp;
      current = current->prev_;
    }

    if (temp != nullptr) {
      head_ = temp->prev_;
    }
  }

  // Удаляет все дубликаты элементов из списка
  void unique() {
    if (head_ == nullptr) return;

    Node *current = head_;
    Node *next_node;

    while (current->next_ != nullptr) {
      if (current->value_ == current->next_->value_) {
        next_node = current->next_->next_;
        delete current->next_;
        --size_;
        current->next_ = next_node;
      } else {
        current = current->next_;
      }
    }
  }

  // Сортирует элементы списка в порядке возрастания
  void sort() {
    if (size_ <= 1) {
      return;
    }

    list<Ty> left_half;
    list<Ty> right_half;

    Node *middle = head_;
    Node *current = head_;

    while (current != nullptr && current->next_ != nullptr) {
      current = current->next_->next_;
      if (current != nullptr) {
        middle = middle->next_;
      }
    }

    right_half.head_ = middle->next_;
    right_half.end_ = end_;
    right_half.size_ = size_ / 2;

    left_half.head_ = head_;
    left_half.end_ = middle;
    left_half.size_ = size_ - right_half.size_;

    middle->next_ = nullptr;
    right_half.head_->prev_ = nullptr;

    left_half.sort();
    right_half.sort();

    merge_sorted(left_half, right_half);
  }

  // Вставляет элемент со значениями args перед позицией, указанной итератором
  // pos
  template <typename... Args>
  iterator emplace(const_iterator pos, Args &&...args) {
    if (pos.ptr_ == nullptr) {
      pos.ptr_ = end_;
    }

    Node *node = nullptr;
    if (pos.ptr_ != nullptr) {
      node = new Node(value_type(std::forward<Args>(args)...));
      if (pos.ptr_->prev_ == nullptr) {
        head_ = node;
        node->next_ = pos.ptr_;
        pos.ptr_->prev_ = node;
      } else {
        node->prev_ = pos.ptr_->prev_;
        node->next_ = pos.ptr_;
        pos.ptr_->prev_->next_ = node;
        pos.ptr_->prev_ = node;
      }
      ++size_;
    }
    return iterator(node);
  }

  // Добавляет элемент со значениями args в конец списка
  template <typename... Args>
  void emplace_back(Args &&...args) {
    Node *node = new Node(value_type(std::forward<Args>(args)...));
    if (end_ == nullptr) {
      head_ = node;
      end_ = node;
    } else {
      node->prev_ = end_;
      end_->next_ = node;
      end_ = node;
    }
    ++size_;
  }

  // Добавляет элемент со значениями args в начало списка
  template <typename... Args>
  void emplace_front(Args &&...args) {
    Node *node = new Node(value_type(std::forward<Args>(args)...));
    if (head_ == nullptr) {
      head_ = node;
      end_ = node;
    } else {
      node->next_ = head_;
      head_->prev_ = node;
      head_ = node;
    }
    ++size_;
  }

 private:
  // Переносит содержимое другого списка в данный список
  void moveHere(list &&other) {
    head_ = other.head_;
    end_ = other.end_;
    size_ = other.size_;

    other.head_ = nullptr;
    other.end_ = nullptr;
    other.size_ = 0;
  }

  // Сливает два отсортированных списка в один отсортированный список
  void merge_sorted(list &left, list &right) {
    Node *left_node = left.head_;
    Node *right_node = right.head_;
    Node *node = nullptr;

    Node *thisHead = nullptr;
    Node *thisEnd = nullptr;
    size_type thisSize = 0;

    while (left_node != nullptr || right_node != nullptr) {
      Node *next_node;
      bool choose_left =
          right_node == nullptr ||
          (left_node != nullptr && left_node->value_ <= right_node->value_);

      if (choose_left) {
        next_node = left_node;
        left_node = left_node->next_;
      } else {
        next_node = right_node;
        right_node = right_node->next_;
      }

      if (node != nullptr) {
        node->next_ = next_node;
        next_node->prev_ = node;
      } else {
        thisHead = next_node;
        next_node->prev_ = nullptr;
      }

      node = next_node;
    }

    thisEnd = node;
    thisSize = left.size_ + right.size_;

    left.head_ = nullptr;
    left.end_ = nullptr;
    left.size_ = 0;

    right.head_ = nullptr;
    right.end_ = nullptr;
    right.size_ = 0;

    head_ = thisHead;
    end_ = thisEnd;
    size_ = thisSize;
  }
};

// Итератор для класса list
template <typename T>
class list<T>::iterator {
 public:
  iterator() : ptr_(nullptr) {}
  explicit iterator(Node *ptr) : ptr_(ptr) {}

  // Возвращает ссылку на значение элемента, на который указывает итератор
  reference operator*() const {
    if (ptr_ == nullptr) {
      static value_type value;
      return value;
    } else {
      return ptr_->value_;
    }
  }

  // Переходит к следующему элементу списка
  iterator &operator++() {
    if (ptr_) ptr_ = ptr_->next_;
    return *this;
  }

  // Переходит к следующему элементу списка, возвращая старое значение
  iterator operator++(int) {
    iterator temp = *this;
    ++(*this);
    return temp;
  }

  // Переходит к предыдущему элементу списка
  iterator &operator--() {
    if (ptr_) ptr_ = ptr_->prev_;
    return *this;
  }

  // Переходит к предыдущему элементу списка, возвращая старое значение
  iterator operator--(int) {
    iterator temp = *this;
    --(*this);
    return temp;
  }

  // Переходит вперед на заданное количество элементов
  iterator operator+(size_type value) const {
    iterator temp = *this;
    while (value-- && temp.ptr_) {
      temp.ptr_ = temp.ptr_->next_;
    }
    return temp;
  }

  // Переходит назад на заданное количество элементов
  iterator operator-(size_type value) const {
    iterator temp = *this;
    while (value-- && temp.ptr_) {
      temp.ptr_ = temp.ptr_->prev_;
    }
    return temp;
  }

  // Проверяет, указывает ли данный итератор на тот же элемент, что и другой
  // итератор
  bool operator==(const iterator &other) const { return ptr_ == other.ptr_; }

  // Проверяет, указывает ли данный итератор на другой элемент, чем другой
  // итератор
  bool operator!=(const iterator &other) const { return ptr_ != other.ptr_; }

 private:
  Node *ptr_;

  friend class list<T>;
};

// Константный итератор для класса list
template <typename T>
class list<T>::const_iterator : public list<T>::iterator {
 public:
  using typename list<T>::iterator::iterator;

  // Возвращает константную ссылку на значение элемента, на который указывает
  // итератор
  const_reference operator*() const { return list<T>::iterator::operator*(); }
};

}  // namespace s21

#endif  // S21_LIST_H_
