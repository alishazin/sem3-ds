# Aim
```
To find consecutive letters if they appear in the given character array.
```


# Algorithm
```
1. START

2. Initialize variables i, flag (int) and text (string)

3. Traverse through the char array starting from 1st index to last.

4. Inside for loop, check if ASCII value of current character and last character are consecutive.

5. If yes, and flag is 0, print the last and current character, and set flag to 1.

6. If flag is 1, print only the current character.

7. If ASCII value of current character and last character are not consecutive, and if flag is 1.

8. Print an endline and set flag to 0.

9. STOP

```

# Output

```
Enter the text to check :AbcDhlmNquvWz
AbcD
lmN
uvW
--------- Author ----------------
Ali Izzath Shazin
220071601028
B. Tech CSE A
```
