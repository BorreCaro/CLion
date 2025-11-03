#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
void pushLine(vector<string> &words, const string &line) {
    size_t begin = 0;
    size_t pos = 0;
    while ((pos = line.find(',', begin)) != string::npos ) {
        words.push_back(line.substr(begin, pos-begin));
        if (words.back().empty()) words.pop_back();
        begin = pos + 1;
    }
    words.push_back(line.substr(begin));
    if (words.back().empty()) words.pop_back();
}
int main() {
    ifstream File("sexy.txt");
    string line;
    vector<string> words;
    while (getline(File, line)) {
        pushLine(words, line);
    }
    for (auto &s : words) cout<<s<<"\n";

    return 0;
}