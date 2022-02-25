#include <iostream>
using namespace std;

    const int size1 = 100;
    float array[size1];
    int size = 1;
	
	//Constructors of code
	int Heap_utaa();
    int Heap_utaa(int arraySize)
    {
        for (int i = 0; i <= arraySize; i++) {
            array[i] = 0;
            size = i;
        }
        
 };
 
    void heapSort(float array[], int size, int number) 
    
{ 	//This function is using for making a heap to Max Heap

    int largest = number; // Initialize largest as root 
    int leftChild = 2 * number + 1; // left = 2*number + 1 
    int rightChild = 2 * number + 2; // right = 2*number + 2 
  
    // If leftChild is smaller than size and larger than parent
    if (leftChild < size && array[leftChild] > array[largest]) {
        largest = leftChild ; 
        heapSort(array, size, largest); }
        
    // If right child is smaller  than size and larger than largest so far 
    if (rightChild < size && array[rightChild] > array[largest]) {
        largest = rightChild; 
        heapSort(array, size, largest); }
        
    // If largest number is not root 
    if (largest != number) { 
        swap(array[number], array[largest]); 
  
        // This function is recursive
        heapSort(array, size, largest); 
    } 
}
    void percolateDown( int root) {
        
        int minimum = root;
        int leftChild = 2 * root+1;
        int rightChild = 2 * root+2;
        if(leftChild == minimum){ //This part works if leftChild equals to minimum(which is parenat) 
            if(array[leftChild]<array[minimum]){
                    int temp =array[leftChild];
                    array[leftChild]=array[root];
                    array[root]=temp;
                }
        }
        
        if (leftChild < size && (rightChild <size || rightChild == size)) {
            if (array[leftChild] < array[root]||array[rightChild]<array[root]) {
                if (array[leftChild] < array[rightChild]) {
                    int temp = array[leftChild];
                    array[leftChild] = array[root];
                    array[root] = temp;
                    percolateDown(leftChild);
                }
                else if (array[rightChild] < array[leftChild]) {
                    int temp = array[rightChild];
                    array[rightChild] = array[root];
                    array[root] = temp;
                    percolateDown(rightChild);

                }
            
            }
	
        }
    }
    
    void percolateUp(int upper) {
        
    int location =(upper - 1)/2;
   if(upper!=0 && upper >0){ 
    if (array[location] > array[upper]) {
            float temp = array[location];
            array[location] = array[upper];
            array[upper] = temp;
            percolateUp(location);
    }
    else
        return;
   }
    
        // In this function if array[location] is greater than its parent does nothing
        // ýn other situations it swaps array[location] with parent, repeats it on the parent
        // This function is recursive

    }

    void makeEmpty(){
        if (size > 0) {
            array[size - 1] = 0; //This function deletes all array elements
            size--;
            makeEmpty();
            
        }
        else
        	cout<<"Succesfully Deleted"<<endl;
            
    }
    
    float findMin(int pos)
    {
        float min;
        int position = size;
                if ((array[pos - 1] < array[pos]) && (pos != 0)) {
            position = pos - 1;
        }
        else {
            position = pos;
        }
        --pos;
        
        if (pos == 0) {
            return position;
        }
        
        findMin(pos); //This function finds minimum number of tree with recursion
    }

    void deleteMin()
    {      
		    size = size - 1;
        array[0] = array[size];
        percolateDown(0); 
	}

	 void insertItem(float newItem)
    {

        size = size + 1;
        array[size-1] = newItem; //Adds newItem to last part of array
      
    }

    void display() {
        for(int i = 0; i<size;i++){
                cout<<array[i]<<"  ";
            }
            cout<<endl;
        for (int i = 1; i <= size; i++) {
                    if ((i & (i - 1)) == 0)  // i is a power of 2
                        cout << endl;
                    cout<<"\t" << array[i-1] << "    \n    "<<endl;
                    cout<<"         /    \\"; //For trying to make tree format
                }
                cout << endl;
                
            }
    
    int main() {
    	int loop;
    	float element;
    	int per =0;
    	
        cout << "Please enter the size of array:" << endl;
        cin >> size;
        
        Heap_utaa(size);
        
        for (int i = 0; i < size; i++) {
            cout << "Please enter " << i+1 << " th element of heap: " << endl;
            cin >> element;
            array[i] = element;
        }
        
        for(int i = 0; i < size; i++) {
			
            percolateDown(i);
            percolateUp(i);
			
        }
        cout<<"Here is your Min Heap: "<<endl;
        display();
			    
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ HERE IS YOUR OPTIONS $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ 1) Insert item to heap $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ 2) Find minimum number from heap $$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ 3) Delete minimum number from heap $$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ 4) Print heap $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ 5) HeapMax $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ 6) Make all heap empty $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ 0) EXIT! $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;	
		
		
		cout<<"Please chose any option you want: "<<endl;
		cin>>loop;
		
        while(loop!=0){
        	
        	if(loop == 1){
        		cout<<"Please enter number for insertion: ";
        		cin>>element;
        		insertItem(element);
        		cout<<"Addition Succesfull"<<endl;
        		display();
			}
			
			else if(loop == 2){
				for( per=0;per<size;per++){
        			findMin(per);
		        }
		        cout<<"Minimum number finded..."<<endl;
		        cout<<"Your minimum number is: "<<array[0]<<endl;
			}
			
			else if(loop == 3){
				cout<<"You want to delete minimum number..."<<endl;
				deleteMin();
				cout<<"Minimum number is succesfully deleted."<<endl;
				display();
			}
			
			else if(loop == 4){
    			if(size==0 ||size<0){
    			        cout<<"Your heap is empty."<<endl;
    			    }
    			else{
    				cout<<"Here is your heap: "<<endl;
    				display();}
    			}
            
			else if(loop == 5){
				while(per<size) {
			            heapSort(array,size,per);
			            per++;
			        }
				cout<<"Here is your sorted heap: "<<endl;
				
				display();
				
			}
			
			else if(loop == 6){
				cout<<"You want to make this heap empty..."<<endl;
				makeEmpty();
			}
			else    
			    cout<<"Please enter valid number: "<<endl;
        
        
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ HERE IS YOUR OPTIONS $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ 1) Insert item to heap $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ 2) Find minimum number from heap $$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ 3) Delete minimum number from heap $$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ 4) Print heap $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ 5) HeapMax $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ 6) Make all heap empty $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$ 0) EXIT! $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;	
		
		
		cout<<"Please chose any option you want: "<<endl;
		cin>>loop;
    }
    
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"---------------------------MISSION COMPLETED---------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    
    
}
