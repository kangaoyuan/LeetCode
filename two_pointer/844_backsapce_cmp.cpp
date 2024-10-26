#include "../headers.h" // IWYU pragma: keep

bool backspaceCompare(string s, string t) {
    uint read = 0, write = 0;
    while (read < s.size()) {
        if (s[read] == '#' && write > 0) {
            read++;
            write--;
        } else if (s[read] == '#' && write == 0) {
            read++;
        } else {
            s[write++] = s[read++];
        }
    }
    int res_loc1 = write;

    read = 0, write = 0;
    while (read < t.size()) {
        if (t[read] == '#' && write > 0) {
            read++;
            write--;
        } else if (t[read] == '#' && write == 0) {
            read++;
        } else {
            t[write++] = t[read++];
        }
    }
    int res_loc2 = write;

    if (res_loc1 == res_loc2) {
        for (uint i = 0; i < write; i++) {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }

    return false;
}
