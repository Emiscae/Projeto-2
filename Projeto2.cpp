#include <iostream>
#include <conio.h>
#include <format>
#include <fstream>

#define N 100

using namespace std;

struct tutor{
    int id;
    char nome[N];
    char endereco[N];
    int compras[N];
};
struct animal{
    int id;
    int idTutor;
    char nome[N];
    char especie[N];
    char idade[N];
};
struct estoque{
    int id;
    char nome[N];
    int quantidade;
};

void cadastrarTutor(tutor tutores[], bool idsTutores[]);
void listarTutores(tutor tutores[], bool idsTutores[]);
void cadastrarAnimal(animal animais[], bool idsAnimais[], bool idsTutores[]);
void listarAnimal(animal animais[], bool idsTutores[]);
void animalTutor(animal animais[], bool idsTutores[]);
void relatorio(bool idsTutores[], bool idsAnimais[], tutor tutores[], animal animais[], estoque produto[]);
void cadastrarProduto(estoque produto[], bool idsProdutos[]);
void mostrarProdutos(estoque produto[], bool idsProdutos[]);
void atualizarProdutos(estoque produto[], bool idsProdutos[]);
void comprasTutor(tutor tutores[], bool idsTutores[], estoque produto[], bool idsProdutos[]);
void salvarInfo(bool idsTutores[], bool idsAnimais[], tutor tutores[], animal animais[], estoque produto[], bool idsProdutos[], int n, int n2);
void carregarInfo(bool idsTutores[], bool idsAnimais[], tutor tutores[], animal animais[], estoque produto[], bool idsProdutos[], int n, int n2);
void consoleClear();

int main(){
    tutor tutores[N];
    animal animais[N * 2];
    bool idsTutores[N] = {false};
    bool idsAnimais[N * 2] = {false};

    estoque produto[N];
    bool idsProdutos[N] = {false};


    while(1){
        int escolha;
        cout << "-----------------------------\n";
        cout << "1) Cadastrar um tutor.\n";
        cout << "2) Cadastrar um animal.\n";
        cout << "3) Listar tutores.\n";
        cout << "4) Listar animais.\n";
        cout << "5) Buscar animal por tutor.\n";
        cout << "6) Cadastrar produto.\n";
        cout << "7) Listar produtos.\n";
        cout << "8) Atualizar produtos.\n";
        cout << "9) Compras do tutor.\n";
        cout << "10) Relatorio geral.\n";
        cout << "11) Salvar informacoes.\n";
        cout << "12) Carregar informacoes.\n";
        cout << "13) Sair.\n";
        cout << "-----------------------------\n";
        cout << "Escolha uma opcao: ";

        cin >> escolha;

        switch(escolha){
            case 1:cadastrarTutor(tutores, idsTutores); break;
            case 2:cadastrarAnimal(animais, idsAnimais, idsTutores); break;
            case 3:listarTutores(tutores, idsTutores); break;
            case 4:listarAnimal(animais, idsTutores); break;
            case 5:animalTutor(animais, idsTutores); break;
            case 6:cadastrarProduto(produto, idsProdutos); break;
            case 7:mostrarProdutos(produto, idsProdutos); break;
            case 8:atualizarProdutos(produto, idsProdutos); break;
            case 9:comprasTutor(tutores, idsTutores, produto, idsProdutos); break;
            case 10:relatorio(idsTutores, idsAnimais, tutores, animais, produto); break;
            case 11:salvarInfo(idsTutores, idsAnimais, tutores, animais, produto, idsProdutos, 100, 200); break;
            case 12:carregarInfo(idsTutores, idsAnimais, tutores, animais, produto, idsProdutos, 100, 200); break;
            case 13:return 0;
        }
    }
}

