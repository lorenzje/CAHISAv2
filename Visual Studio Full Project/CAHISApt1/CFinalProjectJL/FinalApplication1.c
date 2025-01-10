// ------------------------------------------------------------------------------------------
// Name: Jack Lorenz
// Class: C Programming
// Abstract: Final
// ------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

// ------------------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


// ------------------------------------------------------------------------------------------
// User Defined Types (UDTs)
// ------------------------------------------------------------------------------------------
typedef struct
{
    char chrDate[11];  // YYYY-MM-DD
    char chrState[10];
    char chrCounty[20];
    char chrRace[20];
    int intResidents;
    double dblYearlyIncome;
} udtHousehold;
// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
void CollectData(void);
bool ValidateDate(const char* date);
bool ValidateState(const char* state);
bool ValidateCounty(const char* state, const char* county);
bool ValidateRace(const char* race);
bool ValidateNumber(int num);
bool ValidateIncome(double income);
void AppendToFile(udtHousehold audtHousehold);


// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Main Function
// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
int main()
{
    CollectData();
    system("pause");
    return 0;
}
//END OF MAIN




// --------------------------------------------------------------------------------
// AUX Processing
// --------------------------------------------------------------------------------



// Name: collectData
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
void CollectData()
{
    udtHousehold audtHousehold;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%10s", audtHousehold.chrDate);
    while (!ValidateDate(audtHousehold.chrDate)) 
    {
        printf("Invalid date, please re-enter: ");
        scanf("%10s", audtHousehold.chrDate);
    }

    printf("Enter state (Ohio/Kentucky): ");
    scanf("%9s", audtHousehold.chrState);
    while (!ValidateState(audtHousehold.chrState))
    {
        printf("Invalid state, please re-enter: ");
        scanf("%9s", audtHousehold.chrState);
    }

    printf("Enter county: ");
    scanf("%19s", audtHousehold.chrCounty);
    while (!ValidateCounty(audtHousehold.chrState, audtHousehold.chrCounty)) 
    {
        printf("Invalid county for %s, please re-enter: ", audtHousehold.chrState);
        scanf("%19s", audtHousehold.chrCounty);
    }

    printf("Enter race (Caucasian, African American, Hispanic, Asian, Other): ");
    scanf("%19s", audtHousehold.chrRace);
    while (!ValidateRace(audtHousehold.chrRace)) 
    {
        printf("Invalid race, please re-enter: ");
        scanf("%19s", audtHousehold.chrRace);
    }

    printf("Enter number in household: ");
    scanf("%d", &audtHousehold.intResidents);
    while (!ValidateNumber(audtHousehold.intResidents)) {
        printf("Invalid number, must be greater than 0, please re-enter: ");
        scanf("%d", &audtHousehold.intResidents);
    }

    printf("Enter yearly income: ");
    scanf("%lf", &audtHousehold.dblYearlyIncome);
    while (!ValidateIncome(audtHousehold.dblYearlyIncome))
    {
        printf("Invalid income, must be greater than 0, please re-enter: ");
        scanf("%lf", &audtHousehold.dblYearlyIncome);
    }

    AppendToFile(audtHousehold);
}

// --------------------------------------------------------------------------------
// Name: validateDate
// Abstract: Validate the date format and range.
// --------------------------------------------------------------------------------
bool ValidateDate(const char* date)
{
    int intYear;
    int intMonth;
    int intDay;
    if (sscanf(date, "%d-%d-%d", &intYear, &intMonth , & intDay) != 3) return false;
    if (intYear < 2000 || intYear > 9999 || intMonth < 1 || intMonth > 12 || intDay < 1 || intDay > 31) return false;
    return true;
}

// --------------------------------------------------------------------------------
// Name: validateState
// Abstract: Check if the state is one of the predefined valid states.
// --------------------------------------------------------------------------------
bool ValidateState(const char* state)
{
    return (strcmp(state, "Ohio") == 0 || strcmp(state, "Kentucky") == 0);
}

// --------------------------------------------------------------------------------
// Name: validateCounty
// Abstract: Validate the county based on the state.
// --------------------------------------------------------------------------------
bool ValidateCounty(const char* state, const char* county)
{
    if (strcmp(state, "Ohio") == 0) {
        return (strcmp(county, "Hamilton") == 0 || strcmp(county, "Butler") == 0);
    }
    else if (strcmp(state, "Kentucky") == 0) {
        return (strcmp(county, "Boone") == 0 || strcmp(county, "Kenton") == 0);
    }
    return false;
}

// --------------------------------------------------------------------------------
// Name: validateRace
// Abstract: Validate if the entered race is one of the predefined categories.
// --------------------------------------------------------------------------------
bool ValidateRace(const char* race)
{
    const char* valid_races[] = { "Caucasian", "African American", "Hispanic", "Asian", "Other" };
    for (int i = 0; i < 5; i++) {
        if (strcmp(race, valid_races[i]) == 0) return true;
    }
    return false;
}

// --------------------------------------------------------------------------------
// Name: validateNumber
// Abstract: Validate if the number is greater than 0.
// --------------------------------------------------------------------------------
bool ValidateNumber(int num)
{
    return num > 0;
}

// --------------------------------------------------------------------------------
// Name: validateIncome
// Abstract: Validate if the income is greater than 0.
// --------------------------------------------------------------------------------
bool ValidateIncome(double income)
{
    return income > 0;
}

// --------------------------------------------------------------------------------
// Name: appendToFile
// Abstract: Append household data to a CSV file.
// --------------------------------------------------------------------------------
void AppendToFile(udtHousehold audtHousehold)
{
    FILE* file = fopen("data.csv", "a");
    if (file == NULL) 
    {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s,%s,%s,%s,%d,%.2f\n", audtHousehold.chrDate, audtHousehold.chrState, audtHousehold.chrCounty, audtHousehold.chrRace, audtHousehold.intResidents, audtHousehold.dblYearlyIncome);
    fclose(file);
}
