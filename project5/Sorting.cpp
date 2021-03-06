#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std::chrono;
using std::cout;
using std::endl;


//selection sort algorithmn
void selectionSort(int a[], size_t size){

for (size_t i = 0; i < size; i++){

for (size_t j = i + 1; j < size; j++){

if (a[i] > a[j]){

int temp = a[i];

a[i] = a[j];

a[j] = temp;

}

}

}

}


//insertion sort
void insertionSort(int a[], size_t size){

int i, current, j;

for (i = 1; i < size; i++){

current = a[i];

j = i - 1;

while (j >= 0 && a[j] > current){

a[j + 1] = a[j];

j = j - 1;

}

a[j + 1] = current;

}

}


//merge helper function
void merge(int a[], int l, int m, int r){

int i, j, k;

int n1 = m - l + 1;

int n2 = r - m;

int *L = new int[n1];

int *R = new int[n2];

for (i = 0; i < n1; i++)

L[i] = a[l + i];

for (j = 0; j < n2; j++)

R[j] = a[m + 1 + j];

i = 0;

j = 0;

k = l;

while (i < n1 && j < n2){

if (L[i] <= R[j])

{

a[k] = L[i];

i++;

}

else{

a[k] = R[j];

j++;

}

k++;

}

while (i < n1){

a[k] = L[i];

i++;

k++;

}

while (j < n2){

a[k] = R[j];

j++;

k++;

}

}


//mergesort function
void mergeSort(int a[], int from, int to){

if (from < to){

int m = from + (to - from) / 2;

mergeSort(a, from, m);

mergeSort(a, m + 1, to);

merge(a, from, m, to);

}

}


//generate a random array
void generateRandomArray(int values[], size_t size){

for (size_t i = 0; i < size; i++){

values[i] = rand() % size;

}
//printArray(values, size)

}


//generate an array with ascending array
void generateAscendingArray(int values[], size_t size){
int counter;
for(int i = 0; i < size; i++){

for(int j =0; j < size-i-1;j++){

if(values[j] > values[j+1]){

counter=values[j+1];

values[j+1]=values[j];

values[j]=counter;

}

}

}

}


//gemerate descending array
void generateDescendingArray(int values[], size_t size){

int current;

for(int i = 0; i < size; i++){

for(int j =0; j < size-i-1;j++){

if(values[j] < values[j+1]){

current=values[j+1];

values[j+1]=values[j];

values[j]=current;

}
}

}

}


//last ten elements are random
void generateLastTenRandomArray(int values[], size_t size){

int current;

srand(time(NULL));

generateAscendingArray(values,size);

for(int i = size-1; i>=size-10; i--){

current = rand()%size+1;

values[i]=current;

}

}


void generateFewRandomArray(int values[], size_t size){

int current;

srand(time(NULL));

for(int i = 0; i < size;i++){

current = rand()%size+1;

values[i]=current;

}

}


double sortTest(void (*sortingFunction)(int a[], size_t size), int values[],size_t size){
int *arr = new int[size];
int runtime_sum=0;

for (int i=0; i<10; i++){
for (int j=0; j<size; j++){
arr[j]=values[j];
}
auto start = high_resolution_clock().now();
//cout<<start;
sortingFunction(arr, size);
auto end=high_resolution_clock().now();
duration<float, std::micro> runt_time = duration_cast<microseconds>(end-start);
runtime_sum += runt_time.count();
}
double average=runtime_sum/10.0;
return average;
}


double mergeSortTest(int values[], size_t size) {
int *arr = new int[size];
int runtime_sum=0;

for (int i=0; i<10; i++){
for (int j=0; j<size; j++){
arr[j]=values[j];
}
auto start = high_resolution_clock().now();
mergeSort(arr, 0, size-1);
auto end=high_resolution_clock().now();
duration<float, std::micro> runt_time = duration_cast<microseconds>(end-start);
runtime_sum += runt_time.count();
}
double average=runtime_sum/10.0;
return average;
}







