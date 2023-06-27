# College Dorm Admission through Coupons (CDAC) System
> **Note:** This project is made for CSC404 Programming II

The CDAC system is designed to manage the distribution and accumulation of activity-based coupons in a college setting. Students earn coupons by participating in activities around the university, and once a specified number of coupons are accumulated, they qualify for college dorm admission.

## Problem Statement

1. Existing paper-based method is error-prone and inefficient.
2. Difficulty in tracking and validating the number of coupons collected by each student.
3. Lack of an efficient system to verify student eligibility for dorm admission based on coupon count.

## Objectives

1. Develop an efficient, digital system to replace paper and track coupon collection.
2. Validate coupon authenticity based on the activities participated by the students.
3. Automate eligibility checks for dorm admission based on accumulated coupon count.

## Project Structure

```plaintext
CDAC-System
│
└───src
│   │   main.cpp
│   │   student.cpp
│   │   activity.cpp
│   │   dormAdmission.cpp
│   
└───include
│   │   student.h
│   │   activity.h
│   │   dormAdmission.h
│
└───data
│   │   students.txt
│   │   activities.txt
│   │   dormAdmissionStatus.txt
```
## Coding

The program employs various concepts of C++ programming:

1. **Input/output file concepts**: The program reads a .txt file of activity records, each containing information on the activity and the associated coupon value.
2. **Pointer concepts**: Pointers are used to keep track of each Student object and their accumulated coupons.
3. **Function concepts**: Functions are utilized for calculating the total coupons a student has, checking dorm eligibility, and validating coupon authenticity.
4. **Array and Text file concepts**: An array of Student objects keeps track of all students and their respective coupon counts. Activity data and their associated coupon values are stored in a two-dimensional array and are managed using file handling operations in C++.
5. **Exception handling**: The program handles exceptions such as file not found or incorrect file format to ensure smooth operation.

Throughout the program, concepts of pointers, functions, arrays, and text files are seamlessly integrated. Additionally, the program ensures user-friendly interactivity with clear prompts and instructions.

## Sample Outputs

1. Display of all student data including name, ID, and coupon count.
2. Verification of a student's eligibility for dorm admission based on their coupon count.

For more information, please check the code files in the `src` and `include` directories, and the data in the `data` directory.

## Classes

- `Student`: This class represents students, with attributes for Name, ID, and Coupon count.
- `Activity`: This class represents university activities, with attributes for Name and ID
- `DormAdmission`: This class checks and manages dorm admission eligibility of students. It includes a `Student` and a status for Eligibility.
