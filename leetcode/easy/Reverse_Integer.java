class Solution {
    public int reverse(int x) {
        long n=0;
        while(x!=0){
            n=(x%10) + (n*10);
            x=x/10;
        }
        if(n<=Integer.MAX_VALUE && n>=Integer.MIN_VALUE){
            x=(int)n;
            return x;
        }
        else{
            return 0;
        }
    }
}
