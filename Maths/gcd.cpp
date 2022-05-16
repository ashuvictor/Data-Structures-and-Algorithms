


Euclidean algorithm for computing the greatest common divisor

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}
