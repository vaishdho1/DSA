/*Basic trie which stores a string and has operations like
1) insert
2) search
3) startswith
The first implementation uses an array of 26, but we can reduce space by using a map as shown in the second part.
*/

class Trie {
    private:
        Trie * arr[26] = {};
        bool is_word = false;

    public:
        Trie()
        {}
        void add(char ch)
        {
            arr[ch-'a'] = new Trie();
        }
        bool contains(char ch)
        {
            return (arr[ch-'a']!=NULL);
        }
        void setWord()
        {
            is_word = true;
        }
        Trie *moveNext(char ch)
        {
            return arr[ch-'a'];
        }
        void insert(string word) 
        {
            Trie *temp = this;
            for(int i=0;i<word.size();i++)
            {
                if(!temp->contains(word[i]))
                    temp->add(word[i]);
                temp = temp->moveNext(word[i]);
            }
            temp->setWord();
        }
    
        bool search(string word)
        {
            Trie * temp = this;
            for(int i=0;i<word.size();i++)
            {
                if(temp->contains(word[i]))
                    temp =temp->moveNext(word[i]);
                else
                    return false;
            }
            return temp->is_word;
        }
        bool startsWith(string prefix)
        {
            Trie * temp = this;
            for(int i=0;i<prefix.size();i++)
            {
                if(temp->contains(prefix[i]))
                    temp = temp->moveNext(prefix[i]);
                else
                    return false;
            }
            return true;
        }
};
//Using map
class Trie {
    private:
        unordered_map<int,Trie*>Tr;
        bool is_word = false;

    public:
        Trie()
        {}
        void add(char ch)
        {
            Tr[ch] = new Trie();
        }
        bool contains(char ch)
        {
            return (Tr.find(ch)!=Tr.end());
        }
        void setWord()
        {
            is_word = true;
        }
        Trie *moveNext(char ch)
        {
            return Tr[ch];
        }
};

