#include <string>
#include "TrieNode.h"
using namespace std;

class Trie {
    TrieNode *root;

    public:
    Trie() {
        root = new TrieNode('\0'); // root ki data ki jagah NULL
    }

    void insertWord(TrieNode *root, string word) {
        // base case
        if (word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        
        // small calculation
        int index = word[0] - 'a';
        TrieNode* child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        } else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        // recursive call
        insertWord(child, word.substr(1));
    }
    // function for user
    void insertWord(string word) {
        insertWord(root, word);
    }

    bool search(TrieNode *root, string word) {
        if(word.size() == 0) {
            return root -> isTerminal;
        }

        // small calc
        int index = word[0] - 'a';
        TrieNode *child;
        if (root -> children[index] != NULL) {
            child = root -> children[index];
        } else {
            return false;
        }

        // rec call
        return search(child, word.substr(1));
    }

    bool search (string word) {
        return search(root, word);
    }

    void removeWord(TrieNode* root, string word) {
        // Base Case
        if (word.size() == 0) {
            root -> isTerminal = false;
            return;
        }

        // small calculation
        TrieNode *child;
        int index = word[0] - 'a';
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        } else {
            // word not found
            return;
        }

        removeWord(child, word.substr(1));

        // check if child is useless - remove if yes
        if(child -> isTerminal == false) {
            for(int i = 0; i < 26; i++) {
                if (child -> children[i] != NULL) {
                    return;
                }
            }
            delete child;
            root -> children[index] = NULL;
        }
    }

    void removeWord(string word) {
        removeWord(root, word);
    }
};