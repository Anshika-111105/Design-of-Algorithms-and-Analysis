#include <bits/stdc++.h>
using namespace std;
struct Node { 
    char ch; 
    int freq; 
    Node *left, *right; 
}; 
Node* getNode(char ch, int freq, Node* left, Node* right) { 
    Node* node = new Node(); 
    node->ch = ch; 
    node->freq = freq; 
    node->left = left; 
    node->right = right; 
    return node; 
}
struct comp { 
    bool operator()(Node* l, Node* r){ 
        return l->freq > r->freq; // Min-Heap: lowest frequency at the top 
    } 
};
void encode(Node* root, string str, unordered_map<char, string> &huffmanCode) { 
     if (root == nullptr) 
      return; 
     // Leaf node (character node) 
     if (!root->left && !root->right) { 
      huffmanCode[root->ch] = str; 
     } 
     encode(root->left, str + "0", huffmanCode); 
     encode(root->right, str + "1", huffmanCode); 
}

void decode(Node* root, int &index, string str) 
{ 
 if (root == nullptr) { 
  return; 
 } 
 // Leaf node reached, print character 
 if (!root->left && !root->right) 
 { 
  cout << root->ch; 
  return; 
 } 
 index++; 
 if (str[index] == '0') 
  decode(root->left, index, str); 
 else 
  decode(root->right, index, str); 
}
//step1: count frequency of characters
void buildHuffTree(string text){
    unordered_map<char,int> freq;
    for(auto ch:text){
        freq[ch]++;
    }

}
//Step 2: Create priority queue (min-heap) 
priority_queue<Node*, vector<Node*>, comp> pq; 
for(auto pair: freq){ 
  pq.push(getNode(pair.first, pair.second, nullptr, nullptr)); 
} 
// Step 3: Construct Huffman Tree 
while (pq.size() != 1) { 
  Node *left = pq.top(); pq.pop(); 
  Node *right = pq.top(); pq.pop(); 
  int sum = left->freq + right->freq; 
  pq.push(getNode('\0', sum, left, right)); // Internal node with sum of frequencies 
} 
// Step 4: Generate Huffman codes 
Node* root = pq.top(); 
unordered_map<char, string> huffmanCode; 
encode(root, "", huffmanCode);

int main(){
    string text="Huffmann coding is a data compressipn algorithm";
    buildHuffTree(text);
    return 0;
}

