# Understanding the JavaScript Event Loop

# Introduction

JavaScript is a **single-threaded**, **synchronous**, and **non-blocking** programming language.

Being **single-threaded** means JavaScript can execute **only one task at a time**.

If JavaScript executed every task one after another, then operations like:

* Fetching data from a server
* Reading a file
* Waiting for a timer
* User clicks

would block the entire application.

To solve this problem, JavaScript uses the **Event Loop**.

The Event Loop allows JavaScript to perform asynchronous operations while still remaining single-threaded.

---

# What is the Event Loop?

The **Event Loop** is a mechanism that continuously checks whether the Call Stack is empty.

If the Call Stack becomes empty, it moves pending tasks from queues into the Call Stack for execution.

In simple words:

> The Event Loop is the traffic controller that decides **when asynchronous callbacks should execute.**

---

# Why Do We Need the Event Loop?

Imagine the following code:

```javascript
console.log("Start");

setTimeout(() => {
    console.log("Hello");
}, 5000);

console.log("End");
```

Without the Event Loop:

JavaScript would stop for 5 seconds before executing the next line.

Output:

```text
(Start)

(wait 5 seconds)

Hello

End
```

This would freeze the webpage.

Instead, JavaScript executes:

```text
Start

End

(wait 5 seconds)

Hello
```

The Event Loop makes this possible.

---

# JavaScript Runtime Architecture

```text
                    JavaScript Runtime

          +-----------------------------+
          |         Memory Heap          |
          +-----------------------------+

                     ▲
                     │

          +-----------------------------+
          |         Call Stack          |
          +-----------------------------+
                     ▲
                     │
                     │
          +-----------------------------+
          |        Event Loop           |
          +-----------------------------+
              ▲                  ▲
              │                  │
      Microtask Queue      Callback Queue
              ▲                  ▲
              │                  │
         Promise Jobs      setTimeout()
         queueMicrotask()  setInterval()
         MutationObserver  DOM Events
                            MessageChannel
```

---

# Components of the Event Loop

The JavaScript runtime consists of:

* Memory Heap
* Call Stack
* Web APIs
* Callback Queue
* Microtask Queue
* Event Loop

Each component has a specific responsibility.

---

# Memory Heap

The Memory Heap stores:

* Objects
* Arrays
* Functions
* Variables

Example:

```javascript
const user = {
    name: "John"
};
```

The object is stored inside the Heap.

---

# Call Stack

The Call Stack keeps track of the currently executing functions.

It follows the **LIFO (Last In First Out)** principle.

Example:

```javascript
function one() {
    two();
}

function two() {
    three();
}

function three() {
    console.log("Hello");
}

one();
```

Stack execution:

```text
one()

↓

two()

↓

three()

↓

console.log()

↓

Pop console.log()

↓

Pop three()

↓

Pop two()

↓

Pop one()
```

---

# Web APIs

Web APIs are **not part of JavaScript**.

They are provided by the browser.

Examples:

* setTimeout
* setInterval
* fetch
* DOM Events
* Geolocation
* WebSockets

Example:

```javascript
setTimeout(() => {
    console.log("Done");
}, 1000);
```

The timer is handled by the browser.

JavaScript continues executing other code.

---

# Callback Queue (Macrotask Queue)

The Callback Queue stores completed asynchronous callbacks.

Examples:

* setTimeout
* setInterval
* DOM Events
* MessageChannel

Example:

```javascript
setTimeout(() => {
    console.log("Hello");
}, 1000);
```

After one second:

```text
Callback Queue

↓

console.log("Hello")
```

The callback waits until the Call Stack becomes empty.

---

# Microtask Queue

Microtasks have **higher priority** than the Callback Queue.

Examples:

* Promise.then()
* Promise.catch()
* Promise.finally()
* queueMicrotask()
* MutationObserver

Example:

```javascript
Promise.resolve().then(() => {
    console.log("Promise");
});
```

The callback enters the Microtask Queue.

---

# Event Loop Algorithm

The Event Loop continuously performs the following steps:

```text
1. Check Call Stack.

2. Is Call Stack empty?

YES

↓

Execute ALL Microtasks

↓

Execute ONE Callback Queue task

↓

Repeat
```

---

# Execution Order

Priority:

```text
1. Call Stack

↓

2. Microtask Queue

↓

3. Callback Queue (Macrotask Queue)
```

Microtasks always execute before macrotasks.

---

# Synchronous vs Asynchronous

Synchronous code:

```javascript
console.log("A");
console.log("B");
console.log("C");
```

Output:

```text
A
B
C
```

---

Asynchronous code:

```javascript
console.log("A");

setTimeout(() => {
    console.log("B");
}, 0);

console.log("C");
```

Output:

```text
A
C
B
```

---

# Promise vs setTimeout

Example:

```javascript
console.log("Start");

setTimeout(() => {
    console.log("Timeout");
}, 0);

Promise.resolve().then(() => {
    console.log("Promise");
});

console.log("End");
```

Execution:

```text
Call Stack

↓

Start

↓

setTimeout registered

↓

Promise registered

↓

End

↓

Microtask Queue

Promise

↓

Callback Queue

Timeout
```

Output:

```text
Start
End
Promise
Timeout
```

---

# async/await

Example:

```javascript
async function demo() {
    console.log(1);

    await Promise.resolve();

    console.log(2);
}

demo();

console.log(3);
```

Execution:

```text
1

↓

await pauses function

↓

3

↓

Promise resolved

↓

2
```

Output:

```text
1
3
2
```

---

# Common Event Loop APIs

## Microtasks

* Promise.then()
* Promise.catch()
* Promise.finally()
* queueMicrotask()
* MutationObserver

---

## Macrotasks

* setTimeout()
* setInterval()
* DOM Events
* MessageChannel
* postMessage()

---

# Complete Execution Flow

```text
JavaScript Code

↓

Call Stack

↓

Web API

↓

Async Operation

↓

Microtask Queue / Callback Queue

↓

Event Loop

↓

Call Stack

↓

Execution
```

---

# Example

```javascript
console.log("A");

setTimeout(() => {
    console.log("B");
}, 0);

Promise.resolve().then(() => {
    console.log("C");
});

console.log("D");
```

Flow:

```text
Stack

A

↓

setTimeout → Web API

↓

Promise → Microtask Queue

↓

D

↓

Stack Empty

↓

Microtask Queue

↓

C

↓

Callback Queue

↓

B
```

Output:

```text
A
D
C
B
```

---

# Common Mistakes

## Mistake 1

Assuming `setTimeout(fn, 0)` runs immediately.

It doesn't.

It runs only after:

* Current execution finishes.
* All microtasks finish.

---

## Mistake 2

Thinking Promises use the Callback Queue.

Incorrect.

Promises use the **Microtask Queue**.

---

## Mistake 3

Thinking JavaScript itself provides `setTimeout`.

Incorrect.

It is provided by the **Browser** (or Node.js runtime).

---

## Mistake 4

Thinking the Event Loop executes callbacks directly.

Incorrect.

The Event Loop only moves callbacks from queues to the Call Stack.

The Call Stack executes them.

---

# Summary

* JavaScript is single-threaded.
* The Event Loop enables asynchronous programming.
* The Call Stack executes synchronous code.
* Web APIs handle asynchronous operations.
* Completed callbacks are placed into queues.
* Microtask Queue has higher priority than Callback Queue.
* The Event Loop moves tasks from queues to the Call Stack when it becomes empty.
* Promises always execute before `setTimeout` callbacks.
* Understanding the Event Loop is essential for mastering asynchronous JavaScript, Promises, `async/await`, and browser behavior.
