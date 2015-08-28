template <typename W>
class adj_multilist
{
public:

    struct arc_node
    {
        W weight;
        int i, j;
        arc_node *inext, *jnext;

        arc_node(const W & w = W(),
                int i = -1, int j = -1)
            : weight(w), i(i), j(j)
              , inext(NULL), jnext(NULL)
        {}
    };

public:
    
    adj_multilist(int n);

    ~adj_multilist();

    int size() const
    {
        return _size;
    }

    void set(int i, int j, const W & w);

    bool get(int i, int j, W & value) const;

    void remove(int i, int j);

private:

    arc_node * _find(int i, int j) const;

public:

    arc_node ** _heads;

    int   _size;

};


template <typename W>
adj_multilist<W>::adj_multilist(int n)
    : _heads(new arc_node*[n]), _size(n)
{}

template <typename W>
adj_multilist<W>::~adj_multilist()
{
}
