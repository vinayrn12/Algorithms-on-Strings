#include <iostream>
#include <vector>
#include <string>

using namespace std;

int const n = 4;
int const no = -1;

class Node{
public:
    vector<int> next;
    bool pat_end;

    Node(){
        next.resize(n);
        for(int i=0; i<n; i++)
            next[i] = no;
        pat_end = false;
    }
};

int get_index(char letter){
    if(letter == 'A')
        return 0;
    else if(letter == 'C')
        return 1;
    else if(letter == 'G')
        return 2;
    else if(letter == 'T')
        return 3;
    else
        return -1; //Not likely, only 4 letters possible A, C, G and T
}

void form_trie(vector<Node> &t, vector<string> &patterns){
    for(unsigned int i=0; i<patterns.size(); i++){
        int x = 0;
        for(unsigned int j=0; j<patterns[i].length(); j++){
            int index = get_index(patterns[i][j]);
            if(x >= t.size())
                t.resize(x+1);
            if(t[x].next[index] != -1)
                x = t[x].next[index];
            else{
                t[x].next[index] = t.size();
                x = t.size();
                t.resize(x+1);
            }
        }
        t[x].pat_end = true;
    }
}

vector<int> match_patterns(string &text, vector<string> &patterns){
    vector<Node> t;
    form_trie(t, patterns);

    vector<int> r;

    for(unsigned int i=0; i<text.length(); i++){
        int index = get_index(text[i]);
        int x=0;
        if(t[x].next[index] != -1){
            bool found = true;
            for(unsigned int j=i; !t[x].pat_end; j++){
                if(j >= text.size()){
                    found = false;
                    break;
                }
                index = get_index(text[j]);
                if(t[x].next[index] != -1)
                    x = t[x].next[index];
                else{
                    found = false;
                    break;
                }
            }
            if(found)
                r.push_back(i);
        }
    }
    return r;
}

int main(){
    string text;
    int n;
    vector<string> patterns;
    getline(cin, text);
    cin>>n;
    cin>>ws;
    for(int i=0; i<n; i++){
        string temp;
        getline(cin, temp);
        patterns.emplace_back(temp);
    }
    vector<int> res = match_patterns(text, patterns);
    for(unsigned int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    return 0;
}
