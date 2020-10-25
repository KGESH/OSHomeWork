#ifndef __CIRCULARITERATOR_H__
#define __CIRCULARITERATOR_H__

template <class BaseIterator>
class CircularIterator{
    public:
        CircularIterator(BaseIterator begin, BaseIterator end, BaseIterator current = begin) : begin_(begin), end_(end), current_(current) {}
        BaseIterator& operator++(int) { ++current_; if (current_ == end_) { current_ = begin_; return current_; } }
        BaseIterator& Current() { return current_; }
        BaseIterator& Begin() { return begin_; }
        BaseIterator& End() { return end_; }

    private:
        BaseIterator current_;
        BaseIterator begin_;
        BaseIterator end_;
};

#endif
