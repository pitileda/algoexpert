#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

  BST& insert(int val) {
    BST* current = this;
    while (current->left != nullptr &&
           current->right != nullptr) {
      if (val < current->value) {
        current = current->left;
        continue;
      }
      current = current->right;
    }
    if (val < current->value) {
      current->left = new BST(val);
    } else {
      current->right = new BST(val);
    }
    return *this;
  }

  bool contains(int val) {
    BST* current = this;
    while (current != nullptr) {
      if (current->value == val) {
        return true;
      }
    }
    return false;
  }

  BST* get(int val) {
    BST* current = this;
    if (current == nullptr) {
      return nullptr;
    }
    if (current->value == val) {
      return current;
    }
    if (current->left) {
      current->left->get(val);
    }
    if (current->right) {
      current->right->get(val);
    }
  }

  BST& remove(int val) {
    BST* to_remove = get(val);
    if (to_remove) {
      if (to_remove->left == nullptr && to_remove->right == nullptr) {

      }
    }
    return *this;
  }
};

int main(int argc, char *argv[])
{
  BST bst(10);

  bst.insert(5).insert(15).insert(2).insert(5).insert(1).insert(15);
  bst.insert(13).insert(22).insert(14);
  bst.remove(2);
  return 0;
}

