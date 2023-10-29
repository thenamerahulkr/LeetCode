class Solution {
public:
    int mostWordsFound(vector<string>& s) {
      int i,j,max=0;
    for(i=0;i<s.size();i++){
        string t=s[i];
        int j=0;
        int count=0;
        while(j<t.size()){
          if(t[j]==' '){
              count++;
              j++;
          }
          else{
              j++;
          }
        }
        if(count>max){
            max=count;
        }
        }
    
  return max+1;  }
};