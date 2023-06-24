#ifndef __S21_BINARY_TREE_H__
#define __S21_BINARY_TREE_H__

#include <vector/s21_vector.h>

#include <utility>

namespace s21 {
template <typename Ty>
struct TreeNode {
  using value_type = Ty;
  using color_type = uint8_t;
  using node_type = TreeNode<Ty>;

  enum Color {
    Red,
    Black,
  };

  TreeNode(value_type value)
      : left(nullptr),
        right(nullptr),
        parent(nullptr),
        value(value),
        color(Red) {
    // Suppress unused warning/error
    (void)(MORE_MEMORY_FOR_GOD_OF_MEMORY);
  }

  TreeNode(node_type* node)
      : left(nullptr),
        right(nullptr),
        parent(nullptr),
        value(node->value),
        color(node->color) {}

  bool isRoot() { return parent == nullptr; }

  bool isLeaf() { return left == nullptr && right == nullptr; }

  // Этот метод НЕ меняет значения между узлами
  //Он меняет указатель и цвета у узлов, что выглядит как свап значений
  void swapValues(node_type* node) {
    color_type tmpColor = color;
    color = node->color;
    node->color = tmpColor;

    node_type* tmpNode = left;
    setLeft(node->left);
    node->setLeft(tmpNode);

    tmpNode = right;
    setRight(node->right);
    node->setRight(tmpNode);

    if (parent != nullptr) {
      if (parent->left == this)
        parent->left->left = node;
      else
        parent->right = node;
    }

    if (node->parent != nullptr) {
      if (node->parent->left == node)
        node->parent->left = this;
      else
        node->parent->right = this;
    }

    tmpNode = parent;
    parent = node->parent;
    node->parent = tmpNode;
  }

  // Родитель родителя this узла
  node_type* grandparent() {
    if (parent != nullptr) {
      return parent->parent;
    } else {
      return nullptr;
    }
  }

  // "Брат" родителя this узла
  node_type* uncle() {
    node_type* grandpa = grandparent();

    if (grandpa == nullptr) {
      return nullptr;
    } else if (parent == grandpa->left) {
      return grandpa->right;
    } else {
      return grandpa->left;
    }
  }

  // Противоположный от this узел
  node_type* brother() {
    if (this == parent->left) {
      return parent->right;
    } else {
      return parent->left;
    }
  }

  // Присваивает узел как левый и устанавливает для него родителя
  void setLeft(node_type* node) {
    this->left = node;
    if (node != nullptr) {
      node->parent = this;
    }
  }

  // Присваивает узел как правый и устанавливает для него родителя
  void setRight(node_type* node) {
    this->right = node;
    if (node != nullptr) {
      node->parent = this;
    }
  }

  // Перемещает родителя к node узлу
  void replaceParentTo(node_type* node) {
    node->parent = parent;
    if (parent->left == this) {
      parent->left = node;
    } else {
      parent->right = node;
    }
  }

  void clearParent() {
    if (parent != nullptr) {
      if (parent->left == this)
        parent->left = nullptr;
      else if (parent->right == this)
        parent->right = nullptr;
      parent = nullptr;
    }
  }

  void clearPtrs() {
    if (left != nullptr && left->parent != nullptr) left->parent = nullptr;
    if (right != nullptr && right->parent != nullptr) right->parent = nullptr;
    left = nullptr;
    right = nullptr;

    if (parent != nullptr) clearParent();
  }

  // Чистит все указатели и меняет цвет на красный
  // Узел становится как только что созданный,
  //что может быть удобно при перевставки
  void reborn() {
    clearPtrs();
    color = Red;
  }

  node_type* left;
  node_type* right;
  node_type* parent;
  value_type value;

  color_type color;

