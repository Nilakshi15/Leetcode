/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL){
            return NULL;
        }

        unordered_map<Node*, Node*>m;
        Node* newhead = new Node(head -> val);
        Node* oldTemp = head -> next;
        Node* newTemp = newhead;

        m[head] = newhead;

        while(oldTemp != NULL){
            Node* copyNode = new Node(oldTemp-> val);
            m[oldTemp] = copyNode;
            newTemp -> next = copyNode;  // ADD this to link the new node
            newTemp = newTemp->next;   // Move to the newly added node
            oldTemp = oldTemp->next;
        }

        oldTemp = head;
        newTemp = newhead;

        while(oldTemp != NULL){
            newTemp -> random = m[oldTemp -> random];
            oldTemp = oldTemp -> next;
            newTemp = newTemp -> next;
        }

        return newhead;
    }
};