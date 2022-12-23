int max(int const* input, int size) {
    int max = input[0];
    for (int i = 1; i < size; i++) {
        if (input[i] > max) {
            max = input[i];
        }
    }
    return max;
}
{}