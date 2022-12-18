typedef struct Warehouse *Warehouse;

Warehouse WarehouseCreate(unsigned long n, unsigned long cap);

void WarehouseDelete(Warehouse w);

unsigned long WarehouseNStack(Warehouse w);

int WarehouseInsert(Warehouse w, unsigned long i, char c);

void WarehouseReverse(Warehouse w);

int WarehouseMove(Warehouse w, unsigned long o, unsigned long d);

int WarehouseMoveK(Warehouse w, unsigned long k, unsigned long o, unsigned long d);

char WarehouseGetTop(Warehouse w, unsigned long i);

