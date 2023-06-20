/* The purpose of this program is to calculate the average of student grades and output them in a text file. In this part the user has control to input
the number of students between 1 and 100 plus, the number of grades between 1 and 8. Moreover, the ability to choose the text file. Firstly, Command Line is prompted
at the start of the program to input data in the following format: nStudent nGrades File name. After the data is recorded in to an array then split to IDs and grades
then calculations are done. If a -1 number is found it indicates that the grade has not been recorded and should be ignored in the averaging */

// Add libraries that is going to be used through out the program
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main( int argc, char **argv ) {

  // Variables used for user input from the command line argument
  int nStudents = 0;
  int nGrades = 0;


  /* command line arguments */
  // Check if the user input has entered more or less than the 4 arguments
  if (argc != 4) {
    printf("Incorrect arguments given. Expecting nStudents nGrades fileName. Exiting.\n"); // Return 4 suggesting the problem is with the entire argument
    return 4;
  }
  // Check if the number of students is out of range
  if (atoi(argv[1]) < 0 && atoi(argv[1]) > 100) {
    printf("Requires 1 to 100 students. Exiting.\n"); // Print statement to inform number of student is out of range
    return 1; // Return 1 Suggesting the first argument Number of student is out of range
  }
  else if (atoi(argv[1]) > 0 && atoi(argv[1]) <= 100) {
    nStudents = atoi(argv[1]); // Set the number of students since the number is in range
  }

  if (atoi(argv[2]) < 1 && atoi(argv[2]) > 8) {
    printf("Requires 1 to 8 grades. Exiting.\n"); // Print statement to inform grades is out of range
    return 2; // Return 1 Suggesting the first argument number of grades is out of range
  }
  else if (atoi(argv[2]) > 0 && atoi(argv[2]) <= 100) {
    nGrades = atoi(argv[2]); // Set the number of grades since the number is in range
  }


  /* Start assigning Variables */
  int row = nStudents - 1; // Set the number of rows based on the number of students, subtracting 1 for the index to start from zero.
  int col = nGrades + 1; // Set the number of columns based on the number of grades, adding 1 for the student id.
  /* Used to check if both the student id and grade is in range used to output an error in the id or grade */
  int id = 0;
  int grade = 0;
  // 2D array used to store all data from the .txt file. Data id stored in this format [Row][Col] For all 2D array variables.
  int **student_data = malloc(sizeof(int *) * row * col); // Allocate row
  for (int i = 0; i < row; i++) {
      student_data[i] = malloc(sizeof(int *) * col); // Allocate column
  }
  // 2D array used to store number of grades from the student_data array mainly used for printing errors.
  int **grades = malloc(sizeof(int *) * row * col); // Allocate row
  for (int i = 0; i < row; i++) {
      grades[i] = malloc(sizeof(int *) * col - 1); // Allocate column
  }
  // 2D array used to store student id in the first column and the average of the grades in the second column before writing to the text file.
  int **grade_average = malloc(sizeof(int *) * row * col); // Allocate row
  for (int i = 0; i < row; i++) {
      grade_average[i] = malloc(sizeof(int *) * col - 1); // Allocate column
  }


  // reading from file
  printf("Input file. Opening.\n");
  // Access the grades text file
  FILE *fp; // Assign fp which is the file pointer
  fp = fopen(argv[3], "r"); // Open file using the input from the user and set the mode to read

  // If the file does not exist
  if (fp == NULL){
      printf("Input file does not exist. Exiting.\n"); // Print error indicating the file does not exist
      return 3; // return 3 indicating the third argument of the file name has an error
  }

  /* Loops done for the entire program loops over the column and row in a nested for loop were the format of the 2D arrays are set to be
  [Row] which is i [Col (Column)] which is j. To assign the variable id: student_data[i][0] the column is set to zero through out the program */

  // Save data from file
  for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
          fscanf(fp, "%d", &student_data[i][j]); // Read text file and store in the 2D array
      }
  }


  // Close file using the file pointer after is has been used
  fclose(fp);


  // Store grades and student IDs
  for (int i = 0; i < row; i++) {
      for (int j = 1; j < col; j++) {
          grades[i][j-1] = student_data[i][j]; // Store grades stored from the student data
      }
  }

  // data processing
  printf("Checking data.\n");

  // Check Student ID
  for (int i = 0; i < row; i++){
      id = student_data[i][0]; // Set the variable id from the array
      // Check if student ID is in range
      if (id < 2022000 || id > 2022099) {
          printf("Found an invalid student id: %d. Exiting.\n",id); // Print an error indicating the student Id is out of range using id variable
          return 1;
      }
  }

  // Check Grades
  for (int i = 0; i < row; i++) {
      for (int j = 0; j < col - 1; j++) {
          id = student_data[i][0]; // Set the variable id from the array
          // Check if student ID is out of range
          if (grades[i][j] < -1 || grades[i][j] > 100) {
              grade = grades[i][j];
              printf("Found an invalid grade: id %d grade %d. Exiting.\n", id,grade ); // Print an error indicating that a grade is faulty use the id and grade variable
              return 1;
          }
      }
  }

  // Correcting Grades if below 20 or over 90
  for (int i = 0; i < row; i++) {
      for (int j = 0; j < col - 1; j++) {
          id = student_data[i][0];
          // Check if grade is less than 20
          if (grades[i][j] < 20 && grades[i][j] > -1) {
              grade = grades[i][j]; // Assign grade variable from the grades array for printing
              printf("Correcting student %d grade %d\n",id,grade); // Print out the grade that needs to be corrected to 20 using the id and grade variables
              grades[i][j] = 20; // Correct the grade to 20
          }
          // Check if grade is more than 90
          else if (grades[i][j] > 90){
              grade = grades[i][j]; // Assign grade variable from the grades array for printing
              printf("Correcting student %d grade %d\n",id,grade); // Print out the grade that needs to be corrected to 90 using the id and grade variables
              grades[i][j] = 90; // Correct the grade to 90
          }
      }
  }

  // calculate average
  printf("Computing averages.\n");

  // Get average of student grade
  // Loop each row to gather the student id and the grades
  for (int i = 0; i < row; i++) {
    float sum_grade = 0; // Used to add grades per student. Stored as a float for rounding
    float divisor = 0; // Used to create a divisor based on available grades/ Stored as float to divide by the grades
    // Loop over the column to gather grades of the number of grades
    for (int j = 0; j < col - 1; j++) {
        // Check if the grade is available hence grade must be bigger than -1
        if (grades[i][j] > -1) {
        divisor = divisor + 1.0; // Add 1 to divisor id the grade is available
        sum_grade = sum_grade + grades[i][j]; // Add the grades
        }
    }
    grade_average[i][0] = student_data[i][0]; // Assign student ID
    // Check if there is no grades at all to store the grade as zero since this number cannot be a divisor
    if (divisor == 0){
    grade_average[i][1] = 0; // Store the average as zero
    }
    // If a divisor is found get the average
    else if (divisor > 0) {
    grade_average[i][1] = roundf(sum_grade / divisor); // Divide the sum of grades of each student by the corresponding divisor
    }
  }


  /* Used to free student_data and grades from it's allocated memory.
  A for loop is used since both variables are 2D arrays */
  for (int i = 0; i < row; i++){
    free(student_data[i]);
  }
  for (int i = 0; i < row; i++){
    free(grades[i]);
  }


  // writing to file
  printf("Output file. Opening.\n");
  FILE *avg; // create a file pointer
  avg = fopen("averages.txt", "w"); // Open file averages.txt and set the mode for write
  // Loop over the row or the amount of students
  for (int i = 0; i < row; i++) {
      // Write to file
      fprintf(avg, " %d %d\n", grade_average[i][0], grade_average[i][1]); // fprintf is used to write to the file.
  }


  // Used to free grade average from allocated memory
  for (int i = 0; i < row; i++){
    free(grade_average[i]);
  }


  printf("Output file. Closing.\n");
  fclose(avg); // Close File using the avg pointer
  return 0; // Close program successfully
}
