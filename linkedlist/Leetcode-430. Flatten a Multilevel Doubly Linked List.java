class Solution {
     public Node flatten_rec(Node head){
        Node currNode = head, tailNode = head;
        while(currNode != null){
            Node childNode = currNode.child;
            Node nextNode = currNode.next;
            if(childNode != null){
                Node _tailNode = flatten_rec(childNode);
                _tailNode.next = nextNode;
                if(nextNode != null) 
                    nextNode.prev = _tailNode;
                currNode.next = childNode;
                currNode.child = null;
                childNode.prev = currNode;
                currNode = _tailNode;
            }
            else
                currNode = nextNode;
            if(currNode != null) tailNode = currNode;
        }
        return tailNode;
    }
    public Node flatten(Node head) {
        if(head != null) flatten_rec(head);
        return head;
    }
}
