#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> precompute_prefix(string &p){
    vector<int> s(p.length());
    int border = 0;
    s[0] = 0;
    for(unsigned int i=1; i<p.length(); i++){
        while((border > 0) && (p[i] != p[border]))
            border = s[border-1];
        if(p[i] == p[border])
            border += 1;
        else
            border = 0;
        s[i] = border;
    }
    return s;
}

int main()
{
    string pattern, text;
    getline(cin, pattern);
    getline(cin, text);
    string temp = pattern + '$' +text;
    vector<int> s = precompute_prefix(temp);
    vector<int> res;
    for(unsigned int i=pattern.length()+1; i<temp.length(); i++){
        if(s[i] == pattern.length())
            res.push_back(i-(2*pattern.length()));
    }
    for(unsigned int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    return 0;
}
