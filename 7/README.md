# Aim
```
To implement Singly Linked List with Insertion, Deletion and Display Operations.
```


# Algorithm
```

1. START

2. FUNC CreateNode(item):

3. DECLARE node* with malloc()

4. SET node.value = item, node.next = NULL

5. RETURN node. END FUNC

6. FUNC LinkedList(): // constructor

7. SET this.Head = NULL, this._length = 0

8. END FUNC

9. FUNC Insert_Start(node): // Insertion at the beginning

10. SET node.next = this.Head, this.Head = node

11. INCREMENT this._length. END FUNC

12. FUNC Insert_End(node): // Insertion at the end

13. SET lastNode.next = node

14. INCREMENT this._length. END FUNC

15. FUNC Insert_Middle(node): // Insertion at the middle

16. SET node.next = prevNode.next, prevNode.next = node

17. INCREMENT this._length. END FUNC

18. FUNC Delete(index): 

19. IF index == 0:

20. DECLARE temp = this.Head, deletedItem = this.Head.value

21. SET this.Head = this.Head.next

22. DECREMENT this._length, free(temp), RETURN deletedItem

23. END IF

24. DECLARE temp = this.Head.next, prevValue = this.Head

25. FOR (i=1 to i<index):

26. SET prevValue = temp, temp = temp.next

27. END FOR

28. DECLARE deletedItem = temp.value

29. SET prevValue.next = temp.next, free(temp)

30. DECREMENT this._length, RETURN deletedItem. END FUNC

31. FUNC Display(): // Singly Linked List Traversal

32. DECLARE node = this.Head, count = 0

33. Print “[“

34. WHILE (node != NULL):

35. Print node.value

36. SET node = node.next

37. IF count != this._length - 1:

38. Print “]”. END IF

39. INCREMENT count. END WHILE

40. Print “]”. END FUNC

41. STOP
```

# Output

```
---- Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Exit
Enter Choice: 1
Enter item to insert : 10
Enter index to insert to : 0

---- Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Exit
Enter Choice: 1
Enter item to insert : 20
Enter index to insert to : 1

---- Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Exit
Enter Choice: 1
Enter item to insert : 30
Enter index to insert to : 1

---- Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Exit
Enter Choice: 2
Enter index to delete : 0
Deleted Item: 10
---- Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Exit
Enter Choice: 3
[30, 20]
---- Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Exit
Enter Choice: 4

--------- Author ----------------
Ali Izzath Shazin
220071601028
B. Tech CSE A
```
