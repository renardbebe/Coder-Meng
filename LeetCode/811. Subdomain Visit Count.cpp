class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> myMap;
        vector<string> ret;
        for (auto& str : cpdomains) {
            int pos = str.find(" ");
            int times = stoi(str.substr(0, pos));
            string tmp = str.substr(pos+1);
            
            myMap[tmp] += times;
            pos = tmp.find(".");
            while(pos != string::npos) {
                string tmp_sub = tmp.substr(pos+1);
                myMap[tmp_sub] += times;
                pos = tmp.find(".", pos+1);
            }
        }
        for (map<string, int>::iterator it = myMap.begin(); it != myMap.end(); it++) {
            string element = to_string(it->second) + " " + it->first;
            ret.push_back(element);
        }
        return ret;
    }
};