* ## Steps to execute this code

1-Make sure you have a C++ development environment set up.<br />

2-Create a text file named "Input_02.txt" with a list of words.<br />

3-Copy and paste the code into a ".cpp" file.<br />

4-Compile the code with your C++ compiler.<br />

5-Run the compiled program. <br />

6-Review the output, which will display the longest and second-longest compound words and the processing time.<br />
<br />


* ## OverView Of This Program
This C++ program reads a list of words from a file and finds:

1. The longest compound word.
2. The second-longest compound word.
3. Measures time takes to perform this task.

It does this by checking combinations of words from the list to identify compound.

* ## Design Decisions

The code makes several key design decisions:

1. **Recursive Approach**: It uses recursion to find compound words by breaking words into prefixes and suffixes, which allows it to handle multi-part compounds.

2. **Sorting**: The code sorts words by length in descending order for more efficient searching.

3. **Data Structures**: It uses a vector to store words, which offers efficient access and resizing.

4. **Standard Library Functions**: Utilizes C++ Standard Library functions (e.g., `find`, `sort`, `chrono`) for simplicity and readability.

5. **Error Handling**: Checks for successful file opening and handles errors gracefully.

6. **Execution Time Measurement**: Measures execution time using the `<chrono>` library.

7. **Iterative Approach**: After finding the longest compound word, it removes it and searches again for the second-longest, simplifying the code.

8. **Clear Output**: Provides clear and informative output, displaying the longest and second-longest compound words along with processing time.

9. **Encapsulation**: Functions are used for modularity and code organization.

10. **File Input**: Reads words from an external file for flexibility and testing with different word lists.

In summary, the code's design emphasizes readability, efficiency, and modularization, using standard libraries and effective algorithms to find compound words.


* ## Approach 
The code uses a recursive approach to find the longest and second-longest compound words in a list of words. Here's a breakdown of the key steps and approaches taken:

1. **Input Reading**:
   - The program reads a list of words from an input text file named "Input_02.txt" and stores them in a vector called `words`.

2. **Finding Compound Words**:
   - The `isCompoundWord` function checks if a given word is a compound word.
   - It does this by recursively breaking down the word into prefixes and suffixes and checking if both parts exist in the word list.
   - If a word can be divided into two valid words from the list (prefix and suffix), or if a valid prefix is followed by another compound word (recursive call), it's considered a compound word.

3. **Sorting Words by Length**:
   - The `findLongestCompoundWord` function sorts the list of words in descending order of length. This allows the program to check longer words first, improving efficiency.

4. **Iterating Over Words**:
   - The program iterates through the sorted list of words and checks if each word is a compound word using the `isCompoundWord` function.

5. **Displaying Results**:
   - The program prints the longest compound word found.
   - It then removes the longest word from the list to find the second-longest compound word.
   - The processing time for the entire operation is also measured and displayed.

In summary, this code recursively breaks down words into prefixes and suffixes and checks if they exist in the list. It uses sorting to optimize the search for compound words in descending order of length.
