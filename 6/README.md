# Aim
```
To implement queue data structure with Enqueue, Dequeue, Peek and Display.
```


# Algorithm
```
1. START

2. FUNC Queue(size): // Declaring queue

3. DECLARE arr by allocating required size.

4. SET rear = -1

5. SET fromt = 0

6. END FUNC

7. FUNC isEmpty():

8. IF rear = -1,return 1

9. ELSE, return 0

10. END IF, END FUNC

11. FUNC isFull():

12. IF rear = size – 1, return 1

13. ELSE, return 0

14. END IF, END FUNC

15. FUNC Enqueue(item):

16. IF isFull(), throw QueueOverflow

17. END IF

18. INCREMENT rear

19. SET arr[rear] = item

20. END FUNC

21. FUNC Dequeue(item):

22. IF isEmpty(), throw QueueUnderflow

23. END IF

24. SET popItem = arr[front]

25. INCREMENT front

26. IF front > rear

27. SET rear = -1, SET front = 0

28. END IF 

29. Return popItem, END FUNC

30. FUNC Peek():

31. IF isEmpty(), throw StackEmpty

32. ELSE, return arr[front]

33. END IF, END FUNC

34. STOP
```

# Output

```
Enter size of Queue: 3
------ Queue Data Structure ------
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter Choice: 1
Enter item to insert: 10

------ Queue Data Structure ------
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter Choice: 1
Enter item to insert: 20

------ Queue Data Structure ------
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter Choice: 4
[10, 20, _]

------ Queue Data Structure ------
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter Choice: 2
Popped Item: 10

------ Queue Data Structure ------
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter Choice: 3
Front Element: 20

------ Queue Data Structure ------
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter Choice: 5

--------- Author ----------------
Ali Izzath Shazin
220071601028
B. Tech CSE A
```
