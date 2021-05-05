#include <iostream>
#include "maxHeap.h"

using namespace std;

int main()
{
    MaxHeap h(11);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    h.removeAt(2);
    cout << h.extractMax() << " ";
    cout << h.getMax() << endl;
	
    int a[7] = {2, 3, 4, 5, 6, 7, 1};
    MaxHeap h2(7);
    h2.heapify(a, 7);
    cout << h2.extractMax() << " ";
    cout << h2.getMax() << " " << endl;
	cout << "h:" << endl;
    h.print();
    	cout << "h2:" << endl;
    h2.print();	
    return 0;
}
