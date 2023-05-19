/*

Roll Number: cs20b1100
Name: K.Anuj

Q1 - Given two integers m, n.
(i) the objective is to perform m *n using binary representation of m and n
(ii) Present the logic and its asymptotic analysis in worst case.

Marking Scheme : 
Binary repn of m and n(8 marks)
bit level multiplication(8 marks) 
asymptotic analysis(4 marks) 
total 20 marks


Process:

1. Convert m,n into binary numbers and store them in binary1 and binary2 as a integer. 
2. make new variables digit = 1 and product = 0.
3. Divide the variable binary2 by 10 and obtain its remainder and assign it to digit.
4. Check if the digit is equal to 1 or 0. If it is 1, then multiply binary 1 with factor and override binary1 with this value. 
   Call function binaryproduct() by passing binary1 and Product.
5. Else, multiply binary 1 with factor and override binary1 with this value and override binary2 with its quotient got when it is divided by 10.
6. Do steps 2-4 until we get binary2 = 0.
7. In the function binaryproduct(), obtain the remainder(r) and quotient of both b1,b2.
8. Now add the remainders of both parameters and further add the variable remainder.
9. Obtain the remainder and quotient of the result got at step 7 when divided by 2. 
   Store the remainder in the array sum[] and override the variable remainder with the quotient.
10. Override the variables binary1 and binary2 with their quotient got at step 6.
11. Repeat the steps 6-9 with the new values of b1 and b2 until both becomes zero.
12. if b1 = 0 or b2 = 0 and remainder = 1 then copy it into the array sum.
13. Multiply the variable binaryproduct with 10 and add the result to array sum. 
    Override the variable binaryproduct with the got result. Do this step for all array elements and return binaryproduct.
14. Print the final output.
15. Exit.


Asymptotic analysis in worst case:

let number of digits in m be M and number of digits in n be N.
complexity = O(MxN)
as we are multiplying digits of binary1(M) to digits of binary2(N) and adding them at last. 

if Max of digits in m and n be Max.
complexity = O(Max^2).

*/

#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<int> M, N;

int binaryproduct(int b1, int b2)
{
    int i = 0, r = 0, sum[M.size() + N.size() + 1];
    int binaryproduct = 0;

    while (b1 != 0 || b2 != 0)
    {
        sum[i++] = (b1 % 10 + b2 % 10 + r) % 2;
        r = (b1 % 10 + b2 % 10 + r) / 2;
        b1 = b1 / 10;
        b2 = b2 / 10;
    }
    if (r != 0)
        sum[i++] = r;
    --i;
    while (i >= 0)
        binaryproduct = binaryproduct * 10 + sum[i--];
    return binaryproduct;
}

void integerToBinary()
{
    while (m != 0)
    {
        M.push_back(m % 2);
        m /= 2;
    }

    while (n != 0)
    {
        N.push_back(n % 2);
        n /= 2;
    }
}

int main()
{
    while (1)
    {
        cout << "Enter value of m: ";
        cin >> m;
        if (m >= 0)
        {
            break;
        }
        else
        {
            cout << "!!!! Enter valid input(>=0) !!!!" << endl;
        }
    }

    while (1)
    {
        cout << "Enter value of n: ";
        cin >> n;
        if (n >= 0)
        {
            break;
        }
        else
        {
            cout << "!!!! Enter valid input(>=0) !!!!" << endl;
        }
    }

    cout << "\n\n";

    integerToBinary();

    int binary1 = 0, binary2 = 0, Product = 0;
    int digit, factor = 1;

    for (int i = M.size() - 1; i >= 0; i--)
    {
        binary1 = binary1 * 10 + M[i];
    }
    for (int i = N.size() - 1; i >= 0; i--)
    {
        binary2 = binary2 * 10 + N[i];
    }
    cout << "Binary representation of m: ";
    cout << binary1 << endl;
    cout << "Binary representation of n: ";
    cout << binary2 << endl;

    while (binary2 != 0)
    {
        digit = binary2 % 10;
        if (digit == 1)
        {
            binary1 = binary1 * factor;
            Product = binaryproduct(binary1, Product);
        }
        else
            binary1 = binary1 * factor;
        binary2 = binary2 / 10;
        factor = 10;
    }
    cout << "Product of two binary numbers: " << Product;
    return 0;
}