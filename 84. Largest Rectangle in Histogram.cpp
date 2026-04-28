class Solution {
public:
 int largestRectangleArea(vector<int>& heights) {
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
    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     int mxArea = 0;

    //     vector<int> nse(n, 0), pse(n, 0);
    //     stack<int> st;
    //     for(int i = 0; i < n; i++){
    //         while(!st.empty() && heights[st.top()] >= heights[i])st.pop();
    //         if(st.empty())pse[i] = -1;
    //         else pse[i] = st.top();
    //         st.push(i);
    //     }
    //     while(!st.empty()) st.pop();
    //     for(int i = n-1; i >= 0; i--){
    //         while(!st.empty() && heights[st.top()] >= heights[i])st.pop();
    //         if(st.empty())nse[i] = n;
    //         else nse[i] = st.top();
    //         st.push(i);
    //     }

    //     for(int i = 0; i < n; i++){
    //         int area = heights[i] * (nse[i] - pse[i] - 1);
    //         mxArea = max(area, mxArea);
    //     }
    //     return mxArea;
    // }
};


// int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int mxArea = 0;

//         for(int i = 0; i < n; i++){
//             int left = i-1;
//             int right = i+1;
//             while(left >= 0 && heights[left] >= heights[i])left--;
//             while(right < n && heights[right] >= heights[i])right++;
//             int area = heights[i] * (right - left - 1);
//             mxArea = max(mxArea, area);
//         }

//         return mxArea;
//     }