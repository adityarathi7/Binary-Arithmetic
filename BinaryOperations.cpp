#include <bits/stdc++.h>
using namespace std ;

vector<int> twosComplement(int num)
{
    vector<int> ans(32) ;
    int j = 0 ;
    while(num)
    {
        ans[j++] = num%2 ;
        num /= 2 ;
    }

    int carry = 1 ;

    for(int i=0;i<32;i++)
    {
        ans[i] ^= 1 ;
        int temp = ans[i] + carry ;
        ans[i] = (temp)%2 ;
        carry = temp/2 ;
    }

    reverse(ans.begin(),ans.end()) ;
    return ans ;
}


vector<int> int_to_binary(int num)
{
    vector<int> ans(32) ;
    int i=0 ;
    if(num < 0) 
    {
        ans = twosComplement(abs(num)) ;
    }else {
        while(num)
        {
            ans[i++] = num%2 ;
            num /= 2 ; 
        }
        reverse(ans.begin(),ans.end()) ;
    }


    return ans ;
}
// Adding two binary numbers given in vectors - Vinayak
vector<int> add_binary(vector<int> a, vector<int> b)
{
    int n = 32;
    vector<int> result(n, 0);

    int carry = 0;
    for(int i=2;i>=0;i--)
    {
        if(carry==0)
        {
            result[i] = a[i]^b[i];
            if(result[i]==0 and i!=0) carry = 1;
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
    vector<int> b_new = two_complement(b);
    return add_binary(a,b_new);
}


int main() {

    int a,b ;
    cin >> a>>b ;

    vector<int> num1 = int_to_binary(a) , num2 = int_to_binary(b) ;

    return 0;
}
