#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef map<char, int> edge;
typedef vector<edge> trie;

trie compute_tries(vector<string> &patterns){
    trie t;
    for(unsigned int i=0; i<patterns.size(); i++){
        int pos = 0;
        for(unsigned int j=0; j<patterns[i].length(); j++){
            bool matched = false;
            if(pos < t.size()){
                for(auto k: t[pos]){
                    if(k.first == patterns[i][j]){
                        matched = true;
                        pos = k.second;
                        break;
                    }
                }
                if(!matched){
                    t[pos].emplace(patterns[i][j], t.size());
                    pos = t.size();
                }
            }
            else{
                map<char, int> temp;
                temp.emplace(patterns[i][j], t.size()+1);
                t.emplace_back(temp);
                pos = t.size();
            }
        }
        map<char, int> temp;
        temp.emplace('$', -1);
        t.emplace_back(temp);
    }
    return t;
}


int main()
{
    int n;
    cin>>n;
    cin>>ws;
    vector<string> patterns;
    for(int i=0; i<n; i++){
        string s;
        getline(cin, s);
        patterns.emplace_back(s);
    }
    trie res = compute_tries(patterns);
    for(unsigned int i=0; i<res.size(); i++){
        for(auto j: res[i]){
            if(j.first != '$')
                cout<<i<<"->"<<j.second<<":"<<j.first<<endl;
        }
    }
    return 0;
}
