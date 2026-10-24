#include "UI.h"

    int main()
    {
        Database db("dbname=hospital_os user=hospital_user password=YourStrongPassword123! host=localhost");

        UI ui(db);
        ui.MainMenu();

        return 0;
    }