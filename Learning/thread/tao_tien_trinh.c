#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  STARTUPINFO stgStartupInfo;         // for CreateProcess()
  PROCESS_INFORMATION stgProcessInfo;

  DWORD ExitCode;                       // for the ExitCode

  ZeroMemory(&stgStartupInfo, sizeof(STARTUPINFO));
  stgStartupInfo.cb = sizeof(STARTUPINFO);

  char sz[256] = "c:\\windows\\notepad.exe c:\\abc.bat";

  // Start Notepad:
  if (CreateProcess(NULL, sz,
                    NULL, NULL, false,
                    CREATE_DEFAULT_ERROR_MODE | NORMAL_PRIORITY_CLASS,
                    NULL, NULL, &stgStartupInfo, &stgProcessInfo) == TRUE)
  {
    CloseHandle(stgProcessInfo.hThread);  // no longer needed...

    // Wait for the initialization of the newly started application
    // (Initialization is complete when the program is ready to accept user input)
    WaitForInputIdle(stgProcessInfo.hProcess, INFINITE);

    // Initialization of Notepad is now complete!

    // Wait for the program to end (it would also work without a loop
    // with WaitForSingleObject(stgProcessInfo.hProcess, INFINITE),
    // but system messages would not be processed, and the window would not be updated, etc.
    // Therefore, we wait "in slices" every 0.1s and repeatedly call ProcessMessages.
    while (WaitForSingleObject(stgProcessInfo.hProcess, 100) == WAIT_TIMEOUT)
    {
    }

    // The program has ended...

    // Read the exit code:
    GetExitCodeProcess(stgProcessInfo.hProcess, &ExitCode);

    // The variable ExitCode is now initialized with the return value of our application
    // (Notepad)

    // Release resources
    CloseHandle(stgProcessInfo.hProcess);
  }

  STARTUPINFO stgStartupInfo2;         // for CreateProcess()
  PROCESS_INFORMATION stgProcessInfo2;

  DWORD ExitCode2;                       // for the ExitCode

  ZeroMemory(&stgStartupInfo2, sizeof(STARTUPINFO));
  stgStartupInfo2.cb = sizeof(STARTUPINFO);

  // Start Notepad again:
  if (CreateProcess(NULL, sz,
                    NULL, NULL, false,
                    CREATE_DEFAULT_ERROR_MODE | NORMAL_PRIORITY_CLASS,
                    NULL, NULL, &stgStartupInfo2, &stgProcessInfo2) == TRUE)
  {
    CloseHandle(stgProcessInfo2.hThread);  // no longer needed...

    // Wait for the initialization of the newly started application
    // (Initialization is complete when the program is ready to accept user input)
    WaitForInputIdle(stgProcessInfo2.hProcess, INFINITE);

    // Initialization of Notepad is now complete!

    // Wait for the program to end (it would also work without a loop
    // with WaitForSingleObject(stgProcessInfo.hProcess, INFINITE),
    // but system messages would not be processed, and the window would not be updated, etc.
    // Therefore, we wait "in slices" every 0.1s and repeatedly call ProcessMessages.
    while (WaitForSingleObject(stgProcessInfo2.hProcess, 100) == WAIT_TIMEOUT)
    {
      
    }

    // The program has ended...

    // Read the exit code:
    GetExitCodeProcess(stgProcessInfo2.hProcess, &ExitCode2);

    // The variable ExitCode is now initialized with the return value of our application
    // (Notepad)

    // Release resources
    CloseHandle(stgProcessInfo2.hProcess);
  }

  return 0;
}



