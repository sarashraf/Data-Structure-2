#include <iostream>
#include <vector>
using namespace std;
//class node to create a nose in the tree
class node
{
public:
    int data;
    node*left,*right;
    //contructor whichset tha value of the node
    node(int value)
    {
        data=value;
        left =right=NULL;
    }
//destructor
    ~node()
    {
        delete[] left;
        delete[] right;
    }
};

//function to print the trre
void Inorder(node*r)
{
    if(r==NULL)
        return;
    Inorder(r->left);
    cout<<r->data<<"  ";
    Inorder(r->right);
}
//function to create the binary tree
void createTree(node* rnode, int i, vector<string>& arr) {
    if (rnode != nullptr) {
        if (2 * i + 1 < arr.size()) {
            if (arr[2 * i + 1] == "null")
                rnode->left = nullptr;
            else
                rnode->left = new node(stoi(arr[2 * i + 1]));
            createTree(rnode->left, 2 * i + 1, arr);
        }

        if (2 * i + 2 < arr.size()) {
            if (arr[2 * i + 2] == "null")
                rnode->right = nullptr;
            else
                rnode->right = new node(stoi(arr[2 * i + 2]));
            createTree(rnode->right, 2 * i + 2, arr);
        }
    }
}

node* levelOrderCreateTree(vector<string>& arr) {
    if (arr.size() == 0)
        return nullptr;
    node* head = new node(stoi(arr[0]));
    createTree(head, 0, arr);
    return head;
}

 bool check_fold(node*r,node*l)
 {
         if(r==NULL && l==NULL)
         return true;

      else if(r!=NULL && l!=NULL)
             return  check_fold(r->left,l->right) && check_fold(r->right,l->left);

      else
          return false;
 }
 //function that checks if the tree is foldable or not
    bool foldable(node* root)
    {
        if (root == NULL) {
            return true;
        }
        return check_fold(root->right, root->left);
    }

int main() {
    //first vector that contains tha values of the first tree
    vector<string> arr;
    arr.push_back("1");
    arr.push_back("4");
    arr.push_back("2");
    arr.push_back("null");
    arr.push_back("5");
    arr.push_back("3");
    arr.push_back("null");
    node*root1 =levelOrderCreateTree(arr);
    Inorder(root1);
    cout<<endl;
    if(foldable(root1))
        cout<<"first tree is foldable"<<endl;
    else
        cout<<"first tree is not foldable"<<endl;

    cout<<"--------------------------------------------"<<endl;
    //second vector that contains tha values of the second tree
    vector<string> arr2;
    arr2.push_back("1");
    arr2.push_back("2");
    arr2.push_back("3");
    arr2.push_back("4");
    arr2.push_back("null");
    arr2.push_back("null");
    arr2.push_back("5");
    node*root2 =levelOrderCreateTree(arr2);
    Inorder(root2);
    cout<<endl;
    if(foldable(root2))
        cout<<"second tree is foldable"<<endl;
    else
        cout<<"second tree is not foldable"<<endl;

    cout<<"--------------------------------------------"<<endl;
    //third vector that contains tha values of the third tree
    vector<string> arr3;
    arr3.push_back("1");
    arr3.push_back("2");
    arr3.push_back("3");
    arr3.push_back("4");
    arr3.push_back("6");
    arr3.push_back("null");
    arr3.push_back("5");
    node*root3 =levelOrderCreateTree(arr3);
    Inorder(root3);
    cout<<endl;
    if(foldable(root3))
        cout<<"third tree is foldable"<<endl;
    else
        cout<<"third tree is not foldable"<<endl;
    cout<<"--------------------------------------------"<<endl;
    //fourth vector that contains tha values of the fourth tree
    vector<string> arr4;
    arr4.push_back("1");

    node*root4 =levelOrderCreateTree(arr4);
    Inorder(root4);
    cout<<endl;
    if(foldable(root4))
        cout<<"fourth tree is foldable"<<endl;
    else
        cout<<"fourth tree is not foldable"<<endl;
    cout<<"--------------------------------------------"<<endl;
    //fifth vector that contains tha values of the fifth tree
    vector<string> arr5;
    arr5.push_back("7");
    arr5.push_back("2");
    arr5.push_back("6");
    arr5.push_back("null");
    arr5.push_back("3");
    arr5.push_back("4");
    arr5.push_back("null");
    arr5.push_back("8");
    arr5.push_back("null");
    arr5.push_back("10");
    arr5.push_back("null");
    node*root5 =levelOrderCreateTree(arr5);
    Inorder(root5);
    cout<<endl;
    if(foldable(root5))
        cout<<"fifth tree is foldable"<<endl;
    else
        cout<<"fifth tree is not foldable"<<endl;

    return 0;
}
