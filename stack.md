# Generic Stack Implementation Using Array

## 📌 Description
This is a generic Stack implementation in Java using a fixed-size array. It supports common stack operations such as push, pop, peek, isFull, isEmpty, size, and display.

The stack follows LIFO (Last In, First Out) behavior.

## ⏱️ Time and Space Complexity

| Operation   | Time Complexity | Space Complexity |
| ----------- | --------------- | ---------------- |
| `push()`    | O(1)            | O(n) (array)     |
| `pop()`     | O(1)            | O(n) (array)     |
| `peek()`    | O(1)            | O(n) (array)     |
| `isEmpty()` | O(1)            | O(1)             |
| `isFull()`  | O(1)            | O(1)             |
| `size()`    | O(1)            | O(1)             |
| `display()` | O(n)            | O(1)             |

> 🧠 Note: Array-based stack uses a fixed memory block of size capacity.

## 🧾 Code
📂 `Stack.java`
```java
public class Stack<T> {
  private Object[] stack;
  private int top;
  private int capacity;

  public Stack(int size) {
    this.capacity = size;
    this.stack = new Object[capacity];
    this.top = -1;
  }

  public void push(T value) {
    if (isFull()) throw new IllegalStateException ("stack is Full!");
    stack[++top] = value;
  }

  @SuppressWarnings("unchecked")
  public T pop() {
    if (isEmpty()) throw new IllegalStateException ("Stack is empty!");
    return (T) stack[top--];
  }

  @SuppressWarnings("unchecked")
  public T peek() {
    if (isEmpty()) throw new IllegalStateException ("Stack is empty!");
    return (T) stack[top];
  }

  public boolean isFull() {
    return this.top == this.capacity - 1;
  }

  public boolean isEmpty() {
    return this.top == -1;
  }

  public int size() {
    return this.top + 1;
  }

  public void display() {
    System.out.print("Stack(top -> bottom)");
    for (int i = top; i >= 0; i--) {
      System.out.print(stack[i] + (i == 0 ? "": " -> "));
    }
    System.out.println();
  }
}

public class Main {
  public static void main(String[] args) {
    Stack<String> stringStack = new Stack<>(5);
    stringStack.push("A");
    stringStack.push("B");
    stringStack.push("C");

    System.out.println("Top: " + stringStack.peek()); // C
    System.out.println("Popped: " + stringStack.pop()); // C

    stringStack.display(); // B -> A

    Stack<Integer> intStack = new Stack<>(3);
    intStack.push(100);
    intStack.push(200);

    intStack.display(); // 200 -> 100
  }
}
```
