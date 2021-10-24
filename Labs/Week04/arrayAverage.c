// Week 4 Lab
// Find the average of the values in a given array.
// 
// Dan Nguyen (z5206032)
// 2018/08/14
// 
// Dean Wunder (thu11-brass)

// Calculates the average of all the values in a given array,
// and returns the average value.
double arrayAverage(int a[], int size) {

    int counter = 0;
    double sum = 0;
    double avg = 0;
    
    // Calculates the sum of an array.
    while (counter < size) {
        sum += a[counter];
        counter++;
    }
    
    // Calculates the average of array.
    avg = sum / size;
    
    return avg;
}