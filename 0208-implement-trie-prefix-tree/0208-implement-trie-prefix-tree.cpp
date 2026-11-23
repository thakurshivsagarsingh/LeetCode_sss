class Trie {
    struct node{
        node *children[26] = {NULL};
        bool isEnd = false;
    };
    node *root;
    node* traverse(string s){
        node *temp = root;
        for (char ch : s) {
            temp = temp->children[ch - 'a'];
            if (!temp)
                return NULL;
        }
        return temp;
    }
public:
    Trie(){
        root = new node();
    }
    
    void insert(string word) {
        node *temp = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (!temp->children[i])
                temp->children[i] = new node();
            temp = temp->children[i];
        }
        temp->isEnd = true;
    }
    bool search(string word) {
        node *temp = traverse(word);
        return temp && temp->isEnd;
    }
    bool startsWith(string prefix) {
        return traverse(prefix) != NULL;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */