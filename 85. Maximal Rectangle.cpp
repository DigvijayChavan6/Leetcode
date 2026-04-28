class Solution {
    int getMaxArea(vector<int>& heights) {
        int n = heights.size();
        int mxArea = 0, tp, area, prev;
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                tp = st.top();
                st.pop();
                prev = st.empty() ? -1 : st.top();
                area = heights[tp] * (i - prev - 1);
                mxArea = max(area, mxArea);
            }
            st.push(i);
        }
        int last = n;
        while(!st.empty()){
            tp = st.top();
            st.pop();
            prev = st.empty() ? -1 : st.top();
            area = heights[tp] * (last - prev - 1);
            mxArea = max(area, mxArea);
        }

        return mxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int mxArea = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                }else{
                    heights[j] = 0;
                }
            }
            mxArea = max(mxArea, getMaxArea(heights));
        }
        return mxArea;
    }
};