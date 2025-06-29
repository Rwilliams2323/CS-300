 What was the problem you were solving in the projects for this course?
The goal was to build an advising assistant tool for ABCU's Computer Science department. The problem involved designing a program that could read course data from a file, store it efficiently, and allow advisors to access and print course information, including prerequisites, in a user-friendly way. This mimicked a real-world academic advising scenario where fast, reliable access to course data is essential.

 How did you approach the problem? Why are data structures important?
I broke the problem into logical steps: reading from the file, parsing the data, storing it using an appropriate data structure (a hash table), and then interacting with it through menu-based input. I chose a hash table because it offers fast lookups, which is perfect when advisors need to quickly find a course or validate prerequisites.

Understanding data structures was key. Without them, managing large sets of course information would be inefficient. A poor choice like a simple array or list would have made search operations much slower, especially as the number of courses grew.

 How did you overcome roadblocks?
One of my biggest roadblocks was accidentally starting the project as a C# project instead of C++, which caused dozens of errors. Once I realized the mistake, I restarted the project using the correct C++ Console App setup in Visual Studio 2019, and everything compiled as expected.

Another challenge was managing the string parsing and ensuring the program handled edge cases like empty prerequisite fields. I solved that by using istringstream and careful token checks. Also, ensuring all user inputs were valid and the file existed was something I made sure to handle gracefully with error messages.

 How has this expanded your approach to software design and development?
This project helped me think in terms of modular design and responsibility. Each function had a clear purpose: loading data, printing a course, showing the menu, etc. It pushed me to separate logic cleanly, which is something I’ll continue to carry forward into larger projects. I also now think more carefully about what data structure best fits the problem — I don’t just default to vectors or arrays anymore.

How has this changed how you write maintainable, readable, and adaptable code?
Before this course, I focused mainly on getting the program to work. Now I focus more on clean formatting, comments, and good naming conventions so someone else (or future me) can understand the code. I also think about how to make my code adaptable for changes — like what if the course file format changes? What if we want to support multiple departments?

Using a hash table, handling file input, and designing user menus all forced me to write code that’s not just functional — but also clean and expandable.
