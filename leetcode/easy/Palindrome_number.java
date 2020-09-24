class Solution {
    public boolean isPalindrome(int x) {
        if(x<0)
            return false;
        else{
            int n=0,t=x;
            while(x!=0){
                n=n*10 + x%10;
                x=x/10;
            }
            if(t==n)
                return true;
            else
                return false;
        }
    }
}
