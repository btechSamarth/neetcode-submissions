class Solution {
public:
    bool isSafe(string s){
        stack<char> st;

        for(auto i : s){
            if(i == '('){
                st.push(i);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char a = st.top();
                if(a == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        for(int i = 0 ; i < n ; i++){
            s += "(";    
        }
        for(int i = 0 ; i < n ; i++){
            s += ")";    
        }
        vector<string> ans;
        do{
            cout << s << endl;
            if(isSafe(s)) ans.push_back(s);
        }
        while(next_permutation(s.begin() , s.end() ) ) ;

        return ans;
    }
};
