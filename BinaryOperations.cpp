#include <bits/stdc++.h>
using namespace std ;


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
// Converting binary to integer - Vinayak
int binary_to_int(vector<int> a)
{
    int ans = 0;

    for(int i=a.size()-1;i>0;i--)
    {
        ans = ans*2 + a[i];
    }

    return ans;

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

    int a,b ;
    cin >> a>>b ;

    vector<int> num1 = int_to_binary(a) , num2 = int_to_binary(b) ;

    return 0;
}
