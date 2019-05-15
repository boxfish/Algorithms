#include <iostream>
using namespace std;
void merge(int A[],int low,int mid,int high){
    int left[mid-low+2],right[high-mid+1];
    for(int i=0;i<mid-low+1;i++){
        left[i]=A[low+i];
    }
    left[mid-low+1]=10000;
    
    for(int i=0;i<high-mid;i++){
        right[i]=A[mid+1+i];
    }
    right[high-mid]=10000;
    int l=0,r=0;
    for(int i=low;i<=high;i++){
        if(left[l]<=right[r]){
            A[i]=left[l];
            l++;
         //   cout << "l" << l;
        }
        else if(left[l]>=right[r]){
            A[i]=right[r];
            r++;
           // cout << "r" << r;
        }
    }
}
void mergesort(int A[],int low,int high){
    if(low==high) return ;
    int mid;
    if(low<high){
      mid=(low+high)/2;
    }
    mergesort(A,low,mid);
    mergesort(A,mid+1,high);
    merge(A,low,mid,high);
   /* for(int i=low;i<high;i++){
            cout <<A[i] ;  
    }
    cout << endl;*/
}

int main() {
	int n;
	cin >> n;
	int A[n];
	for(int i=0;i<n;i++){
	    cin >> A[i];
	}
	mergesort(A,0,n-1);
	for(int i=0;i<n;i++){
	    cout << A[i]<<" ";
	}
		return 0;
}