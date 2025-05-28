# Generic Circular Queue Implementation Using Array

## 📌 Description
This Java code provides a generic circular queue implementation using an array. It supports basic operations like enqueue, dequeue, peek, isEmpty, isFull, size, and display.

## ⏱️ Time and Space Complexity

| Operation   | Time Complexity | Space Complexity |
| ----------- | --------------- | ---------------- |
| `enqueue()` | O(1)            | O(n) (array)     |
| `dequeue()` | O(1)            | O(n) (array)     |
| `peek()`    | O(1)            | O(n) (array)     |
| `isEmpty()` | O(1)            | O(1)             |
| `isFull()`  | O(1)            | O(1)             |
| `size()`    | O(1)            | O(1)             |
| `display()` | O(n)            | O(1)             |

## 🧾 Code
```java
public class Queue<T> {

  private Object[] queue;
  private int size;
  private int capacity;

  private int front;
  private int rear;

  @SuppressWarnings("unchecked")
  public Queue(int capacity) {
    this.capacity = capacity;
    this.queue = (T[]) new Object[capacity];

    this.size = 0;

    this.front = 0;
    this.rear = -1;
  }

  public void enqueue(T value) {
    if (isFull()) throw new IllegalStateException("Queue is full!");
    rear = (rear + 1) % capacity;
    queue[rear] = value;
    size++;
  }

  public T dequeue() {
    if (isEmpty()) throw new IllegalStateException("Queue is empty!");

    T value = (T) queue[front];
    front = (front + 1) % capacity;
    size--;
    return value;
  }

  public T peek() {
    if (isEmpty()) throw new IllegalStateException("Queue is empty!");
    return (T) queue[front];
  }


  public boolean isEmpty() {
    return size == 0;
  }

  public boolean isFull() {
    return size == capacity;
  }

  public int size() {
    return size;
  }

  public void display() {
    System.out.print("Queue(front -> rear): ");
    for (int i = 0; i < size; i++) {
      int index = (i + front) % capacity;
      System.out.print(queue[index] + (i == size - 1 ? "" : " -> "));
    }
    System.out.println();
  }
}

public class Main {
  public static void main(String[] args) {
    Queue<String> stringQueue = new Queue<>(5);
    stringQueue.enqueue("Apple");
    stringQueue.enqueue("Banana");
    stringQueue.enqueue("Cherry");

    stringQueue.display(); // Apple -> Banana -> Cherry

    System.out.println("Peek: " + stringQueue.peek()); // Apple
    System.out.println("Dequeued: " + stringQueue.dequeue()); // Apple

    stringQueue.display(); // Banana -> Cherry

    Queue<Integer> intQueue = new Queue<>(3);
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    intQueue.display(); // 10 -> 20 -> 30
  }
}
```
