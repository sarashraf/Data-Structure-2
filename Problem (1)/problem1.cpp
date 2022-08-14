#include <iostream>

using namespace std;

template <class t>
class stack
{
private:
    int cnt,siz,dots;
    t *st ;
    string path;

public:
    //default constructor
    stack()
    {
    }

    //parametrize constructor which takes a string
    stack(string p)
    {
        siz=p.length();   //  /sara//ashraf/
        st=new t [siz];
        cnt=-1;
        dots=0;

        //to check the number of dots or check whether the path is valid or not
        for(int i=0;i<siz;i++)
        {
            if(p[i]=='.')
            {
                dots++;
            }
            if(p[i]=='/' && p[i+1]=='/' && (i==0 || p[i+2]=='/' ||i==siz-2) )  // invalid cases
            {
                cout<<"Wrong path"<<endl;
                return;
            }
        }
        //convert the path to the simplified canonical path and push it in the stack
        for(int i=siz-2;i>=0;i--)
        {
            if(p[i]=='/' && p[i+1]=='/')
            {
                continue;
            }
            else if (p[i]=='.' && dots < 3)
            {
                continue;
            }
            else
            {
                puch(p[i]);
            }
        }
    }

    //to return the last element in the stack (at the top)
    t top()
    {
        return st[cnt];
    }

    //to add the element in the stack
    void puch(char ch)
    {
        cnt++;
        st[cnt]=ch;
    }

    //to remove the last element in the stack (at the top)
    void pop()
    {
        cnt--;
    }

    //to check if the stack is empty or not
    bool empity()
    {
        if(cnt==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //to return the size of the stack
    int size()
    {
        return cnt+1;
    }

};


int main()
{
    //trying 5 test cases
    cout<<"Test 1"<<endl;
    stack<string> s1("/home/");
    while (!s1.empity())
    {
        cout<<s1.top();
        s1.pop();
    }

    cout<<endl<<"-------------------------------"<<endl;
    cout<<"Test 2"<<endl;
    stack<string> s2("/home//foo//mycomputer/..//home//foo/");
    while (!s2.empity())
    {
        cout<<s2.top();
        s2.pop();
    }

    cout<<endl<<"-------------------------------"<<endl;
    cout<<"Test 3"<<endl;
    stack<string> s3("/../");
    while (!s3.empity())
    {
        cout<<s3.top();
        s3.pop();
    }
    cout<<endl<<"-------------------------------"<<endl;
    cout<<"Test 4"<<endl;
    stack<string> s4("/.../");
    while (!s4.empity())
    {
        cout<<s4.top();
        s4.pop();
    }
    cout<<endl<<"-------------------------------"<<endl;
    cout<<"Test 5"<<endl;
    stack<string> s5("//home/");
    while (!s5.empity())
    {
        cout<<s5.top();
        s5.pop();
    }


    return 0;
}
