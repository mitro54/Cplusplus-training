#include <iostream>
#include <string>

std::string val_processor(std::string vals) {
    std::string curr_val;
    for (int i = 0; i < vals.length(); i++) {
        if (vals.find(',') != std::string::npos) {
            curr_val = vals.substr(i, vals.find(','));
        }
    }
}

int main(void) {
    std::string values;
    std::getline(std::cin, values);

    std::string txt_template;
    std::getline(std::cin, txt_template);



    std::cout << txt_template << "\n"; 
    return 0;
}