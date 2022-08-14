#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void flip(TreeNode* root)
{
    //Base case to finish the recursive call
    if (root == nullptr) {
        return;
    }
    //Recursive call for the left and right of the node
    flip(root->left);
    flip(root->right);
    // We swap the left and right of the node to flip it
    TreeNode * temp = root->left;
    root->left = root->right;
    root->right = temp;
}
//Function to print the in inorder traversal
void Print_inorder(TreeNode *root)  //Left root right
{
    //Base case
    if (root == nullptr)
        return;
    Print_inorder(root->left);
    cout << root->val << " ";
    Print_inorder(root->right);
}
//Function to print the in preorder traversal
void Print_preorder(TreeNode *root) //Root left right
{
    //Base case
    if (root == nullptr)
        return;
    cout << root->val << " ";
    Print_preorder(root->left);
    Print_preorder(root->right);

}
//Function to print the in postorder traversal
void Print_postorder(TreeNode *root)  // left right root
//Base case
{if (root == nullptr)
    return;
    Print_postorder(root->left);
    Print_postorder(root->right);
    cout << root->val << " ";
}

int main() {
    //First Test case
    TreeNode *root1 =  new TreeNode(1);
    root1->left =  new TreeNode(2);
    root1->right =  new TreeNode(3);
    root1->left->left =  new TreeNode(4);
    root1->left->right =  new TreeNode(5);
    //Calling flip function then print it in inorder traversal
    // you can change the way of printing traversal by calling other functions(preorder,postorder)
    cout<<"First tree after flipping in inorder traversal : "<<endl;
    flip(root1);
    Print_inorder(root1);
    cout<<endl;
    //Second Test case
    TreeNode *root2 =  new TreeNode(0);
    root2->left =  new TreeNode(1);
    root2->right =  new TreeNode(2);
    root2->left->left =  new TreeNode(3);
    root2->left->right =  new TreeNode(4);
    //Calling flip function then print it in inorder traversal
    // you can change the way of printing traversal by calling other functions(preorder,postorder)
    cout<<endl<<"Second tree after flipping in inorder traversal : "<<endl;
    flip(root2);
    Print_inorder(root2);
    cout<<endl;
    //Third Test case
    TreeNode *root3 =  new TreeNode(0);
    root3->left =  new TreeNode(1);
    root3->right =  new TreeNode(2);
    root3->left->left =  new TreeNode(3);
    root3->left->right =  new TreeNode(4);
    root3->right->left=new TreeNode(5);
    //Calling flip function then print it in inorder traversal
    // you can change the way of printing traversal by calling other functions(preorder,postorder)
    cout<<endl<<"Third tree after flipping in inorder traversal : "<<endl;
    flip(root3);
    Print_inorder(root3);
    cout<<endl;
    //Fourth Test case
    TreeNode *root4 =  new TreeNode(0);
    root4->left =  new TreeNode(1);
    root4->right =  new TreeNode(2);
    root4->left->left =  new TreeNode(3);
    root4->left->right =  new TreeNode(4);
    root4->right->left=new TreeNode(5);
    root4->right->left=new TreeNode(6);
    //Calling flip function then print it in inorder traversal
    // you can change the way of printing traversal by calling other functions(preorder,postorder)
    cout<<endl<<"Fourth tree after flipping in inorder traversal : "<<endl;
    flip(root4);
    Print_inorder(root4);
    cout<<endl;
    //Fifth Test case
    TreeNode *root5 =  new TreeNode(5);
    root5->left =  new TreeNode(3);
    root5->right =  new TreeNode(7);
    root5->left->left =  new TreeNode(2);
    root5->left->right =  new TreeNode(4);
    root5->right->left= new TreeNode(6);
    //Calling flip function then print it in inorder traversal
    // you can change the way of printing traversal by calling other functions(preorder,postorder)
    cout<<endl<<"Fifth tree after flipping in inorder traversal : "<<endl;
    flip(root5);
    Print_inorder(root5);

    return 0;
}
