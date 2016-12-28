# CaltechCS11
This repo holds the Cpp examples from CS11 course from Caltech.
http://courses.cms.caltech.edu/cs11/material/advcpp/

I'll use this page to track my progress and collect new information.

   * Operator Overloading
      * Member Operator Overload
      * Non-member Operator Overload

   * Overloading Typecasts

   * Overload Guidelines
      * (),[], -> : Must be member functions
      * Compound assignment operators (+=, -=, \*=, /=, %=,&=,... ): Should be member functions
      * << and >> : Cannot be member functions

TODO
   * Constructor Details
   * Why should compund assignment operators be implemented as member functions?
   * Read in detail about casting in cpp in reference to classes.
   
Additional Details
* [ ] ```const``` [Stackoverflow Answer](http://stackoverflow.com/questions/4622330/operator-overloading-member-function-vs-non-member-function)

* [ ] ```virtual```
When calling a function using pointers or references, the following rules apply:
 * A call to a virtual function is resolved according to the underlying type of object for which it is called.
 * A call to a nonvirtual function is resolved according to the type of the pointer or reference.


* [ ] ```const pointers```
I would like to append a rule of thumb which may help you remember how to discover whether 'const' applies to pointer or to pointed data: split the statement at asterix sign, then, if the const keyword appears in the left part (like in 'const int * foo') - it belongs to pointed data, if it's in the right part ('int * const bar') - it's about the pointer. – Michael Jul 17 '09 at 17:26. [Stackoverflow Answer](http://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const)
