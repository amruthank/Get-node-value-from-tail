/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
    if(positionFromTail<0)
        return -1;

	Node *mid = head,*tail = head;
	int head_cnt = 0,mid_cnt = 0,tail_cnt =0;

	
	//Find the middle node and pos_counts
	while(tail->next){
		tail = tail->next;
		tail_cnt++;
		if(tail->next){
		    mid = mid->next;
		    mid_cnt++;
		    tail = tail->next;
		    tail_cnt++;
		}
	}

	//Find the node data at given position
	if(positionFromTail == head_cnt) //If the first element from the tail
		return tail->data;
	else if(positionFromTail == tail_cnt) //If the last element from tail ie head node
		return head->data;
	else{
		int dist = tail_cnt - positionFromTail;
		if(dist == mid_cnt)
			return mid->data;
		else if(dist<mid_cnt){
			while(head_cnt != dist){
			    head = head->next;
			    head_cnt++;
			}
			return head->data;
		}
		else{
        while(mid_cnt != dist){
            mid = mid->next;
            mid_cnt++;
        }
        return mid->data;   
		  }
	   }
}
