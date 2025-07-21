
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;
    
    // Pointer to the next node in the list
    Node* next;

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to merge K sorted linked lists
Node* mergeKLists(vector<Node*>& listArray){
    // Priority queue to maintain
    // sorted order based on node values
    // Pairs store node value and pointer to the node
    priority_queue<pair<int, Node*>,
        vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    
    // Push the heads of all the
    // linked lists into the priority queue
    for(int i = 0; i < listArray.size(); i++){
        // Check if the current linked list exists
        if(listArray[i]){
            // Push the pair of node data and
            // node pointer into the priority queue
            pq.push({listArray[i]->data, listArray[i]});
        }
    }
    
    // Create a dummy node to build the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    
    // Merge the lists present
    // in the priority queue
    while(!pq.empty()){
        // Get the top element (minimum node value)
        // from the priority queue
        auto it = pq.top();
        pq.pop();
        
        // Check if the current
        // node has a next node
        if(it.second->next){
            // Push the next node
            // into the priority queue
            pq.push({it.second->next->data, it.second->next});
        }
        
        // Set the next pointer of the
        // current node in the merged list
        temp->next = it.second;
        temp = temp->next;
    }
    
    // Return the merged linked list
    return dummyNode->next;
}


// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->data << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}

int main() {
    // Create linked lists
    Node* head1 = new Node(2, new Node(4, new Node(6)));
    Node* head2 = new Node(1, new Node(5));
    Node* head3 = new Node(1, new Node(1, new Node(3, new Node(7))));
    Node* head4 = new Node(8);

    // Populate the lists vector
    vector<Node*> lists = {head1, head2, head3, head4};
    
    cout << "Original Linked Lists:" << endl;
    for (int i = 0; i < lists.size(); ++i) {
        cout << "List " << i + 1 << ": ";
        printLinkedList(lists[i]);
    }

    // Merge the linked lists
    Node* mergedList = mergeKLists(lists);
    
    // Print the merged linked list
    cout << "Merged Linked List: ";
    printLinkedList(mergedList);

    return 0;
}

