using Microsoft.Win32.SafeHandles;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ebliskey.WeChatGooForNet
{
    internal static class Win32API
    {
        [DllImport("kernel32.dll", SetLastError = true)]
        internal static extern bool CloseHandle(IntPtr handle);

        [DllImport("kernel32.dll", SetLastError = true)]
        internal static extern bool FlushInstructionCache(SafeProcessHandle processHandle, IntPtr baseAddress, int regionSize);

        //[DllImport("kernel32.dll", SetLastError = true)]
        //internal static extern bool GetThreadContext(SafeThreadHandle threadHandle, IntPtr contextBuffer);

        [DllImport("kernel32.dll", SetLastError = true)]
        internal static extern bool IsWow64Process(SafeProcessHandle processHandle, out bool isWow64Process);

        //[DllImport("kernel32.dll", SetLastError = true)]
        //internal static extern SafeThreadHandle OpenThread(Enumerations.ThreadAccessMask desiredAccess, bool inheritHandle, int threadId);

        [DllImport("kernel32.dll", SetLastError = true)]
        internal static extern bool ReadProcessMemory(SafeProcessHandle processHandle, IntPtr baseAddress, IntPtr bytesReadBuffer, int bytesToRead, out int numberOfBytesRead);

        //[DllImport("kernel32.dll", SetLastError = true)]
        //internal static extern int ResumeThread(SafeThreadHandle threadHandle);

        //[DllImport("kernel32.dll", SetLastError = true)]
        //internal static extern bool SetThreadContext(SafeThreadHandle threadHandle, IntPtr contextBuffer);

        //[DllImport("kernel32.dll", SetLastError = true)]
        //internal static extern int SuspendThread(SafeThreadHandle threadHandle);

        [DllImport("Kernel32.dll")]
        public static extern int VirtualAllocEx(int hProcess, int lpAddress, int dwSize, int flAllocationType, int flProtect);

        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern Boolean VirtualFreeEx(int hProcess, int lpAddress, int dwSize, int dwFreeType);

        //[DllImport("kernel32.dll", SetLastError = true)]
        //internal static extern bool VirtualProtectEx(SafeProcessHandle processHandle, IntPtr baseAddress, int protectionSize, Enumerations.MemoryProtection protectionType, out Enumerations.MemoryProtection oldProtectionType);

        [DllImport("kernel32.dll")]
        internal static extern void WaitForSingleObject(IntPtr handle, int millisecondsToWait);

        //[DllImport("kernel32.dll", SetLastError = true)]
        //internal static extern bool Wow64GetThreadContext(SafeThreadHandle threadHandle, IntPtr contextBuffer);

        //[DllImport("kernel32.dll", SetLastError = true)]
        //internal static extern bool Wow64SetThreadContext(SafeThreadHandle threadHandle, IntPtr contextBuffer);

        //[DllImport("kernel32.dll", SetLastError = true)]
        //internal static extern int Wow64SuspendThread(SafeThreadHandle threadHandle);

        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern Boolean WriteProcessMemory(int hProcess, int lpBaseAddress, String lpBuffer, int nSize, int lpNumberOfBytesWritten);

        //[DllImport("ntdll.dll", SetLastError = true)]
        //internal static extern Enumerations.NtStatus NtQueryInformationProcess(SafeProcessHandle processHandle, Enumerations.ProcessInformationClass processInformationClass, IntPtr processInformationBuffer, int bufferSize, out int returnLength);

        //[DllImport("ntdll.dll", SetLastError = true)]
        //internal static extern Enumerations.NtStatus RtlCreateUserThread(SafeProcessHandle processHandle, IntPtr securityDescriptorBuffer, bool createSuspended, int stackZeroBits, IntPtr stackReserved, IntPtr stackCommit, IntPtr startAddress, IntPtr parameter, out SafeThreadHandle threadHandle, out IntPtr clientIdBuffer);

        //[DllImport("ntdll.dll")]
        //internal static extern ulong RtlNtStatusToDosError(Enumerations.NtStatus ntStatus);

        // user32.dll imports

        //[DllImport("user32.dll", SetLastError = true)]
        //internal static extern bool PostThreadMessage(int threadId, Enumerations.WindowsMessage message, Enumerations.VirtualKey wParameter, IntPtr lParameter);


        [DllImport("kernel32.dll")]
        public static extern int GetProcAddress(int hModule, String lpProcName);

        [DllImport("kernel32.dll")]
        public static extern int GetModuleHandleA(String lpModuleName);

        [DllImport("kernel32.dll")]
        public static extern IntPtr GetModuleFileNameA(IntPtr hwnd, string name, int size);

        [DllImport("kernel32.dll")]
        public static extern int CreateRemoteThread(int hProcess, int lpThreadAttributes, int dwStackSize, int lpStartAddress, int lpParameter, int dwCreationFlags, int lpThreadId);

        [DllImport("advapi32.dll", SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        internal static extern bool OpenProcessToken(IntPtr ProcessHandle, UInt32 DesiredAccess, out IntPtr TokenHandle);


        [DllImport("advapi32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        internal extern static bool DuplicateToken(IntPtr ExistingTokenHandle, int SECURITY_IMPERSONATION_LEVEL, ref IntPtr DuplicateTokenHandle);

        //[DllImport("advapi32.dll", SetLastError = true)]
        //[return: MarshalAs(UnmanagedType.Bool)]
        //internal static extern bool AdjustTokenPrivileges(IntPtr TokenHandle, [MarshalAs(UnmanagedType.Bool)]bool DisableAllPrivileges, ref TOKEN_PRIVILEGES NewState, UInt32 BufferLengthInBytes, ref TOKEN_PRIVILEGES PreviousState, out UInt32 ReturnLengthInBytes);


        //[DllImport("advapi32.dll")]
        //internal static extern bool LookupPrivilegeValue(string lpSystemName, string lpName, ref LUID lpLuid);

    }
}
