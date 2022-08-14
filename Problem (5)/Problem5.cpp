#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
// write you code here
        //Base case if both trees are empty
        if (p == nullptr && q == nullptr) {
            return true;
        }
        //Recursive call checking both trees are not empty and both trees values are equal their root, left and right
        return (p != nullptr && q != nullptr) && (p->val == q->val) && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

//Function to create tree in case taking input from user with vector
void create_tree(TreeNode *new_node, int i, vector<string> &v) {
    int sz = v.size();
    if (new_node != nullptr) {
        if (2 * i + 1 < sz) {
            if (v[2 * i + 1] == "null" || v[2 * i + 1] == "NULL")
                new_node->left = nullptr;
            else
                new_node->left = new TreeNode(stoi(v[2 * i + 1]));
            create_tree(new_node->left, 2 * i + 1, v);
        }
        if (2 * i + 2 < sz) {
            if (v[2 * i + 2] == "null" || v[2 * i + 2] == "NULL")
                new_node->right = nullptr;
            else
                new_node->right = new TreeNode(stoi(v[2 * i + 2]));
            create_tree(new_node->right, 2 * i + 2, v);
        }
    }
}

//function to make the levels of tree of the given input from user
TreeNode *level_order(vector<string> &v) {
    int sz = v.size();
    if (sz == 0)
        return nullptr;
    TreeNode *head = new TreeNode(stoi(v[0]));
    create_tree(head, 0, v);
    return head;
}

int main() {
    //First Test case
    //First Tree
    TreeNode *eq1_t1;
    eq1_t1 = new TreeNode(1);
    eq1_t1->left = new TreeNode(2);
    eq1_t1->right = new TreeNode(3);
    //Second Tree
    TreeNode *eq1_t2;
    eq1_t2 = new TreeNode(1);
    eq1_t2->left = new TreeNode(2);
    eq1_t2->right = new TreeNode(3);

    //Second Test case
    //First Tree
    TreeNode *eg2_t1;
    eg2_t1 = new TreeNode(1);
    eg2_t1->left = new TreeNode(2);
    //Second Tree
    TreeNode *eg2_t2;
    eg2_t2 = new TreeNode(1);
    eg2_t2->right = new TreeNode(2);

    //Third Test case
    //First Tree
    TreeNode *eg3_t1;
    eg3_t1 = new TreeNode(1);
    eg3_t1->left = new TreeNode(2);
    eg3_t1->right = new TreeNode(1);
    //Second Tree
    TreeNode *eg3_t2;
    eg3_t2 = new TreeNode(1);
    eg3_t2->left = new TreeNode(1);
    eg3_t2->right = new TreeNode(2);

    //Fourth Test case
    //First Tree
    TreeNode *eg4_t1;
    eg4_t1 = new TreeNode(1);
    eg4_t1->left = new TreeNode(1);
    eg4_t1->left->left = new TreeNode(5);
    eg4_t1->right = new TreeNode(2);
    //Second Tree
    TreeNode *eg4_t2;
    eg4_t2 = new TreeNode(1);
    eg4_t2->left = new TreeNode(1);
    eg4_t2->left->left = new TreeNode(5);
    eg4_t2->right = new TreeNode(2);
    Solution obj;

//Checking equality of the two trees in first case
    if (obj.isSameTree(eq1_t1, eq1_t2)) {
        cout << "Same Tree" << endl;
    } else {
        cout << "Not the same Tree" << endl;
    }

    //Checking equality of the two trees in second case
    if (obj.isSameTree(eg2_t1, eg2_t2)) {
        cout << "Same Tree" << endl;
    } else {
        cout << "Not the same Tree" << endl;
    }

    //Checking equality of the two trees in third case
    if (obj.isSameTree(eg3_t1, eg3_t2)) {
        cout << "Same Tree" << endl;
    } else {
        cout << "Not the same Tree" << endl;
    }

    //Checking equality of the two trees in fourth case
    if (obj.isSameTree(eg4_t1, eg4_t2)) {
        cout << "Same Tree" << endl;
    } else {
        cout << "Not the same Tree" << endl;
    }

    // Another way of input if the user wants to input the tree not do it manually in main function
    /*
    vector<string> v1;
    cout << "How many nodes are in the first tree " << endl;
    int nodes1;
    cin >> nodes1;
    cout << "Enter the nodes value of the First tree" << endl;
    while (nodes1--) {
        string elements;
        cin >> elements;
        v1.push_back(elements);
    }
    TreeNode *p = level_order(v1);
    cout << "How many nodes are in the second tree " << endl;
    vector<string> v2;
    int nodes2;
    cin >> nodes2;
    cout << "Enter the nodes value of the Second tree" << endl;
    while (nodes2--) {
        string elements2;
        cin >> elements2;
        v2.push_back(elements2);
    }
    TreeNode *q = level_order(v2);
    Solution obj2;
    if (obj2.isSameTree(p, q)) {
        cout << "Same Tree" << endl;
    } else {
        cout << "Not the same Tree" << endl;
    }
    */
    return 0;
}
