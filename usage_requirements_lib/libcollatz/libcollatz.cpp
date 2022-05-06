
int update(int& in) {
    if (in % 2 == 0) {
        in /= 2;
    } else {
        in = (3 * in) + 1;
    }
    return in;
}

int updateFast(int& in) {
    if(in % 2 == 0) {
        return in/2;
    } else {
        return ((3*in) + 1) / 2;
    }
}