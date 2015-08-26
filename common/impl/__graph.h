template <typename T, typename G>
G * _read_graph()
{
    int len = 0;
    T * arr = array::read<T>(len); 
    if (!arr || len == 0) { 
        return NULL; 
    }
                                                                           
    G * g = new G(arr, arr + len);

    int num_e = 0; 
    std::cin >> num_e;

    T t1, t2;
    for (int i = 0; i < num_e; ++i) {
        std::cin >> t1 >> t2;
        g->add(t1, t2);
    }

    return g;
}

