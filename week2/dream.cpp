#include <iostream>
#include <stack>
using namespace std;


int main()
{
    string a, b;
    stack<int> sum;
    cin >> a ;
    cin >> b;
    int carry = 0,int_a,int_b,result,k;
    int length_a = a.length() - 1;
    int length_b = b.length() - 1;
    int max;

    if (a.length() >= b.length()){
        max= a.length();
    }
    else
    {
         max= b.length();
    }


    for (int i = 0; i < max ; i++)
    {
        if (length_a - i >= 0 && length_b - i >= 0)
        {
            int_a = (int)a[length_a - i] - '0';
            int_b = (int)b[length_b - i] - '0';
            result = int_a + int_b + carry;
            k=result % 10;
            sum.push(k);
            carry = result / 10;
        }
        
        else if (length_a - i < 0)
            {
                result = ((int)b[length_b - i] - '0' + carry);
                k=result % 10;
                sum.push(k);
                carry = result / 10;
            }
        else if (length_b - i < 0)
            {
                result = ((int)a[length_a  - i] - '0' + carry);
                k=result % 10;
                sum.push(k);
                carry = result / 10;
            }
        if (carry != 0 && i == max - 1 )
        {
            sum.push(carry);
        }
        
    }

    while (!sum.empty())
    {
        cout << sum.top();
        sum.pop();
    }
}