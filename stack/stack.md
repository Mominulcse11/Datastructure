Definition:---

 >>>A stack is a linear data structure where elements can be inserted or deleted only from one end,
 which is called the top of the stack. It is based on the Last-In-First-Out (LIFO) principle, 
 meaning the element that was last added is the one that is first removed.



---Operations---

The two key operations are:
>>>push: Adding an element to the stack.
Subtasks include receiving the element, incrementing the stack pointer (top), and storing the element at the new top location.

>>>pop: Reading or deleting an element from the stack.5
Subtasks include retrieving or removing the element at the top and decrementing the stack pointer (top).



---Implementation---

Stacks can be implemented using arrays or linked lists.
>>> Array Implementation: Involves allocating a fixed-size array in memory and performing push/pop operations 
 with a check to prevent going out of bounds.

>>>Linked List Implementation (Advantage): Uses dynamic memory allocation, so the stack only consumes the space
 required for its data elements, which prevents wastage of memory space, unlike fixed-size array-implemented stacks.



---Applications---

Stacks are typically used in the implementation of:
>>>System processes, such as compilation and program control.

>>>Solutions to advanced systems problems such as recursion control and expression evaluation.
