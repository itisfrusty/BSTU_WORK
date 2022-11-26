#include <iostream>
#include "huff.h"
#include "sfano.h"

int main()
{
    std::string F[6] = { "Arh14.rar", "Pic14.bmp", "Pic14.JPG", "text14.doc", "text14.docx", "text14.txt" };

    ftable fr;
    fr.writeToFile(F[0]);
    fr.writeToFile(F[1]);
    fr.writeToFile(F[2]);
    fr.writeToFile(F[3]);
    fr.writeToFile(F[4]);
    fr.writeToFile(F[5]);

    huff haf;
    haf.writeToFile(F[0]);
    haf.writeToFile(F[1]);
    haf.writeToFile(F[2]);
    haf.writeToFile(F[3]);
    haf.writeToFile(F[4]);
    haf.writeToFile(F[5]);

    sfano sfn;
    sfn.writeToFile(F[0]);
    sfn.writeToFile(F[1]);
    sfn.writeToFile(F[2]);
    sfn.writeToFile(F[3]);
    sfn.writeToFile(F[4]);
    sfn.writeToFile(F[5]);

    return 0;
}
