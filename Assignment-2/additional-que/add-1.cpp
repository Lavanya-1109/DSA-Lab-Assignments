#include <iostream>
using namespace std;
void BubbleSort(int arr[],int n) {
    for (int i=0;i<n-1;i++) {
        int flag=0;
        for (int j=0;j<n-1-i;j++) {
            if (arr[j+1]<arr[j]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if (flag == 0){
        	return;
		} 
     }
    return;
}
int countpairs(int arr[],int n,int k) {
    int i=0;
    int j=0;
    BubbleSort(arr,n);
    int count=0;
    while (i<n && j<n) {
        int diff=arr[j]-arr[i];
        if (diff>k) i++;
        else if (diff<k) j++;
        else {
            int ele1=arr[i];
            int ele2=arr[j];
            int count1=0;
            int count2=0;
            while (i<n && arr[i]==ele1) {
                count1++;
                i++;
            }
            while (j<n && arr[j]==ele2) {
                count2++;
                j++;
            }
            if (ele1==ele2) {
                count+=count1*(count1-1)/2;
            }
            else {
            	count+=count1*count2;
			}
        }
    }
    return count;
}
int main() {
    int arr[6] = {2, 2, 2, 3, 3, 4};
    cout<<countpairs(arr,6,0);
    return 0;
}