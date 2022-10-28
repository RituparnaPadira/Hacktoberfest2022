#include <iostream>
using namespace std;

int fac(int n)
{
    if(n==0)
        return 1;
    else
        return n*fac(n-1);
}

int nCr(int n, int r)
{
    if(n>=r)
        return (fac(n)/(fac(r)*fac(n-r))); 
    else
        return -1;
}

int nPr(int n, int r)
{
    if(n>=r)
        return (fac(n)/(fac(n-r)));
    else
        return -1;
}

int main()
{
    char inp;
    int n,r;
    cout<<"Enter C if you want to perform Combination(nCr) "<<endl;
    cout<<"Enter P if you want to perform Permutation(nPr) "<<endl;
    cin>>inp;
    int answer;

    switch(inp)
    {
        case 'C':
        { 
            cout<<"Enter the values of n and r ";
            cin>>n>>r;
            if(n<=0 || r <0 )
            {
                cout<<"Invalid values (should not be used) ";
                return 0;
            }
            answer = nCr(n,r);
            if(answer == -1)
            {
                cout<<"Invalid n should not be greater than r";
                return 0;
            }
            cout<<"The value of "<<n<<"C"<<r<<" is "<<answer;
            break;
        }
        case 'P':
        {
            cout<<"Enter the values of n and r ";
            cin>>n>>r;
            if(n<=0 || r <0 )
            {
                cout<<"Invalid values (should not be used) ";
                return 0;
            }
            answer = nPr(n,r);
            if(answer == -1)
            {
                cout<<"Invalid n should not be greater than r";
                return 0;
            }
            cout<<"The value of "<<n<<"P"<<r<<" is "<<answer;
            break;
        }

        default:
        {
            cout<<"Invalid";
            return 0;
        }
    }
    return 0;
    
}