class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto i : tokens){
            int num;
            if(i != "+" && i != "-" && i != "*" && i != "/"){
                num = stoi(i);
                st.push(num);
            }
            else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res;
                if(i == "+"){
                    res = a+b;
                    st.push(res);
                }
                if(i == "-"){
                    res = b-a;
                    st.push(res);
                }
                if(i == "*"){
                    res = a*b;
                    st.push(res);
                }
                if(i == "/"){
                    res = b/a;
                    st.push(res);
                }
                cout << st.top() << endl;
            }
        }
        return st.empty() ? 0 : st.top();
    }
};