void cadastrarTutor(tutor tutores[], bool idsTurores[]){
    consoleClear();
    int index;

    for(int i = 1; i < N + 1; i++){
        if(idsTurores[i] == false){
            idsTurores[i] = true;
            index = i;
            break;
        }
    }





    cout << "Digite o nome: ";
    cin.ignore();
    cin.getline(tutores[index].nome, 100);
    cout << "Digite o endereco: ";
    cin.getline(tutores[index].endereco, 100);

    tutores[index].id = index;

    cout << "Pressione Enter para continuar:";
    getch();
    consoleClear();
}
void listarTutores(tutor tutores[], bool idsTutores[]){
    consoleClear();
    for(int i = 0; i < N; i++){
        if(idsTutores[i] == true){
            printf("ID: %03d\n", tutores[i].id);
            cout << "Nome do tutor: " << tutores[i].nome << "\n";
            cout << "Endereco do tutor: " << tutores[i].endereco << "\n\n";
        }
    }
    cout << "Pressione Enter para continuar:";
    getch();
    consoleClear();
}
void cadastrarAnimal(animal animais[], bool idsAnimais[], bool idsTutores[]){
    consoleClear();
    int index;
    int idtutor;

    for(int i = 1; i < (N * 2) + 1; i++){
        if(idsAnimais[i] == false){
            idsAnimais[i] = true;
            index = i;
            break;
        }
    }



    cout << "Digite o nome do animal: ";
    cin.ignore();
    cin.getline(animais[index].nome, 100);
    cout << "Digite a especie do animal: ";
    cin.getline(animais[index].especie, 100);
    cout << "Digite a idade do animal: ";
    cin >> animais[index].idade;
    cout << "Digite o ID do tutor: ";
    cin >> animais[index].idTutor;
    if(idsTutores[index] == false){

        cout << "Tutor nao encontrado! pressione Enter para voltar ao menu:";
        getch();
        consoleClear();
        return;
    }



    animais[index].id = index;

    cout << "Pressione Enter para continuar:";
    getch();
    consoleClear();
}
void listarAnimal(animal animais[], bool idsTutores[]){
    consoleClear();
    for(int i = 1; i < (N * 2) + 1; i++){
        if(idsTutores[i] == true){
            printf("ID: %03d\n", animais[i].id);
            cout << "Nome do animal: " << animais[i].nome << "\n";
            cout << "Especie do animal: " << animais[i].especie << "\n";
            cout << "Idade do animal: " << animais[i].idade << "\n\n";
        }
    }
    cout << "Pressione Enter para continuar:";
    getch();
    consoleClear();
}
void animalTutor(animal animais[], bool idsTutores[]){
    consoleClear();
    int x;
    cout << "Digite o ID do tutor: ";
    cin >> x;
    if(idsTutores[x] == false){
        cout << "Tutor nao encontrado! pressione Enter para voltar ao menu:";
        getch();
        consoleClear();
        return;
    }
    else{
        consoleClear();
        for(int i = 0; i < N; i++){
            if(animais[i].idTutor == x){

                printf("%03d\n", animais[i].id);
                cout << "Nome do animal: " << animais[i].nome << "\n";
                cout << "Especie do animal: " << animais[i].especie << "\n";
                cout << "Idade do animal: " << animais[i].idade << "\n\n";
            }
        }
    }
    cout << "Pressione Enter para continuar:";
    getch();
    consoleClear();
}
void relatorio(bool idsTutores[], bool idsAnimais[], tutor tutores[], animal animais[], estoque produto[]){
    consoleClear();
    for(int i = 1; i < N; i++){
        if(idsTutores[i] == true){
            int cont = 0;
            for(int o = 1; o < N; o++){
                if(animais[o].idTutor == i){
                    cont++;
                }

            }

            printf("ID: %03d\n", i);
            cout << "Tutor: " << tutores[i].nome << "\n";
            cout << "Animais: " << cont << "\n";
            cout << "Compras: ";
            for(int p = 0; p < 10; p++){
                if(produto[p].id != 0){
                    if(p > 1){
                        cout << ", ";
                    }
                    cout << produto[p].nome;
                }
            }
            cout << "\n\n";
        }
    }
    cout << "Pressione Enter para continuar:";
    getch();
    consoleClear();
}
void cadastrarProduto(estoque produto[], bool idsProdutos[]){
    consoleClear();
    int index = 1;

    while(idsProdutos[index] == true){
        index++;
    }

    cout << "Digite o nome do produto: ";
    cin.ignore();
    cin.getline(produto[index].nome, 100);
    cout << "Digite a quantidade do produto: ";
    cin >> produto[index].quantidade;
    produto[index].id = index;
    idsProdutos[index] = true;

    consoleClear();
}
void mostrarProdutos(estoque produto[], bool idsProdutos[]){
    consoleClear();

    for(int i = 0; i < N; i++){
        if(idsProdutos[i] == true){
            printf("%03d\n", produto[i].id);
            cout << "Nome do produto: " << produto[i].nome << "\n";
            cout << "Quantidade do produto: " << produto[i].quantidade << "\n\n";
        }
    }

    cout << "Pressione Enter para continuar:";
    getch();
    consoleClear();
}
void atualizarProdutos(estoque produto[], bool idsProdutos[]){
    consoleClear();
    int id;

    cout << "Digite o ID do produto: ";
    cin >> id;
    consoleClear();

    if(idsProdutos[id] == true){
        cout << "Digite a nova quantidade: ";
        cin >> produto[id].quantidade;
        consoleClear();
        cout << "Produto atualizado com sucesso!\n\n";
    }
    else cout << "ID nao encontrado!\n\n";

    cout << "Pressione Enter para continuar:";
    getch();
    consoleClear();
}
void comprasTutor(tutor tutores[], bool idsTutores[], estoque produto[], bool idsProdutos[]){
    consoleClear();
    int idTutor;
    int idProduto;
    int quantidade;

    cout << "Digite o ID do tutor: ";
    cin >> idTutor;

    if(idsTutores[idTutor] == true){
        cout << "Qual o ID do produto ele vai comprar? ";
        cin >> idProduto;

        if(idsProdutos[idProduto] == true){
            cout << "Qual a quantidade que ele vai comprar? ";
            cin >> quantidade;
            produto[idProduto].quantidade -= quantidade;
            for(int i = 0; i < N; i++){
                if(tutores[idTutor].compras[i] == 0){
                    tutores[idTutor].compras[i] = idProduto;
                    break;
                }
            }
        }
        else cout << "ID do produto nao encontrado!\n\n";
    }
    else cout << "ID do tutor nao encontrado!\n\n";

    cout << "Pressione Enter para continuar:";
    getch();
    consoleClear();
}
void salvarInfo(bool idsTutores[], bool idsAnimais[], tutor tutores[], animal animais[], estoque produto[], bool idsProdutos[], int n, int n2){
    consoleClear();
    fstream meuArquivo;

    meuArquivo.open("info.bin", ios::out | ios::binary);

    if(meuArquivo.is_open()) {

        meuArquivo.write((char *) idsTutores, sizeof(bool) * n);
        meuArquivo.write((char *) idsAnimais, sizeof(bool) * n2);
        meuArquivo.write((char *) tutores, sizeof(tutor) * n);
        meuArquivo.write((char *) animais, sizeof(animal) * n2);
        meuArquivo.write((char *) produto, sizeof(estoque) * n);
        meuArquivo.write((char *) idsProdutos, sizeof(bool) * n);

        meuArquivo.close();

        cout << "Informacoes gravadas com sucesso!\n";
    }
    else {
        cout << "Nao foi possivel acessar o 'info.bin'\n";
    }

    cout << "Pressione Enter para continuar:";
    getch();
    consoleClear();
}
void carregarInfo(bool idsTutores[], bool idsAnimais[], tutor tutores[], animal animais[], estoque produto[], bool idsProdutos[], int n, int n2){
    consoleClear();
    fstream meuArquivo;

    meuArquivo.open("info.bin", ios::in | ios::binary);

    if(meuArquivo.is_open()) {

        meuArquivo.read((char *) idsTutores, sizeof(bool) * n);
        meuArquivo.read((char *) idsAnimais, sizeof(bool) * n2);
        meuArquivo.read((char *) tutores, sizeof(tutor) * n);
        meuArquivo.read((char *) animais, sizeof(animal) * n2);
        meuArquivo.read((char *) produto, sizeof(estoque) * n);
        meuArquivo.read((char *) idsProdutos, sizeof(bool) * n);

        meuArquivo.close();

        cout << "Informacoes carregadas com sucesso!\n";
    }
    else {
        cout << "Nao foi possivel acessar o 'info.bin'\n";
    }

    cout << "Pressione Enter para continuar:";
    getch();
    consoleClear();
}
void consoleClear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

