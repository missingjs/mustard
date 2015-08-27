template <typename W>
struct numeric_weight
{
    static W initial_value()
    {
        return std::numeric_limits<W>::max();
    }
};

