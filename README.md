# Student Database Management System
1. AIM: To Create a program that gets and stores Data about students in a file.It should also be able to do functions like Reading , 
Modifying and Deleting datas from file.
2. ALGORITHM:
+ Step 1: Start of Algorithm.
+ Step 2: Import header files.
+ Step 3: Declare line function.
+ Step 4: Declare Student Class with data variables fname,lname,course,section and functions add(), list(), modify(), delete_records().
+ Step 5: Start of definition of add() method.
+ Step 6: Declare and open the file using ofstream of mode append.
+ Step 7: Get the Student Details in store it in data variables .
+ Step 8: Print the student data inputed in the file.
+ Step 9: Close the file.
+ Step 10: End of definition of add() method.
+ Step 11: Start of definition of list() method.
+ Step 12: Declare and open the file using ifstream.
+ Step 13: Print the file using while loop.
+ Step 14: Close the file.
+ Step 15: End of definition of list() method.
+ Step 16: Start of definition of modify() method.
+ Step 17: Declare local variables str,t_name.
+ Step 18: Start of outer while loop to modify data multiple times.
+ Step 19: Get the first name of the student to be modified and store it in t_name.
+ Step 20: Open student database file with ifstream and open a new temporary file with ofstream.
+ Step 21: Get Datas from student database file and write it in temporary file other than data of 't_name' using an inner while loop.
+ Step 22: Get new data of a student and write it in temporary file when t_name data is encountered.
+ Step 23: Close the files.
+ Step 24: Remove student database file.
+ Step 25: Rename temporary file with the student database file name.
+ Step 26: Set a codition to break the loop.
+ Step 27: End of outer while loop.
+ Step 28: End of definition of modify() method.
+ Step 29: Start of definition of delete_records() method.
+ Step 30: Declare local variables str,t_name.
+ Step 31: Start of outer while loop to delete data multiple times.
+ Step 32: Get the first name of the student to be deleted and store it in t_name.
+ Step 33: Open student database file with ifstream and open a new temporary file with ofstream.
+ Step 34: Get Datas from student database file and write it in temporary file other than data of 't_name' using an inner while loop.
+ Step 35: Close the files.
+ Step 36: Remove student database file.
+ Step 37: Rename temporary file with the student database file name.
+ Step 38: Set a codition to break the loop.
+ Step 39: End of outer while loop.
+ Step 40: End of definition of delete_records() method.
+ Step 41: Start of main() function.
+ Step 42: Create an object for student class.
+ Step 43: Start a while loop to do multiple function multiple times.
+ Step 44: Display the choices. ADD RECORDS, LIST RECORDS,MODIFY RECORDS,DELETE RECORDS and EXIT.
+ Step 45: Call the methods accordingly with objects using switch case.
+ Step 46: When EXIT is selected get ratings for the software and append it in a seperate file and respond accordingly.
+ Step 47: End of algorithm.
## Project done by Briju Demel
