
#ifndef FRACTION_H
#define FRACTION_H

// User-defined types are typically defined in header files, and then #included into any code file that requires that type definition


// Define a new type named Fraction
// This only defines what a Fraction looks like, it doesn't create one
// Note that this is a full definition, not a forward declaration, because
// the compiler typically needs to see the full definition to use a given type.
struct Fraction
{
	int numerator {};
	int denominator {};
};

#endi
