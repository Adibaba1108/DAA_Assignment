#include <stdio.h>

int sort(int array[], int count){

    int i, j, temp;
    int swaps = 0;
    for(i = 0; i < count-1; ++i){

        for(j=0; j<count-1-i; ++j){

            if(array[j] > array[j+1]){

                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                swaps++;
            }
        }
    }

    return swaps;
}

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
   
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
        count++;
  
        heapify(arr, n, largest); 
    } 
} 
  
void heapSort(int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i=n-1; i>=0; i--) 
    { 
        swap(arr[0], arr[i]); 
        count++;
  
        heapify(arr, i, 0); 
    } 
} 

void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 

static int count=0;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
            count++;
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    count++;
    return (i + 1); 
} 
  

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

int main(void){

    int numArray[100];
    int counter;

    printf("Enter array length \n");
    scanf("%d", &counter); 

    int i;
    for (i = 0; i < counter; i++){
        printf("%d. Enter a numner: ", i);
        scanf("%d", &numArray[i]);
    }


    int totalSwaps = sort(numArray, counter);

    if (totalSwaps == 0) {
        printf("The array is already in sorted order\n");
        return 0;
    }

    printf("Swaps: %d\n", totalSwaps); 

    for (i = 0; i < counter; i++) {
        printf("Values: %d\n", numArray[i]); 
    }
    return 0;
}