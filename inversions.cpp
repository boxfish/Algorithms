#include <iostream>
using namespace std;
int count=0;
void counting(int A[],int low,int mid,int high){
    int left[mid-low+2],right[high-mid+1];
    for(int i=0;i<mid-low+1;i++){
        left[i]=A[low+i];
    }
    left[mid-low+1]=10000;
    for(int i=0;i<high-mid;i++){
        right[i]=A[mid+1+i];
    }
    right[high-mid]=10000;
    int l=0, r=0;
    for(int i=low;i<=high;i++){
        if(left[l]<=right[r]){
            A[i]=left[l];
            l++;
        }
        else if(left[l]>=right[r]){
            A[i]=right[r];
            r++;
            count=count+mid-low-l+1;
        }
    }
}
void inversion(int A[],int low,int high){
    if(low==high) return ;
    int mid=(low+high)/2;
    inversion(A,low,mid);
    inversion(A,mid+1,high);
    counting(A,low,mid,high);
}

int main() {
	int n;
	cin >> n;
	int A[n];
	for(int i=0;i<n;i++){
	    cin >> A[i];
	}
	inversion(A,0,n-1);
	/*for(int i=0;i<n;i++){
	    cout << A[i];
	}*/
	cout <<count;
	
	return 0;
}