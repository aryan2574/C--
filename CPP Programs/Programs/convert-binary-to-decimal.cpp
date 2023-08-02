#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    string bin;
    getline(cin, bin);
    size_t idx = bin.find('.');
    if (idx == string::npos)
    {
        idx = bin.length();
    }
    long double sum = 0;
    int count = 0;
    for (int i = idx - 1; i >= 0; i--)
    {
        sum += (bin[i] - '0') * pow(2, count);
        count++;
    }
    long double sum2 = 0;
    if (idx != string::npos)
    {
        count = 1;
        for (int i = idx + 1; i < bin.length(); i++)
        {
            sum2 += (bin[i] - '0') / pow(2, count);
            count++;
        }
    }
    cout << sum + sum2;
    return 0;
}