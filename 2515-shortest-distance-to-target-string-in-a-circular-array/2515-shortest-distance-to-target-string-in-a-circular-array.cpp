class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int size = words.size();
        int leftPtr = startIndex, rightPtr = startIndex;
        int distance = 0;

        while(true) {
            if(words[leftPtr] == target || words[rightPtr] == target) {
                return distance;
            }    

            leftPtr = (leftPtr - 1 + size) % size;
            rightPtr = (rightPtr + 1) % size;
            distance++;

            if(leftPtr == rightPtr) { 
                if(words[leftPtr] == target) {
                    return distance;
                }    
                break;
            }
        }

        return -1;
    }
};