// Week 4 Lab
// Test file to test the function "arrayPositiveMin".
// 
// Dan Nguyen (z5206032)
// 2018/08/14
// 
// Dean Wunder (thu11-brass)

// Returns the minimum positive value from a given array.
// A value is a positive value if it is greater than zero.
// If there are no positive values in a given list,
// the function should return zero.
int arrayPositiveMin(int a[], int size) {
    
    int placeholder, counter;
    
    placeholder = a[0];
    
    // if placeholder starts less than or equal to zero.
    counter = 0;
    while (placeholder <= 0 && counter < size) {
        placeholder = a[counter];
        counter++;
    }
    
    // finds minimum positive number.
    counter = 0;
    while (counter < size) {
        if (0 < a[counter] && a[counter] < placeholder) {
            placeholder = a[counter];
        }
        counter++;
    }
    
    // Checks if final placeholder is less than zero then all
    // elements of array is less than zero.
    counter--;
    if (placeholder <= 0) {
        placeholder = 0;
    }
    
    return placeholder;
}