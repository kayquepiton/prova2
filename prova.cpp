#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Declaração da classe base abstrata chamada Lista.
class Lista {
public:
    virtual void adicionar(const string& valor) = 0;
    virtual string mediana() const = 0;
    virtual void listarEmOrdem() const = 0;
    virtual void exibirPrimeirosN(size_t quantidade) const = 0;
    virtual ~Lista() {}
};

// Implementação da classe ListaData
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

// Implementação da classe ListaNomes semelhante à ListaData
class ListaNomes : public Lista {
private:
    vector<string> nomes;
public:
    // Métodos similares aos da classe ListaData, mas para nomes
    void adicionar(const string& valor) override {
        nomes.push_back(valor);
        sort(nomes.begin(), nomes.end());
    }
    string mediana() const override {
        if (nomes.empty()) return "";
        size_t posicaoMeio = nomes.size() / 2;
        if (nomes.size() % 2 == 0) {
            return nomes[posicaoMeio - 1];
        } else {
            return nomes[posicaoMeio];
        }
    }
    void listarEmOrdem() const override {
        for (const string& nome : nomes) {
            cout << nome << " ";
        }
        cout << endl;
    }
    void exibirPrimeirosN(size_t quantidade) const override {
        for (size_t i = 0; i < min(quantidade, nomes.size()); ++i) {
            cout << nomes[i] << " ";
        }
        cout << endl;
    }
};

// Implementação das classes ListaSalarios e ListaIdades
// Como os salários e idades são representados como strings para manter a consistência com as outras listas, eles são tratados de forma semelhante.
class ListaSalarios : public Lista {
private:
    vector<string> salarios;
public:
    // Métodos similares aos da classe ListaData, mas para salários
    void adicionar(const string& valor) override {
        salarios.push_back(valor);
        sort(salarios.begin(), salarios.end());
    }
    string mediana() const override {
        if (salarios.empty()) return "";
        size_t posicaoMeio = salarios.size() / 2;
        if (salarios.size() % 2 == 0) {
            return salarios[posicaoMeio - 1];
        } else {
            return salarios[posicaoMeio];
        }
    }
    void listarEmOrdem() const override {
        for (const string& salario : salarios) {
            cout << salario << " ";
        }
        cout << endl;
    }
    void exibirPrimeirosN(size_t quantidade) const override {
        for (size_t i = 0; i < min(quantidade, salarios.size()); ++i) {
            cout << salarios[i] << " ";
        }
        cout << endl;
    }
};

class ListaIdades : public Lista {
private:
    vector<string> idades;
public:
    // Métodos similares aos da classe ListaData, mas para idades
    void adicionar(const string& valor) override {
        idades.push_back(valor);
        sort(idades.begin(), idades.end());
    }
    string mediana() const override {
        if (idades.empty()) return "";
        size_t posicaoMeio = idades.size() / 2;
        if (idades.size() % 2 == 0) {
            return idades[posicaoMeio - 1];
        } else {
            return idades[posicaoMeio];
        }
    }
    void listarEmOrdem() const override {
        for (const string& idade : idades) {
            cout << idade << " ";
        }
        cout << endl;
    }
    void exibirPrimeirosN(size_t quantidade) const override {
        for (size_t i = 0; i < min(quantidade, idades.size()); ++i) {
            cout << idades[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    vector<Lista*> listas;

    // Instanciar listas e adicioná-las ao vetor
    ListaData* listaData = new ListaData();
    ListaNomes* listaNomes = new ListaNomes();
    ListaSalarios* listaSalarios = new ListaSalarios();
    ListaIdades* listaIdades = new ListaIdades();

    listas.push_back(listaData);
    listas.push_back(listaNomes);
    listas.push_back(listaSalarios);
    listas.push_back(listaIdades);

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
        cin.ignore(); // Evitar problemas com getline após cin

        string entradaValor;
        size_t quantidade;

        switch (opcao) {
            case 1:
                cout << "Digite a data (formato YYYY-MM-DD): ";
                getline(cin, entradaValor);
                listaData->adicionar(entradaValor);
                break;

            case 2:
                cout << "Digite o nome: ";
                getline(cin, entradaValor);
                listaNomes->adicionar(entradaValor);
                break;

            case 3:
                cout << "Digite o salário: ";
                getline(cin, entradaValor);
                listaSalarios->adicionar(entradaValor);
                break;

            case 4:
                cout << "Digite a idade: ";
                getline(cin, entradaValor);
                listaIdades->adicionar(entradaValor);
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
