//
//  bit_magic.cpp
//  XCODE
//
//  Created by Mradul Saxena on 12/9/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#include "common_incl.h"
#include "stddef.h"
#include <stdlib.h>

u_int32_t bitwise_add (u_int32_t a, u_int32_t b)
{
    int partialSum, carry;
    do {
        partialSum = a ^ b;
        carry = (a & b) << 1;
        a = partialSum;
        b = carry;
    } while (carry != 0);
    
    return partialSum;
}

//
//bitwise_multiply : this function multiplies two unsigned numbers using
//                   bitwise operations.idea is to add 2^k*b to the sum for
//                   every kth bit that is set in a
//
u_int32_t bitwise_multiply (u_int32_t a, u_int32_t b)
{
    int sum=0;
    
    while(a) {
        if (a & 1) {
            sum = bitwise_add(sum, b);
        }
        
        a>>=1;
        b<<=1;
    }
    
    return sum;
}

int bitwise_division(int x, int y)
{
    int result = 0;
    int power = 32;
    int y_power = (y << power);
    
    while (x>=y) {
        while (y_power > x) {
            y_power >>= 1;
            --power;
        }
        
        x = x-y_power;
        result += 1;
    }
    
    return result;
}

int bitwise_subtract(int a, int b) {
    return bitwise_add(a, bitwise_add(~b, 1));
}

void* aligned_malloc (int size, int alignment)
{
    void *p1, *p2;
    
    //get the total size from malloc
    p1 = (void *) malloc(size+alignment+sizeof(size_t));
    size_t addr = (size_t)p1 + alignment + sizeof(size_t);
    p2 = (void *) (addr - (addr%alignment));
    *((size_t *)p2-1) = (size_t)p1;
    
    return p2;
}

void
aligned_free(void *p)
{
    cout << "Address is "<<p<<endl;
    
    free((void *)(*((size_t *)p - 1)));
}
void test_bit_magic (void)

{
    cout<<"\nAdd using bit wise operators\n";
    cout<<bitwise_add(5,17);
    cout<<endl;
    
    cout<<"\nSubtract using bit wise operators\n";
    cout<<bitwise_subtract(5,17);
    cout<<endl;
    
    cout<<"\nMultiply using bit wise operators\n";
    cout<<bitwise_multiply(5,7);
    cout<<endl;
    
    cout<<"\nDivision using bit wise operators\n";
    cout<<bitwise_division(87,5);
    cout<<endl;
    
    cout<<"\nAligned Malloc\n";
    void *p = aligned_malloc(30,10);
    cout << p;
    cout << endl;
    
    cout<<"\nAligned Free\n";
    aligned_free(p);
    cout<<endl;
}
