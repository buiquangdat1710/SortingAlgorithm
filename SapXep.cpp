#include<bits/stdc++.h>
using namespace std;
// 1.Sap sep chon
void SelectionSort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int min = i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min = j;
			}
		}
		swap(a[i],a[min]);
	}
}
// 2.Sap xep noi bot
void BubbleSort(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}
// 3.Sap xep chen
void InsertionSort(int a[],int n){
	for(int i=1;i<n;i++){
		int x = a[i];
		int pos = i-1;
		while(pos >=0 && x < a[pos]){
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}
// 4.Sap xep dem phan phoi
int b[10000001];
void CountingSort(int a[],int n){
	int m = INT_MIN;
	for(int i=0;i<n;i++){
		b[a[i]]++;
		m = fmax(m,a[i]);
	}
	for(int i=0;i<=m;i++){
		if(b[i] != 0){
			for(int j=0;j<b[i];j++){
				cout << i << " ";
			}
		}
	}
}
// 5.Sap xep tron
void Merge(int a[],int l,int m,int r){
	vector<int> x(a+l,a+m+1);
	vector<int> y(a+m+1,a+r+1);
	int i=0,j=0;
	while(i<x.size() && j<y.size()){
		if(x[i]<=y[j]){
			a[l] = x[i];
			l++;
			i++;
		}
		else{
			a[l] = y[j];
			l++;
			j++;
		}
	}
	while(i<x.size()){
		a[l] = x[i];
		l++;
		i++;
	}
	while(j<y.size()){
		a[l] = y[j];
		l++;
		j++;
	}
}
void MergeSort(int a[],int l,int r){
	if(l<r){
		int m = (l+r)/2;
		MergeSort(a,l,m);
		MergeSort(a,m+1,r);
		Merge(a,l,m,r);
	}
}
// 6.Sap xep vun dong
void heapify(int a[],int n,int i){
	int l = 2*i+1,r = 2*i+2;
	int largest = i;
	if(l<n && a[l] > a[largest]){
		largest = l;
	}
	if(r<n && a[r] > a[largest]){
		largest = r;
	}
	if(largest != i){
		swap(a[i],a[largest]);
		heapify(a,n,largest);
	}
}
void HeapSort(int a[],int n){
	// Xay dung max heap
	for(int i = n/2 - 1;i>=0;i--){
		heapify(a,n,i);
	}
	for(int i=n-1;i>=0;i--){
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
}
//7. QuickSort voi phan hoach Lomuto
int partition(int a[],int l,int r){
	int pivot = a[r];
	int i = l-1;
	for(int j=l;j<r;j++){
		if(a[j]<=pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	i++;
	swap(a[i],a[r]);
	return i;
}
void QuickSort1(int a[],int l,int r){
	if(l>=r) return;
	int p = partition(a,l,r);
	QuickSort1(a,l,p-1);
	QuickSort1(a,p+1,r);
}
//8. QuickSort theo phan hoach Hoare
int partition2(int a[],int l,int r){
	int pivot = a[l];
	int i = l-1;
	int j = r+1;
	while(1){
		do{
			i++;
		}while(a[i]<pivot);
		do{
			j--;
		}while(a[j] > pivot);
		if(i<j){
			swap(a[i],a[j]);
		}else return j;
	}
}
void QuickSort2(int a[],int l,int r){
	if(l>=r) return;
	int p = partition2(a,l,r);
	QuickSort2(a,l,p);
	QuickSort2(a,p+1,r);
}
int main(){
	int n;
	cin >> n;
	int a[n];
	srand(time(NULL));
	for(int i;i<n;i++){
		a[i] = rand() % 1000;
	}
	QuickSort2(a,0,n-1);
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}