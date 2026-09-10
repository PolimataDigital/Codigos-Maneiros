#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

void formandoALista(vector <string> &listaDePalavras){
    while(true){
        
        int quantidade; 
        cout<<"Digite quantas palavras você quer colocar: \n";

        if(!(cin>>quantidade) || quantidade <=0){
            cout<<"Digite um número inteiro maior que zero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }

        for(int indicePalavra =0;indicePalavra<quantidade;indicePalavra++){
            
            while(true){
                
                cout<<"Insira uma palavra:\n";
        
                string palavraEscolhida;
                
                cin>>palavraEscolhida;
                
    
                bool soLetra=true;
                for (int indiceCaractere = 0; indiceCaractere<palavraEscolhida.size();indiceCaractere++){
                    if(!(isalpha(palavraEscolhida[indiceCaractere]))){
                        soLetra=false;
                    }
    
                }
                if(soLetra){
                    listaDePalavras.push_back(palavraEscolhida);
    
                }else{
                    cout<<"Digite apenas letras\n";
                    continue;
                }
                break;
            }

        }
        
        break;
    }

}

string verificadorDePrefixos(const vector <string> &listaDePalavras){
    string prefixo;

    for(int i =0; i<listaDePalavras[0].size();i++){
        char caractereReferencia = listaDePalavras[0][i];

        for(int j =1;j<listaDePalavras.size(); j++){
            if(i==listaDePalavras[j].size() || listaDePalavras[j][i]!= caractereReferencia){
                return prefixo;
            }
        }
        prefixo.push_back(caractereReferencia);
    }
    
   return prefixo;
}
    

int main() {
    vector <string> listaDePalavras;
    
    formandoALista(listaDePalavras);

    string resultado = verificadorDePrefixos(listaDePalavras);

    if (resultado.empty()) {
        cout << "Nao existe prefixo comum.\n";
    } else {
        cout << "Prefixo encontrado: " << resultado << "\n";
    }

    return 0;
}
