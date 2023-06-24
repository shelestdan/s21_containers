#ifndef __S21_SET_H__
#define __S21_SET_H__

#include <binary_tree/s21_binary_tree.h>

#include <stdexcept>
#include <utility>

namespace s21 {
template <typename Ty>
class set : RBTree<Ty, Ty, false> {
 public:
  using base_type = RBTree<Ty, Ty, false>;
  using key_type = Ty;
  using value_type = Ty;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename base_type::const_iterator;
  using node_type = typename base_type::node_type;
  using size_type = typename base_type::size_type;

  set() {}

  set(std::initializer_list<value_type> const& items) {
    for (const_reference item : items) {
      node_type* node = new node_type(item);
      if (!this->insertNode(node)) {
        delete node;
      }
    }
  }

  set(set& s) : base_type(s) {}

  set(set&& s) : base_type(std::move(s)) {}

  ~set() {}

  set& operator=(set& s) {
    base_type::copyHere(s);
    return *this;
  }

  set& operator=(set&& s) {
    base_type::moveHere(std::move(s));
    return *this;
  }

  iterator begin() { return base_type::cbegin(); }

  iterator end() { return base_type::cend(); }

  iterator rbegin() { return base_type::crbegin(); }

  iterator rend() { return base_type::crend(); }

  bool empty() { return base_type::empty(); }

  size_type size() { return base_type::size(); }

  size_type max_size() { return base_type::max_size(); }

  void clear() { base_type::clear(); }

  std::pair<iterator, bool> insert(const_reference value) {
    std::pair<node_type*, bool> insertResult = base_type::insertValue(value);
    return std::pair<iterator, bool>(iterator(insertResult.first),
                                     insertResult.second);
  }

  template <typename... Args>
  s21::vector<std::pair<iterator, bool>> emplace(Args&&... args) {
    std::initializer_list<value_type> items = {args...};

    vector<std::pair<iterator, bool>> resultVec;

    for (const_reference item : items) {
      std::pair<node_type*, bool> insertRes = base_type::insertValue(item);
      resultVec.push_back(std::pair<iterator, bool>(iterator(insertRes.first),
                                                    insertRes.second));
    }

    return resultVec;
  }

  void erase(iterator pos) { base_type::erase(pos); }

  void swap(set& other) { base_type::swap(other); }

  void merge(set& other) { base_type::merge(other); }

  iterator find(const key_type& key) {
    return iterator(base_type::searchNode(key));
  }

  bool contains(const key_type& key) {
    return base_type::searchNode(key) != nullptr;
  }

 private:
  const key_type& getValueKey(const_reference value) override { return value; }
};
}  // namespace s21

#endif  // __S21_SET_H__