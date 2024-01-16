class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        vector<int>v(v1.begin(),v1.end());
        v.insert(v.end(),v2.begin(),v2.end());
        sort(v.begin(),v.end());
        if(v.size()%2==0) {
            return (float)((v[v.size()/2] + v[v.size()/2-1])/2.0);
        }
        else return v[v.size()/2];
    }
};