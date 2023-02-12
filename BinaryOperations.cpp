#include <bits/stdc++.h>
using namespace std ;

// Function takes twos complenent -- Aditya

/**
 * Function to calculate the two's complement of a binary number.
 * 
 * @param ans - A reference to a binary number represented as a vector of integers.
 * @return A vector of integers representing the two's complement of the input binary number.
 */

vector<int> twosComplement(vector<int> &ans)
{
    int carry = 1 ;

    for(int i=0;i<32;i++)
    {
        ans[i] ^= 1 ;
        int temp = ans[i] + carry ;
        ans[i] = (temp)%2 ;
        carry = temp/2 ;
    }

    return ans ;
}

// Function converts int to binary -- Aditya

/**
 * Function to convert an integer to binary
 * 
 * @param num - An integer number to be converted to binary.
 * @return A vector of integers representing the binary equivalent of the input integer number.
 */

vector<int> int_to_binary(int num)
{
    vector<int> ans(32) ;
    int i=0 , negative = num < 0 ;
    num = abs(num) ;

    while(num)
    {
        ans[i++] = num%2 ;
        num /= 2 ; 
    }

    if(negative) 
    {
        ans = twosComplement(ans) ;
    }

    reverse(ans.begin(),ans.end()) ;

    return ans ;
}

// Converting binary to integer -- Aditya

/**
 * Function to convert a binary number to an integer
 * 
 * @param a - A binary number represented as a vector of integers.
 * @return An integer representation of the input binary number.
 */

int binary_to_int(vector<int> a)
{
    
    int result = 0;
    bool isNegative = !a[0];

    // two's complement if number is negative
    if (isNegative) {
        // Flip all the bits
        for (int i = 0; i < 32; i++) {
            a[i] = a[i] ^ 1; 
        }
        for (int i = 31; i >= 0; i--) {
            if (a[i] == 0) {
                a[i] = 1;
                break;
            }
            a[i] = 0;
        }
    }
    
    // Binary to decimal
    for (int i = 0; i < 32; i++) {
        result += a[i] * pow(2, 31 - i);
    }
}

// Added Add Function -- Aditya
vector<int> add(vector<int> a,vector<int> b)
{
    int carry = 0 ;
    reverse(a.begin(),a.end()) ;
    reverse(b.begin(),b.end()) ;
    vector<int> ans(32) ;
    for(int i=0;i<32;i++)
    {
        int temp = a[i] + b[i] + carry ;
        ans[i] = temp%2 ;
        carry = temp/2 ;
    }
    return ans ;
}

// Added subtract function -- Aditya
vector<int> subtract_binary(vector<int> a, vector<int> b) {
    vector<int> result(32, 0); 
    int borrow = 0; 
    
    for (int i = 31; i >= 0; i--) { 
      int diff = a[i] - b[i] - borrow; 
  
        if (diff >= 0) {
            result[i] = diff;
            borrow = 0;
        } else { 
            result[i] = diff + 2;
            borrow = 1;
        }
    }

    return result;
}

// Adding two binary numbers given in vectors - Vinayak
vector<int> add_binary(vector<int> a, vector<int> b)
{
    int n = a.size();
    vector<int> result(n, 0);

    int carry = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(carry==0)
        {
            result[i] = a[i]^b[i];
            if(result[i]==0 and i!=0 and a[i]==1) carry = 1;
        }
        else
        {
            result[i] = a[i]^b[i]^1;
            if(a[i]==1 and i!=0) carry = 1;
            else carry = 0;
        }
    }

    return result;
}

// Substracting two numbers - Vinayak
vector<int> substract_binary(vector<int> a, vector<int> b)
{
    vector<int> b_new = twosComplement(b);
    return add_binary(a,b_new);
}


int main() {

    // Taking inputs -- Aditya
    int a,b ;
    cin >> a>>b ;

    vector<int> num1 = int_to_binary(a) , num2 = int_to_binary(b) ;

    return 0;
}
