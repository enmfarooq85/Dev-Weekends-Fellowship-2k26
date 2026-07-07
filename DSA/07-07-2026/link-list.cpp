// A Linked List is a linear data structure where each node stores:

// Data
// Pointer(s) to the next node (and sometimes previous node)

// Unlike arrays, linked lists are not stored in contiguous memory.

// Head
//  ↓
// [10|*] → [20|*] → [30|*] → NULL

// Types of Linked Lists
// 1. Singly Linked List

// Each node points to the next node.

// 10 → 20 → 30 → NULL

// Characteristics:

// One pointer per node
// Forward traversal only
// Less memory
// Easy insertion/deletion at head

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// 2. Doubly Linked List

// Each node has previous and next pointers.

// NULL ← 10 ⇄ 20 ⇄ 30 → NULL

// Characteristics:

// Forward traversal
// Backward traversal
// Easier deletion
// Uses more memory


struct Node {
    int val;
    Node* prev;
    Node* next;

    Node(int x){
        val=x;
        prev=nullptr;
        next=nullptr;
    }
};

// 3. Circular Linked List

// Last node points back to head.

// 10 → 20 → 30
// ↑          |
// |__________|

// Characteristics:

// No NULL pointer
// Used in round-robin scheduling
// Infinite traversal until stopped