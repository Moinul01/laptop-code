#include <bits/stdc++.h>
using namespace std;
char s[10] ;
int MAXSIZE = 10;

int top = -1;
int isempty()
{

    if(top == -1)
        return 1;
    else
        return 0;
}

int isfull()
{

    if(top == MAXSIZE)
        return 1;
    else
        return 0;
}

int peek()
{
    return s[top];
}

char pop()
{
    char data;

    if(!isempty())
    {
        data = s[top];
        top = top - 1;
        return data;
    }
    else
    {
        cout<<"Stack is empty.\n";
    }
}

char push(char data)
{

    if(!isfull())
    {
        top = top + 1;
        s[top] = data;
    }
    else
    {
        cout<<"Stack is full.\n";
    }
}

int main()
{
    string st;
    char c;
    int a=0,b=0;
    cin>>st;
    if((st.size())>10)
    {
        cout<<"-----Error-----";
    }
    else
    {
        for(int i=0; i<st.size(); i++)
        {
            push(st[i]);
        }


        for(int i=0; i<st.size(); i++)
        {
            c=pop();
            if(c=='('||c=='{'||c=='[')
            {
                a++;
            }
            if(c==')'||c=='}'||c==']')
            {
                b++;
            }

        }
        if(a==b)
        {
            cout<<"Opening and Closing parentheses matched";
        }

        else if(a>b)
        {
            cout<<"Opening parentheses not end";
        }
        else
        {
            cout<<"Closing parentheses not matched";
        }
    }

}
