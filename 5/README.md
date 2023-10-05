# Algorithm
```
1. START

2. Declare function isEmpty()

3. If top == -1: Return true

4. Else: return false

5. End if. End Func

6. Declare function isFull()

7. If top ==  size - 1: Return true

8. Else: return false

9. End if. End Func

10. Declare push(item)

11. If isFull(): throw Overflow Error

12. Increment top

13. SET arr[top] = item

14. End Func

15. Declare pop()

16. If isEmpty(): throw Underflow Error

17. decrement top

18. Return arr[top + 1]

19. End Func

20. Declare peek()

21. If isEmpty(): throw StackEmpty Error

22. Return arr[top ]

23. End Func

24. STOP
```

# Output

```
Enter size of the stack: 4
---------- Stack Operations ----------
1. Push.
2. Pop.
3. Peek.
4. Display.
5. Exit.
Enter choice: 1
Enter element to push: 2
---------- Stack Operations ----------
1. Push.
2. Pop.
3. Peek.
4. Display.
5. Exit.
Enter choice: 1
Enter element to push: 3
---------- Stack Operations ----------
1. Push.
2. Pop.
3. Peek.
4. Display.
5. Exit.
Enter choice: 1
Enter element to push: 1
---------- Stack Operations ----------
1. Push.
2. Pop.
3. Peek.
4. Display.
5. Exit.
Enter choice: 4

1 <-- Top
3
2
Size = 4


---------- Stack Operations ----------
1. Push.
2. Pop.
3. Peek.
4. Display.
5. Exit.
Enter choice: 2

Popped element: 1

---------- Stack Operations ----------
1. Push.
2. Pop.
3. Peek.
4. Display.
5. Exit.
Enter choice: 3

Top element: 3

---------- Stack Operations ----------
1. Push.
2. Pop.
3. Peek.
4. Display.
5. Exit.
Enter choice: 5
Exiting...

------ Author ------
Ali Izzath Shazin K
220071601028
B.Tech CSE A
```