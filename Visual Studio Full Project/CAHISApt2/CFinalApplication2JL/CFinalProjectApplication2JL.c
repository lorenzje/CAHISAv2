// ------------------------------------------------------------------------------------------
// Name: Jack Lorenz
// Class: C Programming
// Abstract: CFinalProject (Application 2)
// ------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS



// ------------------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------------------
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>



// ------------------------------------------------------------------------------------------
// User Defined Types (UDTs)
// ------------------------------------------------------------------------------------------
typedef struct 
{
    char chrDate[11];   // Date format: YYYY-MM-DD
    char chrState[10];  // "Ohio" or "Kentucky"
    char chrCounty[10]; // "Hamilton", "Butler", "Boone", or "Kenton"
    char chrRace[50];   // Race description
    int intResidents;  // Number of Residents
    double dblYearlyIncome;   // Household income
} udtSurveyRecord;



typedef enum 
{
    Caucasian,
    African_American,
    Hispanic,
    Asian,
    Other,
    NUM_RACES 
} udtRaceIndex;



typedef struct 
{
    char chrCounty[10];
    char chrState[10];
    int intBelowPoverty;
    int intTotalCount;
} udtCountyStatePoverty;


// ------------------------------------------------------------------------------------------
// Global Variables
// ------------------------------------------------------------------------------------------
int intRaceCounts[NUM_RACES] = { 0 };
int intCount = 0;


// ------------------------------------------------------------------------------------------
// Constants
// ------------------------------------------------------------------------------------------



// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
int ReadCSV(const char* filename, udtSurveyRecord** records);
void TotalHouseholds(int recordCount);
void TotalByCounty(udtSurveyRecord* records, int count);
void TotalByRace(udtSurveyRecord* records, int count);
void UpdateRaceCount(const char* race);
void DisplayRaceCounts();
double CalculateAverageIncome(const udtSurveyRecord records[], int count);
void DisplayAverageIncome(double averageIncome);
void AverageIncomeByStateAndCounty(udtSurveyRecord* records, int count);
void AverageIncomeByRace(udtSurveyRecord* records, int count);
int IsBelowPoverty(const udtSurveyRecord* record);
void DisplayPercentageBelowPoverty(udtSurveyRecord* records, int count);
void DisplayPercentageBelowPovertyByCountyAndState(udtSurveyRecord* records, int count);
void DisplayPercentageBelowPovertyByRace(udtSurveyRecord* records, int count);
udtRaceIndex GetRaceIndex(const char* race);
const char* GetRaceName(int raceIndex);


// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
int main()
{
    udtSurveyRecord* records = NULL;
    int intRecordCount = ReadCSV("data.csv", &records);
    double dblAverageIncome = 0;
    char chrChoice;
    int intValidChoice;
    do {
        do
        {
            printf("Enter your choice (A, B, C, D, E, F, G, H, I), [-1 to Quit]: ");
            scanf(" %c", &chrChoice);

            switch (chrChoice)
            {
            case 'A':
                TotalHouseholds(intRecordCount);
                intValidChoice = 1; // Mark choice as valid
                break;
            case 'B':
                TotalByCounty(records, intRecordCount);
                intValidChoice = 1; // Mark choice as valid
                break;
            case 'C':
                TotalByRace(records, intRecordCount);
                intValidChoice = 1; // Mark choice as valid
                break;
            case 'D':
                dblAverageIncome = CalculateAverageIncome(records, intRecordCount);
                DisplayAverageIncome(dblAverageIncome);
                intValidChoice = 1; // Mark choice as valid
                break;
            case 'E':
                AverageIncomeByStateAndCounty(records, intRecordCount);
                intValidChoice = 1; // Mark choice as valid
                break;
            case 'F':  // Assuming 'F' is the designated choice for this function
                AverageIncomeByRace(records, intRecordCount);
                intValidChoice = 1;
                break;
            case 'G':  // Assuming 'G' is the designated choice for this functionality
                DisplayPercentageBelowPoverty(records, intRecordCount);
                intValidChoice = 1;
                break;
            case 'H':  // For displaying poverty percentage by county and state
                DisplayPercentageBelowPovertyByCountyAndState(records, intRecordCount);
                intValidChoice = 1;
                break;
            case 'I':  // For displaying poverty percentage by race
                DisplayPercentageBelowPovertyByRace(records, intRecordCount);
                intValidChoice = 1;
                break;
            case 'Q':  // For displaying poverty percentage by race
                intValidChoice = 1;
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                intValidChoice = 0; // Mark choice as invalid
                break;
            }
        } while (!intValidChoice); // Continue until a valid choice is made


    } while (chrChoice != 'Q');
            printf("Goodbye!\n");
    system("pause");
    free(records);
    return 0;
}



// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// AUX Processing
// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------


// Name: ReadCSV
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
int ReadCSV(const char* filename, udtSurveyRecord** records)
{
    FILE* file = fopen(filename, "r");
    if (!file)
    {
        perror("Failed to open file");
        return 0;
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file)) 
    {
        *records = realloc(*records, (intCount + 1) * sizeof(udtSurveyRecord));
        if (*records == NULL) 
        {
            perror("Failed to allocate memory");
            fclose(file);
            return -1; // indicate failure
        }
        sscanf(buffer, "%10[^,],%9[^,],%9[^,],%49[^,],%d,%lf",
            (*records)[intCount].chrDate,
            (*records)[intCount].chrState,
            (*records)[intCount].chrCounty,
            (*records)[intCount].chrRace,
            &(*records)[intCount].intResidents,
            &(*records)[intCount].dblYearlyIncome);
        intCount++;
    }
    fclose(file);
    return intCount;
}




// Name: TotalHouseholds
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
void TotalHouseholds(int recordCount) 
{
    printf("Total households surveyed: %d\n", recordCount);
}



// Name: TotalByCounty
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
void TotalByCounty(udtSurveyRecord* records, int count) 
{
    printf("Total households surveyed per county:\n");
    // Example of mapping and counting logic. Adjust accordingly.
    int intHamilton = 0;
    int intButler = 0;
    int intBoone = 0;
    int intKenton = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].chrState, "Ohio") == 0) {
            if (strcmp(records[i].chrCounty, "Hamilton") == 0) intHamilton++;
            else if (strcmp(records[i].chrCounty, "Butler") == 0) intButler++;
        }
        else if (strcmp(records[i].chrState, "Kentucky") == 0) {
            if (strcmp(records[i].chrCounty, "Boone") == 0) intBoone++;
            else if (strcmp(records[i].chrCounty, "Kenton") == 0) intKenton++;
        }
    }
    printf("Ohio, Hamilton: %d\nOhio, Butler: %d\nKentucky, Boone: %d\nKentucky, Kenton: %d\n", intHamilton, intButler, intBoone, intKenton);
}



// Name: TotalByRace
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
void TotalByRace(udtSurveyRecord* records, int count) 
{
    //Private Variables
    int intIndex = 0;
    int recordCount = ReadCSV("data.csv", &records);;


    //Update Race Count
    for (intIndex = 0; intIndex < recordCount; intIndex +=1 )
    {
        UpdateRaceCount(records[intIndex].chrRace);
    }


    DisplayRaceCounts();

}



// Name: UpdateRaceCount
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
void UpdateRaceCount(const char* race) 
{
    if (strcmp(race, "Caucasian") == 0) 
    {
        intRaceCounts[Caucasian] += 1;
    }
    else if (strcmp(race, "African American") == 0) 
    {
        intRaceCounts[African_American] += 1;
    }
    else if (strcmp(race, "Hispanic") == 0) 
    {
        intRaceCounts[Hispanic] +=1;
    }
    else if (strcmp(race, "Asian") == 0) 
    {
        intRaceCounts[Asian] += 1;
    }
    else 
    {
        intRaceCounts[Other] += 1;
    }
}



// Name: DisplayRaceCounts
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
void DisplayRaceCounts() 
{
    printf("Total Households Surveyed by Race:\n");
    printf("Caucasian: %d\n", intRaceCounts[Caucasian]);
    printf("African American: %d\n", intRaceCounts[African_American]);
    printf("Hispanic: %d\n", intRaceCounts[Hispanic]);
    printf("Asian: %d\n", intRaceCounts[Asian]);
    printf("Other: %d\n", intRaceCounts[Other]);
}



