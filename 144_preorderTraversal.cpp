#include <stack>
#include <vector>
using namespace std;
#define NULL nullptr

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  // 前序遍历，操作  中、左、右
  void preTraversal(TreeNode *cur, vector<int> &vec) {
    if (cur == NULL) return;
    vec.push_back(cur->val);
    preTraversal(cur->left, vec);
    preTraversal(cur->right, vec);
  }

  // 后序遍历，操作  左、右、中
  void postTraversal(TreeNode *cur, vector<int> &vec) {
    if (cur == NULL) return;
    postTraversal(cur->left, vec);
    postTraversal(cur->right, vec);
    vec.push_back(cur->val);
  }

  // 中序遍历，操作  左、中、右
  void inTraversal(TreeNode *cur, vector<int> &vec) {
    if (cur == NULL) return;
    inTraversal(cur->left, vec);
    vec.push_back(cur->val);
    inTraversal(cur->right, vec);
  }

  vector<int> preorderTraversal(TreeNode *root) {
    // 递归法
    // vector<int> result;
    // preTraversal(root, result);
    // return result;

    // 迭代法
    vector<int> result;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    TreeNode *top;
    while (cur != NULL || !st.empty()) {
      while (cur != NULL) {
        result.push_back(cur->val);
        st.push(cur);
        cur = cur->left;
      }
      top = st.top();
      st.pop();
      cur = top->right;
    }
    return result;
  }

  vector<int> postorderTraversal(TreeNode *root) {
    // // 递归法
    // vector<int> result;
    // postTraversal(root, result);
    // return result;

    // 迭代法
    vector<int> result;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    TreeNode *top, *last;
    while (cur != NULL || !st.empty()) {
      while (cur != NULL) {
        st.push(cur);
        cur = cur->left;
      }
      top = st.top();
      if (top->right == NULL || top->right == last) {
        st.pop();
        result.push_back(top->val);
        last = top;
      } else {
        cur = top->right;
      }
    }
    return result;
  }

  vector<int> inorderTraversal(TreeNode *root) {
    // // 递归法
    // vector<int> result;
    // inTraversal(root, result);
    // return result;

    // 迭代法
    vector<int> result;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    // TreeNode *top;
    while (cur != NULL || !st.empty()) {
      while(cur != NULL) {
        st.push(cur);
        cur = cur->left;
      }
      cur = st.top();
      result.push_back(cur->val);
      st.pop();
      cur = cur->right;
    }
    return result;
  }
};

int main() {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(8);

  Solution s;
  vector<int> preResult;
  preResult = s.preorderTraversal(root);
  vector<int> postResult;
  postResult = s.postorderTraversal(root);
  vector<int> inResult;
  inResult = s.inorderTraversal(root);
  return 0;
}