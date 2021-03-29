/*
cwd, args -> dest

cd("/a/b", "c/../d") -> "/a/b/d"
cd("/a/b", "c/d")    -> "/a/b/c/d"
cd("/a/b", "/c/d")   -> "/c/d"
cd("/a/b", "../../../../../") -> "/"


cwd:  /a/b
args:   c/../d
1: c -> /a/b/c
2: .. -> /a/b
3: d  -> /a/b/d

cwd:   /a/b
args:  /c/d
1: /  -> /
2: c  -> /c
3: d  -> /c/d

*/

// split("1/2/3", '/')  -> ["1", "2", "3"]
// "1,2,3,4,5" -> split("1,2,3,4,5", ',') -> ["1", "2", "3", "4", "5"]
std::vector<std::string> split(std::string &input, std::string &separator);

// join(["1", "2"], "/") -> "1/2"
std::string join(std::vector<std::string> &input, std::string &separator);


// Complexity:
// time: O(N + M)
// space: O(~ N + M)

std::string cd_command(std::string &cwd, std::string &args)
{
    // No arguments, nothing happens, we stay where we are.
    if (args.size() == 0) {
        return cwd;
    }
    
    std::vector<std::string> current_path = {};
    if (args[0] == '/') {
        current_path = {};
    }
    else {
        // O(cwd)
        current_path = split(cwd, '/');
    }
    
    // O(args)
    std::vector<std::string> args_tokens = split(args, '/');
    
    // < O(args)
    for (std::string &token : args_tokens) {
        // Empty string or '.' means do nothing
        if (token == '' || token == '.') {
            continue;
        }
        // .. means go up.
        else if (token == '..' && current_path.size() != 0) {
            current_path.pop_back();
        }
        // valid directory!
        else {
            current_path.push_back(token);
        }
    }
    
    // At this point, we resolved the arguments onto the current path
    // and we need to convert the vector back to a single string (destination)
    std::string final_path = join(current_path, "/");
    final_path = "/" + final_path;
    
    return final_path;
}
