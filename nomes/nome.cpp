#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void menu(){
    cout << "Selecione o metodo de ordenacao: " << endl;
    cout << "1 - Bubble Sort" << endl;
    cout << "2 - Selection Sort" << endl;
    cout << "3 - Insertion Sort" << endl;
    cout << "4 - Merge Sort" << endl;
    cout << "5 - Sair" << endl;
}

void imprimirNomes(string nomes[],int qt){
    for(int i = 0; i < qt; i++){
        cout << nomes[i] << endl;
    }
}

void bubbleSort(string nomes[], int qt){

    for(int i = 0; i < qt - 1; i++){
        bool houveTroca = false;
        for(int j = 0; j < qt - 1; j++){
            if(nomes[j] > nomes[j + 1]){
                houveTroca = true;
                string aux = nomes[j];
                nomes[j] = nomes[j+1];
                nomes[j+1] = aux;
            }
        }
        if(!houveTroca){
            break;
        }
    }

    imprimirNomes(nomes, qt);

}

void selectionSort(string nomes[], int qt){

    for(int i = 0; i < qt - 1; i++){
        int indiceDoMenor = i;

        for(int j = i + 1; j < qt; j++){

            if(nomes[j] < nomes[indiceDoMenor]){
                indiceDoMenor = j;
            }
        }

        if(indiceDoMenor != i){
            string aux = nomes[i];
            nomes[i] = nomes[indiceDoMenor];
            nomes[indiceDoMenor] = aux;
        }
    }

    imprimirNomes(nomes, qt);
}

void insertionSort(string nomes[], int qt){

    for(int i = 1; i < qt; i++){
        string aux = nomes[i];
        int j;

        for(j = i - 1; j >= 0 && nomes[j] > aux; j--){
            nomes[j+1] = nomes[j];
        }

        nomes[j+1] = aux;
    }

    imprimirNomes(nomes, qt);
}

void conquista(string nomes[], int inicio, int meio, int fim){

    int i = inicio, j = meio + 1, k = 0;

    string temp[(fim - inicio) + 1];

    while(i <= meio && j <= fim){

        if(nomes[i] < nomes[j]){
            temp[k++] = nomes[i++];
        }
        else {
            temp[k++] = nomes[j++];
        }
    }

    while(i <= meio){
        temp[k++] = nomes[i++];
    }

    while(j <= fim){
        temp[k++] = nomes[j++];
    }

    for(i = inicio, k = 0; i <= fim; i++, k++){
        nomes[i] = temp[k];
    }

}

void divisao(string nomes[], int inicio, int fim){

    if(inicio < fim){

        int meio = (inicio + fim) / 2;
        divisao(nomes, inicio, meio);
        divisao(nomes, meio + 1, fim);
        conquista(nomes, inicio, meio, fim);
    }
}

void mergeSort(string nomes[], int qt){
    divisao(nomes, 0, qt-1);
    imprimirNomes(nomes, qt);
}


int main() {
    int escolha;

    string arquivo = "nome.txt";

    ifstream arquivoEntrada(arquivo);

    if (!arquivoEntrada.is_open()) {
        cerr << "ERRO! Ao ler o arquivo" << endl;
        return 1;
    }

    string linha;
    string nomes[1001];
    int qtNomes = 0;

    while (getline(arquivoEntrada, linha)) {
        //cout << linha << endl;
        nomes[qtNomes] = linha;
        qtNomes++;
        if (linha.empty()) break;
    }

    menu();
    cin >> escolha;

    switch(escolha){
    case 1:
        bubbleSort(nomes,qtNomes);
        break;
    case 2:
        selectionSort(nomes,qtNomes);
        break;
    case 3:
        insertionSort(nomes, qtNomes);
        break;
    case 4:
        mergeSort(nomes,qtNomes);
        break;
    case 5:
        cout<< "Obrigado por ordenar" << endl;
        break;
    }

    return 0;
}
