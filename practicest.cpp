#include <iostream>
#include <stack>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}

void insertAtBottom(stack<int> s1, int data)
{
    if (s1.empty())
    {
        s1.push(data);
        return;
    }

    int temp = s1.top();
    s1.pop();
    insertAtBottom(s1, data);
    s1.push(data);
}

void recRev(stack<int> &s1)
{
    if (s1.empty())
        return;

    int temp = s1.top();
    s1.pop();
    recRev(s1);
    insertAtBottom(s1, temp);
}

bool isValidSt(char *s)
{
    stack<char> st;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            if (st.empty() || st.top() == ')')
                return false;
            st.pop();
        }
    }

    return st.empty();
}

int main()
{

    stack<char> s1;
    char s[200] = "((a+b)) * ((c))";

    if (isValidSt(s))
    {
        cout << " YES";
    }
    else
        cout << "NO";

    // for (int i = 0; i < s1.size(); i++)
    // {
    //     // Pop One element and save into temp variable
    //     int temp = s1.top();
    //     s1.pop();

    //     // transfer all elements from s1 to s2
    //     transfer(s1, s2, n - i - 1);

    //     // put temp into s1 and then again transfer all s2 elements to s1
    //     s1.push(temp);
    //     transfer(s2, s1, n - i - 1);
    // }
    // recRev(s1);

    // while (!s1.empty())
    // {
    //     cout << s1.top() << endl;
    //     s1.pop();
    // }

    return 0;
}
