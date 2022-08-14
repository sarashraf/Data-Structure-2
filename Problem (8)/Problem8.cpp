#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
using namespace std;
//the count is equal to first index in preorder then search for this element in inorder
int cnt = 0;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}

};

//Function to construct Binary tree from given inorder and preorder of the tree
TreeNode *tree(string preorder, string inorder, int begin, int end) {
    //Base case
    if (begin > end) {
        return nullptr;
    }
    TreeNode *node = new TreeNode(preorder[cnt]);
    //Increasing the count to check for the remaining elements
    cnt++;
    //Tree is constructed
    if (begin == end)
        return node;
    int index;
    for (int i = 0; i <= end; ++i) {
        //finding the index of the element in the inorder traversal
        if (inorder[i] == node->val)
            index = i;
    }
    //Recursive function to make the left subtree  from the beginning till the last index before the root we constructed
    node->left = tree(preorder, inorder, begin, index - 1);
    //Recursive function to make the right subtree  from the next  index after the root we constructed till the end
    node->right = tree(preorder, inorder, index + 1, end);
    return node;
}

void postOrder(TreeNode *tree) {  //Left right root
    //Base case
    if (tree == NULL)
        return;
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->val;
}

//A function taking the inorder and preorder of the function then print it in postorder traversal
void printPostOrder(string &preorder, string &inorder) {
    //Calling function that constructs binary tree from inorder and preorder traversal
    TreeNode *root = tree(preorder, inorder, 0, preorder.size() - 1);
    //calling post order function with given parameter binary tree
    postOrder(root);
    //Reinitialize the count with zero for the more test cases
    cnt = 0;
}

int main() {
    //First Test case
    string s1 = "124795368";
    string s2 = "794251368";
    cout<<"postorder: ";
    printPostOrder(s1, s2);
    cout << endl;
    //Second Test case
    string s3 = "ABC";
    string s4 = "ABC";
    cout<<"postorder: ";
    printPostOrder(s3, s4);
    cout << endl;
    //Third Test case
    string s5 = "ABDEC";
    string s6 = "DBEAC";
    cout<<"postorder: ";
    printPostOrder(s5, s6);
    cout << endl;
    //Fouth Test case
    string s7 = "ABFGC";
    string s8 = "FBGAC";
    cout<<"postorder: ";
    printPostOrder(s7, s8);
    cout << endl;
    //Fifth Test case
    string s9 = "12453";
    string s10 = "42513";
    cout<<"postorder: ";
    printPostOrder(s9, s10);
    cout << endl;

    //In case you want to enter the five test cases in console uncomment the code below,please

    /*string pre,in;
        for(int i = 0;i< 5 ;i++){
            cin>>pre>>in;
            printPostOrder(pre,in);
        }
*/
    return 0;
}
