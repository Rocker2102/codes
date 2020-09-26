class Solution {
    static int roman(char c){
        int n=0;
        switch(c){
            case 'I': n=1;
                break;
            case 'V': n=5;
                break;
            case 'X': n=10;
                break;
            case 'L': n=50;
                break;
            case 'C': n=100;
                break;
            case 'D': n=500;
                break;
            case 'M': n=1000;
                break;
        }
        return n;
    }
    public int romanToInt(String s) {
        
        int total=0,i;
        for(i=0;i<s.length()-1;i++){
            int curr=roman(s.charAt(i));
            int next=roman(s.charAt(i+1));
            if(curr<next){
                total+=(next-curr);
                i++;
            }
            else{
                total+=curr;
            }
        }
        if(i==s.length()-1)
            return total+roman(s.charAt(s.length()-1));
        else
            return total;
    }
}
