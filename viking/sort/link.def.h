struct snode
{
    int key;
    int next;
};

struct slink
{
    snode * vect;
    int key_count;
};

slink * build_links(int * arr, int n);

void dump(int * arr, slink * s);

void free_slink(slink * s);
