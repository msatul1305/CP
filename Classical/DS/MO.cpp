/*
 * https://www.hackerearth.com/practice/notes/mos-algorithm/ 
 * https://blog.anudeep2011.com/mos-algorithm/
 * 
 * NOTES:
 * Sort according to block-size.
 * if two queries belong to the same block, sort according to endingR.
 */

bz = sqrt(n);//block-size

struct Q {
	int l, r, idx;
	bool operator<(const Q &rhs) {
		if(l/bz != rhs.l/bz) {
			return l/bz < rhs.l/bz;
		}
		return r < rhs.r;
	}
};

