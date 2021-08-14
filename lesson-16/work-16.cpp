// Author - Kiselev Ilia

# include <cstdlib>
# include <iostream>
# include <cstring>
# include <string>

using namespace std;

// Task-1 ====================================
void CaesarCipher (string *message, string *crypt, int key) {
    int i = 0;
    string mes = *message;
    string cry = *message;
    while (mes[i] != '\0') {
        char s = mes[i];
        if (s == 32){
            cry[i] = s;
        } else {
            cry[i] = s + key;
        }
        i++;
    }
    *crypt = cry;
}

void CeasarDeCipher (string *crypt, string *message) {
    int i = 0;
    int key;
    string mes = *crypt;
    string cry = *crypt;
    cout << "Inter a key to decryption: ";
    cin >> key;
    while (cry[i] != '\0') {
        char s = cry[i];
        if (s == 32){
            mes[i] = s;
        } else {
            mes[i] = s - key;
        }
        i++;
    }
    *message = mes;
}

void CeasarHack (string *crypt, string *res) {
    int key = 0;
    char answer;
    string mes = *crypt;
    string cry = *crypt;
    do{
        int i = 0;
        key++;
        while (cry[i] != '\0') {
            char s = cry[i];
            if (s == 32){
                mes[i] = s;
            } else {
                mes[i] = s - key;
            }
            i++;
        }
        cout << mes << endl;
        cout << "Inter 'y' to continue: ";
        cin >> answer;
    } while (answer == 'y');    
    *res = mes;
}

// Task-2 ====================================

void permutationEncryption (string *message, string *cryptogram, int col) {
    int counter = 0;
    string mess = *message;
    string crypt = *message;
    while (mess[counter] != '\0') {
        counter++;
    }
    int size = counter + 1;
    int row = size / col;
    if (size % col != 0) {
        row++;
    }
    counter = 0;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (mess[counter] != '\0') {
                crypt [counter++] = mess[i + j*col];
            }
        }
    }
    *cryptogram = crypt;

}

void permutationDecryption (string *cryptogram, string *message) {
    int col;
    int counter = 0;
    string mess = *cryptogram;
    string crypt = *cryptogram;
    while (crypt[counter] != '\0') {
        counter++;
    }
    cout << "Inter a key to decryption: ";
    cin >> col;
    int size = counter + 1;
    int row = size / col;
    if (size % col != 0) {
        row++;
    }
    counter = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (crypt[counter] != '\0') {
                mess[counter++] = crypt[i + j*row];
            }
        }
    }

*message = mess;
}

void permutationHack (string *cryptogram, string *message) {
    int col = 1;
    int counter = 0;
    char answer;
    string mess = *cryptogram;
    string crypt = *cryptogram;
    while (crypt[counter] != '\0') {
        counter++;
    }
    int size = counter + 1;
    while (col <= size) {
        int row = size / col;
        if (size % col != 0) {
            row++;
        }
        counter = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (crypt[counter] != '\0') {
                    mess[counter++] = crypt[i + j*row];
                }
            }
        }
        cout << mess << endl;
        cout << "Inter 'y' to continue: ";
        cin >> answer;
        if (answer != 'y') {
            break;
        } else {
            col++;
        }
    }
    *message = mess;
}

int main (const int argc, const char **argv) {
// Task-1 ====================================
cout << "|| Task-1 ====================================" << endl << endl;

    string cent, recived, cryptogram;
    int key = 5;

    cout << "Inter a message: " << endl;
    getline(cin, cent);
    cout << "Inter a key: ";
    cin >> key;
  
    CaesarCipher(&cent, &cryptogram, key);
    
    cout << "Cryptogram: " << endl;
    cout << cryptogram << endl;

    CeasarDeCipher(&cryptogram, &recived);
    cout << "Decrypted message:" << endl;
    cout << recived << endl << endl;

    string message;
    CeasarHack(&cryptogram, &message);
    cout << "This is the decrypted message:" << endl;
    cout << message << endl;

    cin.clear();
    fflush(stdin);
cout << endl;
// Task-2 ====================================
cout << "|| Task-2 ====================================" << endl << endl;

    string sentMess;
    string resMess, cryptMess, hack;
    int key_2;

    cout << "Inter a message: " << endl;
    getline(cin, sentMess);
    cout << "Inter a key: ";
    cin >> key_2;

    permutationEncryption (&sentMess, &cryptMess, key_2);
    cout << "Cryptogram: " << endl;
    cout << cryptMess << endl;
    permutationDecryption (&cryptMess, &resMess);
    cout << "This is the decrypted message:" << endl;
    cout << resMess << endl;

    permutationHack (&cryptMess, &hack);
    cout << "This is the decrypted message:" << endl;
    cout << hack << endl; 

    system("pause");
    return 0;
}