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
   
Additional Details
* [ ] ```const``` [Stackoverflow Answer](http://stackoverflow.com/questions/4622330/operator-overloading-member-function-vs-non-member-function)

* [ ] ```virtual```
When calling a function using pointers or references, the following rules apply:
 * A call to a virtual function is resolved according to the underlying type of object for which it is called.
 * A call to a nonvirtual function is resolved according to the type of the pointer or reference.

