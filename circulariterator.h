#ifndef __CIRCULARITERATOR_H__
#define __CIRCULARITERATOR_H__

const int kMaxBlockSize = 20;

template <class BaseIterator>
class CircularIterator{
    public:
        CircularIterator(BaseIterator begin, BaseIterator end, BaseIterator current) : begin_(begin), end_(end), current_(current), next_(current), prev_(current) {}
        BaseIterator& operator++() { ++current_; if (current_ == end_) { current_ = begin_;  return current_; } }
        BaseIterator& operator++(int) { ++current_; if (current_ == end_) { current_ = begin_; return current_; } }
        BaseIterator& Current() { return current_; }
        BaseIterator& Begin() { return begin_; }
        BaseIterator& End() { return end_; }
        BaseIterator& Next() { ++next_; if (next_ == end_) { next_ = begin_;} return next_; }
        BaseIterator& Prev() { if (prev_ == begin_) { prev_ = end_; return prev_; } BaseIterator current = current_; prev_ = --current; return prev_;}
        int GetCurrentPosition() { int pos = 0; for(BaseIterator current = current_; current != end_; current++, pos++) {} return kMaxBlockSize - pos;}

    private:
        BaseIterator current_;
        BaseIterator begin_;
        BaseIterator end_;
        BaseIterator next_;
        BaseIterator prev_;
};

#endif
