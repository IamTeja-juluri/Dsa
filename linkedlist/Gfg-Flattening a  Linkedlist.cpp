/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    class compare {
    public:
	bool operator()(Node* a, Node* b)
	{
		return a->data > b->data;
	}
};
    
void flattenHelper(Node* head,priority_queue<Node*,vector<Node*>,compare >&pq){
    if(head==NULL)
    return ;
    pq.push(head);
    flattenHelper(head->bottom,pq);
    flattenHelper(head->next,pq);
    
}
    
Node *flatten(Node *root)
{
  Node* ptr = root;
	Node* head = NULL;


	priority_queue<Node*,
			vector<Node*>,
			compare> pq;

    flattenHelper(root,pq);

	while (!pq.empty()) {

		Node* temp = pq.top();

		
		if (head == NULL) {
			head = temp;
			ptr = temp;
			ptr->bottom = NULL;
		}
		else {
			ptr->bottom = temp;
			ptr = temp;
			ptr->next = NULL;
		}
			pq.pop();
	}

	return head;
      
      
  }
