
/**
 * @file heap.cpp
 * Implementation of a heap class.
 */

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    /// @todo Update to return the index you are choosing to be your root.
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the left child.
    return 2*currentIdx;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the right child.
    return 2*currentIdx+1;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    /// @todo Update to return the index of the parent.
    return floor(currentIdx/2);
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    /// @todo Update to return whether the given node has a child
    return 2*currentIdx<=(_elems.size()-1);
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
    if(hasAChild(currentIdx) == false) return 0;
    
    if((2*currentIdx)==(_elems.size()-1)) return 2*currentIdx;
    
    else if(higherPriority(_elems[leftChild(currentIdx)],_elems[rightChild(currentIdx)])){
        return leftChild(currentIdx);
    }
    else return rightChild(currentIdx);
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    /// @todo Implement the heapifyDown algorithm.
    if(!hasAChild(currentIdx)) {
	return;
    }    
    size_t max = maxPriorityChild(currentIdx);
    if(higherPriority(_elems[max], _elems[currentIdx])){
        std::swap(_elems[max], _elems[currentIdx]);
        heapifyDown(max);
    }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    /// @todo Depending on your implementation, this function may or may
    ///   not need modifying
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems)
{
    /// @todo Construct a heap using the buildHeap algorithm
    if(elems.size()==0){
        _elems=elems;
    }
    else{
        typename std::vector<T> myvector=elems;
        typename std::vector<T>::iterator it=myvector.begin();
        myvector.insert(it,T());
        _elems=myvector;
        for(size_t i=(_elems.size()-1);i>=1;i--){
            heapifyDown(i);
        }
    }
}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    /// @todo Remove, and return, the element with highest priority
    if(empty()) return T();
    else{
        T value=_elems[1];
        _elems[1]=_elems[_elems.size()-1];
        _elems.pop_back();
        heapifyDown(1);
        return value;
    }
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    /// @todo Return, but do not remove, the element with highest priority
    if(!empty()){
        return _elems[1];
    }
    else return T();
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    /// @todo Add elem to the heap
    if(_elems.size()==0){
        _elems.push_back(T());
        _elems.push_back(elem);
    }
    else{
        _elems.push_back(elem);
        heapifyUp(_elems.size()-1);
    }
}

template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    /// @todo Determine if the heap is empty
    return _elems.size()==0 || _elems.size()==1;
}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}

