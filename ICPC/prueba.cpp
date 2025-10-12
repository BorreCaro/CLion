#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Warning: variable no usada
    int unused_variable = 42;
    
    // Warning: comparación signed/unsigned
    vector<int> vec = {1, 2, 3, 4, 5};
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    
    // Warning: división por cero (algunos compiladores)
    int x = 5;
    int y = 0;
    // int result = x / y;  // Descomenta para ver error en runtime
    
    // Warning: variable puede no estar inicializada
    int uninitialized;
    if (x > 3) {
        uninitialized = 10;
    }
    // cout << uninitialized << endl; // Descomenta para usar variable posiblemente no inicializada
    
    // Warning: conversión implícita con pérdida de datos
    double pi = 3.14159;
    int truncated = pi;  // Pierde la parte decimal
    cout << "\nTruncated: " << truncated << endl;
    
    // Warning: función no retorna valor en todos los casos
    auto checkValue = [](int val) -> int {
        if (val > 0) {
            return val * 2;
        }
        // Falta return aquí
    };
    
    cout << "Check: " << checkValue(5) << endl;
    
    return 0;
}