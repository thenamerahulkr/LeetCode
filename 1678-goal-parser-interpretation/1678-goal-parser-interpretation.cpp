class Solution {
public:
    string interpret(string command) {
        string ans = "";
        for(int i=0;i<command.length();i++){
            if(command[i]=='G') ans+=command[i];
            if(command[i]=='(' && command[i+1]==')') ans+='o';
            if(command[i]=='(' && command[i+1]=='a') ans+="al"; 
        }
        return ans;
    }
};