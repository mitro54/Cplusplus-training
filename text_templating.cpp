#include <iostream>
#include <string>

std::string key_formatter(std::string k) {
   return k.insert(0, 1, '[').insert(k.length(), 1, ']');
}

std::string val_processor(std::string vals, std::string txt_template) {
    std::string curr_val, key, keys_val;
    for (int i = 0; i < vals.length(); i++) {
        if (vals.find(',') != std::string::npos) {
            curr_val = vals.substr(0, vals.find(','));
            key = curr_val.substr(0, vals.find('='));
            keys_val = curr_val.substr(vals.find('=') + 1);
            vals.erase(0, curr_val.length() + 1);
            i = 0;
        } else {
            curr_val = vals;
            key = curr_val.substr(0, vals.find('='));
            keys_val = curr_val.substr(vals.find('=') + 1);
            int start_pos = txt_template.find(key_formatter(key));
            txt_template.replace(start_pos, key_formatter(key).length(), keys_val);
            if (txt_template.find(key_formatter(key)) != std::string::npos) continue;
            else break;
        }
        int start_pos = txt_template.find(key_formatter(key));
        txt_template.replace(start_pos, key_formatter(key).length(), keys_val);
    }
    return txt_template;
}

int main(void) {
    std::cout << "Text template translator. First set a template like person=John,action=meet\n";
    std::cout << "then give a text, example: Hello [person], its nice to [action] you.\n";
    std::cout << "It is translated to Hello John, its nice to meet you.\n";
    std::cout << "Set a template: ";
    std::string values;
    std::getline(std::cin, values);

    std::cout << "Give a text: ";
    std::string txt_template;
    std::getline(std::cin, txt_template);
    std::cout << val_processor(values, txt_template) << "\n";
    return 0;
}