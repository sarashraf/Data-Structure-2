#include <iostream>

using namespace std;

//function to invert the string to integer
int changeIntoInt(string str)
{
    int number=0;
    if (str[1]=='-')  //if the number is negative
    {
        for (int i=2;i<str.length();i++)
        {
            number=number*10+(int(str[i])-48);
        }
        number=number*(-1);
    }
    else   //if the number is positive
    {
        for (int i=1;i<str.length();i++)
        {
            number=number*10+(int(str[i])-48);
        }
    }
    return number;
}

//class to create the node
class node
{
public:
    string data;
    int val;
    node* left;
    node* right;

    node()  //default constructor
    {
        left=NULL;
        right=NULL;
    }
    node(string ch) //parametrize constructor set the symbol
    {
        data=ch;
        left=NULL;
        right=NULL;
    }
    node(int item)  //parametrize constructor set the integer
    {
        val=item;
        left=NULL;
        right=NULL;
    }

};

//class expression tree to create the tree
class ExpT
{
public:
    node * root;
    node * root2;
    bool flag=true;
    bool lef= true;

    //parameterize constructor which take prefix notation and builds an expression tree
    ExpT(string n)
    {
        root=NULL;
        string x;
        bool flag2=true;
        int cnt=-1;

        for(int i=0;i<n.length();i++)
        {
            //if char of the string is integer or negative sign
            if((n[i]>='0' && n[i]<='9' )|| (n[i]=='-' && n[i+1] !=' '))
            {
                flag2= false;
                cnt++; //0 1 2
            }
            //if char of the string is a symbol
            else if( n[i]=='+' || (n[i]=='-' && n[i+1]==' ') || n[i]=='*' || n[i]=='/' )
            {
                x=n[i];
                insert(x);
                x=" ";
            }

            //to indicate a new node
            else if(n[i]==' ' && flag2 == false)
            {
                for(int j=0;j<=cnt;j++)
                {
                    x.push_back(n[i-cnt-1+j]);
                    flag =false;
                }
                if(flag ==false)
                {
                    insert(x);
                    x=" ";
                    cnt=-1;
                }
                flag2= true;
            }
        }
    }

    //function to insert the symbol in the correct position
    node * insert(node * r ,string item)
    {
        if(r==NULL) //if tree's root is empty
        {
            node* newnode=new node(item);
            r=newnode;
        }
        else if (lef== false)
        {
            lef= true;
            r->right=insert(r->right,item);

        }
        else if(r->left==NULL || (r->left->data == "+" || r->left->data == "-" || r->left->data == "*" || r->left->data == "/") && lef==true)
        {
            r->left= insert(r->left,item);
        }
        else if( r->right == NULL|| (r->right->data == "+" || r->right->data == "-" || r->right->data == "*" || r->right->data == "/") && lef==true )
        {
            r->right= insert(r->right,item);
        }
        else
        {
            lef = false;
            root2 = r;
            r=insert(root2, item);

        }
        return r;

    }

    //function to insert the integer in the correct position
    node * insert(node * r ,int item)
    {
        if(r==NULL)
        {
            node* newnode=new node(item);
            r=newnode;
        }
        else if (r->left == NULL  || (r->left->data == "+" || r->left->data == "-" || r->left->data == "*" || r->left->data == "/"))
        {
            r->left= insert(r->left,item);
        }
        else if(r->right==NULL || (r->right->data == "+" || r->right->data == "-" || r->right->data == "*" || r->right->data == "/"))
        {
            r->right = insert(r->right,item);
        }
        else
        {
            if(r->left->data=="+" || r->left->data=="-" ||r->left->data=="*" ||r->left->data=="/")
            {
                r->left= insert(r->left,item);
            }
            else
            {
                r->right= insert(r->right,item);
            }
        }
        return r;
    }

    //function to insert the node
    void insert(string item)
    {
        //if node the symbol
        if(item =="+" || item =="-" || item =="*" || item =="/" || item == "%")
        {
            root= insert(root,item);
        }

        else  //if node in integer
        {
            int val =changeIntoInt(item);
            root= insert(root,val);
        }
    }

    //function to print the tree in preorder (root - left - right )
    void preorder(node *r)
    {
        if(r==NULL)
        {
            return;
        }
        if(r->data=="+" || r->data=="-" || r->data=="*" || r->data=="/" )
        {
            cout<<r->data<<" ";
        }
        else
        {
            cout<<r->val<<" ";
        }
        preorder(r->left);
        preorder(r->right);
    }

