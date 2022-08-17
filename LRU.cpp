#pragma

#include <unordered_map>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::unordered_map;

class DoubleList
{
    public:
    int key_;
    int value_;
    DoubleList *prior_;
    DoubleList *next_;
    // 构造函数
    DoubleList() : key_(0), value_(0), prior_(nullptr), next_(nullptr) { }
    DoubleList(int key, int value) : key_(key), value_(value), prior_(nullptr), next_(nullptr){ }
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity), size_(0) {
        head_ = new DoubleList();
        tail_ = new DoubleList();
        head_->next_ = tail_;
        tail_->prior_ = head_;
    }
    
    // 尾部插入节点
    void TaiInsert(DoubleList *node)
    {
        node->prior_ = tail_->prior_;
        node->next_ = tail_;
        node->prior_->next_ = node;
        tail_->prior_ = node;
    }

    // 删除节点 一定存在
    void RemoveNode(DoubleList *node)
    {
        node->prior_->next_ = node->next_;
        node->next_->prior_ = node->prior_;
    }

    // 删除头部节点并返回,为了更新映射关系
    DoubleList *RemoveHead()
    {
        auto node = head_->next_;
        head_->next_ = node->next_;
        node->next_->prior_ = head_;
        return node;
    }

    // 将节点移动到尾部，更新算法
    void MoveNodeTail(DoubleList *node)
    {
        RemoveNode(node);
        TaiInsert(node);
    }

    int get(int key) {
        // 存在
        if (key_node_.count(key))
        {
            auto node = key_node_[key];
            MoveNodeTail(node);
            return node->value_;
        } else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (key_node_.count(key))
        {
            auto node = key_node_[key];
            node->value_ = value;
            MoveNodeTail(node);
            key_node_[key] = node;
        } else{
            auto node = new DoubleList(key, value);
            TaiInsert(node);
            key_node_[key] = node;
            size_++;

            if (capacity_ < size_)
            {
                auto node = RemoveHead();
                key_node_.erase(node->key_);
                size_--;
                delete node;
            }
            
        }
    }

    ~LRUCache()
    {
        delete head_;
        delete tail_;
    }

private:
    DoubleList cache_;
    unordered_map<int, DoubleList*> key_node_;
    DoubleList *head_;
    DoubleList *tail_;
    int capacity_;
    int size_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {
    }
    
    int get(int key) {
        // - 如果存在
        if (key_list_.count(key))
        {
            auto node = *key_list_[key];
            cache_.erase(key_list_[key]);
            cache_.emplace_front(node);
            key_list_[key] = cache_.begin();
            return node.second;
        } else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto node = std::make_pair(key, value);
        // - 如果存在
        if (key_list_.count(key))
        {
            cache_.erase(key_list_[key]);
        } else
        {
            if (capacity_ == cache_.size())
            {
                key_list_.erase(cache_.back().first);
                cache_.pop_back();
            }
        }
        cache_.emplace_front(node);
        key_list_[key] = cache_.begin();
    }

private:
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> key_list_;
    int capacity_;
};