#include <stdio.h>

// Provides our main Selection Sort function
void selectionSort(double arr[], int n){
    if (n < 1)
    {
        return;
    }
    double max = arr[0];
    int max_index = 0;

    int index = 0;

    for (double *p = &arr[0]; p < &arr[n]; p++)
    {
        if (*p > max)
        {
            max = *p;
            max_index = index;
            // Assigning new max value
        }
        index++;
            // Increments Index of array through each counter
    }

    arr[max_index] = arr[n-1];
    arr[n-1] = max;

    selectionSort(arr, n-1);
    
}

// Function to find size of provided File and allocate
int fileSize(char *filename){
    double buffer[225];
    int i = 0;
    int size = 0;

    FILE *fptr = fopen(filename, "r");

    while (fscanf(fptr, "%lf,", &buffer[i++]) != EOF)
        size++;

    fclose(fptr);

    return size;
}

// Function to read file and input to array
void readFile(double arr[], char *filename){
    double *p = &arr[0];
    double buffer[225];
    int i = 0;
    int size = 0;

    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        printf("An error has occured while reading this file.");
        // Error to present if issue arrises trying to read
    }
    else
    {
        while (fscanf(fptr, "%lf,", &arr[i++]) != EOF){
        }
    }

    fclose(fptr);
}

// Function to write to file and output from array
void writeFile(double arr[], char *filename, int size){
    FILE *fp = fopen(filename, "w");
    if(fp == NULL)
        printf("An error has occured while writing this file.");
    for(double *p = &arr[0]; p < &arr[size]; p++){
        fprintf(fp, "%0.2lf,", *p);
    }
    fprintf(fp, "\n");
    fclose(fp);   
}

void main(){
    char *filename = "num.txt";
    int size = fileSize(filename);
    double arr[size];
    readFile(arr,filename);
    selectionSort(arr,size);
    char *sFile = "ascended_num.txt";
    writeToFile(arr, sFile,size);
}