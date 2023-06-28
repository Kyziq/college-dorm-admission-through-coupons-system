# College Dorm Admission through Coupons (CDAC) System
> **Note:** This project is part of CSC404 Programming II

The CDAC system is an application developed to manage the distribution and accumulation of activity-based coupons in a college setting. Students can earn coupons by participating in university activities. Accumulating a certain number of these coupons qualifies them for college dorm admission.

## Problem Statement

1. Existing paper-based method is error-prone and inefficient.
2. Difficulty in tracking and validating the number of coupons collected by each student.
3. Lack of an efficient system to verify student eligibility for dorm admission based on coupon count.

## Objectives

1. To develop a digital system to efficiently track coupon collection, replacing the existing paper-based method.
2. To validate the authenticity of the coupons based on the activities a student has participated in.
3. To automate eligibility checks for dorm admission based on the number of coupons a student has accumulated.

## Project Structure

```plaintext
CDAC-System
│
└───src
│   │   main.cpp
│
└───data
│   │   students.txt
│   │   activities.txt
```
## Coding

The CDAC system employs various concepts of C++ programming:

1. **Input/output file concepts:** The application reads from a .txt file that contains the records of students, each entry representing a student with their ID, name, and the number of coupons they've collected.
2. **Vector concepts:** Vectors are used to dynamically manage an array of Student objects.
3. **Pointer concepts:** Pointers are used to handle Student objects when updating their coupon count.
4. **Function concepts:** Functions are utilized for tasks like loading students from a file, saving students to a file, finding a student by their ID, and displaying the menu.
5. **File handling concepts:** Student data is saved and loaded using text files, facilitating persistent data between different runs of the application.

## Sample Outputs

1. Display of all student data including name, ID, and coupon count.
2. Verification of a student's eligibility for dorm admission based on their coupon count.

For more information, please check the code files in the `src` and `include` directories, and the data in the `data` directory.

## Structs

- `Student`: This class represents students, with attributes for Name, ID, and Coupon count.
- `Activity`: This class represents university activities, with attributes for Name and ID
