 string convertToTitle(int columnNumber) {

        string res = "";
        
        while(columnNumber){
            columnNumber--;
            char ch = 'A' + columnNumber % 26;
            res += ch;
            columnNumber = columnNumber/26;
        }

        reverse(res.begin(),res.end());

        return res;
        
}
