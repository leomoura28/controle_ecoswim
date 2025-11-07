#include <bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define endl '\n'
#define LONGINF 9223372036854775807
#define int long long int

signed main() {
    int n = 1143, m = 92;
    vector<string> v1,v2, v5; // nome, id, kit
    map<string, pair<string,string>> mapa1;
    for(int i = 0; i < n; i++){
        string a;
        getline(cin, a);
        v1.push_back(a);
    }
    
    for(int i = 0; i < n; i++){
        string a;
        getline(cin, a);
        v2.push_back(a);
    }
    
    for(int i = 0; i < n; i++){
        string a;
        getline(cin, a);
        v5.push_back(a);
    }

    for(int i = 0; i < n; i++){
        mapa1[v1[i]] = {v2[i], v5[i]};
    }

    vector<string> v3,v4; // id, equipe
    map<string, string> mapa2;
    for(int i = 0; i < m; i++){
        string a;
        getline(cin , a);
        v3.push_back(a);
    }
    
    for(int i = 0; i < m; i++){
        string a;
        getline(cin, a);
        v4.push_back(a);
    }
    
    for(int i = 0; i < m; i++){
        mapa2[v3[i]] = v4[i];
    }
    map<string, pair<string, string>> mapa3; //nome, equipe , kit
    for(auto it = mapa1.begin(); it != mapa1.end(); it++){
        mapa3[it->first] = {mapa2[it->second.first], mapa1[it->first].second};
    }
    
    for(int i = 0; i < 100; i++) cout << "a\n"; 
    for(auto it = mapa3.begin(); it != mapa3.end(); it++){
        cout << it->first << endl;
    }
    
    for(int i = 0; i < 100; i++) cout << "a\n";
    for(auto it = mapa3.begin(); it != mapa3.end(); it++){
        cout << it->second.first << endl;
    }
    
    for(int i = 0; i < 100; i++) cout << "a\n";
    for(auto it = mapa3.begin(); it != mapa3.end(); it++){
        cout << it->second.second << endl;
    }



    return 0;
}