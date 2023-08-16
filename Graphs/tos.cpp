class LockingTree {
public:
    map<int,int> mp;
    vector<int> par;
    vector<int> adj[2001];
    int n;
    LockingTree(vector<int>& parent) {
        par = parent;
        n = par.size();
        for(int i=0 ; i<n ; i++ )
        {
            mp[i] = 0;
            adj[i].clear();
        }

        for(int i=1; i<n ; i++){
            adj[par[i]].push_back(i); //for getting childs
        }
    }
    
    bool lock(int num, int user) {
        if(mp[num]!=0)
        return false;
        mp[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(mp[num]!=user)
        return false;
        mp[num] = 0;
        return true;
    }

    //checking descendants

    bool dfs(int val)
    {
        bool ans = false;
        for(auto i:adj[val])
           ans = ans | dfs(i);
        if(mp[val] >= 1)
           ans = true;
        return ans;
    }

    void unlock_des(int val){
        mp[val] = 0;
        for(auto i:adj[val])
            unlock_des(i);
    }
    
    bool upgrade(int num, int user) {
        //phele ancestors ko check kro koi bhi locked na ho
        //then descendatas ko check kro at least ek lock hona chaiye
        int val = num;
        //checking ancestors

        while(num!=-1){
            if(mp[num]>=1)
            return false;
            num = par[num];
        }

        num = val;
        bool ans = dfs(num);
        if(ans == false)
        return false;
        //unlock descendants
        unlock_des(num);
        mp[num] = user;
        return true;

    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */