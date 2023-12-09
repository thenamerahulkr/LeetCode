class Solution {
public:
    int calPoints(vector<string>& o) {
        stack<int> s;
        for(int i = 0; i < o.size();i++){
            if(s.empty()) s.push(stoi(o[i]));
            else{
                if(o[i] == "+"){
                    int x = s.top();
                    s.pop();
                    int y = s.top();
                    s.push(x);
                    s.push(x+y);
                }
                else if(o[i] == "C"){
                    s.pop();
                }
                else if(o[i] == "D"){
                    s.push(2*s.top());
                }
                else{
                    s.push(stoi(o[i]));
                }
            }
        }
        int sum = 0;
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};