// GFG 

// T.C. = O(N) and S.C. = O(N)
Node* linkdelete(Node* head, int n, int m) {
        if(head == NULL) return NULL;
        Node* temp = head;
        while(temp!=NULL){
            Node* prev = nullptr;
            for(int i=0;i<m && temp!=NULL ; i++){
                prev = temp;
                temp = temp->next;
            }
            
            if(temp==NULL) return head;
            
            for(int i=0;i<n && temp!=NULL ;i++){
                Node* ToDelete = temp;
                prev->next = temp->next;
                temp = temp->next;
                delete(ToDelete);
            }
        }
        return head;
    }