class Solution {
public:
    int computeArea(long A, long B, long C, long D, long E, long F, long G, long H) {
        long area1=(C-A)*(D-B);
        long area2=(G-E)*(H-F);

        long ox1=max(A,E);
        long oy1=max(B,F);
        long ox2=min(C,G);
        long oy2=min(D,H);
        
        long s1=ox2-ox1;
        long s2=oy2-oy1;
        long overlap=0;
        if(s1>0 && s2>0)
            overlap=s1*s2;

        return area1+area2-overlap;
    }
};