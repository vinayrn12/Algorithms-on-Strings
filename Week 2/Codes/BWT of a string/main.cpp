#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    vector<string> m;
    for(unsigned int i=0; i<str.length(); i++){
        rotate(str.begin(), str.begin()+str.length()-1, str.end());
        m.push_back(str);
    }
    sort(m.begin(), m.end());
    for(unsigned int i=0; i<m.size(); i++)
        cout<<m[i][str.length()-1];
    return 0;
}
