class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();
        int m=nums2.size();

        stack<int> st;
        for(int i=0;i<m;i++){
            st.push(nums2[i]);
        }
        stack<int> res=st;
        vector<int> answer;
        for(int i=0;i<n;i++){
            int ans=-1;
            st=res;
            while(!st.empty()){
                vector<int> temp;
                int top = st.top();
                st.pop();
                if(top>nums1[i]){
                    ans=top;
                }
                if(top==nums1[i]){
                    break;
                }
            }
            answer.push_back(ans);
        }

        return answer;
    }
};