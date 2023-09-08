#include <iostream>
using namespace std;
int main()
{
    int arr[5];
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int l=0;
	int r=n;
	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x){
			cout<<"Found at index "<<m;
			break;
		}
		// If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	// if we reach here, then element was
	// not present
	return 0;
}