// Name: CalculateAverageIncome
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
double CalculateAverageIncome(const udtSurveyRecord records[], int count) 
{
    // Avoid division by zero
    if (count == 0) return 0.0; 
    

    // Declare Variables
    int intIndex = 0;
    double dblTotalIncome = 0;
    double dblAverageIncome = 0;

    //Main Loop
    for (intIndex = 0; intIndex < count; intIndex += 1)
    {
        dblTotalIncome += records[intIndex].dblYearlyIncome;
    }


    //Calculate Average Income
    dblAverageIncome = dblTotalIncome / count;


    return dblAverageIncome;
}




// Name: DisplayAverageIncome
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
void DisplayAverageIncome(double averageIncome) 
{
    printf("Average Household Income: $%.2f\n", averageIncome);
}



// Name: AverageIncomeByStateAndCounty
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
void AverageIncomeByStateAndCounty(udtSurveyRecord* records, int count) 
{
    if (count == 0) 
    {
        printf("No records to display.\n");
        return;
    }

    double totalIncomeOH_Hamilton = 0, totalIncomeOH_Butler = 0;
    double totalIncomeKY_Boone = 0, totalIncomeKY_Kenton = 0;
    int countOH_Hamilton = 0, countOH_Butler = 0;
    int countKY_Boone = 0, countKY_Kenton = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].chrState, "Ohio") == 0) {
            if (strcmp(records[i].chrCounty, "Hamilton") == 0) {
                totalIncomeOH_Hamilton += records[i].dblYearlyIncome;
                countOH_Hamilton++;
            }
            else if (strcmp(records[i].chrCounty, "Butler") == 0) {
                totalIncomeOH_Butler += records[i].dblYearlyIncome;
                countOH_Butler++;
            }
        }
        else if (strcmp(records[i].chrState, "Kentucky") == 0) {
            if (strcmp(records[i].chrCounty, "Boone") == 0) {
                totalIncomeKY_Boone += records[i].dblYearlyIncome;
                countKY_Boone++;
            }
            else if (strcmp(records[i].chrCounty, "Kenton") == 0) {
                totalIncomeKY_Kenton += records[i].dblYearlyIncome;
                countKY_Kenton++;
            }
        }
    }

    printf("Average Income by State and County:\n");
    if (countOH_Hamilton > 0) printf("Ohio, Hamilton: $%.2f\n", totalIncomeOH_Hamilton / countOH_Hamilton);
    if (countOH_Butler > 0) printf("Ohio, Butler: $%.2f\n", totalIncomeOH_Butler / countOH_Butler);
    if (countKY_Boone > 0) printf("Kentucky, Boone: $%.2f\n", totalIncomeKY_Boone / countKY_Boone);
    if (countKY_Kenton > 0) printf("Kentucky, Kenton: $%.2f\n", totalIncomeKY_Kenton / countKY_Kenton);
}



// Name: AverageIncomeByRace
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
void AverageIncomeByRace(udtSurveyRecord* records, int count) 
{
    double incomeSum[NUM_RACES] = { 0 };
    int raceCount[NUM_RACES] = { 0 };
    double averageIncome[NUM_RACES];

    // Accumulate sums and counts
    for (int i = 0; i < count; i++) {
        int raceIndex = -1;
        if (strcmp(records[i].chrRace, "Caucasian") == 0) raceIndex = Caucasian;
        else if (strcmp(records[i].chrRace, "African American") == 0) raceIndex = African_American;
        else if (strcmp(records[i].chrRace, "Hispanic") == 0) raceIndex = Hispanic;
        else if (strcmp(records[i].chrRace, "Asian") == 0) raceIndex = Asian;
        else raceIndex = Other;

        if (raceIndex != -1) 
        {
            incomeSum[raceIndex] += records[i].dblYearlyIncome;
            raceCount[raceIndex]++;
        }
    }

    // Calculate averages and display them
    for (int i = 0; i < NUM_RACES; i++) {
        if (raceCount[i] > 0) {
            averageIncome[i] = incomeSum[i] / raceCount[i];
        }
        else {
            averageIncome[i] = 0;  // No data for this race
        }
        printf("%s: Average Income = $%.2f\n", GetRaceName(i), averageIncome[i]);
    }
}



// Name: GetRaceName
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
const char* GetRaceName(int raceIndex) 
{
    switch (raceIndex) 
    {
    case Caucasian: return "Caucasian";
    case African_American: return "African American";
    case Hispanic: return "Hispanic";
    case Asian: return "Asian";
    default: return "Other";
    }
}



// Name: GetRaceIndex
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
udtRaceIndex GetRaceIndex(const char* race) 
{
    if (strcmp(race, "Caucasian") == 0) return Caucasian;
    if (strcmp(race, "African American") == 0) return African_American;
    if (strcmp(race, "Hispanic") == 0) return Hispanic;
    if (strcmp(race, "Asian") == 0) return Asian;
    return Other;  // Default case
}



// Name: IsBelowPoverty
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
int IsBelowPoverty(const udtSurveyRecord* record) {
    if ((record->intResidents == 1 && record->dblYearlyIncome < 12000) ||
        (record->intResidents == 2 && record->dblYearlyIncome < 18000) ||
        (record->intResidents == 3 && record->dblYearlyIncome < 25000) ||
        (record->intResidents == 4 && record->dblYearlyIncome < 30000) ||
        (record->intResidents >= 5 && record->dblYearlyIncome < 40000)) {
        return 1;
    }
    return 0;
}



// Name: DisplayPercentageBelowPoverty
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
void DisplayPercentageBelowPoverty(udtSurveyRecord* records, int count) {
    int totalBelowPoverty = 0;
    for (int i = 0; i < count; i++) {
        if (IsBelowPoverty(&records[i])) {
            totalBelowPoverty++;
        }
    }

    double percentage = ((double)totalBelowPoverty / count) * 100;
    printf("Percentage below Poverty: %.2f%%\n", percentage);
}



// Name: DisplayPercentageBelowPovertyByCountyAndState
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
void DisplayPercentageBelowPovertyByCountyAndState(udtSurveyRecord* records, int count) {
    int totalBelowPoverty = 0;
    int totalCounty = 0;



    udtCountyStatePoverty results[10]; // Increase size as needed
    int numResults = 0;
    int found = 0;

    for (int i = 0; i < count; i++) {
        found = 0;
        // Check each record in the results array
        for (int j = 0; j < numResults; j++) {
            if (strcmp(records[i].chrCounty, results[j].chrCounty) == 0 &&
                strcmp(records[i].chrState, results[j].chrState) == 0) {
                found = 1;
                results[j].intTotalCount++;
                if (IsBelowPoverty(&records[i])) {
                    results[j].intBelowPoverty++;
                }
                break;
            }
        }
        // If county and state not found, add new
        if (!found) {
            strcpy(results[numResults].chrCounty, records[i].chrCounty);
            strcpy(results[numResults].chrState, records[i].chrState);
            results[numResults].intTotalCount = 1;
            results[numResults].intBelowPoverty = IsBelowPoverty(&records[i]) ? 1 : 0;
            numResults++;
        }
    }

    // Displaying the results
    printf("Percentage below Poverty by County and State:\n");
    for (int j = 0; j < numResults; j++) {
        double percentage = ((double)results[j].intBelowPoverty / results[j].intTotalCount) * 100;
        printf("%s, %s: %.2f%%\n", results[j].chrState, results[j].chrCounty, percentage);
    }
}



// Name: DisplayPercentageBelowPovertyByRace
// Abstract: Collect data from user, validate it and append to file.
// --------------------------------------------------------------------------------
void DisplayPercentageBelowPovertyByRace(udtSurveyRecord* records, int count) {
    int racePovertyCounts[NUM_RACES] = { 0 };
    int raceTotalCounts[NUM_RACES] = { 0 };

    // Calculate counts
    for (int i = 0; i < count; i++) 
    {
        udtRaceIndex raceIndex = GetRaceIndex(records[i].chrRace);
        raceTotalCounts[raceIndex]++;
        if (IsBelowPoverty(&records[i]))
        {
            racePovertyCounts[raceIndex]++;
        }
    }

    // Display results
    printf("Percentage Below Poverty by Race:\n");
    for (int i = 0; i < NUM_RACES; i++) {
        if (raceTotalCounts[i] > 0) {  // Avoid division by zero
            double percentage = ((double)racePovertyCounts[i] / raceTotalCounts[i]) * 100.0;
            printf("%s: %.2f%%\n", GetRaceName(i), percentage);
        }
        else {
            printf("%s: No data available\n", GetRaceName(i));
        }
    }
}
