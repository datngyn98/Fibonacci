#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"

FibonacciSequenceIterator::FibonacciSequenceIterator(FibonacciSequence& aSequenceObject, unsigned long aStart): fSequenceObject(aSequenceObject), fIndex(aStart) {
}
const unsigned long& FibonacciSequenceIterator::operator*() const {
	return fSequenceObject.current();
}
FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() {
	fSequenceObject.advance();
	fIndex++;
	return *this;
}
FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) {
	FibonacciSequenceIterator result = *this;
	++(*this);
	return result;
}
bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const {
	return (fIndex == aOther.fIndex);
}
bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator& aOther) const {
	return !(*this == aOther);
}
FibonacciSequenceIterator FibonacciSequenceIterator::begin() const {
	return fSequenceObject.begin();
}
FibonacciSequenceIterator FibonacciSequenceIterator::end() const {
	return fSequenceObject.end();
}