int main() {
const size_t SMALL_ARRAY_SIZE = 100;
const size_t MEDIUM_ARRAY_SIZE = 1000;
const size_t LARGE_ARRAY_SIZE = 10000;
const size_t HUGE_ARRAY_SIZE = 100000;
  
int values[HUGE_ARRAY_SIZE];
  
//*** FIRST TEST RANDOM VALUES ON SMALL_ARRAY_SIZE ***/
generateRandomArray(values, LARGE_ARRAY_SIZE);
cout << "Elapsed time for selection sort averaged over 10 runs on array of size " << LARGE_ARRAY_SIZE << " is: " << sortTest(&selectionSort, values, LARGE_ARRAY_SIZE)<< " microseconds" << endl;


generateRandomArray(values, SMALL_ARRAY_SIZE);
cout << "Elapsed time for insertion sort averaged over 10 runs on array of size " <<SMALL_ARRAY_SIZE << " is: " << sortTest(&insertionSort, values, SMALL_ARRAY_SIZE)<< " microseconds" << endl;
  
generateRandomArray(values, SMALL_ARRAY_SIZE);
cout << "Elapsed time for merge sort averaged over 10 runs on array of size " << SMALL_ARRAY_SIZE << " is: " << mergeSortTest(values, SMALL_ARRAY_SIZE)<< " microseconds" << endl;
 
generateAscendingArray(values, SMALL_ARRAY_SIZE);
cout << "Elapsed time for selection sort averaged over 10 runs on array of size " << SMALL_ARRAY_SIZE << " is: " << sortTest(&selectionSort, values, SMALL_ARRAY_SIZE)<< " microseconds" << endl;
  
generateAscendingArray(values, SMALL_ARRAY_SIZE);
cout << "Elapsed time for insertion sort averaged over 10 runs on array of size " << SMALL_ARRAY_SIZE << " is: " << sortTest(&insertionSort, values, SMALL_ARRAY_SIZE)<< " microseconds" << endl;
  
generateAscendingArray(values, SMALL_ARRAY_SIZE);
cout << "Elapsed time for merge sort averaged over 10 runs on array of size " << SMALL_ARRAY_SIZE << " is: " << mergeSortTest(values, SMALL_ARRAY_SIZE)<< " microseconds" << endl;




generateRandomArray(values, LARGE_ARRAY_SIZE);
cout << "Elapsed time for selection sort averaged over 10 runs on array of size " << LARGE_ARRAY_SIZE << " is: " << sortTest(&selectionSort, values, LARGE_ARRAY_SIZE)<< " microseconds" << endl;


generateRandomArray(values, LARGE_ARRAY_SIZE);
cout << "Elapsed time for insertion sort averaged over 10 runs on array of size " << LARGE_ARRAY_SIZE << " is: " << sortTest(&insertionSort, values,  LARGE_ARRAY_SIZE)<< " microseconds" << endl;
  
generateRandomArray(values,  LARGE_ARRAY_SIZE);
cout << "Elapsed time for merge sort averaged over 10 runs on array of size " <<  LARGE_ARRAY_SIZE << " is: " << mergeSortTest(values, LARGE_ARRAY_SIZE)<< " microseconds" << endl;
 
 
 
 
generateAscendingArray(values, MEDIUM_ARRAY_SIZE);
cout << "Elapsed time for selection sort averaged over 10 runs on array of size " << MEDIUM_ARRAY_SIZE << " is: " << sortTest(&selectionSort, values, MEDIUM_ARRAY_SIZE)<< " microseconds" << endl;
  
generateAscendingArray(values, MEDIUM_ARRAY_SIZE);
cout << "Elapsed time for insertion sort averaged over 10 runs on array of size " << MEDIUM_ARRAY_SIZE << " is: " << sortTest(&insertionSort, values, MEDIUM_ARRAY_SIZE)<< " microseconds" << endl;
  
generateAscendingArray(values, MEDIUM_ARRAY_SIZE);
cout << "Elapsed time for merge sort averaged over 10 runs on array of size " << MEDIUM_ARRAY_SIZE << " is: " << mergeSortTest(values, MEDIUM_ARRAY_SIZE)<< " microseconds" << endl;

return 0;
}
