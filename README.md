# College Dorm Admission through Coupons (CDAC) System

> **Note:** This project is part of CSC404 Programming II

The CDAC system is an application developed to manage the distribution and accumulation of activity-based coupons in a college setting. Students can earn coupons by participating in university activities. Accumulating a certain number of these coupons qualifies them for college dorm admission.

## Problem Statement

1. Current manual tracking of activity-based coupons is error-prone and inefficient.
2. Determining dorm eligibility based on coupon count is difficult and unreliable.
3. The absence of a centralized system for student registration and coupon allocation causes operational delays.

## Objectives

1. To develop the CDAC system for efficient and accurate digital management of activity-based coupons, helping minimize errors and reduce processing time.
2. To enable real-time student registration, coupon updates, and dorm eligibility checks through the CDAC system.
3. To create a reliable system for transparent student data handling and easy data visualization.

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
│   │   participations.txt
```

## Coding

The CDAC system employs various concepts of C++ programming:

1. FUNCTION CONCEPT
2. POINTER CONCEPT
3. STRUCT CONCEPT
4. TEXT FILES CONCEPT
5. INPUT OUTPUT FILES CONCEPT
6. ONE DIMENSIONAL AND TWO-DIMENSIONAL ARRAY CONCEPTS
7. CALCULATION
8. EXCEPTION HANDLING (ERROR HANDLING)

## Sample Outputs

1. Display of one or all student data including name, ID, and coupon count.
2. Display all current activites, including name and ID.
3. Display the activities that a student joins.
4. Verification of a student's eligibility for dorm admission based on their coupon count.

For more information, please check the code files in the `src` directory, and the data in the `data` directory.

## Structs

-   `Student`: This class represents students, with attributes for Name, ID, and Coupon count.
-   `Activity`: This class represents university activities, with attributes for Name and ID
