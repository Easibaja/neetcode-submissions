class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encoded = "";

        for (const std::string& sentence : strs) {
            encoded += "%" + std::to_string(sentence.size()) + "%" + sentence;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        std::vector<std::string> strs;

        while (!s.empty()) {
            short end = s.find('%', 1);
            int length = std::stoi(s.substr(1, end - 1));
            strs.push_back(s.substr(end + 1, length));
            s = s.substr(end + 1 + length);
        }
        return strs;
    }
};
