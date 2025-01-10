# CAHISAv2

Product Description: Cincinnati Area Household Income Survey Application
The Cincinnati Area Household Income Survey Application, developed in C, is a two-part program designed to collect, validate, and analyze household income data for select counties in Ohio and Kentucky.

Technical Operation

Part 1: Data Collection and Validation

Input Handling: Users input survey data including date, state, county, race, household size, and annual income. The program validates each field to ensure correctness, such as checking that household size and income are numeric and greater than zero.
Validation Rules: State and county are restricted to specific values, and race is limited to predefined options (Caucasian, African American, Hispanic, Asian, Other).
Data Storage: Validated data is appended to a comma-delimited text file, preserving historical records and enabling incremental updates. File I/O functions handle reading and writing efficiently.
Part 2: Data Analysis

Data Loading: The program reads the text file and loads the data into a structured array for in-memory processing, using pointers to manage memory and optimize performance.
Query Processing: Users select predefined actions, such as calculating the total households surveyed, averages by county or race, or poverty percentages based on federal guidelines.
Output Generation: Results are processed and presented neatly on the screen, with calculations performed dynamically to reflect the most current dataset.
Design and Implementation
The program is modular, with discrete functions for input validation, file handling, data processing, and output generation. Pointers are used extensively to manage structured data, demonstrating proficiency in advanced C programming concepts. Error handling is implemented to manage invalid inputs and file access issues.

This application highlights expertise in C programming, file I/O, structured arrays, and modular design, making it a robust and practical solution for analyzing regional household income data.