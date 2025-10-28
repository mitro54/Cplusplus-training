#include <iostream>
#include <string>

std::string key_formatter(std::string k) {
   return k.insert(0, 1, '[').insert(k.length(), 1, ']');
}

std::string val_processor(std::string vals, std::string txt_template) {
    std::string curr_val, key, keys_val, newstr;
    for (int i = 0; i < vals.length(); i++) {
        if (vals.find(',') != std::string::npos) {
            curr_val = vals.substr(i, vals.find(','));
            key = curr_val.substr(0, vals.find('='));
            keys_val = curr_val.substr(vals.find('=') + 1);
            vals.erase(i, vals.find(',') + 1);
        } else {
            curr_val = vals;
            key = curr_val.substr(0, vals.find('='));
            keys_val = curr_val.substr(vals.find('=') + 1);
            int start_pos = txt_template.find(key_formatter(key));
            txt_template.replace(start_pos, key_formatter(key).length(), keys_val);
            break;
        }
        int start_pos = txt_template.find(key_formatter(key));
        txt_template.replace(start_pos, key_formatter(key).length(), keys_val);
    }
    return txt_template;
}

int main(void) {
    std::string values;
    // std::getline(std::cin, values);

    std::string txt_template;
    // std::getline(std::cin, txt_template);
    values = "place=world,type=beautiful";
    txt_template = "say hello to [place] friend, isnt it [type] here?";

    // Put values into the template
    std::cout << val_processor(values, txt_template) << "\n"; 
    return 0;
}