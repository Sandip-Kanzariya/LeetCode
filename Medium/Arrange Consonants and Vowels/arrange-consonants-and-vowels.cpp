//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

class Solution
{
    public:
    // task is to complete this function
    // function should return head to the list after making 
    // necessary arrangements
    
    bool isVowel(char c){
       return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    struct Node* arrangeCV(Node *head)
    {
        Node *vowels = new Node(0), *tv = vowels;
        Node *consonants = new Node(0), *tc = consonants;
        
        
        Node *temp = head;
        
        while(temp){
            
            if(isVowel(temp -> data)){
                
                Node *t = new Node(temp -> data);
                tv -> next = t;
                tv = t;
            }
            else{
                Node *t = new Node(temp -> data);
                tc -> next = t;
                tc = t;
            }
            temp = temp -> next;
        }
        
        tv -> next = consonants -> next;
        
        return vowels -> next;
        
    }
};



//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends