#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

//definition of structure of heap
struct heap
{
    vector<int> array;
    //Number of elements in heap        
    int count;        
    //size of the heap
    int capacity;    
    //min heap or max heap
    string heap_type; 
};


//class containing the function for performing heap sort
class HeapFunctions
{
    public:
        //function to create a heap 
        //mainly to fill the structure of heap
        //time complexity: O(1)
        struct heap *createHeap(int capacity, string heap_type)
        {
            //assigning memory for structure of heap
            struct heap *h = (struct heap*)malloc(sizeof(struct heap));
            if(!h)
            { 
                //if memory is not assigned, print memory overflow
                cout<<"Memory overflow.."<<endl;
                return NULL;
            }

            //assign the passed capacity
            h->capacity = capacity;
            //assign the heap type passed
            h->heap_type = heap_type;
            //initially the elements in heap are 0
            h->count = 0;
            

            //return the pointer to the structure of heap
            return h;

        }
        
        //function to get the index of parent of the current element
        //time complexity: O(1)
        int parent(struct heap *h, int i)
        {
            //if the passed index i is less than 0 or greater than the elments inside the array (heap), then return -1
            if(i<=0 || i>=h->count)
                return -1;
            
            //parent is always at index (i-1)/2
            return (i-1)/2;
        }

        //function to get the left child of the heap element when index i is passed
        //time complexity: O(1)
        int leftChild(struct heap *h, int i)
        {
            int left = (2*i) + 1;
            if(left >= h->count)
                return -1;
            return left;
        }

        //function to get the right child of the heap element when index i is passed
        //time complexity: O(1)
        int rightChild(struct heap *h, int i)
        {
            int right = (2*i) + 2;
            if(right >= h->count)
                return -1;
            return right;
        }

        //function to get the maximum element of heap, if it is a max heap
        int getMaximum(struct heap *h)
        {
            //if there is no element in the heap return -1
            if(h->count == 0)
                return -1;
            //if the heap is min heap, then we cannot send the max element
            if(h->heap_type == "min")
                return -1;
            //otherwise return the first element of the array
            return h->array[0];
        }

        //function to percolate down the element i in the heap
        //basically if any element at i is not following the property of max heap, then it will be swapped with its largest child and process will repeat until it follows the property of heap
        //time complexity: O(log n)
        void percolateDown(struct heap *h, int i)
        {
            int l,r,max;
            l = leftChild(h,i);
            r = rightChild(h,i);

            if(l!=-1 && h->array[l] > h->array[i])
                max = l;
            else
                max = i;

            if(r!=-1 && h->array[r] > h->array[max])
                max = r;
            
            if(max!=i)
            {
                swap(h->array[i],h->array[max]);
            }

            percolateDown(h,max);
        }

        //function to delete the max element in the heap
        //1. check if there are elements inside heap or not
        //2. second store the max element in temp var and store the last added element in heap to root node
        //3. reduce the element size (count)
        //4. perform percolatedown operation for the root
        int deleteMax(struct heap *h)
        {
            int data;
            if(h->count == 0)
                return -1;
            
            //storing the max element
            data = h->array[0];
            //storing the last element in root node
            h->array[0] = h->array[h->count - 1];
            //reducing the count 
            h->count--;
            h->array.pop_back();
            //performing the percolate down operation
            percolateDown(h,0); 
            return data;
        }

        //function to insert a data into heap
        //time complexity: O(log n)
        int insert(struct heap *h, int data)
        {
            int i;
            h->count++;
            i = h->count -1;
            //taking the element to parent node where it follows the max heap property
            while(i>=0 && data > h->array[(i-1)/2])
            {
                h->array[i] = h->array[(i-1)/2];
                i = (i-1)/2;
            }
            h->array[i] = data;
        }

        //function to heapify a whole array
        struct heap *buildHeap(vector<int> arr)
        {
            struct heap *h = createHeap(arr.size(),"max");
            for(int i=0;i<arr.size();i++)
                h->array[i] = arr[i];
            
            h->count = arr.size();

            //leaf nodes always satisfy the heap property and do not need to care for them. The leaf elements are always at the end and to heapify the given array it should be enough if we heapify the non leaf nodes
            //the last leaf node element is at location h->count - 1
            //to find the first non leaf node it is enough to find the parent of the last element
            for(int i=(h->count-1)/2;i>=0;i--)
                percolateDown(h,i); 

            return h;  
        }

        //function to perform heap sort on an array passed
        void heapSort(vector<int> arr)
        {
            int n = arr.size();

            struct heap *h = buildHeap(arr);
            int origsize = h->count;
            for(int i=n-1;i>0; i--)
            {
                swap(h->array[0],h->array[h->count-1]);
                h->array.pop_back();
                h->count--;
                percolateDown(h,0);
            }
            h->count = origsize;
        }
};

void display(vector<int> arr)
{
    cout<<endl<<"array: ";
    for(int i: arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> arr = {2,12,4,2,4};
    display(arr);
    HeapFunctions obj;
    obj.heapSort(arr);

    display(arr);
}