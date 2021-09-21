#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<int> v;
    while (t > 0)
    {
        int n, s;
        cin >> n >> s;
        if (n == 1)
        {
            v.push_back(s);
        }
        else
        {
            int cv = ceil(n / 2);
            int maxV = ceil(s / cv);
            int k = n - cv + 1;
            bool found = false;
            while (!found)
            {
                if (k * maxV <= s)
                {
                    v.push_back(maxV);
                    found = true;
                }
                maxV--;
            }
        }

        t--;
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    return 0;
}