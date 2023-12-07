class Trie {
private:
    struct node{
        struct node* next[26];
        bool endmark;
        node(){
            endmark=0;
            for(int i=0; i<26; i++){
                next[i]=nullptr;
            }
        }
    };
    struct node* root;
public:
    Trie() {
      root=new node();
    }
    
    void insert(string word) {
        int len=word.size();
        struct node* cur=root;
        for(int i=0; i<len; i++){
            if(cur->next[(word[i]-'a')]==nullptr)
                cur->next[(word[i]-'a')]=new node();
            cur=cur->next[(word[i]-'a')];
        }
        cur->endmark=1;
    }
    
    bool search(string word) {
        int len=word.size();
        struct node* cur=root;
        for(int i=0; i<len; i++){
            if(cur->next[(word[i]-'a')]==nullptr){
                return 0;
            }else{
                cur=cur->next[(word[i]-'a')];
            }
        }
        if(cur->endmark){
            return 1;
        }else{
            return 0;
        }
    }
    
    bool startsWith(string prefix) {
        int len=prefix.size();
        struct node* cur=root;
        for(int i=0; i<len; i++){
            if(cur->next[(prefix[i]-'a')]==nullptr){
                return 0;
            }else{
                cur=cur->next[(prefix[i]-'a')];
            }
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
