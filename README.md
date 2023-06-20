Here is a possible README.md for your project:

# Student Grades Calculator

This project is a C program that calculates the average grades of a number of students and writes them to an output file. The program takes three command line arguments: the number of students, the number of grades per student, and the name or path of the input file. The input file should contain one line for each student, with the student ID (between 2022000 and 2022099) followed by the grades (between 0 and 100). The program uses a dynamically allocated 2D array to store the grades and checks for the constraints on the input data. The output file will contain one line for each student, with the student ID and the average grade.

## How to compile and run

To compile the program, use the gcc compiler with the following command:

`gcc gradeAvg.c -o program.exe -lm`

To run the program, use the following command:

`./program.exe <number_of_students> <number_of_grades> <input_file>`

For example, if you have an input file named `grades.txt` with 10 students and 5 grades per student, you can run the program as follows:

`./program.exe 10 5 grades.txt`

The program will create an output file named `output.txt` in the same directory as the input file.

## Author and license

This project was made by Karim Amr Elsayed Khater. It is not licensed and is free to use and modify.