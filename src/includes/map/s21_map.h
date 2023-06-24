#ifndef __S21_MAP_H__
#define __S21_MAP_H__

#include <binary_tree/s21_binary_tree.h>

#include <stdexcept>
#include <utility>

namespace s21 {
template <typename KTy, typename VTy>
class map : RBTree<KTy, std::pair<const KTy, VTy>, false> {
 public:
  using base_type = RBTree<KTy, std::pair<const KTy, VTy>, false>;
  using key_type = KTy;
  using mapped_type = VTy;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename base_type::iterator;
  using const_iterator = typename base_type::const_iterator;
  using size_type = size_t;
  using node_type = typename base_type::node_type;

  map() {}

  map(std::initializer_list<value_type> const& items) {
    for (const_reference item : items) {
      node_type* node = new node_type(item);
      if (!base_type::insertNode(node)) {
        delete node;
      }
    }
  }

  map(map& m) : base_type(m) {}

  map(map&& m) : base_type(std::move(m)) {}

  ~map() {}

  map& operator=(map& m) {
    base_type::copyHere(m);
    return *this;
  }

  map& operator=(map&& m) {
    base_type::moveHere(std::move(m));
    return *this;
  }

  iterator begin() { return base_type::begin(); }

  iterator end() { return base_type::end(); }

  iterator rbegin() { return base_type::rbegin(); }

  iterator rend() { return base_type::rend(); }

  const_iterator cbegin() { return base_type::cbegin(); }

  const_iterator cend() { return base_type::cend(); }

  const_iterator crbegin() { return base_type::crbegin(); }

  const_iterator crend() { return base_type::crend(); }

  mapped_type& at(const key_type& key) {
    node_type* node = this->searchNode(key);
    if (node == nullptr) {
      throw std::out_of_range("Node was not found");
    }
    return node->value.second;
  }

  mapped_type& operator[](const key_type& key) {
    node_type* node = this->searchNode(key);
    if (node == nullptr) {
      node = new node_type(value_type(key, mapped_type()));
      this->insertNode(node);
    }
    return node->value.second;
  }

  bool empty() { return base_type::empty(); }

  size_type size() { return base_type::size(); }

  size_type max_size() { return base_type::max_size(); }

  void clear() { base_type::clear(); }

  std::pair<iterator, bool> insert(const value_type& value) {
    std::pair<node_type*, bool> insertResult = base_type::insertValue(value);
    return std::pair<iterator, bool>(iterator(insertResult.first),
                                     insertResult.second);
  }

  std::pair<iterator, bool> insert(const key_type& key,
                                   const mapped_type& obj) {
    std::pair<node_type*, bool> insertResult =
        base_type::insertValue(value_type(key, obj));
    return std::pair<iterator, bool>(iterator(insertResult.first),
                                     insertResult.second);
  }

  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj) {
    std::pair<node_type*, bool> insertResult =
        base_type::insertValue(value_type(key, obj));

    if (!insertResult.second) {
      insertResult.first->value.second = obj;
    }

    return std::pair<iterator, bool>(iterator(insertResult.first),
                                     insertResult.second);
  }

  template <typename... Args>
  s21::vector<std::pair<iterator, bool>> emplace(Args&&... args) {
    std::initializer_list<value_type> items = {args...};

    vector<std::pair<iterator, bool>> resultVec;

    for (const_reference item : items) {
      std::pair<node_type*, bool> insertRes = this->insertValue(item);
      resultVec.push_back(std::pair<iterator, bool>(iterator(insertRes.first),
                                                    insertRes.second));
    }

    return resultVec;
  }

  void erase(iterator pos) {
    base_type::erase(static_cast<const_iterator>(pos));
  }

  void swap(map& other) { base_type::swap(other); }

  void merge(map& other) { base_type::merge(other); }

  bool contains(const key_type& key) {
    return base_type::searchNode(key) != nullptr;
  }

 private:
  const key_type& getValueKey(const_reference value) override {
    return value.first;
  }
};
}  // namespace s21

#endif  // __S21_MAP_H__