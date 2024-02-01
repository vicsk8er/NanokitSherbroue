#ifndef I2CSCREEN_H
#define I2CSCREEN_H



//déclaration de fonction qui sont partagé dans avec les autres fichiers

void i2cScreenInit();
void i2cScreenPrint(const char* message, int row, int col);
void i2cScreenPrintTemp(double temp, int ROW, int COL);

#endif