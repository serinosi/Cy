#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
};
//shi
class SuffixTrie {
public:
    TrieNode* root;

    SuffixTrie() {
        root = new TrieNode();
    }

    void insertSuffix(const string& suffix) {
        TrieNode* curr = root;
        for (char c : suffix) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
    }

    void buildSuffixTrie(const string& text) {
        for (size_t i = 0; i < text.length(); ++i) {
            insertSuffix(text.substr(i));
        }
    }

    void printTrieUtil(TrieNode* node, string& prefix) {
        if (node->children.empty()) {
            cout << prefix << endl;
            return;
        }

        for (const auto& kv : node->children) {
            prefix.push_back(kv.first);
            printTrieUtil(kv.second, prefix);
            prefix.pop_back();
        }
    }

    void printTrie() {
        string prefix;
        printTrieUtil(root, prefix);
    }
};

int main() {
    string text;
    cout << "Enter a string: ";
    cin >> text;

    SuffixTrie trie;
    trie.buildSuffixTrie(text);

    cout << "Trie (pictorial representation with characters):" << endl;
    trie.printTrie();

    return 0;
}
