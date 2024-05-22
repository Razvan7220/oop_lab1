#include <iostream>
#include<algorithm>
using namespace std;

template <typename K, typename V>
class Map
{
private:
    struct pereche
    {
        K Key;
        V Value;
    };

    int count = 0;
    int nrElemente = 1000;
    pereche* map;

public:
    Map() : map(new pereche[nrElemente]) {}

    ~Map()
    {
        delete[] map;
    }

    V& operator[](const K& Key)
    {
        return Set(Key, V{});
    }

    V& Set(const K& Key, const V& Value)
    {
        for (int i = 0; i < count; i++)
        {
            if (map[i].Key == Key)
            {
                map[i].Value = Value;
                return map[i].Value;
            }
        }

        if (count >= nrElemente)
        {
            cout << "Map size exceeded";
        }

        map[count].Key = Key;
        map[count].Value = Value;
        return map[count++].Value;
    }

    bool Get(const K& key, V& value)
    {
        for (int i = 0; i < count; i++)
        {
            if (map[i].Key == key)
            {
                value = map[i].Value;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& other)
    {
        for (int i = 0; i < other.count; i++)
        {
            bool found = false;
            for (int j = 0; j < count; j++)
                if (map[j].Key == other.map[i].Key)
                {
                    found = true;
                    break;
                }

            if (!found)
                return false;
        }
        return true;
    }

    void Clear()
    {
        delete[] map;
        map = new pereche[nrElemente];
        count = 0;
    }

    int Count()
    {
        return count;
    }

    bool Delete(const K& key)
    {
        for (int i = 0; i < count; i++)
        {
            if (map[i].Key == key)
            {
                for (int j = i; j < count - 1; j++)
                    map[j] = map[j + 1];//shiftam

                count--;
                return true;
            }
        }
        return false;
    }

    class iterator
    {
    private:
        pereche* ptr;
        int index;

    public:
        iterator(pereche* p, int idx = 0) : ptr(p), index(idx) {}

        iterator& operator++()
        {
            ++ptr;
            ++index;
            return *this;
        }

        bool operator!=(const iterator& other)
        {
            return ptr != other.ptr;
        }

        auto operator*()
        {
            return make_tuple(ptr->Key, ptr->Value, index);
        }
    };

    iterator begin()
    {
        return iterator(&map[0], 0);
    }

    iterator end()
    {
        return iterator(&map[count], count);
    }
};


int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    //for(iterator i=m.begin();i!=m.end();i++)
    //auto key=(*i).key
    //auto value=(*i).value
    //auto index=(*i).index
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m.Clear();
    cout << '\n';
    m.Set(11, "ce faci");
    m.Set(12, "bine");
    const char* r;
    m.Get(11, r);
    m.Delete(11);
    cout << r << '\n';
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }


    Map<int, const char*>m1; Map<int, const char*>m2;
    m1[10] = "C++";
    m1[20] = "test";
    m1[30] = "Poo";
    m1[40] = "SO";
    m1[50] = "PA";

    m2[10] = "gcc";
    m2[20] = "g++";
    m2[31] = "cl";
    cout << m1.Includes(m2);


    return 0;
}