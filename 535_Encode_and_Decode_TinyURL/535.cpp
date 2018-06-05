// The concise idea
class Solution {
    vector<string> url;
    int now = 0;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        url.push_back(longUrl);
        ++now;
        return to_string(now-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return url[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));




// My ugly Soultion
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string tmp, res;
        int i =0;
        
        // String before //
        for (;i<longUrl.length();++i){
            if (longUrl[i]=='/') { i += 2; break;}
            res+=longUrl[i];
        }
      
        // String before .com/
        for (;i<longUrl.length();++i) 
            if (longUrl[i]!='/') tmp+=longUrl[i];
            else break;
        
        v.push_back(tmp); ++num; tmp.resize(0);
        
        // string after .com/
       for (i+=1;i<longUrl.length();++i) 
            tmp += longUrl[i];        
        v.push_back(tmp); ++num; 
 
        res+=("//"+to_string(num-2)+"/"+to_string(num-1));
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {     
        string tmp, res;
        int i = 0;
        
        for (;i<shortUrl.length();++i)
        {
            if (shortUrl[i]=='/') 
            { i += 2; break;}
            res+=shortUrl[i];
        }
        for (;i<shortUrl.length();++i) 
            if (shortUrl[i]!='/') tmp+=shortUrl[i];
            else break;
        
        res+="//"+v[stoi(tmp)];
        tmp.resize(0);
        
        for (i+=1;i<shortUrl.size();++i) 
            tmp += shortUrl[i];
        
        res+="/"+v[stoi(tmp)];
        
        return res;
    }
private: 
    vector<string> v;
    int num = 0;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));