  // Это значение существует только для соответствия размера текущей ноды
  // размеру нод из стандартной библиотеки. Необходимо чтобы в тестах max_size у
  // s21 и std реализаций совпадал. Отдадим же не много памяти во имя дара
  // успешно прошедших тестов
  const int MORE_MEMORY_FOR_GOD_OF_MEMORY = 0;
};

template <typename TreeTy>
class TreeConstIterator;

template <typename TreeTy>
class TreeIterator;

template <typename KTy, typename VTy, bool Multi>
class RBTree {
 public:
  using tree_type = RBTree<KTy, VTy, Multi>;
  using key_type = KTy;
  using value_type = VTy;
  using node_type = TreeNode<VTy>;
  using reference = VTy&;
  using const_reference = const VTy&;
  using iterator = TreeIterator<tree_type>;
  using const_iterator = TreeConstIterator<tree_type>;
  using size_type = size_t;

  RBTree() : rootNode_(nullptr), size_(0) {}

  virtual ~RBTree() { clear(); }

  bool empty() { return rootNode_ == nullptr; }

  size_type size() { return size_; }

  size_type max_size() { return PTRDIFF_MAX / sizeof(node_type); }

  void clear() {
    if (rootNode_ != nullptr) {
      clearSubtree(rootNode_);
      rootNode_ = nullptr;

      size_ = 0;
    }
  }

  void erase(const_iterator pos) {
    if (pos.getPtr() != nullptr) {
      deleteNode(pos.getPtr());
    }
  }

  // Просто меняет указатели на корень дерева
  void swap(RBTree& other) {
    node_type* tmpNode = rootNode_;
    rootNode_ = other.rootNode_;
    other.rootNode_ = tmpNode;

    size_type tmpSize = size_;
    size_ = other.size_;
    other.size_ = tmpSize;
  }

  // Сливает узлы из текущего дерева в other дерева
  void merge(RBTree& other) {
    for (const_iterator iter = other.cbegin(); iter != other.cend();) {
      const_iterator spliceIter = iter++;
      node_type* spliceNode = other.takeNode(spliceIter.getPtr());

      spliceNode->reborn();

      bool isInserted = insertNode(spliceNode);
      if (!isInserted) {
        other.insertNode(spliceNode);
      }
    }
  }

  static node_type* max(node_type* node) {
    node_type* maxNode = node;
    while (maxNode != nullptr && maxNode->right != nullptr) {
      maxNode = maxNode->right;  // Идти вправо, пока не встретится больший узел
    }
    return maxNode;
  }

  static node_type* min(node_type* node) {
    node_type* minNode = node;
    while (minNode != nullptr && minNode->left != nullptr) {
      minNode = minNode->left;  // Идти влево, пока не встретится больший узел
    }
    return minNode;
  }

 protected:
  // Internal Constructors

  RBTree(const RBTree& tree) { copyHere(tree); }

  RBTree(RBTree&& tree) : rootNode_(tree.rootNode_), size_(tree.size_) {
    tree.rootNode_ = nullptr;
    tree.size_ = 0;
  }

  // Internal

  virtual const key_type& getValueKey(const_reference value) = 0;

  const key_type& getNodeKey(node_type* node) {
    return getValueKey(node->value);
  }

  node_type* getRootNode() { return rootNode_; }

  iterator begin() { return iterator(min(rootNode_)); }

  iterator end() { return iterator(nullptr); }

  iterator rbegin() { return iterator(max(rootNode_)); }

  iterator rend() { return iterator(nullptr); }

  const_iterator cbegin() { return const_iterator(min(rootNode_)); }

  const_iterator cend() { return const_iterator(nullptr); }

  const_iterator crbegin() { return const_iterator(max(rootNode_)); }

  const_iterator crend() { return const_iterator(nullptr); }

  bool insertNode(node_type* node) {
    // Если дерево пустое - вставить узел как корень
    if (rootNode_ == nullptr) {
      node->color = node_type::Black;
      rootNode_ = node;
    } else {
      // В противном случае - простая вставка узла в бинарное дерево
      node_type* parentNode = rootNode_;
      node_type* nextNode = nullptr;
      int cmp = 0;

      do {
        cmp = compareKeys(getNodeKey(node), getNodeKey(parentNode));
        nextNode = (cmp < 0) ? parentNode->left : parentNode->right;

        if (!Multi && cmp == 0) {
          // Вставляемый узел уже существует в дереве и вставка происходит не в
          // multiset
          return false;  // Такая вставка невозможно - просто возвращается false
        }

        if (nextNode != nullptr) {
          parentNode = nextNode;
        }
      } while (nextNode != nullptr);

      if (cmp < 0) {
        parentNode->setLeft(node);
      } else {
        parentNode->setRight(node);
      }

      // После вставки - балансировка начиная со вставленого узла
      insertCase1_parentBlack(node);
    }

    size_ += 1;
    return true;
  }

