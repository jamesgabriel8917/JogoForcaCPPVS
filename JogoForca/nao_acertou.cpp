#include "nao_acertou.hpp"


bool nao_acertou(std::map<char, bool>& chutou, const std::string& palavra_secreta){
    for(char letra : palavra_secreta){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}