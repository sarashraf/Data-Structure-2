#include <iostream>
using namespace std;
//a class for creating the node of the tree
class BSTNode {
public:
    int data;
    BSTNode *left;
    BSTNode *right;
};
//a class for creating the tree
class BSTFCI {
public:
    BSTNode *root;
    BSTFCI(){//default contructor
        root = NULL;
    }
    //function that adds a node to the tree in its correct place
    BSTNode*insert(BSTNode* node , int element){ // node is root
        if(node==NULL){
            BSTNode * newnode = new BSTNode();
            newnode->data=element;
            node = newnode;
        }
        else if(element < node->data){
            node->left =  insert(node->left,element);
        }
        else{
            node->right = insert(node->right, element);
        }
        return node;
    }

    //function that search for a specific node and if found it returns this node
    BSTNode*search(BSTNode* node, int element){
        if(node==NULL){
            return NULL;
        }
        else if(node->data == element){
            return node;
        }
        else if(element < node->data){
            return search(node->left,element);
        }
        else{
            return search(node->right, element);
        }
    }
//function that prints the values between a specific range
    void PrintRange(BSTNode*node, int lowkey ,int highkey){
        if(node == NULL){
            return;
        }
        if(lowkey < node->data) {
            PrintRange(node->left, lowkey, highkey);
        }
        if(lowkey <=node->data && highkey>=node->data){
            cout  <<node->data << " ";
        }
        if (highkey > node->data){
            PrintRange(node->right,lowkey,highkey);
        }
    }
    //function that find the minimum value in the tree
    BSTNode*findmin(BSTNode*node){
        if(node==NULL){
            return NULL;
        }
        else if(node->left==NULL){
            return node;
        }
        else{
            return findmin(node->left);
        }
    }
    //function that find the maximum value in the tree
    BSTNode*findmax(BSTNode*node){
        if(node==NULL){
            return NULL;
        }
        else if(node->right==NULL){
            return node;
        }
        else{
            return findmax(node->right);
        }
    }
    //function that delete a node in the tree
    BSTNode* Delete(BSTNode*node, int element){
        if(node==NULL){ //empty tree
            return NULL;
        }
        else if(element < node->data){ //item exists in left sub tree
            node->left = Delete(node->left,element);
        }
        else if(element > node->data){//item exists in right sub tree
            node->right = Delete(node->right,element);
        }
        else{
            if(node->right ==NULL && node->left == NULL){ //leaf node
                node=NULL;
            }
            else if(node->left!=NULL && node->right==NULL){//one child on the left
                node->data = node->left->data;
                delete node->left;
                node->left =NULL;
            }
            else if(node->left==NULL && node->right!=NULL){//one child on the right
                node->data = node->right->data;
                delete node->right;
                node->right =NULL;
            }
            else{
                //predecessor
                BSTNode *pre = findmax(node->left);
                node->data=pre->data;
                node->left = Delete(node->left,pre->data);
                // successor
//                Node *suc = findmin(node->right);
//                node->data=suc->data;
//                node->right = Delete(node->right,suc->data);
            }
        }
        return node ;
    }
    //function that checks if a specific value is in the tree or not
    bool search(int element){
        BSTNode *result = search(root,element);
        if(result==NULL){
            return false;
        }
        else{
            return true;
        }
    }
    //function that calls the previous insert node as it takes the value only as a parameter
    void insert(int element){
        root = insert(root,element);
    }
    //function that calculate the height of the right subtree
    int Right_height(BSTNode *node){
        if(node==NULL){
            return 0;
        }
        else{
            int Rheight = Right_height(node->right);
                return Rheight +1;
        }
    }
    //function that calculate the height of the left subtree
    int left_height(BSTNode *node) {
        if (node == NULL) {
            return 0;
        } else {
            int lheight = left_height(node->left);
            return lheight + 1;
        }
    }
    //function that check if the tree is balanced or not
    void isBalance(BSTNode *node){
        if (node == NULL) {
            cout << "tree isempty" <<endl;
        }
        else {
            int R = Right_height(node);
            int L = left_height(node);
            if(R == L || R+1==L || R==L+1){
                cout << "isbalance" <<endl;

            }
            else{
                cout << "is not balance" <<endl;
            }

        }
    }


//function that print the values of the tree in the preorder way
    void preorder(BSTNode*node) { //root-left-right
        if (node == NULL) {
            return;
        }
        else {
            cout << node->data <<endl;
            preorder(node->left);
            preorder(node->right);
        }
    }
    //function that print the values of the tree in the Inorder way
    void inorder(BSTNode*node){ //left-root-right
        if(node==NULL){
            return;
        }
        inorder(node->left);
        cout <<node->data << "  ";
        inorder(node->right);

    }
    //function that print the values of the tree in the Postorder way
    void postorder(BSTNode*node) { //left-right-root
        if (node==NULL) {
            return;
        } else {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << "  ";
        }
    }
//function that checks if the two trees are identical or not
    bool identical(BSTNode*r1,BSTNode*r2)
    {
        if(r2==NULL &&r1==NULL)
            return true;
        if(r2==NULL &&r1!=NULL)
            return false;
        if(r1==NULL && r2!=NULL)
            return false;

        return (r1->data == r2->data && identical(r1->left,r2->left) && identical(r1->right,r2->right));
    }
    //function that checks if a tree is subtree from another or not
    bool Subtree(BSTNode*n1,BSTNode*n2)
    {
        if (n2==NULL)
        {
            return true;
        }
        if (n1==NULL)
        {
            return false;
        }
        if(identical(n1,n2))
            return true;

        return Subtree(n1->left,n2) || Subtree(n1->right,n2);
    }
   // function that calls the Subtree function
    bool isSubtree(BSTFCI t1,BSTFCI t2)
    {
        if(Subtree(t1.root,t2.root))
            return true;
        else
            return false;
    }

};


