void POP(int STACK[], int &TOP, int &ITEM) {
    if (TOP == 0) {
        cout << "UNDERFLOW" << endl;
        return;
    }
    ITEM = STACK[TOP];
    TOP = TOP - 1;
}
