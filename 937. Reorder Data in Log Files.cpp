 vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<pair<string,string>>let;
        vector<pair<string,string>>dig;
        
        
        for(auto x:logs){
            string s="",t="";
        bool flag=false;
            for(int j=0;j<(int)x.size();j++){
                if(x[j]==' ' and flag==false){
                    flag=true;
                    continue;
                }
                if(flag==false) s+=(char)(x[j]);
                else t+=(char)(x[j]);
            }
            if(t[0]>='a' and t[0]<='z') let.push_back({t,s});
            else dig.push_back({t,s});            
        }
        sort(let.begin(),let.end());
        vector<string>ans;
        for(auto i:let){
            ans.push_back((string)i.second+" "+i.first);
        }
        for(auto y:dig){
            ans.push_back((string)y.second+" "+y.first);
        }
        return ans;        
        
    }
