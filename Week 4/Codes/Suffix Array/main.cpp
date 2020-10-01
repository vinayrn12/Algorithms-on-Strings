#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int m = 2 * 1e5 + 5;
const int alpha = 256;
vector<int> order(m), char_class(m);
string s;
int n;

vector<int> sort_characters(){
    vector<int> order(m);
    vector<int> c(alpha);
    for(int i=0; i<n; i++)
        c[s[i]] += 1;
    for(int i=1; i<alpha; i++)
        c[i] = c[i-1]+c[i];
    for(int i=n-1; i>=0; i--){
        int t = s[i];
        c[t] -= 1;
        order[c[t]] = i;
    }
    return order;
}

vector<int> compute_charclass(vector<int> &order){
    vector<int> char_class(m);
    char_class[order[0]] = 0;
    for(int i=1; i<n; i++){
        if(s[order[i]] != s[order[i-1]])
            char_class[order[i]] = char_class[order[i-1]]+1;
        else
            char_class[order[i]] = char_class[order[i-1]];
    }
    return char_class;
}

vector<int> sort_doubled(int l, vector<int> &order, vector<int> &char_class){
    vector<int> c(n);
    vector<int> neworder(m);
    for(int i=0; i<n; i++)
        c[char_class[i]] += 1;
    for(int i=1; i<n; i++)
        c[i] = c[i] + c[i-1];
    for(int i=n-1; i>=0; i--){
        int start = (order[i]-l+n)%n;
        int t = char_class[start];
        c[t] -= 1;
        neworder[c[t]] = start;
    }
    return neworder;
}

vector<int> update_classes(vector<int> &neworder, vector<int> &char_class, int l){
    vector<int> newclass(m);
    newclass[neworder[0]] = 0;
    for(int i=1; i<n; i++){
        int curr = neworder[i]; int prev = neworder[i-1];
        int curr_mid = (curr+l)%n; int prev_mid = (prev+l)%n;

        if((char_class[curr] != char_class[prev]) || (char_class[curr_mid] != char_class[prev_mid]))
            newclass[curr] = newclass[prev] + 1;
        else
            newclass[curr] = newclass[prev];
    }
    return newclass;
}

vector<int> build_suffix_array(){
    order = sort_characters();
    char_class = compute_charclass(order);
    int l = 1;
    while(l < n){
        order = sort_doubled(l, order, char_class);
        char_class = update_classes(order, char_class, l);
        l = l * 2;
    }
    return order;
}

int main()
{
    getline(cin, s);
    n = s.length();
    vector<int> res = build_suffix_array();
    for(int i=0; i<n; i++)
        cout<<res[i]<<" ";
    return 0;
}