    //function to print the tree inorder (left - root - right )
    void inorder(node *r)
    {
        if(r==NULL)
        {
            return;
        }
        inorder(r->left);
        if(r->data=="+" || r->data=="-" || r->data=="*" || r->data=="/" )
        {
            cout<<r->data<<" ";
        }
        else
        {
            cout<<r->val<<" ";
        }
        inorder(r->right);
    }

    //function to print the tree inpost order (left - right - root)
    void postorder(node *r)
    {
        if(r==NULL)
        {
            return;
        }
        postorder(r->left);
        postorder(r->right);
        if(r->data=="+" || r->data=="-" || r->data=="*" || r->data=="/" )
        {
            cout<<r->data<<" ";
        }
        else
        {
            cout<<r->val<<" ";
        }

    }
};


//class to Evaluate the result
class evalution
{
public:
    int evaluate(node* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else if (root->left == nullptr || root->right == nullptr)
        {
            return root->val;
        }
        int leftvalue = evaluate(root->left);

        int rightvalue = evaluate(root->right);

        if (root->data == "+") //if addition
        {
            return leftvalue + rightvalue;
        }
        else if (root->data == "-")  //if subtract
        {
            return leftvalue - rightvalue;
        }
        else if (root->data == "*")  //if multiplication
        {
            return leftvalue * rightvalue;
        }
        else  // if divide
        {
            return leftvalue / rightvalue;
        }
    }

};


int main() {

    //trying out 5 test cases
    cout<<"Test 1:"<<endl;
    ExpT tree1("+ 3 * 4 / 8 2 ");
    cout<<"preorder:"<<endl;
    tree1.preorder(tree1.root);
    cout << endl << "inorder: "<<endl;
    tree1.inorder(tree1.root);
    cout << endl<<"postorder: "<<endl;
    tree1.postorder(tree1.root);
    cout << endl<<endl;
    evalution e1;
    cout <<"Evaluation: "<< e1.evaluate(tree1.root)<<endl;
    cout<<"---------------------------------------------------"<<endl;

    cout<<"Test 2:"<<endl;
    ExpT tree2("+ 31 * 4 / 8 -2 ");
    cout<<"preorder:"<<endl;
    tree2.preorder(tree2.root);
    cout << endl << "inorder: "<<endl;
    tree2.inorder(tree2.root);
    cout << endl<<"postorder: "<<endl;
    tree2.postorder(tree2.root);
    cout << endl<<endl;
    evalution e2;
    cout <<"Evaluation: "<< e2.evaluate(tree2.root)<<endl;
    cout<<"---------------------------------------------------"<<endl;

    cout<<"Test 3:"<<endl;
    ExpT tree3("* 1 * 3 + -8 2 ");
    cout<<"preorder:"<<endl;
    tree3.preorder(tree3.root);
    cout << endl << "inorder: "<<endl;
    tree3.inorder(tree3.root);
    cout << endl<<"postorder: "<<endl;
    tree3.postorder(tree3.root);
    cout << endl<<endl;
    evalution e3;
    cout <<"Evaluation: "<< e3.evaluate(tree3.root)<<endl;
    cout<<"---------------------------------------------------"<<endl;

    cout<<"Test 4:"<<endl;
    ExpT tree4("+ 3 -3 ");
    cout<<"preorder:"<<endl;
    tree4.preorder(tree4.root);
    cout << endl << "inorder: "<<endl;
    tree4.inorder(tree4.root);
    cout << endl<<"postorder: "<<endl;
    tree4.postorder(tree4.root);
    cout << endl<<endl;
    evalution e4;
    cout <<"Evaluation: "<< e4.evaluate(tree4.root)<<endl;
    cout<<"---------------------------------------------------"<<endl;

    cout<<"Test 5:"<<endl;
    ExpT tree5("/ 100 * 2 / 100 + 7 3 ");
    cout<<"preorder:"<<endl;
    tree5.preorder(tree5.root);
    cout << endl << "inorder: "<<endl;
    tree5.inorder(tree5.root);
    cout << endl<<"postorder: "<<endl;
    tree5.postorder(tree5.root);
    cout << endl<<endl;
    evalution e5;
    cout <<"Evaluation: "<< e5.evaluate(tree5.root)<<endl;


    return 0;
}