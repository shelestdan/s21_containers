#ifndef __S21_MULTISET_H__
#define __S21_MULTISET_H__

#include <binary_tree/s21_binary_tree.h>

namespace s21 {
template <typename Ty>
class multiset : RBTree<Ty, Ty, true> {
 public:
  using base_type = RBTree<Ty, Ty, true>;
  using key_type = Ty;
  using value_type = Ty;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename base_type::const_iterator;
  using size_type = typename base_type::size_type;
  using node_type = typename base_type::node_type;

  multiset() {}

  multiset(std::initializer_list<value_type> const& items) {
    for (const_reference item : items) {
      node_type* node = new node_type(item);
      if (!this->insertNode(node)) {
        delete node;
      }
    }
  }

  multiset(const multiset& ms) : base_type(ms) {}

  multiset(multiset&& ms) : base_type(std::move(ms)) {}

  ~multiset() {}

  multiset& operator=(multiset& ms) {
    base_type::copyHere(ms);
    return *this;
  }

  multiset& operator=(multiset&& ms) {
    base_type::moveHere(std::move(ms));
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

  iterator insert(const_reference value) {
    node_type* newNode = new node_type(value);
    base_type::insertNode(newNode);
    return iterator(newNode);
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

  void swap(multiset& other) { base_type::swap(other); }

  void merge(multiset& other) { base_type::merge(other); }

  size_type count(const key_type& key) {
    size_type nodesCount = 0;

    std::pair<iterator, iterator> keyEqRange = equal_range(key);
    for (iterator& iter = keyEqRange.first; iter != keyEqRange.second; ++iter) {
      nodesCount += 1;
    }

    return nodesCount;
  }

  iterator find(const key_type& key) {
    return iterator(base_type::searchNode(key));
  }

  bool contains(const key_type& key) {
    return this->searchNode(key) != nullptr;
  }

  std::pair<iterator, iterator> equal_range(const key_type& key) {
    node_type* node = base_type::getRootNode();
    node_type* lowerNode = nullptr;
    node_type* upperNode = nullptr;

    while (node != nullptr) {
      const key_type& nodeKey = getValueKey(node->value);
      if (nodeKey < key) {
        node = node->right;
      } else {
        if (upperNode == nullptr && key < nodeKey) {
          upperNode = node;
        }

        lowerNode = node;
        node = node->left;
      }
    }

    node = upperNode == nullptr ? base_type::getRootNode() : upperNode->left;
    while (node != nullptr) {
      if (key < getValueKey(node->value)) {
        upperNode = node;
        node = node->left;
      } else {
        node = node->right;
      }
    }

    return std::pair<iterator, iterator>(iterator(lowerNode),
                                         iterator(upperNode));
  }

  iterator lower_bound(const key_type& key) { return equal_range(key).first; }

  iterator upper_bound(const key_type& key) { return equal_range(key).second; }

 private:
  const key_type& getValueKey(const_reference value) override { return value; }
};
}  // namespace s21

#endif  // __S21_MULTISET_H__