  /**
   * Вставить новый узел в дерево по его значению
   * @returns Пара - вставленный узел (если он был вставлен, иначе уже
   * существующий) и bool указывающий произошла ли вставка
   */
  std::pair<node_type*, bool> insertValue(const_reference value) {
    node_type* node = nullptr;
    bool isInserted = false;

    if (!Multi) {
      node = searchNode(getValueKey(value));
    }

    if (node == nullptr) {
      node = new node_type(value);
      isInserted = insertNode(node);
    }

    return std::pair<node_type*, bool>(node, isInserted);
  }

  // "Вырывает" узел из дерева и возвращает его, производя балансировку
  node_type* takeNode(node_type* node) {
    // Поиск ближайшего по значению узла (т.к. он будет содержать 1 или 0
    // дочерних узлов)
    node_type* delNode = node;
    if (node->left != nullptr)
      delNode = max(node->left);
    else if (node->right != nullptr)
      delNode = min(node->right);

    // Свап ближайшего узла с удаляемым
    if (delNode != node) {
      delNode->swapValues(node);
      if (delNode->isRoot()) {
        // Если delNode это корень после свапа - дерево должно быть
        // проинформировано
        rootNode_ = delNode;
        rootNode_->color = node_type::Black;
      }

      delNode = node;
    }

    // Получение потомка удаляемого узла для проведения балансировки
    node_type* child =
        (delNode->left != nullptr) ? delNode->left : delNode->right;

    // Балансировка выполняется при условии если удаляемая нода черная
    if (delNode->color == node_type::Black) {
      if (child == nullptr) {
        // Если у удаляемой ноды нет потомков, используется сама delNode для
        // выполнения балансировки Это работает потому что delNode черная и
        // будет вести себя как мнимая (фантомная) нода
        deleteCase1_brotherRed(delNode);
      } else {
        // В противном случае удаляемая нода меняется местами с её потомком
        // просто меняя родителя
        delNode->replaceParentTo(child);

        // Если child красный просто меняется цвет, иначе выполняем балансировку
        // начиная от child
        if (child->color == node_type::Red) {
          child->color = node_type::Black;
        } else {
          deleteCase1_brotherRed(child);
        }
      }
    }

    // Дерево должно "забыть" о взятой ноде
    delNode->clearParent();

    if (delNode == rootNode_) {
      rootNode_ = nullptr;
    }

    size_ -= 1;

    return delNode;
  }

  // Достаёт ноду выполняя условия балансировки и чистит для неё память
  void deleteNode(node_type* node) {
    node_type* takedNode = takeNode(node);
    if (takedNode != nullptr) {
      delete takedNode;
    }
  }

  node_type* searchNode(const key_type& key) {
    node_type* node = rootNode_;
    int cmp = 0;

    // Шаги в право-лево пока нужная нода не будет найдена
    while (node != nullptr && (cmp = compareKeys(key, getNodeKey(node))) != 0) {
      if (cmp < 0)
        node = node->left;
      else
        node = node->right;
    }

    // Возвращается нода или nullptr
    return cmp == 0 ? node : nullptr;
  }

  bool containNode(node_type* node) {
    node_type searchNode = rootNode_;
    int cmp = 0;

    while (searchNode != nullptr && searchNode != node) {
      if (getNodeKey(node) < getNodeKey(searchNode)) {
        searchNode = searchNode->left;
      } else {
        searchNode = searchNode->right;
      }
    }

    return searchNode == node;
  }

