class Solution {
public:
    string reverseWords(string s) {
		// append a blank character at end of string to track words by blank
        s += " ";
		
        char temp;
        int i = 0, j, size = s.length(), saveIndex;
        
        while(i < size)
        {
            j = i;
            
			// keep going till blank space is encountered
            while(s[j] != ' ')
                j++;
				
			// save this index since the next will start from this index + 1 i.e., later i = saveIndex + 1;
            saveIndex = j;
            
			// come back to the last letter of the word, currently j was at blank space's index
            --j;
			
			// simply reverse the word elements now from i to j
            while(i < j)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                ++i; --j;
            }            
			
            i = saveIndex + 1;
        }
        s.pop_back();
        return s;
    }
};