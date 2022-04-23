class Solution {
public:
    unordered_map <int, string> enc;
    int count = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        count++;
        enc[count] = longUrl;
        return to_string(count);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        return enc[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));