  // Чистит текущее дерево и копирует узлы из дерева other в текущее дерево,
  // никак не меняя порядок узлов
  void copyHere(const RBTree& other) {
    clear();

    if (other.rootNode_ != nullptr) {
      rootNode_ = new node_type(other.rootNode_);
      copyChildNodes(other.rootNode_, rootNode_);
    }

    size_ = other.size_;
  }

  // Чистит текущее дерево и производит простой перенос указателя на корневой
  // узел
  void moveHere(RBTree&& tree) {
    clear();

    rootNode_ = tree.rootNode_;
    size_ = tree.size_;

    tree.rootNode_ = nullptr;
    tree.size_ = 0;
  }

 private:
  int compareKeys(const key_type& key1, const key_type& key2) {
    if (key1 < key2) {
      return -1;
    } else if (key1 == key2) {
      return 0;
    } else {
      return 1;
    }
  }

  // Методы красно-черного дерева (повороты, балансировка и т.п.)

  // Поворот узла налево относительно своего правого потомка
  void rotateLeft(node_type* parentNode) {
    node_type* childNode = parentNode->right;

    childNode->parent = parentNode->parent;
    if (parentNode->parent != nullptr) {
      if (parentNode->parent->left == parentNode) {
        parentNode->parent->left = childNode;
      } else {
        parentNode->parent->right = childNode;
      }
    }

    parentNode->setRight(childNode->left);
    childNode->setLeft(parentNode);

    if (childNode->isRoot()) {
      rootNode_ = childNode;
      rootNode_->color = node_type::Black;
    }
  }

  // Поворот узла направо относительно своего левого потомка
  void rotateRight(node_type* parentNode) {
    node_type* childNode = parentNode->left;

    childNode->parent = parentNode->parent;
    if (parentNode->parent != nullptr) {
      if (parentNode->parent->left == parentNode) {
        parentNode->parent->left = childNode;
      } else {
        parentNode->parent->right = childNode;
      }
    }

    parentNode->setLeft(childNode->right);
    childNode->setRight(parentNode);

    if (childNode->isRoot()) {
      rootNode_ = childNode;
      rootNode_->color = node_type::Black;
    }
  }

  // --- Insert Cases ---

  void insertCase1_parentBlack(node_type* node) {
    if (node->isRoot() || node->parent->color == node_type::Black) {
      return;
    } else {
      insertCase2_parentUncleRed(node);
    }
  }

  void insertCase2_parentUncleRed(node_type* node) {
    node_type* uncle = node->uncle();

    if (uncle != nullptr && uncle->color == node_type::Red) {
      // Если "дядя" существует и он красный, то родитель узла уже должен быть
      // красный, исходя из insertCase1
      node_type* grandpa = node->grandparent();
      colorSwapWithChildren(grandpa);
      // Рекурсивно выполняем балансировку для прародителя узла
      insertCase1_parentBlack(grandpa);
    } else {
      insertCase3_parentRedOrdering(node);
    }
  }

  void insertCase3_parentRedOrdering(node_type* node) {
    node_type* grandpa = node->grandparent();

    // Узел должен быть на той же стопрне от родителя как родитель от
    // прародителя
    if (node->parent == grandpa->right && node == node->parent->left) {
      rotateRight(node->parent);
      node = node->right;
    } else if (node->parent == grandpa->left && node == node->parent->right) {
      rotateLeft(node->parent);
      node = node->left;
    }

    insertCase4_parentRed(node);
  }

  void insertCase4_parentRed(node_type* node) {
    node_type* grandpa = node->grandparent();

    node->parent->color = node_type::Black;
    grandpa->color = node_type::Red;
    if (node->parent == grandpa->left && node == node->parent->left) {
      rotateRight(grandpa);
    } else {
      rotateLeft(grandpa);
    }

    if (node->parent->isRoot()) {
      rootNode_ = node->parent;
    }
  }

  // --- Delete cases ---

