#include<stdio.h>

void linear_sort(int *a, int size)
{
    int pass, cand, temp;

    for(pass=0; pass < size-1; pass++)
        for(cand=pass+1; cand < size; cand++)
            if(a[pass] > a[cand]) {
                temp=a[pass];
                a[pass]=a[cand];
                a[cand]=temp;
            }
    return;
}

//  Bubble sort from Jones & Harrow book, p 547.
void bubble_sort(int arr[], int n)
{
	int i,swapped,temp;

	do {
		swapped=0;

		for(i=0;i<n-1;i++) {
			if(arr[i]>arr[i+1]) {
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
				swapped=1;
			}
		}
	} while(swapped);
}

/*  Insertion sort: O(n^2)  */
void insert_sort(int data[], int no_elems)
{
	int tmp,j,i;

	for(i=1;i<no_elems;i++) {
		tmp=data[i];
		j=i-1;
		while( (data[j]>tmp) && (j>=0) ) {
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=tmp;
	}
}

int findmax(int a[], int size)
{
	int max=a[0], find=0, i;

	for(i=1;i<size;i++)
		if(max<a[i]) {
			max=a[i];
			find=i;
		}
	return find;
}

/* Max sort: O(n^2) */
void maxsort(int a[],int size)
{
    int indmax, temp;
	if(size==1)
		return;
	else {
		indmax=findmax(a,size);
		temp=a[size-1];
		a[size-1]=a[indmax];
		a[indmax]=temp;
		maxsort(a,size-1);
	}
}

/*  Selection sort: O(n^2)  */
void selection_sort(int a[], int n)
{
	int largepos,i,last, temp;

	for(last=n-1; last>0; last--) {
		largepos=0;
		for(i=1; i<=last;i++)  /* {  */
			if(a[i]>a[largepos])
				largepos=i;
	/*	if(largepos!=last) { */
			temp=a[last];
			a[last]=a[largepos];
			a[largepos]=temp;
	/*	}   */
	/*	}   */
	}
}


/*  Langsam, p.365           */
void insertion_sort(int *x, int n)
{
    int i,k,y;
    
    for(k=1; k<n; k++) {
        y=x[k];
        for(i=k-1; i>=0 && y<x[i]; i--)
            x[i+1]=x[i];
        x[i+1]=y;
    }
}    


void test_sorting()
{
    int data[]={8,23,6,5,11, -9, 131, -32};
    int sort[]={1,2,3,4,5,6};
    int i=0;
    int size=sizeof(data)/sizeof(data[0]);

/*  Add here method to test */
/*    selection_sort(data, size);   */
    insert_sort(data, size);
/*  Print array after sorting */    
    for(i=0; i<size; i++)
        printf("data[%d] = %d\n", i, data[i]);
/*    
    size=sizeof(sort)/sizeof(sort[0]);    
    selection_sort(sort, size);
    for(i=0; i<size; i++)
        printf("sort[%d] = %d\n", i, sort[i]);        */
    return;    
}




//	Merge sort?
/*
 *We need 2 arrays 'a' and 'b', of equal size
 *Here 'a' is the primary array (i.e which contains initial
     input, and final output)
 *And 'b' is the temporary array,
     used for merging 2 sorted half's in 'a'
 */
  
void merge(int a[], int low, int mid, int high)
{
    int b[10000];
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
  
    while (j <= high)
        b[k++] = a[j++];
  
    k--;
    while (k >= 0) {
        a[low + k] = b[k];
        k--;
    }
}
  
void mergesort(int a[], int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}







int partition(int *a, int p, int r)
{
    int x=a[r];
    int i=p-1;
    int j=0, temp=0;
    
    for(j=p;j<r-1;j++) {
        if(a[j]<=x) {
            ++i;
            
            //  swap a[i] and a[j] here
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    
    //  swap a[i+1] and a[r];
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return i+1;
}   
    
    
    
void quick_sort(int *a, int p, int r)
{   
    int q=0;
    if(p<r) {
        q=partition(a, p, r);
        quick_sort(a, p, q-1);
        quick_sort(a,q+1,r);
    }
}


    
void test_quick_sort()
{
    int a[]={8,23,6,5,11, -9, 131, -32};
    int i=0, size_of_a=sizeof(a)/sizeof(a[0]);
//    quick_sort(a, 1, size_of_a); // 0 shoud be as a starting index?
    quick_sort(a, 0, size_of_a-1); 
    
    //  print sorted array
    for(i=0; i<size_of_a;i++)
        printf("%d\t", a[i]);
    puts("\n");
}




int main()
{
//    test_sorting();
    test_quick_sort();
    return 0;
}

//  -32 -9 6 5 8 11 23 131

