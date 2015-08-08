#ifndef MUSTARD_QU_H
#define MUSTARD_QU_H 1

namespace mustard {

namespace qu {

template <typename T>
class cyc_queue
{
    const int length;
    T  *data;
    int front, rear;

public:
    cyc_queue(int len)
        : length(len), data(new T[len])
        , front(0), rear(0)
    {}

    ~cyc_queue()
    {
        delete[] data;
    }

    int capacity() const
    {
        return length;
    }

    int size() const
    {
        return (rear - front + length) % length;
    }

    bool empty() const
    {
        return front == rear;
    }

    bool full() const
    {
        return _next(rear) == front;
    }

    T & front()
    {
        return data[front];
    }

    T front() const
    {
        return data[front];
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
            front = _next(front);
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