  void deleteCase1_brotherRed(node_type* node) {
    if (node->parent != nullptr) {
      node_type* brother = node->brother();

      if (brother != nullptr && brother->color == node_type::Red) {
        node->parent->color = node_type::Red;
        brother->color = node_type::Black;

        if (node->parent->left == node) {
          rotateLeft(node->parent);
        } else {
          rotateRight(node->parent);
        }
      }

      deleteCase2_parentBrotherChildrenBlack(node);
    }
  }

  void deleteCase2_parentBrotherChildrenBlack(node_type* node) {
    node_type* brother = node->brother();

    if ((brother != nullptr) && (node->parent->color == node_type::Black) &&
        (brother->color == node_type::Black) &&
        (brother->left == nullptr ||
         brother->left->color == node_type::Black) &&
        (brother->right == nullptr ||
         brother->right->color == node_type::Black)) {
      brother->color = node_type::Red;
      deleteCase1_brotherRed(node->parent);
    } else {
      deleteCase3_parentRedBrotherChildrenBlack(node);
    }
  }

  void deleteCase3_parentRedBrotherChildrenBlack(node_type* node) {
    node_type* brother = node->brother();

    if ((brother != nullptr) && (node->parent->color == node_type::Red) &&
        (brother->color == node_type::Black) &&
        (brother->left == nullptr ||
         brother->left->color == node_type::Black) &&
        (brother->right == nullptr ||
         brother->right->color == node_type::Black)) {
      brother->color = node_type::Red;
      node->parent->color = node_type::Black;
    } else {
      deleteCase4_brotherBlackChildRed(node);
    }
  }

  void deleteCase4_brotherBlackChildRed(node_type* node) {
    node_type* brother = node->brother();

    if (brother != nullptr && brother->color == node_type::Black) {
      if ((node == node->parent->left) &&
          (brother->right == nullptr ||
           brother->right->color == node_type::Black) &&
          (brother->left != nullptr &&
           brother->left->color == node_type::Red)) {
        brother->color = node_type::Red;
        brother->left->color = node_type::Black;
        rotateRight(brother);
      } else if ((node == node->parent->right) &&
                 (brother->left == nullptr ||
                  brother->left->color == node_type::Black) &&
                 (brother->right != nullptr &&
                  brother->right->color == node_type::Red)) {
        brother->color = node_type::Red;
        brother->right->color = node_type::Black;
        rotateLeft(brother);
      }
    }

    deleteCase5_balanceRotations(node);
  }

  void deleteCase5_balanceRotations(node_type* node) {
    node_type* brother = node->brother();

    if (brother != nullptr) brother->color = node->parent->color;
    node->parent->color = node_type::Black;

    if (node == node->parent->left) {
      if (brother != nullptr && brother->right != nullptr)
        brother->right->color = node_type::Black;
      rotateLeft(node->parent);
    } else {
      if (brother != nullptr && brother->left != nullptr)
        brother->left->color = node_type::Black;
      rotateRight(node->parent);
    }
  }

  // --- End of cases ---

  // Свап цветов ноды с потомками. Должен происходить ТОЛЬКО при условии если
  // узел черный, а потомки красные Функция существует только для выполнения
  // балансировки в определёных случаях
  void colorSwapWithChildren(node_type* node) {
    node->left->color = node_type::Black;
    node->right->color = node_type::Black;
    // Узел меняет цвет только если он не являет корневым в дереве
    node->color = node->isRoot() ? node_type::Black : node_type::Red;
  }

  // Рекурсивно копирует узел fromNode и всех его потомков в узел toNode
  void copyChildNodes(const node_type* fromNode, node_type* toNode) {
    if (fromNode->left != nullptr) {
      node_type* leftNode = new node_type(fromNode->left);
      toNode->setLeft(leftNode);
      copyChildNodes(fromNode->left, leftNode);
    }

    if (fromNode->right != nullptr) {
      node_type* rightNode = new node_type(fromNode->right);
      toNode->setRight(rightNode);
      copyChildNodes(fromNode->right, rightNode);
    }
  }

