/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
medium: https://rambabuy.medium.com/
Problem:  Design Add and Search Words Data Structure
------------------------------------------------------------------
Description:

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True


------------------------------------------------------------------
Solution:

In this implementation, each node in the trie contains a boolean flag indicating whether the path from the root to that node represents a valid word. The addWord() method traverses the trie to insert the new word, creating new nodes as necessary.

The search() method recursively traverses the trie to match the input word against the stored words. If the current character in the input word is a dot, it searches all child nodes. 
If the current character is a letter, it follows the child node corresponding to that letter. If the input word is empty, it checks whether the current node represents a valid word.

Note that this implementation assumes that the input strings contain only lowercase letters and dots. If you need to handle other characters, you may need to modify the code accordingly.


------------------------------------------------------------------
Notes:

The time complexity of adding a new word to the trie in the addWord() method is O(m), where m is the length of the word being added. This is because we need to traverse the trie from the root to the end of the word, creating new nodes as necessary.

The time complexity of searching for a word in the trie in the search() method is O(m), where m is the length of the word being searched. This is because we need to traverse the trie from the root to the end of the word, checking if each character is present in the trie.

In addition to the time complexity, the space complexity of the trie is O(n*m), where n is the number of words stored in the trie and m is the average length of the words. 
This is because each node in the trie requires space to store its is_word flag and its children map, and each character in each word adds another node to the trie.

Overall, the trie data structure provides a relatively efficient solution for storing and searching for words with a time complexity of O(m) per operation, where m is the length of the word being added or searched for. However, the space complexity can be quite large if the number of words and/or their lengths are large.


------------------------------------------------------------------
*/

#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    bool is_word;
    std::unordered_map<char, TrieNode*> children;

    TrieNode() : is_word(false) {}
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(std::string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_word = true;
    }

    bool search(std::string word) {
        return search_helper(word, root);
    }

private:
    TrieNode* root;

    bool search_helper(std::string word, TrieNode* node) {
        if (word.empty()) {
            return node->is_word;
        }
        if (word[0] == '.') {
            for (auto [c, child] : node->children) {
                if (search_helper(word.substr(1), child)) {
                    return true;
                }
            }
            return false;
        } else {
            if (node->children.count(word[0])) {
                return search_helper(word.substr(1), node->children[word[0]]);
            } else {
                return false;
            }
        }
    }
};

int main() {
    WordDictionary dict;
    dict.addWord("hello");
    dict.addWord("world");
    dict.addWord("hey");

    std::cout << std::boolalpha << dict.search("hello") << std::endl; // true
    std::cout << std::boolalpha << dict.search("hey") << std::endl; // true
    std::cout << std::boolalpha << dict.search("he") << std::endl; // false
    std::cout << std::boolalpha << dict.search("h.llo") << std::endl; // true
    std::cout << std::boolalpha << dict.search("wo.ld") << std::endl; // true
    std::cout << std::boolalpha << dict.search("w.rld") << std::endl; // false

    return 0;
}

