lass LRUCache : public Cache{
    
    public:
    int cp;
    LRUCache(int capacity):cp(capacity){}
    void set(int key, int val){
        
        if(mp.find(key) != mp.end())
            return ;
        
        Node *newNode;
        newNode = new Node(key,val);
        
        if(mp.size() == 0){
            head = newNode;
            tail = newNode;
            newNode->prev = newNode;
        }
            
        
        mp[key] = newNode;
        head->next = newNode;
        newNode->prev = head;
        head = newNode;
        head->next = head;
        
        if(mp.size() > cp){
            mp.erase(tail->key);
            Node *oldTail = tail;
            tail = tail->next;
            tail->prev = tail;
            delete oldTail;
        }

    }
    
    int get(int key){
        
        if(mp.find(key) == mp.end())
            return -1;
        
        if(key == head->key)
            return head->value;
        
        mp[key]->prev->next = mp[key]->next;
        mp[key]->next->prev = mp[key]->prev;
        
        mp[key]->prev = head;
        mp[key]->next = mp[key];
        head->next = mp[key];
        head = mp[key];
        
        return mp[key]->value;
        
    }
    
};


// Lool at this

struct Val{
    int value;
    int key;
    Val(int k, int v):key(k),value(v){};
    Val(Val* v):key(v->key),value(v->value){}
};

class LRUCache{

    vector<Val> value;
    map<int,vector<Val>::iterator> keys;
    int cp;
    
    public:
    LRUCache(int capacity):cp(capacity){}
    
    void set(int key, int val){
        
        vector<Val>::iterator link = value.emplace(value.end(),new Val(key,val));
        keys[key] = link;
        
        if(value.size() > cp){
            Val tmp = value.front();
            value.erase(value.begin());
            keys.erase(tmp.key);
        }
    }
    
    int get(int key){
        
        if(keys.find(key) == keys.end())
            return -1;
        
        Val tmp = (*keys[key]);
        value.erase(keys[key]);
        cout << tmp.key;
        vector<Val>::iterator link = value.emplace(value.end(),tmp);
        keys[key] = link;
        for(auto v : keys)
            cout << v.first << endl;
        return tmp.value;
    }
};


// And here it is YEAH ------------------------------------------------------------------->

class LRUCache{
    
    map<int,int> cache;
    vector<int> order;
    int cp;
    
    public:
        LRUCache(int capacity):cp(capacity){}
    
        void set(int key,int val){
            cache[key] = val;
            order.push_back(key);
            if(cache.size() > cp){
                cache.erase(order.front());
                order.erase(order.begin());
            }
        }
    
        int get(int key){
            
            if(cache.find(key) == cache.end())
                return -1;

            order.erase(remove(order.begin(), order.end(), key), order.end());
            order.push_back(key);
            return cache[key];
        }
    
    
};
