#include <iostream>
#include <string>

std::string key_formatter(std::string k) {
   return k.insert(0, 1, '[').insert(k.length(), 1, ']');
}

std::string val_processor(std::string vals) {
    std::string curr_val, key, keys_val;
    for (int i = 0; i < vals.length(); i++) {
        if (vals.find(',') != std::string::npos) {
            curr_val = vals.substr(i, vals.find(','));
            key = curr_val.substr(0, vals.find('='));
            keys_val = curr_val.substr(vals.find('=') + 1);

            std::cout << curr_val << "\n";
            std::cout << key << "\n";
            std::cout << keys_val << "\n";
            std::cout << key_formatter(key) << "\n";
            break;
        }
    }
    return "thenewstring";
}

int main(void) {
    std::string values;
    std::getline(std::cin, values);

    std::string txt_template;
    std::getline(std::cin, txt_template);

    // Put values into the template
    val_processor(values);

    //std::cout << txt_template << "\n"; 
    return 0;
}