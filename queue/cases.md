
# QUEUE — PRIMARY CASES & SPECIAL CONDITIONS (CHEAT CHECKLIST)
Operation,Linked List (1 Pointer),Linked List (2 Pointers),Array (Fixed size)
Enqueue,  O(n),           O(1),    O(1)
Dequeue,  O(1),           O(1),    O(n) (Shifting proyojon hole)
Peek,     O(1),           O(1),    O(1)
## 1️⃣ EMPTY QUEUE

**Condition**

* Array queue: `front == -1`
* Linked list queue: `front == NULL`

**Must handle in**

* `dequeue`
* `peek`
* `display`

**Action**

* Print error / return error value
* Do **not** access array or node

Miss this → underflow / segfault.

---

## 2️⃣ FULL QUEUE (OVERFLOW)

**Condition**

* Simple array queue: `rear == size - 1`
* Circular queue: `(rear + 1) % size == front`
* Linked list: `malloc == NULL`

**Must handle in**

* `enqueue`

**Action**

* Reject insertion
* Do NOT modify pointers/indexes

Miss this → memory corruption.

---

## 3️⃣ INSERTING FIRST ELEMENT (EMPTY → NON-EMPTY)

This is where most people screw up.

### Array queue

```c
if(front == -1)
    front = 0;
```

### Linked list queue

```c
front = rear = newNode;
```

**Must handle in**

* `enqueue`

If you don’t → front stays invalid forever.

---

## 4️⃣ DELETING LAST ELEMENT (NON-EMPTY → EMPTY)

Another classic bug.

### Array queue

```c
if(front > rear)
    front = rear = -1;
```

### Circular queue

```c
if(front == rear)
    front = rear = -1;
```

### Linked list queue

```c
if(front == NULL)
    rear = NULL;
```

**Must handle in**

* `dequeue`

Miss this → dangling pointers.

---

## 5️⃣ FRONT AND REAR UPDATE ORDER

**Correct order**

* Enqueue: update `rear` → assign value
* Dequeue: read value → update `front`

Wrong order → lost data.

---

## 6️⃣ CIRCULAR WRAP-AROUND (CIRCULAR QUEUE ONLY)

**Condition**

```c
index = (index + 1) % size;
```

Used in:

* `enqueue`
* `dequeue`

Forget modulo → array out-of-bounds.

---

## 7️⃣ SINGLE ELEMENT QUEUE

When:

```c
front == rear
```

Must handle separately in:

* `dequeue`

Because removing it empties the queue.

---

## 8️⃣ INVALID OPERATIONS

You must reject:

* `enqueue` on full queue
* `dequeue` on empty queue
* `peek` on empty queue

Never “assume valid input”.

---

## 9️⃣ MEMORY SAFETY (LINKED LIST QUEUE)

✔ Check `malloc`
✔ Free removed node
✔ Never access freed memory

---

## 🔥 ONE-LOOK EXAM CHECKLIST (MEMORIZE THIS)

Before coding queue operations, ask:

> empty?
> full?
> first insert?
> last delete?
> wrap-around?
> malloc fail?

If all answered → correct solution.

---

## MOST COMMON EXAM FAIL MISTAKES

❌ Not resetting `front` & `rear`
❌ Wrong circular full condition
❌ Deleting from rear
❌ Mixing stack logic
❌ Forgetting single-element case

---

## Brutal truth

Queue is **not hard**.
It only looks hard because people ignore **state transitions**.

Empty → One element → Many → One → Empty
That’s the whole game.

enqueue():

   full? 
   empty?
   first insert?

dequeue():

   empty?
   single element?
   reset front/rear?

peek():

   empty?

display():

   empty?
