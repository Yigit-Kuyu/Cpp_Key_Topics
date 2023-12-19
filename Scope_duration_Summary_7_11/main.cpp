
/*
// Duration Summary:

-Variables with automatic duration are created at the point of definition, and destroyed when the block they are part of is exited. This includes:
Local variables
Function parameters

-Variables with static duration are created when the program begins and destroyed when the program ends. This includes:
Global variables
Static local variables

-Variables with dynamic duration are created and destroyed by programmer request. This includes:
Dynamically allocated variables

*/


/*
// Linkage Summary:


-An identifier with no linkage means the identifier only refers to itself. This includes:
Local variables
Program-defined type definitions (such as enums and classes) declared inside a block

-An identifier with internal linkage can be accessed anywhere within the file it is declared. This includes:
Static global variables (initialized or uninitialized)
Static functions
Const global variables
Functions declared inside an unnamed namespace
Program-defined type definitions (such as enums and classes) declared inside an unnamed namespace

-An identifier with external linkage can be accessed anywhere within the file it is declared, or other files (via a forward declaration). This includes:
Functions
Non-const global variables (initialized or uninitialized)
Extern const global variables
Inline const global variables


*/


// Related page: https://www.learncpp.com/cpp-tutorial/scope-duration-and-linkage-summary/
