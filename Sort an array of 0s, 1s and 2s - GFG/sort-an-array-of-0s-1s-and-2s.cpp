//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int j=-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                j++;
                swap(a[i],a[j]);
            }
        }
         for(int i=j+1;i<n;i++)
        {
            if(a[i]==1)
            {
                j++;
                swap(a[i],a[j]);
            }
        }
        
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends