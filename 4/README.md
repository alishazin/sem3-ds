# Algorithm
```
1. START

2. For storing matrix as pointer to pointer variable.

3. Firstly, initialize a pointer to pointer, and assign it with a pointer array of row size.

4. Loop through the pointer array and create array of column size in each index.

5. For addition and subtraction.

6. Declare two for loops. One traversing from i=0 to i=row size. Second one traversing from j=0 to j = col size.

7. Create a third zero matrix and assign the sum to each indices.

8. Finally, return the third matrix.

9. For multiplication of matrix.

10. Declare three for loops, One traversing from i=0 to i=row size of mat1. Second from j=0 to j=col size of mat2. Third one traversing from k=0 to k=col size of mat1 or row size of mat2
11. Then inside all three loops, mat3[i][j] += mat1[i][k] * mat2[k][j];

12. STOP
```

# Output

```
Enter matrix 1 rows and columns: 2 2
Enter matrix 1 elements:
Enter element (1, 1): 1
Enter element (1, 2): 2
Enter element (2, 1): 3
Enter element (2, 2): 4
1       2
3       4
(2, 2)

Enter matrix 2 rows and columns: 2 2
Enter matrix 2 elements:
Enter element (1, 1): 1
Enter element (1, 2): 2
Enter element (2, 1): 3
Enter element (2, 2): 4
1       2
3       4
(2, 2)

Matrix 1 + matrix 2
2       4
6       8
(2, 2)

Matrix 1 - matrix 2
0       0
0       0
(2, 2)

Matrix 1 * matrix 2
7       10
15      22
(2, 2)

--------- Author ----------------
Ali Izzath Shazin
220071601028
B. Tech CSE A
```
