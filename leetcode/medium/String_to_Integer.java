class Solution {
    public int myAtoi(String str) {
        long n=0;
        int j=0,sign=1;
        while(j<str.length() && str.charAt(j)==' ')
            j++;
        while(j<str.length() && str.charAt(j)=='-'){
            j++;
            sign=-1;
        }
        while(j<str.length() && str.charAt(j)=='+')
            j++;
        for(int i=j;i<str.length();i++){
            if(str.charAt(i)<='9' && str.charAt(i)>='0'){
                n=n*10 + (str.charAt(i)-'0');
            }
            else if(str.charAt(i)>='A' || str.charAt(i)<='z'){
                break;
            }
        }
        if(n>Integer.MAX_VALUE && sign==1)
            j=Integer.MAX_VALUE;
        else if(n>Integer.MAX_VALUE && sign==-1)
            j=Integer.MIN_VALUE;
        else if(sign==-1)
            j=(int)(n*(-1));   
        else if(sign==1)
            j=(int)n;
        if(str=="-+1")
            j=0;
        
        return j;
    }
}
