#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char* argv[])
{
    string S;
    cin >> S;

    int oneCount = 0;
    int zeroCount = 0;
    string tmp = "";
    tmp += S[0];  
    for (int i = 1; S.length() > i; i++)
    {
        if (S[i] == tmp.back())
            tmp += S[i]; 
        else
        {
            
            if ('0' == tmp.back())
                zeroCount++;
            else
                oneCount++;

            tmp = S[i]; 
        }
    }
    if ('0' == tmp.back())
        zeroCount++;
    else
        oneCount++;

    cout << min(zeroCount, oneCount);

    return 0;
}