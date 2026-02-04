Operation,              1 Pointer (Head),     2 Pointers (Head + Tail)
---------------------------------------------------------------------------------------
Insert at Beginning,    O(1),                 O(1)
>>>>>>Insert at End,          O(n),                 O(1)
Delete from Beginning,  O(1),O(1)
Delete from End,        O(n),                 O(n)
Search,                 O(n),O(n)


Condition,             Stops At...,                 Best For...
----------------------------------------------------------------------------------------
temp->next != tail,    Second-to-last node,         Deleting the tail.
temp->next != NULL,    Last node,                   Appending a new node.
temp != tail,          Last node,                   Fast traversal to the end.
temp != NULL,          NULL (Past the list),        Printing or searching the whole list.
# 🔗 SINGLY LINKED LIST — COMPLETE ERROR-HANDLING CHEAT SHEET

Applies to:

* Insert
* Delete
* Search
* Traverse
* Reverse

---

## 🧠 GLOBAL INVARIANTS (EXAM GOLD)

* `head == NULL` → list empty
* Last node → `node->next == NULL`
* Never lose `head`
* Never access `temp->next` without checking `temp != NULL`

Miss one → segmentation fault → zero logic marks.

---

## 🔹 1️⃣ INSERT OPERATIONS

---

### 🔸 A. Insert at BEGINNING

#### Checks Required

| Case           | Action                |
| -------------- | --------------------- |
| List empty     | new node becomes head |
| List non-empty | link new → head       |

#### Code Logic

```c
new->next = head;
head = new;
```

❌ No loop
❌ No empty rejection

---

### 🔸 B. Insert at END

#### Checks Required

| Case           | Action                       |
| -------------- | ---------------------------- |
| List empty     | head = new                   |
| List non-empty | traverse till `next == NULL` |

#### While Condition

```c
while(temp->next != NULL)
```

❌ Don’t check `temp != NULL` inside loop (already guaranteed)

---

### 🔸 C. Insert at K-th Position

#### MUST HANDLE ALL

| Case         | Meaning                     |
| ------------ | --------------------------- |
| List empty   | Only valid if k = 1         |
| k = 1        | Same as insert at beginning |
| k > length+1 | Invalid                     |
| Middle       | Normal insert               |
| End          | Same as insert at end       |

#### Loop Rule

```c
for(i = 1; i < k-1; i++)
```

❌ Missing bounds check = buggy code

---

## 🔹 2️⃣ DELETE OPERATIONS

---

### 🔸 A. Delete at BEGINNING

#### Checks

| Case           | Action             |
| -------------- | ------------------ |
| List empty     | Underflow          |
| Single node    | free + head = NULL |
| Multiple nodes | move head          |

#### Core Logic

```c
temp = head;
head = head->next;
free(temp);
```

---

### 🔸 B. Delete at END

#### MUST HANDLE

| Case           | Action              |
| -------------- | ------------------- |
| List empty     | Underflow           |
| Single node    | free + head = NULL  |
| Multiple nodes | stop at second last |

#### Loop

```c
while(temp->next->next != NULL)
```

---

### 🔸 C. Delete by VALUE (MOST IMPORTANT)

#### REQUIRED CASES (EXAM CHECKLIST)

| Case            | Required |
| --------------- | -------- |
| List empty      | ✔        |
| Value at head   | ✔        |
| Value in middle | ✔        |
| Value at end    | ✔        |
| Value not found | ✔        |

Miss one → solution invalid.

#### Loop

```c
while(temp != NULL && temp->data != value)
```

---

### 🔸 D. Delete at K-th Position

#### MUST CHECK

| Condition  |
| ---------- |
| List empty |
| k ≤ 0      |
| k = 1      |
| k > length |

---

### 🔸 E. Delete Node WITHOUT HEAD (INTERVIEW FAVORITE)

#### Valid ONLY IF

| Condition     |
| ------------- |
| Node not NULL |
| Node not last |

#### Trick

```c
node->data = node->next->data;
node->next = node->next->next;
```

❌ Cannot delete last node

---

## 🔹 3️⃣ SEARCH

#### Cases

| Case        | Meaning         |
| ----------- | --------------- |
| List empty  | not found       |
| Found       | return position |
| End reached | not found       |

#### Loop

```c
while(temp != NULL)
```

---

## 🔹 4️⃣ TRAVERSE / PRINT

#### MUST CHECK

```c
if(head == NULL)
```

Print until:

```c
temp != NULL
```

❌ Printing `temp->next != NULL` misses last node

---

## 🔹 5️⃣ REVERSE LINKED LIST (CLASSIC TRAP)

#### 3 POINTER METHOD

```c
prev = NULL;
curr = head;

while(curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
head = prev;
```

❌ Missing `head = prev` = wrong answer

---

## 🔹 6️⃣ COUNT / LENGTH

```c
count = 0;
while(temp != NULL){
    count++;
    temp = temp->next;
}
```

No shortcuts.

---

## 🔥 EXAM ONE-LINE MEMORY MAP

```
INSERT → never lose head
DELETE → free exactly one node
SEARCH → stop at NULL
REVERSE → 3 pointers
```

---

## 💀 MOST COMMON LINKED LIST MISTAKES

❌ Accessing `temp->next` when `temp == NULL`
❌ Forgetting empty list case
❌ Forgetting head deletion case
❌ Wrong loop condition
❌ Memory leak (not freeing)
❌ Freeing wrong node

---

## 🧠 FINAL REALITY CHECK

If you can’t **list these cases from memory**,
you don’t *know* linked list — you just memorized code.

Exams don’t test syntax.
They test **edge-case thinking**.

---

