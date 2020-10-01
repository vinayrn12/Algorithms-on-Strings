#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string bwt_inverse(string &s){
    string res{""};

    vector<pair<char, int>> letters(s.length());
    for(unsigned int i=0; i<s.length(); i++)
        letters[i] = make_pair(s[i], i);
    sort(letters.begin(), letters.end());
    int pos = 0;
    for(unsigned int i=0; i<letters.size(); i++){
        pos = letters[pos].second;
        res += letters[pos].first;
    }
    return res;
}

int main()
{
    string str;
    getline(cin, str);
    cout<<bwt_inverse(str);
    return 0;
}
