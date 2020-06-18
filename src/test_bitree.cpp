#include <iostream>
#include <vector>
#include <time.h>
#include <future>
#include <time.h>

struct Dirct {
  const int Left = 1;
  const int Right = 2;
  const int Middle = 0;
};

struct TreeNode {
  int val;
  std::shared_ptr<TreeNode> left;
  std::shared_ptr<TreeNode> right;
  std::shared_ptr<TreeNode> middle;
  TreeNode(int x) : val(x), left(NULL), right(NULL), middle(NULL) {}
};

// time cost: 0.076
class BiTree {
 public:
  BiTree() = default;
  ~BiTree() = default;

 public:
  inline std::vector<std::string> BinaryTreePaths(std::shared_ptr<TreeNode> root) {
    std::vector<std::string> res;
    if (root == nullptr) { return res; }
    BinaryTreePaths(root, res, "");
    return res;
  }

  inline void BinaryTreePaths(std::shared_ptr<TreeNode> root,
                              std::vector<std::string>& res,
                              std::string path) {
    path += std::to_string(root->val);
    if (root->left == nullptr &&
        root->right == nullptr &&
        root->middle == nullptr) {
      res.push_back(path);
      return;
    }

    if (root->left) { BinaryTreePaths(root->left, res, path + "->"); }
    if (root->right) { BinaryTreePaths(root->right, res, path + "->"); }
    if (root->middle) { BinaryTreePaths(root->middle, res, path + "->"); }
  }
};

int main() {
  Dirct dirc;
  std::shared_ptr<TreeNode> root(new TreeNode(dirc.Middle));
  std::shared_ptr<TreeNode> left1(new TreeNode(dirc.Left));
  std::shared_ptr<TreeNode> mid1(new TreeNode(dirc.Middle));
  std::shared_ptr<TreeNode> right1(new TreeNode(dirc.Right));
  std::shared_ptr<TreeNode> mid21(new TreeNode(dirc.Middle));
  std::shared_ptr<TreeNode> mid22(new TreeNode(dirc.Middle));
  std::shared_ptr<TreeNode> mid23(new TreeNode(dirc.Middle));
  std::shared_ptr<TreeNode> left31(new TreeNode(dirc.Left));
  std::shared_ptr<TreeNode> right32(new TreeNode(dirc.Right));
  std::shared_ptr<TreeNode> left33(new TreeNode(dirc.Left));
  std::shared_ptr<TreeNode> mid34(new TreeNode(dirc.Middle));
  std::shared_ptr<TreeNode> right41(new TreeNode(dirc.Right));
  std::shared_ptr<TreeNode> mid42(new TreeNode(dirc.Middle));
  std::shared_ptr<TreeNode> right43(new TreeNode(dirc.Right));
  std::shared_ptr<TreeNode> left44(new TreeNode(dirc.Left));
  std::shared_ptr<TreeNode> left5(new TreeNode(dirc.Left));

  root->left = left1;
  root->middle = mid1;
  root->right = right1;
  left1->middle = mid21;
  mid1->middle = mid22;
  right1->middle = mid23;
  mid21->left = left31;
  mid21->right = right32;
  mid22->left = left33;
  mid23->middle = mid34;
  left31->right = right41;
  right32->middle = mid42;
  left33->right = right43;
  mid34->left = left44;
  mid42->left = left5;

  clock_t time_start = clock();
  std::shared_ptr<BiTree> bi_tree(new BiTree());
  auto result = bi_tree->BinaryTreePaths(root);
  std::cout << "BinaryTreePaths: " << (clock() - time_start) * 1000.0 /  CLOCKS_PER_SEC << std::endl;

  for (auto i : result) {
    std::cout << i << std::endl;
  }
  return 0;
}




