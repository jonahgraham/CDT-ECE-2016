int main(void) {
	int X = 0;
	int a = 0;
	X = X; // @suppress("Assignment to itself")
	if (X = a) { // @suppress("Assignment in condition")
	}
	if (X = X) { // @suppress("Assignment in condition")  // @suppress("Assignment to itself")
	}
	return X;
}
