#include <stdio.h>
#include <windows.h>

int main()
{
    printf("Launching notepad.exe...\n");

    // Using ShellExecute to launch notepad.exe with SW_SHOW flag
    ShellExecute(NULL, "open", "notepad.exe", NULL, NULL, SW_SHOW);

    return 0;
}
