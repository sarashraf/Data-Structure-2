#include <bits/stdc++.h>

using namespace std;
// struct to create the tree node
struct Treenode
{
    public:
    int val;
    Treenode* left;
    Treenode* right;

    //default constructor
    Treenode()
    {
        val=0;
        left=nullptr;
        right=nullptr;
    }

    //paramaterized constructor which takes the value of the node and set it
    Treenode(int x)
    {
        val=x;
        left=nullptr;
        right=nullptr;
    }

    //paramterized constructor which takes the value,left node and right node of the tree and set them
    Treenode(int x, Treenode* l,Treenode* r)
    {
        val=x;
        left=l;
        right=r;
    }
};

    // a function which prints the nodes of the tree in preorder(root->left->right)
    void preorder(Treenode* R)
    {
        if (R==nullptr)
        {
            return;
        }
        else
        {
            cout<<R->val<<"\t";
            preorder(R->left);
            preorder(R->right);
        }

    }

    // a function which prints the nodes of the tree in inorder(left->root->right)
    void inorder(Treenode* R)
    {
        if (R==nullptr)
        {
           return;
        }
        else
        {
            inorder(R->left);
            cout<<R->val<<"\t";
            inorder(R->right);
        }

    }


    // a function which prints the nodes of the tree in postorder(left->right->root)
    void postorder(Treenode* R)
    {
       if(R==nullptr)
       {
          return;

       }
       else
       {
           postorder(R->left);
           postorder(R->right);
           cout<<R->val<<"\t";
       }

    }

// a function which creates the tree to let it's elements be entered  in form of levels
void createTree(Treenode* node, int i, vector<string>& arr)
{
    if (node != nullptr)
        {
        if (2 * i + 1 < arr.size())
        {
            if (arr[2 * i + 1] == "null")
                node->left = nullptr;
            else
                node->left = new Treenode(stoi(arr[2 * i + 1]));
            createTree(node->left, 2 * i + 1, arr);
        }

        if (2 * i + 2 < arr.size())
            {
            if (arr[2 * i + 2] == "null")
                node->right = nullptr;
            else
                node->right = new Treenode(stoi(arr[2 * i + 2]));
            createTree(node->right, 2 * i + 2, arr);
            }
    }
}

// a function which makes the tree in the form of levels
Treenode* levelOrderCreateTree(vector<string>& arr)
{
    if (arr.size() == 0)
        return nullptr;
    Treenode* head = new Treenode(stoi(arr[0]));
    createTree(head, 0, arr);
    return head;
}


// class solution which contains the the function check nodes
class Solution
 {
public:

    // a function which indicates whether the tree is mirror to its self or not
    bool check(Treenode *t)
    {
        return isSmatrricTree(t,t);
    }


//a boolean function which takes the root of the tree as a paramater and returns true if the tree is mirror to itself
//and  returns false otherwise
  bool isSmatrricTree(Treenode *p, Treenode *q) {
// write you code here
        //Base case if both trees are empty
        if (p == nullptr && q == nullptr) {
            return true;
        }
        //Recursive call checking both trees are not empty and both trees values are equal their root, left and right
        return (p != nullptr && q != nullptr) && (p->val == q->val) && isSmatrricTree(p->left, q->right) &&
               isSmatrricTree(p->right, q->left);
    }
};





int main()
{
/*

 // Building the tree manually without using a function and this is done by using paramterized constructor
  Treenode* root=new Treenode(1);
  root->left= new Treenode(2);
  root->left->left=new Treenode(3);
  root->left->right= new Treenode(4);

  root->right= new Treenode(2);
  root->right->left=new Treenode(4);
  root->right->right= new Treenode(3);

  */





// asking the user at first to choose whether to enter a test case or end the program
 int testcase;
 cout<<"Enter 1 for trying a test case or 0 for ending the program: ";
 cin>>testcase;

// while loop to display the menu for the user every time to let him choose whether to enter another test case or end
while(testcase!=0)
{

// creating object(result) from class solution to use the function (isSymmetric) to indicate whether the
//tree is mirror to itself or not
  Solution result;

  // entering the elements of the trees by levels
  vector<string> arr;
    cout << "Enter the number of nodes of the Tree: ";
    int numOfNodes;
    cin >> numOfNodes;
    while (numOfNodes--)
    {
        string num;
        cin >> num;
        arr.push_back(num);
    }
    Treenode* root = levelOrderCreateTree(arr);

  cout<<"\nPreorder: ";
  preorder(root);
  cout<<endl<<endl;

  cout<<"Inorder: ";
  inorder(root);
  cout<<endl<<endl;

  cout<<"Postorder: ";
  postorder(root);
   cout<<endl<<endl;

    // using the isSymmetric function of class solution
  if(result.check(root))
  {
      // will print true if the tree is symmetric (mirror it itself)
      cout<<"\nTrue... The tree is a mirror to its self (symmetric)\n";
  }
  else
  {
      // will print false if the tree is not  symmetric (not mirror it itself)
      cout<<"\nFalse!...The tree is not a mirror to its self (symmetric)\n";
  }

    cout<<"\nEnter 1 for trying a test case or 0 for ending the program: ";
    cin>>testcase;
}

return 0;
}
