//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Helper function to find the parents of all nodes
    void findParents(Node* root, unordered_map<Node*, Node*>& parentMap, Node*& targetNode, int target) {
        if (!root) return;
        if (root->data == target) targetNode = root;
        if (root->left) {
            parentMap[root->left] = root;
            findParents(root->left, parentMap, targetNode, target);
        }
        if (root->right) {
            parentMap[root->right] = root;
            findParents(root->right, parentMap, targetNode, target);
        }
    }
    
    // Function to calculate the minimum time to burn the entire tree
    int minTime(Node* root, int target) {
        if (!root) return 0;
        
        unordered_map<Node*, Node*> parentMap; // To store parent of each node
        Node* targetNode = nullptr; // To store the target node
        
        // Find the parents of all nodes and locate the target node
        findParents(root, parentMap, targetNode, target);
        
        // BFS to burn the tree
        unordered_set<Node*> visited; // To keep track of visited nodes
        queue<Node*> q;
        q.push(targetNode);
        visited.insert(targetNode);
        
        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            bool burnedAnyNode = false;
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                
                // Check and add left child
                if (current->left && visited.find(current->left) == visited.end()) {
                    q.push(current->left);
                    visited.insert(current->left);
                    burnedAnyNode = true;
                }
                
                // Check and add right child
                if (current->right && visited.find(current->right) == visited.end()) {
                    q.push(current->right);
                    visited.insert(current->right);
                    burnedAnyNode = true;
                }
                
                // Check and add parent node
                if (parentMap[current] && visited.find(parentMap[current]) == visited.end()) {
                    q.push(parentMap[current]);
                    visited.insert(parentMap[current]);
                    burnedAnyNode = true;
                }
            }
            if (burnedAnyNode) time++; // Increase time if any node was burned
        }
        
        return time;
    }
   
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends