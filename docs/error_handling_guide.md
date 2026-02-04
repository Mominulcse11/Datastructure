# 🛡️ Beginner's Guide to Error Handling in Data Structures

This guide is designed to help you **understand** error handling, not just memorize it. As a student, you want your code to be robust—meaning it doesn't crash even if someone uses it incorrectly.

## 🧠 The Mental Model: "Check Before You Step"

Imagine your data structure is a house.
- **Memory Allocation (`malloc`)** is building a new room. You must check if you have land (memory) available.
- **Pointers** are addresses of rooms. `NULL` means "Nowhere". You cannot enter a room that is "Nowhere".
- **Accessing Data** is walking into a room. You cannot walk into a room that doesn't exist.

---

## 🚦 The 3 Golden Rules
Every time you write a function, ask these three questions:

1.  **Is it Empty?** (Can I delete or peek?)
2.  **Is it Full?** (Can I insert?)
3.  **Does it Exist?** (Is the pointer NULL?)

---

## 📚 Common Errors & How to Fix Them

### 1. The "Memory Full" Crash (Heap Overflow)
When you create a new node, the computer *might* say no. You must listen.

**❌ Bad:**
```c
node *temp = malloc(sizeof(node));
temp->data = 10; // CRASH if malloc failed!
```

**✅ Good:**
```c
node *temp = malloc(sizeof(node));
if (temp == NULL) {
    printf("Error: Memory Full!\n");
    return; // Stop right here
}
temp->data = 10; // Safe
```

### 2. The "Ghost Room" (NULL Pointer Dereference)
Trying to access data inside a `NULL` pointer is the #1 cause of crashes (Segmentation Faults).

**❌ Bad:**
```c
while (temp->data != target) { // CRASH if temp becomes NULL
    temp = temp->next;
}
```

**✅ Good:**
```c
// Check if temp exists FIRST
while (temp != NULL && temp->data != target) {
    temp = temp->next;
}
```

### 3. The "Lost Head" (Updating Head Pointer)
When inserting at the beginning or deleting the first node, the `head` of your list changes. If you don't update the global `head`, you lose the new node (memory leak) or keep referring to the deleted one.

**✅ Fix:** Always explicitely update `head = newItem` when inserting at start.

### 4. The "Off-By-One" (Array Bounds)
Arrays start at 0. If size is 5, valid indices are 0, 1, 2, 3, 4.

**❌ Bad:**
```c
if (top > 0) ... // Ignores index 0!
```

**✅ Good:**
```c
if (top >= 0) ... // Includes index 0
```

---

## 🛠️ Checklist for specific Data Structures

### 🟦 Linked List
- [ ] **Insert**: Did I handle `malloc` failure?
- [ ] **Delete**: Is the list empty (`head == NULL`)?
- [ ] **Delete**: Am I deleting the *first* node? (Update head)
- [ ] **Delete**: Am I deleting the *last* node? (Update tail or previous node's next)
- [ ] **Traversal**: Did I stop at `NULL`?

### 🟩 Stack (Array)
- [ ] **Push**: Is `top == capacity - 1`? (Stack Overflow)
- [ ] **Pop**: Is `top == -1`? (Stack Underflow)

### 🟨 Queue (Array)
- [ ] **Enqueue**: Is `rear == capacity - 1`?
- [ ] **Dequeue**: Is `front == -1`? (Empty)
- [ ] **Front/Rear**: Check `>= 0`, not just `> 0`!

---

## 💡 Pro Tip: "Fail Early"
Handle errors at the very top of your function. It makes code cleaner.

```c
void deleteFirst() {
    // 1. Error check FIRST
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // 2. Real logic SECOND
    node *temp = head;
    head = head->next;
    free(temp);
}
```
