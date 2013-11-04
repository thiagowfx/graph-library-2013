# Sobre template programming

* http://stackoverflow.com/questions/4100893/undefined-reference-to-template-members
* http://stackoverflow.com/questions/14914129/c-undefined-reference-to-template-class-method

```
#include <boost/assign/list_of.hpp> // std::vector<int> v = boost::assign::list_of(1)(2)(3)(4);
#include <boost/assign/std/vector.hpp> // for 'operator+=()'; // vector<int> values; values += 1,2,3,4,5,6,7,8,9; //insert values at the end of the container
using namespace boost::assign; // bring 'operator+=()' into scope
#include <boost/assert.hpp> // BOOST_ASSERT( true )
// v = {10,11} --std=c++11 way (flag to gcc)
```
