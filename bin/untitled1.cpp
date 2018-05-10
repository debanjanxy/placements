#include <iostream>
using namespace std;

class AptArray
{
private:
	int n;
	int *arr;
public:
	AptArray(int n) :n(n)
	{	
		arr = new int[n];
		for(int i=0;i<n;i++)
			arr[i] = 0;
	}
	AptArray(const AptArray &A)
	{
		n = A.n;
		arr = new int[n];
		for(int i=0;i<n;i++)
			arr[i] = A.arr[i];	
	}
	AptArray(int A[], int n) : n(n)
	{
		arr = new int[n];
		for(int i=0;i<n;i++)
			arr[i] = A[i];	

	}
	int operator [](int i)
	{
		if(i>=0 and i<n)
			return arr[i];
		return -1;
	}
	void print()
	{
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	AptArray operator +(const AptArray &p)
	{
		AptArray ans(max(n,p.n));
		
		for(int i=0;i<n;i++){
			ans.arr[i] += arr[i];
		}
		for(int i=0;i< p.n;i++){
			ans.arr[i] += p.arr[i];
		}
		return ans;
	}
	double avg()
	{
		double res = 0;
		for(int i=0;i< n;i++){
			res += arr[i];
		}
		return res/n;
	}
	bool operator < (const AptArray &p)
	{	int i;
		for( i=0;i<min(n,p.n);i++){
			if(arr[i] >= p.arr[i])
				return false;
		}
		if(n<=p.n){
			for(;i<p.n;i++){
				if(0 >= p.arr[i])
					return false;
			}
		}
		else{
			for(;i<n;i++)
				if(arr[i] >= 0 )		
					return false;
		}
		return true;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	int arr[n],arr2[n];
	for(int i = 0; i < n; ++i)
	{
		int val;
		cin>>val;
		arr[i]=val;
		arr2[i]=2*val;
	}

	AptArray a(m), b(arr2,n), c(arr, n);
	a.print();
	b.print();
	for(int i = 0; i < n; ++i)
		cout << c[i] << " ";
	cout << endl;

	AptArray d(b+c);
	d.print();

	AptArray e(a+c);
	e.print();

	AptArray f(a+b);
	f.print();

	double avg = (a.avg()+b.avg()+c.avg()+d.avg()+e.avg()+f.avg())/6.0;
	cout << "avg = " << avg << endl;

	cout << (a<b) << " " << (b<c) << " " << (c<d) << " " << (d<e) << " " << (e<f) << endl;


}
