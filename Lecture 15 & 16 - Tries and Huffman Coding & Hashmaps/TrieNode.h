class TrieNode {
    public:
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char data) {
        this -> data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        } // we are assuming that we will be using lower alphabets
        // we will be saving 0 pr a, then 1 pr b,,, aise order mei
        // seedha uske index p jaake dekha krenge fir
        isTerminal = false;
    }
};