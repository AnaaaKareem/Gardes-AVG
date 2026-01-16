# Student Grades Calculator

The **Student Grades Calculator** is a C program designed to compute the average grades for a group of students and store the results in an output file. The program reads student data from an input file, validates the data against predefined constraints, calculates the average grade for each student, and writes the results in a structured format.

The program accepts three command-line arguments:

1. The number of students
2. The number of grades per student
3. The name or path of the input file

A dynamically allocated 2D array is used to store the grades, allowing the program to handle different numbers of students and grades efficiently.

---

## Input Format

The input file must contain one line per student. Each line should follow this format:

* **Student ID**: an integer between **2022000** and **2022099**
* **Grades**: integers between **0** and **100**

Example line:

```
2022001 85 90 78 88 92
```

---

## Output Format

The program generates an output file named **`output.txt`**, created in the same directory as the input file.
Each line in the output file contains:

* The student ID
* The calculated average grade

Example output:

```
2022001 86.6
```

---

## How to Compile and Run

### Compilation

Use the GCC compiler to compile the program:

```
gcc -o student_grades student_grades.c
```

### Execution

Run the program using the following command:

```
./student_grades <number_of_students> <number_of_grades> <input_file>
```

Example:

```
./student_grades 10 5 grades.txt
```

This command processes 10 students, each with 5 grades, from the file `grades.txt`.

---

## Program Features

* Dynamic memory allocation for flexible data handling
* Input validation for student IDs and grades
* Average grade calculation for each student
* File input and output handling
* Clear error handling for invalid inputs or file access issues

---

## Author and License

It is not licensed and is free to use and modify.

---
