(0xB6DB6DB6)16 = (10110110110110110110110110110110)2
bool checkPowerOf8(unsigned n)
{
    // return true if `n` is a power of 2, and its only
    // set bit is present at (0, 3, 6, … ) position
    return n && !(n & (n - 1)) && !(n & 0xB6DB6DB6);
}