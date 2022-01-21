class MaxHeap{

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

         //Above are Basic Utility Functions

         void BubbleUp(int index) //Last index of inserted number
         {
           
           int childIndex=index;
           int parentIndex=parentIndex(index);

           while(hasParent(childIndex) and ar[childIndex]>ar[parentIndex])
           {
           	swap(childIndex,parentIndex);
           	childIndex=parentIndex;
           	parentIndex=parentIndex(parentIndex);

           }
         }

         void BubbleDown(int index)
         {
         	if(hasLeftChild(index))
         	{
         		if(hasRightchild(index))
         		{
                            int maxIndex=index;
                            if(ar[maxIndex]<ar[lChild_Index(index)])maxIndex=lChild_Index(index);
                            if(ar[maxIndex]<ar[rChild_Index(index)])maxIndex=rChild_Index(index);
                            swap(maxIndex,index);
                            BubbleDown(maxIndex);
         		}
         		else{ //has only left Child. So check with LeftChild only

                            if(ar[index]<ar[lChild_Index(index)]){
                             swap(lChild_Index(index),index);
                             BubbleDown(lChild_Index(index));
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
          				BubbleUp(index);
          			else BubbleDown(index);
          		}
          	}
          }




};
