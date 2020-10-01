#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b){
    return (a.first < b.first) ? 1: 0;
}

int main()
{
    string s;
    getline(cin, s);
    vector<pair<string, int>> suffix_array(s.length());
    for(unsigned int i=0; i<s.length(); i++){
        string temp = s.substr(i, s.length()-1);
        suffix_array[i] = make_pair(temp, i);
    }
    sort(suffix_array.begin(), suffix_array.end(), cmp);
    for(unsigned int i=0; i<suffix_array.size(); i++)
        cout<<suffix_array[i].second<<" ";
    return 0;
}
