#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Declaração da classe base abstrata chamada Lista.
class Lista {
public:
    // Método virtual puro para adicionar um valor à lista.
    virtual void adicionar(const string& valor) = 0;

    // Método virtual puro para determinar a mediana dos valores na lista.
    virtual string mediana() const = 0;

    // Método virtual puro para listar todos os valores da lista em ordem.
    virtual void listarEmOrdem() const = 0;

    // Método virtual puro para exibir os primeiros N elementos da lista.
    virtual void exibirPrimeirosN(size_t quantidade) const = 0;

    // Destrutor virtual.
    virtual ~Lista() {}
};

// Declaração da classe ListaData que herda de Lista.
class ListaData : public Lista {
private:
    vector<string> datas;

public:
    void adicionar(const string& valor) override {
        datas.push_back(valor);
        sort(datas.begin(), datas.end());
    }

    string mediana() const override {
        if (datas.empty()) return "";
        size_t posicaoMeio = datas.size() / 2;
        if (datas.size() % 2 == 0) {
            return datas[posicaoMeio - 1];
        } else {
            return datas[posicaoMeio];
        }
    }

    void listarEmOrdem() const override {
        for (const string& data : datas) {
            cout << data << " ";
        }
        cout << endl;
    }

    void exibirPrimeirosN(size_t quantidade) const override {
        for (size_t i = 0; i < min(quantidade, datas.size()); ++i) {
            cout << datas[i] << " ";
        }
        cout << endl;
    }
};

// Esboço das classes ListaNomes, ListaSalarios e ListaIdades.
class ListaNomes : public Lista { /* Implementação semelhante à ListaData */ };
class ListaSalarios : public Lista { /* Implementação semelhante à ListaData */ };
class ListaIdades : public Lista { /* Implementação semelhante à ListaData */ };

int main() {
    vector<Lista*> listas;

    int opcao;
    do {
        cout << "MENU - DataFruta\n";
        cout << "1. Adicionar data\n";
        cout << "2. Adicionar nome\n";
        cout << "3. Adicionar salário\n";
        cout << "4. Adicionar idade\n";
        cout << "5. Listar todos os valores de cada lista\n";
        cout << "6. Exibir primeiros N elementos de cada lista\n";
        cout << "7. Sair\n";
        cout << "Digite sua opção: ";
        cin >> opcao;

        string entradaValor;
        size_t quantidade;

        switch (opcao) {
            case 1:
                cout << "Digite a data (formato YYYY-MM-DD): ";
                cin >> entradaValor;
                // Adicione a data à lista de datas.
                break;

            case 2:
                cout << "Digite o nome: ";
                cin >> entradaValor;
                // Adicione o nome à lista de nomes.
                break;

            case 3:
                cout << "Digite o salário: ";
                cin >> entradaValor;
                // Adicione o salário à lista de salários.
                break;

            case 4:
                cout << "Digite a idade: ";
                cin >> entradaValor;
                // Adicione a idade à lista de idades.
                break;

            case 5:
                cout << "Listando todos os valores:\n";
                for (Lista* lista : listas) {
                    lista->listarEmOrdem();
                }
                break;

            case 6:
                cout << "Digite a quantidade N: ";
                cin >> quantidade;
                for (Lista* lista : listas) {
                    lista->exibirPrimeirosN(quantidade);
                }
                break;

            case 7:
                cout << "Saindo...\n";
                break;

            default:
                cout << "Opção inválida! Tente novamente.\n";
                break;
        }
    } while (opcao != 7);

    // Liberação da memória alocada para as listas.
    for (Lista* lista : listas) {
        delete lista;
    }

    return 0;
}
