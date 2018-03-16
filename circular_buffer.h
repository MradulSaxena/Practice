//
//  circular_buffer.h
//  XCODE
//
//  Created by Mradul Saxena on 3/16/18.
//  Copyright © 2018 Mradul Saxena. All rights reserved.
//

#ifndef circular_buffer_h
#define circular_buffer_h

template <class T>
class circularBuffer {
public:
    circularBuffer(int size) : _size(size),
    _buf(std::unique_ptr<T[]>(new T(size))){
        //nothing in it
    }
    
    //
    // we read from the tail
    //
    T get (void) {
        std::lock_guard<std::mutex> lock(_mutex);
        
        //Read data and advance the tail (we now have a free space)
        auto val = _buf[_tail];
        _tail    = (_tail + 1) % _size;
        return val;
    }
    
    //
    // we write to the head
    //
    void put (T data) {
        std::lock_guard<std::mutex> lock(_mutex);
        _buf[_head] = data;
        _head       = (_head + 1) % _size;
        
        if (_head == _tail) {
            _tail = (_tail + 1) % _size;
        }
    }
    
    void reset (void) {
        std::lock_guard<std::mutex> lock(_mutex);
        _head = _tail;
    }
    
    //
    // if tail is one ahead of the head then we are full
    //
    bool full (void) {
        if (((_head+1) %_size) == _tail) {
            return true;
        }
        
        return false;
    }
    
    //
    // if the head and tail are equal we are empty
    //
    bool empty (void) {
        if (_head == _tail) {
            return true;
        }
        return false;
    }
    
private:
    size_t _head{0};
    size_t _tail{0};
    std::unique_ptr<T[]> _buf;
    std::mutex _mutex;
    size_t _size;
};

void
test_circular_buffer (void);
#endif /* circular_buffer_h */

