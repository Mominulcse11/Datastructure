Queues

---Definition---

>>>A queue is a linear data structure where elements are inserted from one end (called rear) and deleted from the other end (called front). It is based on the First-In-First-Out (FIFO) principle, meaning the element that was first added is the one that is first removed.



---Types of Queues---

>>>Circular Queue (Definition and Advantage): A queue whose start and end locations are logically connected. They remove a major disadvantage of array-implemented queues by preventing a lot of memory space from being wasted due to inefficient utilization.

>>>Priority Queue (Definition): A type of queue where each element has a priority, and the order of deletion is decided by the associated priorities.

Deletion Rule: An element with the lowest priority is deleted before all others of higher priority. If two elements have the same priority, they are deleted based on the order they were added (FIFO).



---Operations---

The two key operations are:
>>>insert: Adds an element at the rear end of the queue.
Subtasks include receiving the element, incrementing the queue pointer (rear), and storing the element at the new rear location.

>>>delete: Removes an element from the front end of the queue.
Subtasks include retrieving or removing the element from the front and incrementing the queue pointer (front) to point to the next element.



---Implementation---

Queues can be implemented using arrays or linked lists.
>>>Array Implementation: Involves allocating a fixed-size array and performing operations with a check to ensure the array does not go out of bounds.

>>>Linked List Implementation (Advantage): Uses dynamic memory allocation, consuming only the space required for its data elements and thus preventing memory wastage, which is contrary to array-implemented queues.



---Applications---

Queues are typically used in the implementation of key system processes such as:
>>>CPU scheduling.
>>>Resource sharing.
