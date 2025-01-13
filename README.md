
# Cincinnati Area Household Income Survey Application (CAHISA)

## Project Overview

The Cincinnati Area Household Income Survey Application (CAHISA), developed in C, is a two-part program designed to collect, validate, and analyze household income data for select counties in Ohio and Kentucky. It consists of:

- **Application 1:** Data collection and validation.
- **Application 2:** Data analysis and reporting.

---

## Author

- **Name:** Jack Lorenz  


---

## Features

### Application 1: Data Collection
- Collects household data including date, state, county, race, number of residents, and yearly income.
- Validates inputs to ensure data integrity.
- Appends valid records to a CSV file for later analysis.

### Application 2: Data Analysis
- Reads data from the CSV file.
- Analyzes total households, income averages, and poverty rates by:
  - County  
  - Race  
  - State  
- Calculates average income and identifies households below the poverty line.
- Presents data in an interactive menu-driven format.

---

## Table of Contents
1. [Abstract](#abstract)  
2. [Prerequisites](#prerequisites)  
3. [Setup Instructions](#setup-instructions)  
4. [Data Collection (Application 1)](#data-collection-application-1)  
5. [Data Analysis (Application 2)](#data-analysis-application-2)  
6. [Functions and Logic](#functions-and-logic)  
7. [License](#license)  

---

## Abstract

This project serves as a capstone for a C programming course, showcasing skills in structured programming, file I/O, and modular design. The two-part application facilitates household income data collection and comprehensive analysis.

---

## Prerequisites

- A C compiler (e.g., GCC).
- Familiarity with the command-line interface.
- A basic understanding of CSV file structures.

---

## Setup Instructions

1. **Compilation:** Compile each application separately using a C compiler. Example:
   ```bash
   gcc -o Application1 FinalApplication1.c
   gcc -o Application2 CFinalProjectApplication2JL.c
   ```

2. **Execution:** Run the compiled executables in order:
   ```bash
   ./Application1
   ./Application2
   ```

3. **Input File:** Ensure the CSV file (`data.csv`) exists in the same directory. Application 1 will create this file if it does not already exist.

---

## Data Collection (Application 1)

### Workflow
Prompts user for:
- **Date:** YYYY-MM-DD  
- **State:** Ohio or Kentucky  
- **County:** Hamilton, Butler, Boone, or Kenton  
- **Race:** Caucasian, African American, Hispanic, Asian, Other  
- **Number of residents**  
- **Yearly income**  

Validates each input using dedicated functions. Appends valid records to `data.csv`.

### Key Functions
- **ValidateDate:** Ensures the date is in YYYY-MM-DD format.
- **ValidateState:** Checks for valid state entries.
- **ValidateCounty:** Confirms the county matches the state.
- **ValidateRace:** Verifies race against predefined categories.
- **ValidateNumber:** Ensures number of residents is greater than 0.
- **ValidateIncome:** Confirms income is greater than 0.
- **AppendToFile:** Writes validated data to `data.csv`.

---

## Data Analysis (Application 2)

### Workflow
- Reads household data from `data.csv`.
- Provides an interactive menu with options to:
  - Display total households surveyed.
  - Analyze totals by county and race.
  - Calculate average income.
  - Show poverty rates by county, race, and state.

### Key Functions
- **ReadCSV:** Reads records from `data.csv`.
- **TotalHouseholds:** Displays the total number of households.
- **TotalByCounty:** Counts households per county.
- **TotalByRace:** Counts households per race.
- **CalculateAverageIncome:** Computes average income for all households.
- **IsBelowPoverty:** Determines if a household falls below the poverty line.
- **DisplayPercentageBelowPoverty:** Shows the percentage of households below poverty.

---

## Functions and Logic

### Input Validation
- Ensures all data is accurate before appending to the file.
- Prevents invalid entries using robust checks.

### Data Analysis
- Provides insights into income distribution and poverty levels.
- Enables exploration of trends by demographic and geographic categories.

---

## License

This project is for educational purposes only and is not intended for real-world deployment.
