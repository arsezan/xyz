#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b)
 {
    string result;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) 
    {
        carry += (i >= 0 ? a[i--] - '0' : 0);
        carry += (j >= 0 ? b[j--] - '0' : 0);
        result += (carry % 2) + '0';
        carry /= 2;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
 {
    string a, b;
    cout << "Enter first binary number: ";
    cin >> a;
    cout << "Enter second binary number: ";
    cin >> b;

    cout << "Sum: " << addBinary(a, b) << endl;
    return 0;
}
