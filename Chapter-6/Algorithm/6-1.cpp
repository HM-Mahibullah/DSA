void PUSH(int STACK[], int &TOP, int MAXSTK, int ITEM) {
    if (TOP == MAXSTK) {
        cout << "OVERFLOW" << endl;
        return;
    }
    TOP = TOP + 1;
    STACK[TOP] = ITEM;
}
