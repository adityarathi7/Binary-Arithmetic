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

vector<int> int_to_binary(int a)
{
   vector<int> result(32, 0);
    int i = 31;
    bool negative = (a < 0);

    if (negative) {
        a = -a;

        while (a > 0) {
            result[i] = a % 2;
            a /= 2;
            i--;
        }

        for (int j = 0; j < 32; j++) {
            result[j] = result[j] ^ 1;
        }

        for (int j = 31; j >= 0; j--) {
            if (result[j] == 0) {
                result[j] = 1;
                break;
            }
            result[j] = 0;
        }
    } else {
        while (a > 0) {
            result[i] = a % 2;
            a /= 2;
            i--;
        }
    }

    return result;
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

// Added Add Function --  Vinayak

/**
 * Function to add two binary numbers
 * 
 * @param a - A binary number represented as a vector of integers.
 * @param b - Another binary number represented as a vector of integers.
 * @return A vector of integers representing the sum of the two binary numbers.
 */


vector<int> add_binary(vector<int> a, vector<int> b)
{
    vector<int> result(32, 0);
    int carry = 0;

    for (int i = 31; i >= 0; i--) {
        int sum = a[i] + b[i] + carry;
        carry = sum / 2;
        result[i] = sum % 2;
    }

    return result;
}


// Added subtract function -- Aditya

/**
 * @brief Subtracts two binary numbers represented in vector form.
 * @param a Vector of binary digits representing first number.
 * @param b Vector of binary digits representing second number.
 * @return Vector of binary digits representing the difference of two input binary numbers.
 * 
 * This function performs subtraction of two binary numbers represented in vector form. The difference is calculated
 * by starting from the least significant bit and working towards the most significant bit. The borrow is stored and 
 * used for calculation of the next bit.
 */

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





int main() {

    // Taking inputs -- Aditya
    int a,b ;
    cin >> a>>b ;

    vector<int> num1 = int_to_binary(a) , num2 = int_to_binary(b) ;

    return 0;
}
