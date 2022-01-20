
class MinHeap{


	vector<int> ar;

	int lChild_Index(int parent)
	{
		return (2*parent+1);  //parent is index
	}

	int rChild_Index(int parent)
	{
		return (2*parent+2);  //parent is index
	}

	int parentIndex(int child)
	{
		return (child-1)/2;
	}


	bool hasLeftChild(int parent)
	{
		return lChild_Index(parent)<ar.size();
	}

	bool hasRightchild(int parent)
	{
		return rChild_Index(parent)<a.size();
	}

	//Check if a index has parent or not
	bool hasParent(int child)
	{
		return parentIndex(child)>=0 and parentIndex(child)<ar.size();
	}

	//Now, functions for Returning the element

	int leftChild(int parent)
	{
		return ar[lChild_Index(parent)];
	}

	int rightChild(int parent)
	{
		return ar[rightChild(parent)];
	}

	int parent(int child)
	{
		return ar[parentIndex(child)];


	}
         void swap(int idx1, int idx2)
         {
         	int temp=ar[idx1];
         	ar[idx1]=ar[idx2];
         	ar[idx2]=temp;
         }
        //Bubble up is required when we inserted element at the last.
        // Now this element is required to be inserted at Right position int he Binary Heap
	void BubbleUp(int index)
	{
             inr childIdx=index;
             int parentIdx=parentIndex(index);

             while(hasParent(childIdx) and ar[childIdx]<ar[parentIdx])
             {
             	swap(childIdx,parentIdx);
             	childIdx=parentIdx;
             	parentIdx=parentIndex(childIdx);
             }
	}

	//This is required when we are removing root element 
	void BubbleDown(int idx)
	{

          //There can be two cases
	    //1: If the parent node has both left and Right Child
	    //2: If the parent node has only Left Child
          if(hasLeftChild(idx))
          {
          	if(hasRightchild(idx))
          	{
                   int minIndex=idx;
                   if(ar[minIndex]>ar[lChild_Index(idx)])minIndex=lChild_Index(idx);
                   if(ar[minIndex]>ar[rChild_Index(idx)])minIndex=rChild_Index(idx);

                   swap(minIndex,idx);
                   BubbleDown(minIndex);
          	}
          	else{
                   if(ar[lChild_Index(idx)]<ar[idx])
                   {
                   	swap(minIndex,idx);
                   	BubbleDown(lChild_Index(idx));
                   }
          	}
          }
	}


    public:
    	 void insert(int num)
    	 {
    	 	ar.push_back(num);
    	 	BubbleUp(ar.size()-1);
    	 }

    	 int FindRoot()   //top

    	  {
    	  	if(ar.size()==0)
    	  	{
    	  		return -1;
    	  	}
    	  	else return ar[0];
    	  }

    	  //Delete the Minimum Element of the MinHeap

    	  void RemoveRoot()
    	  {
    	  	ar[0]=ar[ar.size()-1];  //Copy the end element to the Zero index and Remove the Duplicate from Back
    	  	ar.pop_back();

    	  	BubbleDown(0);  //Bubble Down starts from Zero index
    	  }

    	  //Remove Element at Particular index

          void RemoveAtIndex(int idx)
          {
          	int index=0;

          	while(index<ar.size() and index!=idx)
          	{
          		index++;
          	}

          	if(index<ar.size())
          	{
          		if(index==ar.size()-1)
          		{
          			ar.pop_back();

          		}
          		else{
          			ar[index]=ar[ar.size()-1];
          			ar.pop_back();
          			if(index==0 || ar[index]>ar[parent(index)])
          				BubbleDown(index);
          			else BubbleUp(index);
          		}
          	}
          }

};