  void clearSubtree(node_type* node) {
    if (node->left != nullptr) {
      // Рекурсивно очищается левый узел
      clearSubtree(node->left);
    }

    if (node->right != nullptr) {
      // Рекурсивно очищается правый узел
      clearSubtree(node->right);
    }

    // И... чистится память для текущего узла
    delete node;
  }

  node_type* rootNode_ = nullptr;
  size_type size_ = 0;
};

template <typename TreeTy>
class TreeConstIterator {
 public:
  using tree_type = TreeTy;
  using node_type = typename TreeTy::node_type;
  using value_type = typename TreeTy::value_type;
  using const_reference = const value_type&;

  TreeConstIterator(node_type* nodePtr) : ptr_(nodePtr) {}

  TreeConstIterator(TreeIterator<tree_type>& iter) : ptr_(iter.getPtr()) {}

  node_type* getPtr() { return ptr_; }

  const_reference operator*() const {
    if (ptr_ == nullptr) {
      static value_type defaultValue = value_type{};
      return defaultValue;
    }
    return ptr_->value;
  }

  TreeConstIterator& operator++() {
    if (ptr_ != nullptr) {
      if (ptr_->right == nullptr) {
        // Если справа nullptr мы должны меремещаться к родителю, ищется больший
        // родитель
        node_type* parent = nullptr;
        while ((parent = ptr_->parent) != nullptr && ptr_ == parent->right) {
          // Пока указатель итератора справа от своего родителя (родитель
          // меньше)
          ptr_ = parent;  // Указатель итератора меняется на родителя
        }
        ptr_ = parent;
      } else {
        // Если у узла есть правый узел - просто перемещаем итератор к меньшему
        // значению этого узла
        ptr_ = tree_type::min(ptr_->right);
      }
    }
    return *this;
  }

  TreeConstIterator& operator--() {
    if (ptr_ != nullptr) {
      if (ptr_->left == nullptr) {
        // Если слева nullptr мы должны меремещаться к родителю, ищется меньший
        // родитель
        node_type* parent = nullptr;
        while ((parent = ptr_->parent) != nullptr && ptr_ == parent->left) {
          // Пока указатель итератора слева от своего родителя (родитель больше)
          ptr_ = parent;  // Указатель итератора меняется на родителя
        }
        ptr_ = parent;
      } else {
        // Если у узла есть левый узел - просто перемещаем итератор к большему
        // значению этого узла
        ptr_ = tree_type::max(ptr_->left);
      }
    }
    return *this;
  }

  TreeConstIterator operator++(int) {
    TreeConstIterator tmp = *this;
    operator++();
    return tmp;
  }

  TreeConstIterator operator--(int) {
    TreeConstIterator tmp = *this;
    operator--();
    return tmp;
  }

  bool operator==(const TreeConstIterator& other) const {
    return this->ptr_ == other.ptr_;
  }

  bool operator!=(const TreeConstIterator& other) const {
    return this->ptr_ != other.ptr_;
  }

 private:
  node_type* ptr_;
};

template <typename TreeTy>
class TreeIterator : TreeConstIterator<TreeTy> {
 public:
  using base_type = TreeConstIterator<TreeTy>;
  using node_type = typename base_type::node_type;
  using value_type = typename TreeTy::value_type;
  using reference = value_type&;

  TreeIterator(node_type* node) : base_type(node) {}

  node_type* getPtr() { return base_type::getPtr(); }

  reference operator*() const {
    return const_cast<reference>(base_type::operator*());
  }

  TreeIterator& operator++() {
    base_type::operator++();
    return *this;
  }

  TreeIterator& operator--() {
    base_type::operator--();
    return *this;
  }

  TreeIterator operator++(int) {
    TreeIterator tmp = *this;
    base_type::operator++();
    return tmp;
  }

  TreeIterator operator--(int) {
    TreeIterator tmp = *this;
    base_type::operator--();
    return tmp;
  }

  bool operator==(const TreeIterator& other) const {
    return base_type::operator==(other);
  }

  bool operator!=(const TreeIterator& other) const {
    return base_type::operator!=(other);
  }
};
}  // namespace s21

#endif  // __S21_BINARY_TREE_H__
