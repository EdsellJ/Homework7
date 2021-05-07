#include "maxHeap.h"
#include <iostream>
using namespace std;

MaxHeap::MaxHeap(int cap)
{
	size = 0;
	capacity = cap;
	arr = new int[capacity];
}
int MaxHeap::parent(int i){return i/2;}
int MaxHeap::left(int i){return (2*i);}
int MaxHeap::right(int i){return ((2*i) + 1);}
int MaxHeap::getSize(){return size;}
bool MaxHeap::isLeaf(int i){
	return (i < size/2) ? false:true;
}
void MaxHeap::swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void MaxHeap::siftup(int i){
	while(i > 0 && arr[parent(i)] < arr[i]){
		swap(&arr[i], &arr[parent(i)]);
		i = parent(i);
	}
}
void MaxHeap::siftdown(int i){
	while(!isLeaf(i)){
		int l = left(i);
		int r = right(i);
		int smaller = arr[l];
		if(r < size)
			smaller = (arr[l] < arr[r])?l:r;
		if(arr[i] <= arr[smaller])
			break;
		swap(&arr[i], &arr[smaller]);
		i = smaller;
	}
}
void MaxHeap::insert(int k){
	if (size >= capacity)
		throw Overflow();
	int i = size;
	arr[i] = k;
	siftup(i);
	size++;
}

int MaxHeap::removeAt(int i) {    
	if(i < 0 || size <= i) throw Underflow();
	if(size == 1) return arr[--size];            
	int result = arr[i];    
	arr[i] = arr[--size];    
	if(arr[i] > result) siftdown(i);    
	else siftup(i);
	return result;
}

int MaxHeap::extractMax() {    
	if(size <= 0) throw Underflow();
	if(size == 1) return arr[--size];            
	int result = arr[0];    
	arr[0] = arr[--size];    
	siftdown(0);    
	return result;
}

int MaxHeap::getMax(){
	return arr[0];
}

void MaxHeap::heapify(int *array, int len)
{    
	arr = array;    
	capacity = size = len;    
	int half = size/2 - 1;	// the index of the last internal node
	for(int i = half; i >= 0; i--)        
		siftdown(i);
}

void MaxHeap::print(){
	for (int i = 1; i <= size/2; i++){
		cout << "Parent: " <<  arr[i] << " ";
		cout << "Left Child: " << arr[left(i)] << " "; 
		cout << "Right Child: " << arr[right(i)] << " ";
		cout << endl;
	}
}