int main() {
//inserting 7 trees to check the previous functions
BSTFCI A,B,C,D,E,F,G;
A.insert(12);
A.insert(10);
A.insert(5);
A.insert(6);
A.insert(15);
A.insert(1);
/*----------------------------*/
B.insert(12);
B.insert(10);
B.insert(15);
B.insert(13);
B.insert(14);
B.insert(16);
B.insert(11);
B.insert(5);
B.insert(6);
B.insert(1);
/*----------------------------*/
D.insert(12);
D.insert(10);
D.insert(5);
D.insert(11);
D.insert(13);
D.insert(14);
D.insert(15);
D.insert(16);
/*----------------------------*/
C.insert(12);
C.insert(10);
C.insert(5);
/*----------------------------*/
E.insert(10);
E.insert(12);
E.insert(5);
E.insert(11);
E.insert(13);
E.insert(6);
E.insert(3);
/*----------------------------*/
F.insert(15);
F.insert(13);
F.insert(14);
F.insert(16);
/*----------------------------*/
G.insert(10);
G.insert(5);
G.insert(11);
G.insert(6);
G.insert(1);
/*----------------------------*/
cout << "<<<<<<<<<<< isBalance >>>>>>>>>>>>" <<endl;//five test cases to check isbalanced function
cout << "test case one" <<endl;
A.isBalance(A.root);
cout <<"-----------------------"<<endl;
cout <<endl;
cout << "test case two" <<endl;
B.isBalance(B.root);
cout <<"-----------------------"<<endl;
cout << endl;
cout << "test case three" <<endl;
C.isBalance(C.root);
cout <<"-----------------------"<<endl;
cout << endl;
cout << "test case four" <<endl;
D.isBalance(D.root);
cout <<"-----------------------"<<endl;
cout << endl;
cout << "test case five" <<endl;
E.isBalance(E.root);
cout <<"-----------------------"<<endl;
cout << endl;

cout << "<<<<<<<<<<< Is SubTree >>>>>>>>>>>>" <<endl; //five test cases to check the subtree function

cout << "test case one" <<endl;

if(A.isSubtree(A,C))
{
    cout<< "C" <<" is sub tree from " << "A" <<endl;
}
else
    cout<<"C is not sub tree from A"<<endl;
cout <<"-----------------------"<<endl;

cout <<endl;

cout << "test case two" <<endl;
if(B.isSubtree(B,E))
{
    cout<<"E is sub tree from B"<<endl;
}
else
    cout<<"E is not sub tree from B"<<endl;

cout <<"-----------------------"<<endl;
cout <<endl;

cout << "test case three" <<endl;

if(B.isSubtree(B,D))
{
    cout<<"D is sub tree from B"<<endl;
}
else
    cout<<"D is not sub tree from B"<<endl;

cout <<"-----------------------"<<endl;
cout <<endl;

cout << "test case four" <<endl;

if(B.isSubtree(B,F))
{
    cout<<"F is sub tree from B"<<endl;
}
else
    cout<<"F is not sub tree from B"<<endl;

cout <<"-----------------------"<<endl;
cout <<endl;

cout << "test case five" <<endl;

if(B.isSubtree(B,G))
{
    cout<<"G is sub tree from B"<<endl;
}
else
    cout<<"G is not sub tree from B"<<endl;

cout <<"-----------------------"<<endl;
cout <<endl;


cout << "<<<<<<<<<<< PrintRange >>>>>>>>>>>>" <<endl; //five test cases to check the PrintRange function
cout << "test case one" <<endl;
A.PrintRange(A.root,6,13);
cout <<endl;
cout <<"-----------------------"<<endl;
cout <<endl;
cout << "test case two" <<endl;
B.PrintRange(B.root,1,14);
cout << endl;
cout <<"-----------------------"<<endl;
cout << endl;
cout << "test case three" <<endl;
C.PrintRange(C.root,10,10);
cout << endl;
cout <<"-----------------------"<<endl;
cout << endl;
cout << "test case four" <<endl;
D.PrintRange(D.root,13,16);
cout << endl;
cout <<"-----------------------"<<endl;
cout << endl;
cout << "test case five" <<endl;
E.PrintRange(E.root,5,13);
cout <<endl;
cout <<"-----------------------"<<endl;
cout << endl;
        return 0;
}