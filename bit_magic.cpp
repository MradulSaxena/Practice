//
//  bit_magic.cpp
//  XCODE
//
//  Created by Mradul Saxena on 12/9/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#include "common_incl.h"


u_int32_t bitwise_add (u_int32_t a, u_int32_t b)
{
    u_int32_t temp_a = a;
    u_int32_t temp_b = b;
    u_int32_t carry_in = 0;
    u_int32_t sum = 0;
    u_int32_t k = 1;
    while(temp_a || temp_b) {
        
        u_int32_t a_k = (a & k);
        u_int32_t b_k = (b & k);
        u_int32_t carry_out = ((a_k & carry_in) | (a_k & b_k) | (b_k & carry_in));

        sum |= (a_k ^ b_k ^ carry_in);
        
        temp_a >>= 1;
        temp_b >>= 1;
        
        carry_in = (carry_out << 1);
        k <<= 1;
    }
    
    return (sum | carry_in);
}

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

void test_bit_magic (void)

{
    cout<<"\nAdd using bit wise operators\n";
    cout<<bitwise_add(5,7);
    cout<<endl;
    
    
    cout<<"\nMultiply using bit wise operators\n";
    cout<<bitwise_multiply(5,7);
    cout<<endl;
}
