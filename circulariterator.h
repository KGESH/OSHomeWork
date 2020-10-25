#ifndef __CIRCULARITERATOR_H__
#define __CIRCULARITERATOR_H__

const int kMaxBlockSize = 20;

template <class BaseIterator>
class CircularIterator{
    public:
        CircularIterator(BaseIterator begin, BaseIterator end) : begin_(begin), end_(end), current_(begin), next_(begin) {}
        BaseIterator& operator++() { ++current_; if (current_ == end_) { current_ = begin_;  return current_; } }
        BaseIterator& operator++(int) { ++current_; if (current_ == end_) { current_ = begin_; return current_; } }
        BaseIterator& Current() { return current_; }
        BaseIterator& Begin() { return begin_; }
        BaseIterator& End() { return end_; }
        BaseIterator& Next() { if (next_ == end_) { next_ = begin_; return next_; } else { ++next_; return next_; } }
        int GetCurrentPosition() { int pos = 0; for(BaseIterator current = current_; current != end_; current++, pos++) {} return kMaxBlockSize - pos;}

    private:
        BaseIterator current_;
        BaseIterator begin_;
        BaseIterator end_;
        BaseIterator next_;
};

#endif
