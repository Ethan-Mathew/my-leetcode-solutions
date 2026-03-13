class Solution {
public:
    string simplifyPath(string path) {
        std::vector<std::string> pathDirs;
        pathDirs.reserve(1000);
        int ptr = 0;
        int consecutiveDots = 0;
        std::string dirNameBuffer = "";
        path += "/";

        while (ptr < path.length()) {
            if (path[ptr] == '/') {
                std::cout << dirNameBuffer << '\n';
                if (dirNameBuffer == ".." && pathDirs.size() > 0) {
                    pathDirs.pop_back();
                } else if (dirNameBuffer.length() > 0 && dirNameBuffer != "." && dirNameBuffer != "..") {
                    pathDirs.push_back(dirNameBuffer);
                }

                dirNameBuffer = "";

            } else {
                dirNameBuffer += path[ptr];
            }

            ptr++;
        }

        std::string finalPath = "/";
        for (const std::string& str : pathDirs) {
            finalPath += str;
            finalPath += "/";
        }

        if (finalPath != "/") {
            finalPath.pop_back();
        }

        return finalPath;
    }
};