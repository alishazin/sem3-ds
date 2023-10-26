# Aim
```
To implement Doubly Linked List with Insertion, Deletion and Display Operations.
```


# Algorithm
```

1.	START

2.	FUNC CreateNode(item):

3.	DECLARE node* with malloc()

4.	SET node.value = item, node.next = NULL, node.prev = NULL

5.	RETURN node. END FUNC

6.	FUNC DoublyLinkedList(): // constructor

7.	SET this.Head = NULL, this.End = NULL, this._length = 0

8.	END FUNC

9.	FUNC Insert_Start(node): // Insertion at the beginning

10.	SET node.next = this.Head, this.Head = node

11.	IF node.next == NULL: SET this.End = node

12.	ELSE: SET node.next.prev = node, ENDIF

13.	INCREMENT this._length. END FUNC

14.	FUNC Insert_End(node): // Insertion at the end

15.	SET node.prev = this.End, this.End.next = node, this.End = node

16.	INCREMENT this._length. END FUNC

17.	FUNC Insert_Middle(node, prevNode): // Insertion at the middle

18.	SET node.next = prevNode.next, node.prev = prevNode, node.next.prev = node, prevNode.next = node

19.	INCREMENT this._length. END FUNC

20.	FUNC Delete_Start(): 

21.	DECLARE temp = this.Head, deletedItem = this.Head.value

22.	SET this.Head = this.Head.next

23.	IF this.Head == NULL: SET this.End = NULL

24.	ELSE: SET this.Head.prev = NULL, ENDIF

25.	DECREMENT this._length, free(temp)

26.	RETURN deletedItem, END FUNC

27.	FUNC Delete_End(): 

28.	DECLARE temp = this.Head, deletedItem = this.Head.value

29.	SET this.End = this.End.prev

30.	IF this.End == NULL: SET this.Head = NULL

31.	ELSE: SET this.End.next= NULL, ENDIF

32.	DECREMENT this._length, free(temp)

33.	RETURN deletedItem, END FUNC

34.	FUNC Delete_Middle(index, nodeToDelete)

35.	DECLARE deletedItem = nodeToDelete.value

36.	SET nodeToDelete.prev.next = nodeToDelete.next, nodeToDelete.next.prev = nodeToDelete.prev

37.	DECREMENT this._length, free(temp)

38.	RETURN deletedItem, END FUNC

39.	FUNC Display():

40.	DECLARE node = this.Head, count = 0

41.	Print “[“

42.	WHILE (node != NULL):

43.	Print node.value

44.	SET node = node.next

45.	IF count != this._length - 1:

46.	Print “]”. END IF

47.	INCREMENT count. END WHILE

48.	Print “]”. END FUNC

49.	FUNC DisplayReverse():

50.	DECLARE node = this.End, count = 0

51.	Print “[“

52.	WHILE (node != NULL):

53.	Print node.value

54.	SET node = node.prev

55.	IF count != this._length - 1:

56.	Print “]”. END IF

57.	INCREMENT count. END WHILE

58.	Print “]”. END FUNC

59.	STOP
```

# Output

```
---- Doubly Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Display Reverse
5. Access A Node
6. Exit
Enter Choice: 1
Enter item to insert : 10
Enter index to insert to : 0

---- Doubly Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Display Reverse
5. Access A Node
6. Exit
Enter Choice: 1
Enter item to insert : 20
Enter index to insert to : 1

---- Doubly Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Display Reverse
5. Access A Node
6. Exit
Enter Choice: 1
Enter item to insert : 30
Enter index to insert to : 1

---- Doubly Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Display Reverse
5. Access A Node
6. Exit
Enter Choice: 3
[10, 30, 20]
---- Doubly Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Display Reverse
5. Access A Node
6. Exit
Enter Choice: 4
[20, 30, 10]
---- Doubly Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Display Reverse
5. Access A Node
6. Exit
Enter Choice: 5
Enter index to access : 0
Number of nodes traversed from left: 0
Accessed Node: 10
---- Doubly Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Display Reverse
5. Access A Node
6. Exit
Enter Choice: 5
Enter index to access : 2
Number of nodes traversed from right: 0
Accessed Node: 20
---- Doubly Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Display Reverse
5. Access A Node
6. Exit
Enter Choice: 2
Enter index to delete : 1
Deleted Item: 30
---- Doubly Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Display Reverse
5. Access A Node
6. Exit
Enter Choice: 3
[10, 20]
---- Doubly Linked List Data Structure ----
1. Insert
2. Delete
3. Display
4. Display Reverse
5. Access A Node
6. Exit
Enter Choice: 6

--------- Author ----------------
Ali Izzath Shazin
220071601028
B. Tech CSE A
```
