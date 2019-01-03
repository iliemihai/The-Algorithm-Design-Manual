#include <iostream>
#include <stack>

using namespace std;

//time complexity O(n)
//space complexity O(n)

class Solve
{
public:

    bool is_ok(string str)
    {
        for(int i=0; i<str.size(); i++)
            if(str[i] == '(' || 
               str[i] == '[' ||
               str[i] == '{')
            {
            	st.push(str[i]);
            } 
            else
            {
            	if (st.size() == 0)
            		return false;

            	char final;
                char top = st.top();
                st.pop();

                switch(str[i])
                {
                    case ')':
                    	final = '(';
                        break;
                    case ']':
                    	final = '[';
                        break;
                    case '}':
                    	final = '{';
                        break;
				}

				if(top != final)
                    return false;
            }

            if (st.size() != 0)
            	return false;

            return true;
    }
private:
	stack<char> st;
};

int main()
{
	Solve s = Solve();
	cout <<(s.is_ok("{[()]}") ? "True":"False")<<endl;
	cout <<(s.is_ok("{[()]}{}()") ? "True":"False")<<endl;
	cout <<(s.is_ok("{[()]}}{") ? "True":"False")<<endl;
}