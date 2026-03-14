Node *getListAfterDeleteOperation(Node *head, int n, int m)
{
	if(head==NULL || head->next==NULL){
		return head;
	}
	// Write your code here.
	Node* curr=head;
	while(curr!=NULL){
		int travm=0;
		// traverse m nodes
		while(travm<m-1){
			curr=curr->next;
			travm++;
			if(curr==NULL){
				return head;
			}
		}

		// delete n nodes
		Node* rem = curr->next;
		int remn=0;
		while(remn<=n-1){
			Node* temp = rem;
			rem=rem->next;
			delete temp;
			remn++;
			if(rem==NULL){
			    curr->next=NULL;
				return head;
			}
		}
		curr->next=rem;
		curr=curr->next;
	}
	return head;
}