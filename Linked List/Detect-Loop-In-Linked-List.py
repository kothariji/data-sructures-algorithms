#The idea is to keep two pointers one will be incremented by one and other by two,
#If they meet at same node at any point then there is loop in linked list
def detect_loop(head): #returns True if loop is present
	pointer1 = head
	pointer2 = head
	while pointer1 and pointer2 and pointer2.next:
		pointer1 = pointer1.next
		pointer2 = pointer2.next.next
		if pointer1 == pointer2:
			return True
	return False
