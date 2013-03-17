

template<class T>
class TArray {
public:
    TArray ();
    TArray (uint initialCapacity);
    
    void Add (const T & t);
    void Clear ();
    uint Count () const { return m_count; }
    T *  New ();
    void Remove (uint index);
    void SetCount (uint count);
    void Swap (TArray<T> * array);
    
    T *  Ptr () const { return m_data; }
    T *  End () const { return m_data + m_count; }
    
    T & operator [] (uint index);

private:
    void Grow ();
    void GrowTo (uint count);

private:
    T *  m_data;
    uint m_count;
    uint m_capacity;
};

template<class T>
TArray<T>::TArray () {

}

template<class T>
TArray<T>::TArray (uint initialCapacity)
  : m_count(0),
    m_capacity(initialCapacity)
{
    
}

template<class T>
void TArray<T>::Add (const T & t) {
    if (m_count == m_capacity)
        Grow();
    m_data[m_count] = t;
    ++m_count;
}

template<class T>
void TArray<T>::Clear () {
    delete [] m_data;
    m_data = NULL;
}

template<class T>
void TArray<T>::GrowTo (uint count) {
    if (count == 0) {
        Clear();
        return;
    }
    T * newData = new T[count];
    HeapReAlloc()
}

template<class T>
void TArray<T>::Grow () {
    if (m_capacity == 0)
        GrowTo(1);
    else
        GrowTo(m_capacity * 2);
}

template<class T>
void TArray<T>::SetCount (uint count) {
    GrowTo(count);
}

template<class T>
void TArray<T>::Swap (TArray<T> * array) {
    TSwap(m_data, array->m_data);
    TSwap(m_count, array->m_count);
    TSwap(m_capacity, array->m_capacity);
}
