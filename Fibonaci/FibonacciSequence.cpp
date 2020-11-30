#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"

#include <stdexcept>

using namespace std;
FibonacciSequence::FibonacciSequence(unsigned long aLimit) {
	fPrevious = 0;
	fCurrent = 1;
	fPosition = 1;
	fLimit = aLimit;
}
const unsigned long& FibonacciSequence::current() const {
	return fCurrent;
}
void FibonacciSequence::advance() {
	if (fLimit == 0 || fPosition <= fLimit) {
		unsigned long lNext = fCurrent + fPrevious;
		fPrevious = fCurrent;
		fCurrent = lNext;
		fPosition++;
	}
	else {
		throw out_of_range("Fibonacci sequence limit exceeded");
	}
}
const unsigned long& FibonacciSequence::getLimit() const {
	return fLimit;
}
FibonacciSequenceIterator FibonacciSequence::begin() {
	fPrevious = 0;
	fCurrent = 1;
	fPosition = 1;
	return FibonacciSequenceIterator(*this, fPosition);
}
FibonacciSequenceIterator FibonacciSequence::end() {
	return FibonacciSequenceIterator(*this, fLimit + 1);
}