// Tim Mertogul
// tmertogu@ucsc.edu
// Michael Lowe
// mimlowe@ucsc.edu
// CMPS109
// Spring 2015
// ASG 2

// $Id: bigint.h,v 1.16 2014-07-02 20:01:17-07 - - $

#ifndef __BIGINT_H__
#define __BIGINT_H__

#include <exception>
#include <iostream>
#include <utility>
using namespace std;

#include "debug.h"

//
// Define class bigint
//
using digit_t = unsigned char;
using bigvalue_t = vector<digit_t>;

class bigint {
    friend ostream& operator<< (ostream&, const bigint&);
private:
    
    long long_value {};

    bigvalue_t op_value;
    void init (const string& that);
    using quot_rem = pair<bigint,bigint>;
    using unumber = unsigned long;
    friend quot_rem divide (const bigint&, const bigint&);
    friend void multiply_by_2 (unumber&);
    friend void divide_by_2 (unumber&);

public:

    //
    // Ensure synthesized members are genrated.
    //
    bigint() = default;
    bigint (const bigint&) = default;
    bigint (bigint&&) = default;
    bigint& operator= (const bigint&) = default;
    bigint& operator= (bigint&&) = default;
    ~bigint() = default;
    
    bigvalue_t big_value;
    bool negative;
    //
    // Extra ctors to make bigints.
    //
    bigint (const long);
    bigint (const string&);
    
    //
    // Big Operators
    //
    bigvalue_t do_bigadd (const bigvalue_t& left, const bigvalue_t& 
                                                               right);
    bigvalue_t do_bigsub(const bigvalue_t& left, const bigvalue_t& 
                                                               right);
    bool do_bigless(const bigvalue_t& left, const bigvalue_t& right);
    
    bigvalue_t do_bigmul (const bigvalue_t& left, const bigvalue_t&
                                                               right);
    //
    // Basic add/sub operators.
    //
    friend bigint operator+ (const bigint&, const bigint&);
    friend bigint operator- (const bigint&, const bigint&);
    friend bigint operator+ (const bigint&);
    friend bigint operator- (const bigint&);
    bool to_long() const;
    long exp_long() const;
    
    //
    // Extended operators implemented with add/sub.
    //
    friend bigint operator* (const bigint&, const bigint&);
    friend bigint operator/ (const bigint&, const bigint&);
    friend bigint operator% (const bigint&, const bigint&);
    
    //
    // Comparison operators.
    //
    friend bool operator== (const bigint&, const bigint&);
    friend bool operator<  (const bigint&, const bigint&);
};

//
// The rest of the operators do not need to be friends.
// Make the comparisons inline for efficiency.
//
//bigvalue_t equals(const bigvalue_t& that);
bigint signInt(bigint result);
bigint pow (const bigint& base, const bigint& exponent);

inline bool operator!= (const bigint &left, const bigint &right) {
    return not (left == right);
}
inline bool operator>  (const bigint &left, const bigint &right) {
    return right < left;
}
inline bool operator<= (const bigint &left, const bigint &right) {
    return not (right < left);
}
inline bool operator>= (const bigint &left, const bigint &right) {
    return not (left < right);
}

#endif
