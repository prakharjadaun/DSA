#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *head = NULL, *tail = NULL;
    map<int,int> hashmap1;
    map<int,int> hashmap2;
    Node *temp = head1;
    while(temp)
    {
        hashmap1[temp->data]++;
        temp = temp->next;
    }
    temp = head2;
    while(temp)
    {
        hashmap2[temp->data]++;
        temp = temp->next;
    }
    
    vector<int> inter;
    for(auto i : hashmap1)
    {
        if(hashmap2.find(i.first)==hashmap2.end())
            continue;
        else
        {
            int iter = (i.second==hashmap2[i.first])? i.second : min(i.second,hashmap2[i.first]);
            for(int j=0;j<iter;j++)
                inter.push_back(i.first);
        }
    }
    for(auto i : inter)
    {
       
        if(!head)
        {
            head = new Node(i);
            tail = head;
        }
        else
        {
            tail->next = new Node(i);
            tail = tail->next;
        }
        
    }
    return head;
    
}