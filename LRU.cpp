#pragma

#include <unordered_map>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::unordered_map;

// - 双链表节点类
class DoubleList
{
    // - 成员
    public:
        int value_, key_;
        DoubleList *prior_;
        DoubleList *next_;
        DoubleList() : key_(0), value_(0), prior_(nullptr), next_(nullptr) { }
        DoubleList(int key, int value) : key_(key), value_(value), prior_(nullptr), next_(nullptr) { }
};

class LRUCache
{
    private:
        unordered_map<int, DoubleList*> cache_;
        DoubleList *head_;
        DoubleList *tail_;
        int size_;
        int capacity_;

    public:
        LRUCache(int capacity) : capacity_(capacity), size_(0)
        {
            // 头节点和尾节点，方便操作
            head_ = new DoubleList();
            tail_ = new DoubleList();
            head_->next_ = tail_;
            tail_->prior_ = head_;
        }
        ~LRUCache()
        {
            delete head_;
            delete tail_;
        }
        // 尾部插入元素
        void TailInsert(DoubleList *x);
        // 删除某个元素
        void RemoveNode(DoubleList *x);
        // 删除头部元素，并返回
        DoubleList *RemoveFront();
        // 返回长度
        int GetSize()
        {
            return size_;
        }
        // 返回关键字的值
        int Get(int key)
        {
            if (!cache_.count(key)) return -1;
            // 如果key存在，先通过hash定位，在移动尾部
            auto node = cache_[key]; 
            RemoveNode(node);
            TailInsert(node);
            return node->value_;
        }

        // lru过程，如果关键字在，则将其数据变为value，如果不存在则插入该数据，如果数据已满，则将最久未使用的淘汰
        void Put(int key, int value)
        {
            // 如果不存在
            if (!cache_.count(key))
            {
                auto node = new DoubleList(key, value);
                TailInsert(node);

                // 超出容量
                if (size_ > capacity_)
                {
                    // 删除头部节点，也就最久未使用的
                    auto remove_node = RemoveFront();
                    cache_.erase(remove_node->key_);
                    delete remove_node; // 防止内存泄漏
                }
            } else
            {
                // 如果key存在，定位修改value并且移到尾部   
                auto node = cache_[key];
                node->value_ = value;
                TailInsert(node);
                RemoveNode(node);
            }
        }
};

void LRUCache::TailInsert(DoubleList *x)
{
    x->prior_ = tail_->prior_;
    x->next_ = tail_;
    tail_->prior_->next_ = x;
    tail_->prior_ = x;
    size_++;
}

void LRUCache::RemoveNode(DoubleList *x)
{
    x->prior_->next_ = x->next_;
    x->next_->prior_ = x->prior_;
    size_--;
}

DoubleList *LRUCache::RemoveFront()
{
    auto node = head_->next_;
    RemoveNode(head_->next_);
    return node;
}
