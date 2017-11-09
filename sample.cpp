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
