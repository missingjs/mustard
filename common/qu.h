#ifndef MUSTARD_QU_H
#define MUSTARD_QU_H 1

namespace mustard {

namespace qu {

template <typename T>
class cyc_queue
{
    const int length;
    T  *data;
    int pfront, rear;

public:
    cyc_queue(int len)
        : length(len + 1), data(new T[len + 1])
        , pfront(0), rear(0)
    {}

    ~cyc_queue()
    {
        delete[] data;
    }

    int capacity() const
    {
        return length - 1;
    }

    int size() const
    {
        return (rear - pfront + length) % length;
    }

    bool empty() const
    {
        return pfront == rear;
    }

    bool full() const
    {
        return _next(rear) == pfront;
    }

    T & front()
    {
        return data[pfront];
    }

    T front() const
    {
        return data[pfront];
    }

    void push(const T & t)
    {
        if (!full()) {
            data[rear] = t;
            rear = _next(rear);
        }
    }

    void pop()
    {
        if (!empty()) {
            pfront = _next(pfront);
        }
    }

private:
    int _next(int i) const
    {
        return (i + 1) % length;
    }

};

} // namespace ::mustard::qu

} // namespace ::mustard

#endif
