#include <iostream>
#include <string>
#include <map>
#include <array>
#include "imprime_cabecalho.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "chuta.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "adiciona_palavra.hpp"
#include "nao_acertou.hpp"

using namespace std;
using namespace Forca;

static string palavra_secreta;
map<char, bool> chutou;
int value = 0;
int* arraySize = &value;
std::array<char, 5>* chutes_errados = new std::array<char, 5> {}; // Inicialização com array vazio



int main()
{
    imprime_cabecalho();

    palavra_secreta = sorteia_palavra();

    while(nao_acertou(palavra_secreta, chutou) && *arraySize < 5) {
        imprime_erros(*chutes_errados);

        imprime_palavra(palavra_secreta, chutou);

        chuta(chutou, *chutes_errados, *arraySize, palavra_secreta);
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if(nao_acertou(palavra_secreta, chutou)){
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;

        cout << "Você deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        }
    }

    cin.get();
}