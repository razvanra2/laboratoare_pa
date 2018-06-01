#include <iostream>
#include <algorithm>
using namespace std;

struct Object {
    int discountPrice;
    int wholePrice;
};

bool rule(Object a, Object b) {
    /*sortez dupa obiectele care au cel mai mare discount*/
    return (a.discountPrice - a.wholePrice) < (b.discountPrice - b.wholePrice);
}

int main() {

    int n, k;
    cin >> n >> k;

    Object objects[10005]; /*Darius voice: mai bine faceai cu vector*/

    for (int i = 0; i < n; i++) {
        cin >> objects[i].discountPrice;
    }
    for (int i = 0; i < n; i++) {
        cin >> objects[i].wholePrice;
    }

    sort(objects, objects + n, rule); /*sortez dupa regula nebuna de mai sus*/

    int spentMoneyz = 0;
    for (int i = 0; i < k; i++) {  /* cumpara orice ar fi primele k obiecte*/
        spentMoneyz += objects[i].discountPrice;
    }

    int temp = k; /* si dupa daca e avantajos, mai cumpara cateva ca i-au facut baietii pret*/
    for (int i = k; i < n; i++) {
        if (objects[i].discountPrice - objects[i].wholePrice < 0) {
            spentMoneyz += objects[i].discountPrice;
        } else {
            temp = i;
            break;
        }
    }

    for (int i = temp; i < n; i++) { /* daca nu i-au facut pret */
        spentMoneyz += objects[i].wholePrice; /* tot cumpara Igor, ca aia e, dar cu alta ocazie*/
    }

    cout << spentMoneyz << endl; /* uite atata a dat cheltuit Igor */

    return 0;
}
