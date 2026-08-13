class TrieNode {
public:
    bool isEndWord;
    TrieNode* children[26];
    TrieNode() {
        isEndWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() { 
        root = new TrieNode(); 
    }

    void insert(string word) {
        TrieNode* curr = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEndWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr)
                return false;
            curr = curr->children[idx];
        }
        return curr->isEndWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char ch : prefix) {
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr)
                return false;
            curr = curr->children[idx];
        }
        return true;
    }
};
