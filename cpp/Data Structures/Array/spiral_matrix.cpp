vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int>v;
        int row=m.size();
        if(row==0) return {};
        int n=m[0].size();
        if(n==0) return v
;
        int top=0,bot=row-1,left=0,right=n-1,dir=0;
        while(top<=bot && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++) v.push_back(m[top][i]);
                top++;
            }
            else if(dir==1){
                for(int i=top;i<=bot;i++) v.push_back(m[i][right]);
                right--;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--) v.push_back(m[bot][i]);
                bot--;
            }
            else if(dir==3){
                for(int i=bot;i>=top;i--) v.push_back(m[i][left]);
                left++;
            }
            dir=(dir+1)%4;
        }
        return v;
    }
