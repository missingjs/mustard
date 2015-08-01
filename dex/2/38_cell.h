template <typename T>
struct cell
{
    T   data;
    int freq;

    cell() :
        data(T()), freq(0)
    {}
};

