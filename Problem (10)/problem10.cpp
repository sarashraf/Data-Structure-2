#include <iostream>
using namespace std;

int temp=0;
/* class stack to store the element that delete from tree,
 and used to insert element again in the tree*/
class stack{
    struct Node{
        int data;
        Node *Next;
    };
public:
    Node*top;
    stack(){
        top=NULL;
    }
    // to check if the stack is empty or not
    bool isempty(){
        return (top==NULL);
    }
    //to insert elements in stack
    void push(int element){
        Node *newnode = new Node;
        newnode->data=element;
        if(isempty()) {
            newnode->Next=NULL;
            top=newnode;
        }
        else{
            newnode->Next=top;
            top=newnode;
        }
    }
    // to exit the element from the stack
    int pop(){
        int value;
        Node *del = top;
        value=top->data;
        top=top->Next;
        delete del;
        return value;
    }
    // return the top of the stack
    int peek(){
        return top->data;
    }
    // show the stack
    void display(){
        Node *temp = top;
        while (temp!=NULL){
            cout << temp->data <<" ";
            temp=temp->Next;
        }
        cout<<endl;
    }
    // return the numbers of elements in the stack
    int count(){
        int counter=0;
        Node *temp = top;
        while (temp!=NULL){
            counter++;
            temp=temp->Next;
        }
        return counter;
    }
    // to search element in the stack
    int search(int element){
        Node *temp = top;
        int counter=1;
        while (temp->data!=element){
            temp=temp->Next;
            counter++;
        }
        return counter;
    }
};

// class BST for creating binary search tree
class BST {
    //struct node for creating the node of the tree
    struct Node {
        int data;
        Node *left;
        Node *right;
    };
public:
    Node *root;
    // default constructor
    BST(){
        root = NULL;
    }
    //function that adds a node to the tree in its correct place
    Node*insert(Node* node , int element){ // node is root
        if(node==NULL){
            Node * newnode = new Node();
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
    Node*search(Node* node, int element){
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
    //function that find the minimum value in the tree
    Node*findmin(Node*node){
        if(node==NULL){
            return NULL;
        }
        else if(node->left==NULL){
            cout << node->data <<endl;
            temp=node->data;
            return node;
        }
        else{
            return findmin(node->left);
        }
    }
    //function that find the maximum value in the tree
    Node*findmax(Node*node){
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
    Node* Delete(Node*node, int element){
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
                Node *pre = findmax(node->left);
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
        Node *result = search(root,element);
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
    //function that print the values of the tree in the preorder way
    void preorder(Node*node) { //root-left-right
        if (node == NULL) {
            return;
        }
        else {
            cout << node->data << "  ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    //function that print the values of the tree in the Inorder way
    void inorder(Node*node){ //left-root-right
        if(node==NULL){
            return;
        }
        inorder(node->left);
        cout <<node->data << "  ";
        inorder(node->right);

    }
    //function that print the values of the tree in the Postorder way
    void postorder(Node*node) { //left-right-root
        if (node==NULL) {
            return;
        } else {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << "  ";
        }
    }

};
/* to calculate the the summation the elements which
 * is less or equalto the kth smallest
 * element in the binary search tree*/
void summation(BST tree,int key){
    stack Recycle_Bin;
    int element , sum=0;

    for (int i = 0; i < key ; ++i) {
        tree.findmin(tree.root);
        Recycle_Bin.push(temp);
        sum = sum +temp;
        tree.Delete(tree.root,temp);
    }
    for (int i = 0; i < key ; ++i) {
        int temp2 = Recycle_Bin.pop();
        tree.insert(temp2);
    }
    cout << "the summation is: " << sum <<endl;
}


int main() {

    //trying 5 test cases
    cout<<"Test case 1"<<endl;
    BST t1;
    t1.insert(1);
    t1.insert(2);
    t1.insert(3);
    t1.insert(4);
    t1.insert(5);
    t1.insert(6);

    summation(t1,3);
    cout<<"----------------------"<<endl;
    cout<<"Test case 2"<<endl;
    BST t2;
    t2.insert(8);
    t2.insert(7);
    t2.insert(6);
    t2.insert(5);
    t2.insert(4);
    summation(t2,3);
    cout<<"----------------------"<<endl;
    cout<<"Test case 3"<<endl;
    BST t3;
    t3.insert(8);
    t3.insert(2);
    t3.insert(3);
    t3.insert(4);
    t3.insert(5);
    t3.insert(11);
    summation(t3,2);
    cout<<"----------------------"<<endl;
    cout<<"Test case 4"<<endl;
    BST t4;
    t4.insert(2);
    t4.insert(0);
    t4.insert(1);
    t4.insert(3);
    t4.insert(8);
    t4.insert(10);
    summation(t4,4);
    cout<<"----------------------"<<endl;
    cout<<"Test case 5"<<endl;
    BST t5;
    t5.insert(1);
    t5.insert(-1);
    t5.insert(0);
    t5.insert(6);
    t5.insert(8);
    t5.insert(7);
    t5.insert(3);
    t5.insert(11);
    summation(t5,3);

    return 0;
}
